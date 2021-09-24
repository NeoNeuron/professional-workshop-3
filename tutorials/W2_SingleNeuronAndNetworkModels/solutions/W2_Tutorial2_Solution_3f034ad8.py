
start_scope()

# USE these parameters. (Of course, you can try other values latter)
tau_m = 20*ms       # membrane time constant
V_reset = 10*mV     # reset potential
V_th = 20*mV        # threshold potential
J = 0.2*mV          # EPSP
g = 6               # ratio of IPSP/EPSP
delay=1.8*ms        # synaptic transimition delay
ext_ratio = 0.9     # ratio of nu_ext/nu_th
p = 0.1             # connectivity probability

# define the system of LIF model
eqs = '''
dv/dt = -v/tau_m : volt (unless refractory)
'''

ratio = 4
N_I = 2500
N_E = N_I*ratio

# write your own code to construct the network
G_E = NeuronGroup(N_E, eqs, threshold='v>V_th', reset='v=V_reset', refractory=2*ms, method='euler')
G_I = NeuronGroup(N_I, eqs, threshold='v>V_th', reset='v=V_reset', refractory=2*ms, method='euler')
G_E.v = 'rand()*V_th'
G_I.v = 'rand()*V_th'

S_EE = Synapses(G_E, G_E, 'w:volt',  on_pre='v+=w', delay=delay)
S_IE = Synapses(G_E, G_I, 'w:volt',  on_pre='v+=w', delay=delay)
S_EI = Synapses(G_I, G_E, 'w:volt',  on_pre='v-=w', delay=delay)
S_II = Synapses(G_I, G_I, 'w:volt',  on_pre='v-=w', delay=delay)


for S in (S_EE, S_II):
    S.connect(condition='i!=j', p=p)
for S in (S_IE, S_EI):
    S.connect(p=p)

for S in (S_EE, S_IE):
    S.w = J
for S in (S_EI, S_II):
    S.w = J*g

# define external Poisson drive
nu_th = V_th/(p*N_E*J*tau_m)
Poisson_E = PoissonGroup(N_E, rates=nu_th*N_E*p*ext_ratio)
Poisson_I = PoissonGroup(N_I, rates=nu_th*N_E*p*ext_ratio)

# Also use Synapses to inject outputs from PoissonGroup to NeuronGroup
SP_E = Synapses(Poisson_E, G_E, on_pre='v+=J')
SP_I = Synapses(Poisson_I, G_I, on_pre='v+=J')
SP_E.connect(condition='i==j')
SP_I.connect(condition='i==j')

# write your own code to run simulation and plot the results

# define Monitors
spikemon_E = SpikeMonitor(G_E)
spikemon_I = SpikeMonitor(G_I)
pop_E = PopulationRateMonitor(G_E)
pop_I = PopulationRateMonitor(G_I)

# run simulation
T=500*ms
run(T)

fig, ax = plt.subplots(2,1, figsize=(15,10))
ax[0].plot(spikemon_E.t/ms, spikemon_E.i, '.b', ms=2)
ax[0].plot(spikemon_I.t/ms, spikemon_I.i+N_E, '.r', ms=2)
ax[0].set_xlim(0, T/ms)
ax[0].set_ylim(0,N_E+N_I)
ax[0].set_xlabel('Time (ms)')
ax[0].set_ylabel('Neuron index')
ax[0].set_title(f'Individual firing rate : {(spikemon_E.i.shape[0] + spikemon_I.i.shape[0])/(N_E+N_I)/T/Hz:5.2f} Hz')

ax[1].plot(pop_E.t / ms, pop_E.smooth_rate(width=2 * ms) / Hz, color='b', label='excitatory')
ax[1].plot(pop_I.t / ms, pop_I.smooth_rate(width=2 * ms) / Hz, color='r', label='inhibitory')
ax[1].legend()
ax[1].set_xlim(0, T/ms)
ax[1].set_xlabel('Time (ms)')
ax[1].set_ylabel('Populational Firing Rate (Hz)');