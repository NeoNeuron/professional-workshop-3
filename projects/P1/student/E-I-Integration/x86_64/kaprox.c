/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__kap
#define _nrn_initial _nrn_initial__kap
#define nrn_cur _nrn_cur__kap
#define _nrn_current _nrn_current__kap
#define nrn_jacob _nrn_jacob__kap
#define nrn_state _nrn_state__kap
#define _net_receive _net_receive__kap 
#define rates rates__kap 
#define states states__kap 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gkabar _p[0]
#define gka _p[1]
#define n _p[2]
#define l _p[3]
#define ek _p[4]
#define Dn _p[5]
#define Dl _p[6]
#define ik _p[7]
#define _g _p[8]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alpl(void);
 static void _hoc_alpn(void);
 static void _hoc_betl(void);
 static void _hoc_betn(void);
 static void _hoc_rates(void);
 static void _hoc_states(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_kap", _hoc_setdata,
 "alpl_kap", _hoc_alpl,
 "alpn_kap", _hoc_alpn,
 "betl_kap", _hoc_betl,
 "betn_kap", _hoc_betn,
 "rates_kap", _hoc_rates,
 "states_kap", _hoc_states,
 0, 0
};
#define alpl alpl_kap
#define alpn alpn_kap
#define betl betl_kap
#define betn betn_kap
 extern double alpl( double );
 extern double alpn( double );
 extern double betl( double );
 extern double betn( double );
 /* declare global and static user variables */
#define a0n a0n_kap
 double a0n = 0.05;
#define gml gml_kap
 double gml = 1;
#define gmn gmn_kap
 double gmn = 0.55;
#define linf linf_kap
 double linf = 0;
#define lmin lmin_kap
 double lmin = 2;
#define ninf ninf_kap
 double ninf = 0;
#define nmin nmin_kap
 double nmin = 0.1;
#define pw pw_kap
 double pw = -1;
#define q10 q10_kap
 double q10 = 5;
#define qq qq_kap
 double qq = 5;
#define taun taun_kap
 double taun = 0;
#define taul taul_kap
 double taul = 0;
#define tq tq_kap
 double tq = -40;
#define vhalfl vhalfl_kap
 double vhalfl = -56;
#define vhalfn vhalfn_kap
 double vhalfn = 11;
#define zetal zetal_kap
 double zetal = 3;
#define zetan zetan_kap
 double zetan = -1.5;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "vhalfn_kap", "mV",
 "vhalfl_kap", "mV",
 "a0n_kap", "/ms",
 "zetan_kap", "1",
 "zetal_kap", "1",
 "gmn_kap", "1",
 "gml_kap", "1",
 "lmin_kap", "mS",
 "nmin_kap", "mS",
 "pw_kap", "1",
 "gkabar_kap", "mho/cm2",
 0,0
};
 static double delta_t = 1;
 static double l0 = 0;
 static double n0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "vhalfn_kap", &vhalfn_kap,
 "vhalfl_kap", &vhalfl_kap,
 "a0n_kap", &a0n_kap,
 "zetan_kap", &zetan_kap,
 "zetal_kap", &zetal_kap,
 "gmn_kap", &gmn_kap,
 "gml_kap", &gml_kap,
 "lmin_kap", &lmin_kap,
 "nmin_kap", &nmin_kap,
 "pw_kap", &pw_kap,
 "tq_kap", &tq_kap,
 "qq_kap", &qq_kap,
 "q10_kap", &q10_kap,
 "ninf_kap", &ninf_kap,
 "linf_kap", &linf_kap,
 "taul_kap", &taul_kap,
 "taun_kap", &taun_kap,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"kap",
 "gkabar_kap",
 0,
 "gka_kap",
 0,
 "n_kap",
 "l_kap",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 9, _prop);
 	/*initialize range parameters*/
 	gkabar = 0;
 	_prop->param = _p;
 	_prop->param_size = 9;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _kaprox_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 9, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kap /Users/kchen/Desktop/TA2020A/professional-workshop-3/tutorials/W4_ModelPractice/E-I-Integration/x86_64/kaprox.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double _zfacn , _zfacl ;
static int _reset;
static char *modelname = "K-A channel from Klee Ficker and Heinemann";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(double);
static int states();
 
double alpn (  double _lv ) {
   double _lalpn;
 double _lzeta ;
 _lzeta = zetan + pw / ( 1.0 + exp ( ( _lv - tq ) / qq ) ) ;
   _lalpn = exp ( 1.e-3 * _lzeta * ( _lv - vhalfn ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lalpn;
 }
 
static void _hoc_alpn(void) {
  double _r;
   _r =  alpn (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double betn (  double _lv ) {
   double _lbetn;
 double _lzeta ;
 _lzeta = zetan + pw / ( 1.0 + exp ( ( _lv - tq ) / qq ) ) ;
   _lbetn = exp ( 1.e-3 * _lzeta * gmn * ( _lv - vhalfn ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lbetn;
 }
 
static void _hoc_betn(void) {
  double _r;
   _r =  betn (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double alpl (  double _lv ) {
   double _lalpl;
 _lalpl = exp ( 1.e-3 * zetal * ( _lv - vhalfl ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lalpl;
 }
 
static void _hoc_alpl(void) {
  double _r;
   _r =  alpl (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double betl (  double _lv ) {
   double _lbetl;
 _lbetl = exp ( 1.e-3 * zetal * gml * ( _lv - vhalfl ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lbetl;
 }
 
static void _hoc_betl(void) {
  double _r;
   _r =  betl (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int  states (  ) {
   rates ( _threadargscomma_ v ) ;
   n = n + _zfacn * ( ninf - n ) ;
   l = l + _zfacl * ( linf - l ) ;
   
/*VERBATIM*/
        return 0;
  return 0; }
 
static void _hoc_states(void) {
  double _r;
   _r = 1.;
 states (  );
 hoc_retpushx(_r);
}
 
static int  rates (  double _lv ) {
   double _la , _lqt ;
 _lqt = pow( q10 , ( ( celsius - 24.0 ) / 10.0 ) ) ;
   _la = alpn ( _threadargscomma_ _lv ) ;
   ninf = 1.0 / ( 1.0 + _la ) ;
   taun = betn ( _threadargscomma_ _lv ) / ( _lqt * a0n * ( 1.0 + _la ) ) ;
   if ( taun < nmin ) {
     taun = nmin ;
     }
   _zfacn = ( 1.0 - exp ( - dt / taun ) ) ;
   _la = alpl ( _threadargscomma_ _lv ) ;
   linf = 1.0 / ( 1.0 + _la ) ;
   taul = 0.26 * ( _lv + 50.0 ) ;
   if ( taul < lmin ) {
     taul = lmin ;
     }
   _zfacl = ( 1.0 - exp ( - dt / taul ) ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("kap", "cannot be used with CVODE"); return 0;}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  l = l0;
  n = n0;
 {
   rates ( _threadargscomma_ v ) ;
   n = ninf ;
   l = linf ;
   gka = gkabar * n * l ;
   ik = gka * ( v - ek ) ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gka = gkabar * n * l ;
   ik = gka * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
 { error =  states();
 if(error){fprintf(stderr,"at line 65 in file kaprox.mod:\n	SOLVE states \n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/kchen/Desktop/TA2020A/professional-workshop-3/tutorials/W4_ModelPractice/E-I-Integration/kaprox.mod";
static const char* nmodl_file_text = 
  "TITLE K-A channel from Klee Ficker and Heinemann\n"
  ": modified by Brannon and Yiota Poirazi \n"
  ": to account for Hoffman et al 1997 proximal region kinetics\n"
  ": used only in soma and sections located < 100 microns from the soma\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "\n"
  "}\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "PARAMETER {                       \n"
  "        dt              (ms)\n"
  "	v               (mV)\n"
  "        ek = -90        (mV)      :K reversal potential  (to be reset in init.hoc)\n"
  "	celsius = 24	(degC)\n"
  "       	gkabar = 0      (mho/cm2) :initialized conductance\n"
  "        vhalfn = 11     (mV)      :activation half-potential\n"
  "        vhalfl = -56    (mV) 	  :inactivation half-potential\n"
  "        a0n = 0.05      (/ms)     :parameters used\n"
  "        zetan = -1.5    (1)       :in calculation of\n"
  "        zetal = 3       (1)       :steady state values\n"
  "        gmn = 0.55      (1)       :and time constants\n"
  "        gml = 1         (1)\n"
  "	lmin = 2        (mS)\n"
  "	nmin = 0.1      (mS)\n"
  "	pw = -1         (1)\n"
  "	tq = -40\n"
  "	qq = 5\n"
  "	q10 = 5                   :temperature sensitivity\n"
  "}\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX kap\n"
  "	USEION k READ ek WRITE ik\n"
  "        RANGE gkabar,gka\n"
  "        GLOBAL ninf,linf,taul,taun,lmin\n"
  "}\n"
  "\n"
  "STATE {          :the unknown parameters to be solved in the DEs \n"
  "	n l\n"
  "}\n"
  " \n"
  "ASSIGNED {       :parameters needed to solve DE\n"
  "	ik (mA/cm2)\n"
  "        ninf\n"
  "        linf      \n"
  "        taul\n"
  "        taun\n"
  "        gka\n"
  "}\n"
  "\n"
  "INITIAL {		:initialize the following parameter using rates()\n"
  "	rates(v)\n"
  "	n = ninf\n"
  "	l = linf\n"
  "	gka = gkabar*n*l\n"
  "	ik = gka*(v-ek)\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states \n"
  "	gka = gkabar*n*l\n"
  "	ik = gka*(v-ek)\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION alpn(v(mV)) { LOCAL zeta \n"
  "  zeta = zetan+pw/(1+exp((v-tq)/qq))\n"
  "  alpn = exp(1.e-3*zeta*(v-vhalfn)*9.648e4/(8.315*(273.16+celsius))) \n"
  "}\n"
  "\n"
  "FUNCTION betn(v(mV)) { LOCAL zeta\n"
  "  zeta = zetan+pw/(1+exp((v-tq)/qq))\n"
  "  betn = exp(1.e-3*zeta*gmn*(v-vhalfn)*9.648e4/(8.315*(273.16+celsius))) \n"
  "}\n"
  "\n"
  "FUNCTION alpl(v(mV)) {\n"
  "  alpl = exp(1.e-3*zetal*(v-vhalfl)*9.648e4/(8.315*(273.16+celsius))) \n"
  "}\n"
  "\n"
  "FUNCTION betl(v(mV)) {\n"
  "  betl = exp(1.e-3*zetal*gml*(v-vhalfl)*9.648e4/(8.315*(273.16+celsius))) \n"
  "}\n"
  "\n"
  "LOCAL facn,facl\n"
  ":if state_borgka is called from hoc, garbage or segmentation violation will\n"
  ":result because range variables won't have correct pointer.  This is because\n"
  ": only BREAKPOINT sets up the correct pointers to range variables.\n"
  "PROCEDURE states() {     : exact when v held constant; integrates over dt step\n"
  "        rates(v)\n"
  "        n = n + facn*(ninf - n)\n"
  "        l = l + facl*(linf - l)\n"
  "        VERBATIM\n"
  "        return 0;\n"
  "        ENDVERBATIM\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v (mV)) {                  :callable from hoc\n"
  "        LOCAL a,qt\n"
  "        qt = q10^((celsius-24)/10)         : temprature adjustment factor\n"
  "        a = alpn(v)\n"
  "        ninf = 1/(1 + a)                   : activation variable steady state value\n"
  "        taun = betn(v)/(qt*a0n*(1+a))      : activation variable time constant\n"
  "	if (taun<nmin) {taun=nmin}         : time constant not allowed to be less than nmin\n"
  "        facn = (1 - exp(-dt/taun))\n"
  "        a = alpl(v)\n"
  "        linf = 1/(1+ a)                    : inactivation variable steady state value\n"
  "	taul = 0.26*(v+50)                 : inactivation variable time constant\n"
  "	if (taul<lmin) {taul=lmin}         : time constant not allowed to be less than lmin\n"
  "        facl = (1 - exp(-dt/taul))\n"
  "}\n"
  ;
#endif
