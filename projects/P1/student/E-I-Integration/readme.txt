This directory includes the NEURON code for simulating dendritic integration of excitation and inhibition in the CA1 pyramidal neuron- 
-Jiang Hao, Xu-dong Wang, Yang Dan, Mu-ming Poo, and Xiao-hui Zhang ¡°An Arithmetic Rule for Spatial Summation of Excitatory and Inhibitory Inputs in Pyramidal Neurons¡±, 2009.

Neuron morphology: n128.hoc, apical_dendrite.hoc, apical_trunk.hoc, axon_sections.hoc, basal_dendrite.hoc, radiatum.hoc
Active ion channels: na3.mod, nax.mod, kdrca1.mod, kaprox.mod, kadist.mod, h.mod
Transmitter receptors: ampa.mod, nmda.mod, gabaa.mod, gabab.mod

Module tools: dist.hoc, find_peak.hoc, find_min.hoc, addgraph.hoc, morph_plot.hoc£¬random_pick
Main programs: init.hoc, preload_files.hoc, trace.hoc, parameter_search.hoc, parameter_search_IE.hoc, k_fast_run.hoc, k_normal_run.hoc, SC_random.hoc, SC_random_mean.hoc, shunting_factor.mod, plot_k.hoc, mulEI.hoc, spike.hoc, dendritic spike.hoc

Running the program "trace.hoc" generates traces of EPSP, IPSP and SUM. Linear SUM and Residue are also calculated. 
¡°parameter-search.hoc¡± and ¡°parameter-search-IE.hoc¡± produce source files for use by other programs. 
¡°SC_random.hoc¡± and ¡°SC_random_mean.hoc¡± are two programs used in studying the relationship among shunting component, EPSP and IPSP. 
¡°k_normal_run.hoc¡± is used to calculate the k value for each combination of E-I locations. 
¡°k_fast_run.hoc¡± is a fast procedure for roughly estimating the k value. 
¡°plot_k.hoc¡± is used to plot the dendritic k-profile. 
¡°mulEI.hoc¡± is for E-I integration with multiple Es and Is getting involved.
¡°spike.hoc¡± is for summation in the presense of spikes.
¡°dendritic spike.hoc¡± is used to examine the interaction between an IPSP and a dendritic spike. 

Under the windows system, use the ¡°mknrndll¡± command to compile the mod files, and double-click the target program for running. 
Note: The programs are running in NEURON 5.7. Some functions may not be supported by the later versions.

Xu-dong Wang
wxd@ion.ac.cn
Dec. 17th, 2009
