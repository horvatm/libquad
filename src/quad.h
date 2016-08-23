#if !defined(__quad_h)
#define __quad_h

/*
  Library for INTEL C++ support of _Quad format enabled by compiler option
  
   -Qoption,cpp,--extended_float_type
  
  and constants are define with 'q' suffix, e.g.
  * 
    3.1415926q

  Author: Martin Horvat, March 2013
  
  Ref:

  * http://software.intel.com/en-us/forums/topic/304052
  * http://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format 
*/ 

#include <cmath>
#include <complex>
#include <limits>
#include <iostream>
#include <cstdio>

typedef _Quad quad;

#define QUAD_MAX 1.18973149535723176508575932662800702e4932Q
#define QUAD_MIN 3.36210314311209350626267781732175260e-4932Q
#define QUAD_EPSILON 1.92592994438723585305597794258492732e-34Q
#define QUAD_DENORM_MIN 6.475175119438025110924438958227646552e-4966Q
#define QUAD_MANT_DIG 113
#define QUAD_MIN_EXP (-16381)
#define QUAD_MAX_EXP 16384
#define QUAD_DIG 33
#define QUAD_MIN_10_EXP (-4931)
#define QUAD_MAX_10_EXP 4932

#define M_Eq            2.7182818284590452353602874713526625Q  /* e */
#define M_LOG2Eq        1.4426950408889634073599246810018921Q  /* log_2 e */
#define M_LOG10Eq       0.4342944819032518276511289189166051Q  /* log_10 e */
#define M_LN2q          0.6931471805599453094172321214581766Q  /* log_e 2 */
#define M_LN10q         2.3025850929940456840179914546843642Q  /* log_e 10 */
#define M_PIq           3.1415926535897932384626433832795029Q  /* pi */
#define M_PI_2q         1.5707963267948966192313216916397514Q  /* pi/2 */
#define M_PI_4q         0.7853981633974483096156608458198757Q  /* pi/4 */
#define M_1_PIq         0.3183098861837906715377675267450287Q  /* 1/pi */
#define M_2_PIq         0.6366197723675813430755350534900574Q  /* 2/pi */
#define M_2_SQRTPIq     1.1283791670955125738961589031215452Q  /* 2/sqrt(pi) */
#define M_SQRT2q        1.4142135623730950488016887242096981Q  /* sqrt(2) */
#define M_SQRT1_2q      0.7071067811865475244008443621048490Q  /* 1/sqrt(2) */

namespace std
{

// provide the numeric limits for the quad precision type
template <>
class numeric_limits<quad>
{
public:
    static const bool is_specialized = true;

    static quad min() { return QUAD_MIN; }
    static quad max() { return QUAD_MAX; }

    // number of bits in mantissa
    static const int digits = QUAD_MANT_DIG;
    // number of decimal digits
    static const int digits10 = QUAD_DIG;
    static const bool is_signed = true;
    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = 0;
    static quad epsilon() { return QUAD_EPSILON; }
    static quad round_error() { return 0.5Q; }

    static const int min_exponent = QUAD_MIN_EXP;
    static const int min_exponent10 = QUAD_MIN_10_EXP;
    static const int max_exponent = QUAD_MAX_EXP;
    static const int max_exponent10 = QUAD_MAX_10_EXP;

    static const bool has_infinity = true;
    static const bool has_quiet_NaN = true;
    static const bool has_signaling_NaN = true;
    static const float_denorm_style has_denorm = denorm_present;
    static const bool has_denorm_loss = false;
//    static const quad infinity() { return __builtin_huge_valq(); };
//    static const quad quiet_NaN(){ return __builtin_nan(""); }
//    static const quad signaling_NaN() { return __builtin_nans(""); }
    static quad denorm_min() { return QUAD_DENORM_MIN; }

    static const bool is_iec559 = true;
    static const bool is_bounded = true;
    static const bool is_modulo = false;

    static const bool traps = std::numeric_limits<double>::traps;
    static const bool tinyness_before = std::numeric_limits<double>::tinyness_before;
    static const float_round_style round_style = round_to_nearest;
};


extern "C" {
  void sprintfq_(char *, const int *, const char *, const quad *);
  void atoq_(const char *str, quad *);  
  
  void absq_(const quad *, quad *);
  
  void logq_(const quad *, quad *);
  void expq_(const quad *, quad *);
  
  void sqrtq_(const quad *, quad *);
  
  void sinq_(const quad *, quad *);
  void cosq_(const quad *, quad *);
  void tanq_(const quad *, quad *);
  void cotq_(const quad *, quad *);
  
  void sinhq_(const quad *, quad *);
  void coshq_(const quad *, quad *);
  void tanhq_(const quad *, quad *);
  
  void asinq_(const quad *, quad *);
  void acosq_(const quad *, quad *);
  void atanq_(const quad *, quad *);
  void atan2q_(const quad *, const quad *, quad *);
  
  void powq_(const quad *, const quad *, quad *);
  
  void powiq_(const quad *, const int *, quad *);
  
  void modq_(const quad *, const quad *, quad *);
  void moduloq_(const quad *, const quad *, quad *);
  
  void floorq_(const quad *, quad *);
  void ceilq_(const quad *, quad *);
  
  int isnanq_(const quad *val);
  int isinfq_(const quad *val); 
  
}

quad atoq(const char *str){
  quad val;
  
  atoq_(str, &val); 
  
  return val;
}  

static char sprintfq_format[255] = "(ES44.35E4)";

inline std::ostream & operator<< (std::ostream & os, const quad & val) {
  
  int len = 512;
  
  char buf[len];
      
  sprintfq_(buf, &len, sprintfq_format, &val) ;
    
  return os << buf;
}

inline std::istream& operator>>(std::istream& is, quad &val){
  
  char buf[512];

  is >> buf;

  atoq_(buf, &val);

  return is;
}

inline quad abs(const quad & val) {
  return (val < 0) ? -val : val;
}

inline quad floor(const quad & arg) { 
  quad val;
  floorq_(&arg, &val); 
  return val;
}

inline quad ceil(const quad & arg) { 
  quad val;
  ceilq_(&arg, &val); 
  return val;
}

inline quad max(const quad & a, const quad & b) { 
  return (a>b)?a:b; 
}

inline quad min(const quad & a, const quad & b){
  return (a<b)?a:b; 
}

inline quad sqrt(const quad & arg) {
  quad val;
  sqrtq_(&arg, &val); 
  return val;
}

inline quad pow(const quad & base, const quad & exp) { 
  quad val;
  powq_(&base, &exp, &val); 
  return val;
}

inline quad pow(const quad & base, const int & exp) { 
  
  quad val;
  powiq_(&base, &exp, &val);  
  return val;
}

inline quad mod(const quad & a, const quad & p) { 
  quad val;
  modq_(&a, &p, &val); 
  return val;
}

inline quad modulo(const quad & a, const quad & p) { 
  quad val;
  moduloq_(&a, &p, &val); 
  return val;
}

inline quad exp(const quad & arg) {
  quad val;
  expq_(&arg, &val);
  return val; 
}

inline quad log(const quad & arg) {
  quad val;
  logq_(&arg, &val); 
  return val;
}

inline quad sin(const quad & arg) {
  quad val;
  sinq_(&arg, &val);
  return val;
}

inline quad cos(const quad & arg) {
  quad val;
  cosq_(&arg, &val); 
  return val;
}

inline void sincos(const quad & arg, quad *s, quad *c) {
  sinq_(&arg, s);
  cosq_(&arg, c);
}

inline quad tan(const quad & arg) {
  quad val;
  tanq_(&arg, &val); 
  return val;
}

inline quad cot(const quad & arg) {
  quad val;
  cotq_(&arg, &val); 
  return val;
}


inline quad sinh(const quad & arg) {
  quad val;
  sinhq_(&arg, &val);
  return val;
}

inline quad cosh(const quad & arg) {
  quad val;
  coshq_(&arg, &val); 
  return val;
}

inline quad tanh(const quad & arg) {
  quad val;
  tanhq_(&arg, &val); 
  return val;
}

inline quad asin(const quad & arg) { 
  quad val;
  asinq_(&arg, &val); 
  return val;
}

inline quad acos(const quad & arg) { 
  quad val;
  acosq_(&arg, &val); 
  return val;
}

inline quad atan(const quad & arg) { 
  quad val;
  atanq_(&arg, &val); 
  return val;
}

inline quad atan2(const quad & y, const quad & x) { 
  quad val;
  atan2q_(&y, &x, &val);
  return val; 
}

inline bool isfinite(const quad & val) { 
  return (isnanq_(&val) == 0) && (isinfq_(&val) == 0); 
}

inline bool isnan(const quad & val) {
  return isnanq_(&val) == 1;
}

inline bool isinf(const quad & val) { 
  return isinfq_(&val) == 1; 
}

inline quad abs(const std::complex <quad> & x){
  
  quad a = std::abs(x.imag()),
       b = std::abs(x.real());
       
  if (a > b) {
    b /= a;
    return a*std::sqrt(quad(1) + b*b);
  } else {
    a /= b;
    return b*std::sqrt(quad(1) + a*a);
  }
}

} // namespace std


#endif //#if !defined(__quad_h)
