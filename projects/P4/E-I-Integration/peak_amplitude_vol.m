close all;

EPSP=load('Etrace_EIpair.dat');
IPSP=load('Itrace_EIpair.dat');
SSP=load('Strace_EIpair.dat');

posE=max(EPSP,[],2);
pE=find(posE==max(posE));
timeE=find(EPSP(pE,:)==max(posE),1)

posI=min(IPSP,[],2);
pI=find(posI==min(posI));
timeI=find(IPSP(pI,:)==min(posI),1)

posS=max(SSP,[],2);
pS=find(posS==max(posS));
timeS=find(SSP(pS,:)==max(posS),1)

figure();
subplot(1,3,1);
plot(EPSP');
subplot(1,3,2);
plot(IPSP');
subplot(1,3,3);
plot(SSP');

E=EPSP(:,pE);
I=IPSP(:,pI);
S=SSP(:,pS);

save volE.dat E -ascii
save volI.dat I -ascii
save volS.dat S -ascii