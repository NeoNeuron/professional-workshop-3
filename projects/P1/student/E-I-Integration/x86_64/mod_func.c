#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _NetStim1_reg(void);
extern void _ampa_reg(void);
extern void _gabaa_reg(void);
extern void _gabab_reg(void);
extern void _h_reg(void);
extern void _kadist_reg(void);
extern void _kaprox_reg(void);
extern void _kdrca1_reg(void);
extern void _na3_reg(void);
extern void _nax_reg(void);
extern void _nmda_reg(void);
extern void _shunting_factor_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," NetStim1.mod");
    fprintf(stderr," ampa.mod");
    fprintf(stderr," gabaa.mod");
    fprintf(stderr," gabab.mod");
    fprintf(stderr," h.mod");
    fprintf(stderr," kadist.mod");
    fprintf(stderr," kaprox.mod");
    fprintf(stderr," kdrca1.mod");
    fprintf(stderr," na3.mod");
    fprintf(stderr," nax.mod");
    fprintf(stderr," nmda.mod");
    fprintf(stderr," shunting_factor.mod");
    fprintf(stderr, "\n");
  }
  _NetStim1_reg();
  _ampa_reg();
  _gabaa_reg();
  _gabab_reg();
  _h_reg();
  _kadist_reg();
  _kaprox_reg();
  _kdrca1_reg();
  _na3_reg();
  _nax_reg();
  _nmda_reg();
  _shunting_factor_reg();
}
