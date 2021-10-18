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
 
#define nrn_init _nrn_init__GABAb
#define _nrn_initial _nrn_initial__GABAb
#define nrn_cur _nrn_cur__GABAb
#define _nrn_current _nrn_current__GABAb
#define nrn_jacob _nrn_jacob__GABAb
#define nrn_state _nrn_state__GABAb
#define _net_receive _net_receive__GABAb 
#define bindkin bindkin__GABAb 
#define release release__GABAb 
 
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
#define gmax _p[0]
#define i _p[1]
#define g _p[2]
#define C _p[3]
#define lastrelease _p[4]
#define R _p[5]
#define G _p[6]
#define Gn _p[7]
#define DR _p[8]
#define DG _p[9]
#define _g _p[10]
#define _nd_area  *_ppvar[0]._pval
#define pre	*_ppvar[2]._pval
#define _p_pre	_ppvar[2]._pval
 
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
 static int hoc_nrnpointerindex =  2;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_release();
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

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "release", _hoc_release,
 0, 0
};
 /* declare global and static user variables */
#define Cdur Cdur_GABAb
 double Cdur = 1;
#define Cmax Cmax_GABAb
 double Cmax = 1;
#define Deadtime Deadtime_GABAb
 double Deadtime = 1;
#define Erev Erev_GABAb
 double Erev = -90;
#define KD KD_GABAb
 double KD = 100;
#define K4 K4_GABAb
 double K4 = 0.034;
#define K3 K3_GABAb
 double K3 = 0.18;
#define K2 K2_GABAb
 double K2 = 0.0012;
#define K1 K1_GABAb
 double K1 = 0.2;
#define Prethresh Prethresh_GABAb
 double Prethresh = 0;
#define n n_GABAb
 double n = 4;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Cmax_GABAb", "mM",
 "Cdur_GABAb", "ms",
 "Deadtime_GABAb", "ms",
 "K1_GABAb", "/ms",
 "K2_GABAb", "/ms",
 "K3_GABAb", "/ms",
 "K4_GABAb", "/ms",
 "Erev_GABAb", "mV",
 "gmax", "umho",
 "i", "nA",
 "g", "umho",
 "C", "mM",
 "lastrelease", "ms",
 0,0
};
 static double G0 = 0;
 static double R0 = 0;
 static double delta_t = 1;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Cmax_GABAb", &Cmax_GABAb,
 "Cdur_GABAb", &Cdur_GABAb,
 "Prethresh_GABAb", &Prethresh_GABAb,
 "Deadtime_GABAb", &Deadtime_GABAb,
 "K1_GABAb", &K1_GABAb,
 "K2_GABAb", &K2_GABAb,
 "K3_GABAb", &K3_GABAb,
 "K4_GABAb", &K4_GABAb,
 "KD_GABAb", &KD_GABAb,
 "n_GABAb", &n_GABAb,
 "Erev_GABAb", &Erev_GABAb,
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
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"GABAb",
 "gmax",
 0,
 "i",
 "g",
 "C",
 "lastrelease",
 0,
 "R",
 "G",
 0,
 "pre",
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 11, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 11;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _gabab_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 11, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GABAb /Users/kchen/Desktop/TA2020A/professional-workshop-3/tutorials/W4_ModelPractice/E-I-Integration/x86_64/gabab.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "minimal model of GABAB receptors";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int release();
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static double *_temp1;
 static int _slist1[2], _dlist1[2];
 static int bindkin(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   release ( _threadargs_ ) ;
   DR = K1 * C * ( 1.0 - R ) - K2 * R ;
   DG = K3 * R - K4 * G ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 release ( _threadargs_ ) ;
 DR = DR  / (1. - dt*( ( K1 * C )*( ( ( - 1.0 ) ) ) - ( K2 )*( 1.0 ) )) ;
 DG = DG  / (1. - dt*( ( - ( K4 )*( 1.0 ) ) )) ;
  return 0;
}
 /*END CVODE*/
 
static int bindkin () {_reset=0;
 {
   release ( _threadargs_ ) ;
   DR = K1 * C * ( 1.0 - R ) - K2 * R ;
   DG = K3 * R - K4 * G ;
   }
 return _reset;}
 
static int  release (  ) {
   double _lq ;
 _lq = ( ( t - lastrelease ) - Cdur ) ;
   if ( _lq > Deadtime ) {
     if ( pre > Prethresh ) {
       C = Cmax ;
       lastrelease = t ;
       }
     }
   else if ( _lq < 0.0 ) {
     }
   else if ( C  == Cmax ) {
     C = 0. ;
     }
    return 0; }
 
static double _hoc_release(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 release (  );
 return(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  G = G0;
  R = R0;
 {
   C = 0.0 ;
   lastrelease = - 1000.0 ;
   R = 0.0 ;
   G = 0.0 ;
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
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   Gn = pow( G , n ) ;
   g = gmax * Gn / ( Gn + KD ) ;
   i = g * ( v - Erev ) ;
   }
 _current += i;

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
 _g = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
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
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
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
 { error =  euler(_ninits, 2, _slist1, _dlist1, _p, &t, dt, bindkin, &_temp1);
 if(error){fprintf(stderr,"at line 156 in file gabab.mod:\n	SOLVE bindkin METHOD euler\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 2; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(R) - _p;  _dlist1[0] = &(DR) - _p;
 _slist1[1] = &(G) - _p;  _dlist1[1] = &(DG) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/kchen/Desktop/TA2020A/professional-workshop-3/tutorials/W4_ModelPractice/E-I-Integration/gabab.mod";
static const char* nmodl_file_text = 
  "TITLE minimal model of GABAB receptors\n"
  "\n"
  "COMMENT\n"
  "-----------------------------------------------------------------------------\n"
  "\n"
  "	Minimal kinetic model for GABA-B receptors\n"
  "	==========================================\n"
  "\n"
  "	Minimal model of GABAB currents including nonlinear stimulus \n"
  "	dependency (fundamental to take into account for GABAB receptors).\n"
  "\n"
  "\n"
  "	Features:\n"
  "\n"
  "  	  - peak at 100 ms; time course fit from experimental PSC\n"
  "	  - NONLINEAR SUMMATION (psc is much stronger with bursts)\n"
  "	    due to cooperativity of G-protein binding on K+ channels\n"
  "\n"
  "	Approximations:\n"
  "\n"
  "	  - single binding site on receptor	\n"
  "	  - model of alpha G-protein activation (direct) of K+ channel\n"
  "	  - G-protein dynamics is second-order; simplified as follows:\n"
  "		- saturating receptor\n"
  "		- no desensitization\n"
  "		- Michaelis-Menten of receptor for G-protein production\n"
  "		- \"resting\" G-protein is in excess\n"
  "		- Quasi-stat of intermediate enzymatic forms\n"
  "	  - binding on K+ channel is fast\n"
  "\n"
  "\n"
  "	Kinetic Equations:\n"
  "\n"
  "	  dR/dt = K1 * T * (1-R) - K2 * R\n"
  "\n"
  "	  dG/dt = K3 * R - K4 * G\n"
  "\n"
  "	  R : activated receptor\n"
  "	  T : transmitter\n"
  "	  G : activated G-protein\n"
  "	  K1,K2,K3,K4 = kinetic rate cst\n"
  "\n"
  "  n activated G-protein bind to a K+ channel:\n"
  "\n"
  "	n G + C <-> O		(Alpha,Beta)\n"
  "\n"
  "  If the binding is fast, the fraction of open channels is given by:\n"
  "\n"
  "	O = G^n / ( G^n + KD )\n"
  "\n"
  "  where KD = Beta / Alpha is the dissociation constant\n"
  "\n"
  "-----------------------------------------------------------------------------\n"
  "\n"
  "  Based on voltage-clamp recordings of GABAB receptor-mediated currents in rat\n"
  "  hippocampal slices (Otis et al, J. Physiol. 463: 391-407, 1993), this model \n"
  "  was fit directly to experimental recordings in order to obtain the optimal\n"
  "  values for the parameters (see Destexhe and Sejnowski, 1995).\n"
  "\n"
  "-----------------------------------------------------------------------------\n"
  "\n"
  "  This mod file includes a mechanism to describe the time course of transmitter\n"
  "  on the receptors.  The time course is approximated here as a brief pulse\n"
  "  triggered when the presynaptic compartment produces an action potential.\n"
  "  The pointer \"pre\" represents the voltage of the presynaptic compartment and\n"
  "  must be connected to the appropriate variable in oc.\n"
  "\n"
  "-----------------------------------------------------------------------------\n"
  "\n"
  "  See details in:\n"
  "\n"
  "  Destexhe, A. and Sejnowski, T.J.  G-protein activation kinetics and\n"
  "  spill-over of GABA may account for differences between inhibitory responses\n"
  "  in the hippocampus and thalamus.  Proc. Natl. Acad. Sci. USA  92:\n"
  "  9515-9519, 1995.\n"
  "\n"
  "  See also: \n"
  "\n"
  "  Destexhe, A., Mainen, Z.F. and Sejnowski, T.J.  Kinetic models of \n"
  "  synaptic transmission.  In: Methods in Neuronal Modeling (2nd edition; \n"
  "  edited by Koch, C. and Segev, I.), MIT press, Cambridge, 1996.\n"
  "\n"
  "\n"
  "  Written by Alain Destexhe, Laval University, 1995\n"
  "\n"
  "-----------------------------------------------------------------------------\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	POINT_PROCESS GABAb\n"
  "	POINTER pre\n"
  "	RANGE C, R, G, g, gmax, lastrelease\n"
  "	NONSPECIFIC_CURRENT i\n"
  "	GLOBAL Cmax, Cdur, Prethresh, Deadtime\n"
  "	GLOBAL K1, K2, K3, K4, KD, Erev\n"
  "}\n"
  "UNITS {\n"
  "	(nA) = (nanoamp)\n"
  "	(mV) = (millivolt)\n"
  "	(umho) = (micromho)\n"
  "	(mM) = (milli/liter)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "\n"
  "	Cmax	= 1	(mM)		: max transmitter concentration\n"
  "	Cdur	= 1	(ms)		: transmitter duration (rising phase)\n"
  "	Prethresh = 0 			: voltage level nec for release\n"
  "	Deadtime = 1	(ms)		: mimimum time between release events\n"
  ":\n"
  ":	Parameters obtained from simplex fitting of the model directly to\n"
  ":	experimental data.  In order to activate GABAB currents sufficiently\n"
  ":	a long pulse of transmitter was used for the fit (5ms 0.5mM)\n"
  ":\n"
  "	K1	= 0.2	(/ms mM)	: forward binding rate to receptor\n"
  "	K2	= 0.0012 (/ms)		: backward (unbinding) rate of receptor\n"
  "	K3	= 0.18 (/ms)		: rate of G-protein production\n"
  "	K4	= 0.034 (/ms)		: rate of G-protein decay\n"
  "	KD	= 100			: dissociation constant of K+ channel\n"
  "	n	= 4			: nb of binding sites of G-protein on K+\n"
  "	Erev	= -90	(mV)		: reversal potential (E_K)\n"
  "	gmax		(umho)		: maximum conductance\n"
  "}\n"
  "\n"
  "\n"
  "ASSIGNED {\n"
  "	v		(mV)		: postsynaptic voltage\n"
  "	i 		(nA)		: current = g*(v - Erev)\n"
  "	g 		(umho)		: conductance\n"
  "	C		(mM)		: transmitter concentration\n"
  "	Gn\n"
  "	pre 				: pointer to presynaptic variable\n"
  "	lastrelease	(ms)		: time of last spike\n"
  "}\n"
  "\n"
  "\n"
  "STATE {\n"
  "	R				: fraction of activated receptor\n"
  "	G				: fraction of activated G-protein\n"
  "}\n"
  "\n"
  "\n"
  "INITIAL {\n"
  "	C = 0\n"
  "	lastrelease = -1000\n"
  "\n"
  "	R = 0\n"
  "	G = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE bindkin METHOD euler\n"
  "	Gn = G^n\n"
  "	g = gmax * Gn / (Gn+KD)\n"
  "	i = g*(v - Erev)\n"
  "}\n"
  "\n"
  "\n"
  "DERIVATIVE bindkin {\n"
  "\n"
  "	release()		: evaluate the variable C\n"
  "\n"
  "	R' = K1 * C * (1-R) - K2 * R\n"
  "	G' = K3 * R - K4 * G\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE release() { LOCAL q\n"
  "	:will crash if user hasn't set pre with the connect statement \n"
  "\n"
  "	q = ((t - lastrelease) - Cdur)		: time since last release ended\n"
  "\n"
  "						: ready for another release?\n"
  "	if (q > Deadtime) {\n"
  "		if (pre > Prethresh) {		: spike occured?\n"
  "			C = Cmax			: start new release\n"
  "			lastrelease = t\n"
  "		}\n"
  "						\n"
  "	} else if (q < 0) {			: still releasing?\n"
  "	\n"
  "		: do nothing\n"
  "	\n"
  "	} else if (C == Cmax) {			: in dead time after release\n"
  "		C = 0.\n"
  "	}\n"
  "\n"
  "}\n"
  ;
#endif
