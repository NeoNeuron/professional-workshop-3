TITLE K-A channel from Klee Ficker and Heinemann
: modified by Brannon and Yiota Poirazi 
: to account for Hoffman et al 1997 distal region kinetics
: used only in locations > 100 microns from the soma


UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

PARAMETER {                        
        dt (ms)
	v (mV)
        ek = -90                   :K reversal potential  (to be reset in init.hoc)
	celsius = 24	(degC)
:	gkabar = 0.008  (mho/cm2)  :suggested conductance value
	gkabar = 0      (mho/cm2)  :initialized conductance
        vhalfn = -1     (mV)       :activation half-potential
        vhalfl = -56    (mV)       :inactivation half-potential
        a0n = 0.1       (/ms)      :parameters used
        zetan = -1.8    (1)        :in calculation of
        zetal = 3       (1)        :steady state values
        gmn   = 0.39    (1)        :and time constants
        gml   = 1       (1)
	lmin  = 2       (mS)
	nmin  = 0.1     (mS)
	pw    = -1      (1)
	tq    = -40
	qq    = 5
	q10   = 5                  :temperature sensitivity
}


NEURON {
	SUFFIX kad
	USEION k READ ek WRITE ik
        RANGE gkabar,gka
        GLOBAL ninf,linf,taul,taun,lmin
}

STATE {       :the unknown parameters to be solved in the DEs 
	n l
}

ASSIGNED {    :parameters needed to solve DE
	ik (mA/cm2)
        ninf
        linf      
        taul
        taun
        gka
}

INITIAL {    :initialize the following parameter using rates()
	rates(v)
	n=ninf
	l=linf
	gka = gkabar*n*l
	ik = gka*(v-ek)	
}

BREAKPOINT {
	SOLVE states
	gka = gkabar*n*l
	ik = gka*(v-ek)
}

FUNCTION alpn(v(mV)) { LOCAL zeta
  zeta = zetan+pw/(1+exp((v-tq)/qq))
  alpn = exp(1.e-3*zeta*(v-vhalfn)*9.648e4/(8.315*(273.16+celsius))) 
}

FUNCTION betn(v(mV)) { LOCAL zeta
  zeta = zetan+pw/(1+exp((v-tq)/qq))
  betn = exp(1.e-3*zeta*gmn*(v-vhalfn)*9.648e4/(8.315*(273.16+celsius))) 
}

FUNCTION alpl(v(mV)) {
  alpl = exp(1.e-3*zetal*(v-vhalfl)*9.648e4/(8.315*(273.16+celsius))) 
}

FUNCTION betl(v(mV)) {
  betl = exp(1.e-3*zetal*gml*(v-vhalfl)*9.648e4/(8.315*(273.16+celsius))) 
}
LOCAL facn,facl
:if state_borgka is called from hoc, garbage or segmentation violation will
:result because range variables won't have correct pointer.  This is because
: only BREAKPOINT sets up the correct pointers to range variables.
PROCEDURE states() {     : exact when v held constant; integrates over dt step
        rates(v)
        n = n + facn*(ninf - n)
        l = l + facl*(linf - l)
        VERBATIM
        return 0;
        ENDVERBATIM
}

PROCEDURE rates(v (mV)) {		 :callable from hoc
        LOCAL a,qt
        qt = q10^((celsius-24)/10)       : temprature adjustment factor
        a = alpn(v)
        ninf = 1/(1 + a)		 : activation variable steady state value
        taun = betn(v)/(qt*a0n*(1+a))	 : activation variable time constant
	if (taun<nmin) {taun=nmin}	 : time constant not allowed to be less than nmin
        facn = (1 - exp(-dt/taun))
        a = alpl(v)
        linf = 1/(1+ a)                  : inactivation variable steady state value
	taul = 0.26*(v+50)               : inactivation variable time constant
	if (taul<lmin) {taul=lmin}       : time constant not allowed to be less than lmin
        facl = (1 - exp(-dt/taul))
}
