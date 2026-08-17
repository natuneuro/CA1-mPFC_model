#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _CaDynamics_E2_reg(void);
extern void _Ca_HVA_reg(void);
extern void _Ca_LVAst_reg(void);
extern void _Ca_reg(void);
extern void _ch_HCNp_reg(void);
extern void _ch_Kdrp_reg(void);
extern void _ch_KvAdistp_reg(void);
extern void _ch_KvAproxp_reg(void);
extern void _ch_Navaxonp_reg(void);
extern void _ch_Navp_reg(void);
extern void _Ih_reg(void);
extern void _Im_reg(void);
extern void _K_Pst_reg(void);
extern void _K_Tst_reg(void);
extern void _mynetstim_reg(void);
extern void _Nap_Et2_reg(void);
extern void _NaTa_t_reg(void);
extern void _NaTs2_t_reg(void);
extern void _SK_E2_reg(void);
extern void _SKv3_1_reg(void);
extern void _vecstim_reg(void);
extern void _xtra_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"mod_minimal/CaDynamics_E2.mod\"");
    fprintf(stderr, " \"mod_minimal/Ca_HVA.mod\"");
    fprintf(stderr, " \"mod_minimal/Ca_LVAst.mod\"");
    fprintf(stderr, " \"mod_minimal/Ca.mod\"");
    fprintf(stderr, " \"mod_minimal/ch_HCNp.mod\"");
    fprintf(stderr, " \"mod_minimal/ch_Kdrp.mod\"");
    fprintf(stderr, " \"mod_minimal/ch_KvAdistp.mod\"");
    fprintf(stderr, " \"mod_minimal/ch_KvAproxp.mod\"");
    fprintf(stderr, " \"mod_minimal/ch_Navaxonp.mod\"");
    fprintf(stderr, " \"mod_minimal/ch_Navp.mod\"");
    fprintf(stderr, " \"mod_minimal/Ih.mod\"");
    fprintf(stderr, " \"mod_minimal/Im.mod\"");
    fprintf(stderr, " \"mod_minimal/K_Pst.mod\"");
    fprintf(stderr, " \"mod_minimal/K_Tst.mod\"");
    fprintf(stderr, " \"mod_minimal/mynetstim.mod\"");
    fprintf(stderr, " \"mod_minimal/Nap_Et2.mod\"");
    fprintf(stderr, " \"mod_minimal/NaTa_t.mod\"");
    fprintf(stderr, " \"mod_minimal/NaTs2_t.mod\"");
    fprintf(stderr, " \"mod_minimal/SK_E2.mod\"");
    fprintf(stderr, " \"mod_minimal/SKv3_1.mod\"");
    fprintf(stderr, " \"mod_minimal/vecstim.mod\"");
    fprintf(stderr, " \"mod_minimal/xtra.mod\"");
    fprintf(stderr, "\n");
  }
  _CaDynamics_E2_reg();
  _Ca_HVA_reg();
  _Ca_LVAst_reg();
  _Ca_reg();
  _ch_HCNp_reg();
  _ch_Kdrp_reg();
  _ch_KvAdistp_reg();
  _ch_KvAproxp_reg();
  _ch_Navaxonp_reg();
  _ch_Navp_reg();
  _Ih_reg();
  _Im_reg();
  _K_Pst_reg();
  _K_Tst_reg();
  _mynetstim_reg();
  _Nap_Et2_reg();
  _NaTa_t_reg();
  _NaTs2_t_reg();
  _SK_E2_reg();
  _SKv3_1_reg();
  _vecstim_reg();
  _xtra_reg();
}

#if defined(__cplusplus)
}
#endif
