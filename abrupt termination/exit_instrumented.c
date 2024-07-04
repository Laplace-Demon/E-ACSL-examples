/* Generated by Frama-C */
typedef int int32_t;
typedef unsigned int uint32_t;
typedef unsigned long uintptr_t;
typedef unsigned long size_t;
typedef int wchar_t;
typedef int32_t pid_t;
struct __stdio_file {
   int fd ;
   int flags ;
   uint32_t bs ;
   uint32_t bm ;
   uint32_t buflen ;
   char *buf ;
   struct __stdio_file *next ;
   pid_t popen_kludge ;
   unsigned char ungetbuf ;
   char ungotten ;
};
typedef struct __stdio_file FILE;
struct __e_acsl_mpz_struct {
   int _mp_alloc ;
   int _mp_size ;
   unsigned long *_mp_d ;
};
typedef struct __e_acsl_mpz_struct __e_acsl_mpz_struct;
typedef __e_acsl_mpz_struct ( __attribute__((__FC_BUILTIN__)) __e_acsl_mpz_t)[1];
struct __e_acsl_mpq_struct {
   __e_acsl_mpz_struct _mp_num ;
   __e_acsl_mpz_struct _mp_den ;
};
typedef struct __e_acsl_mpq_struct __e_acsl_mpq_struct;
typedef __e_acsl_mpq_struct ( __attribute__((__FC_BUILTIN__)) __e_acsl_mpq_t)[1];
typedef unsigned long __e_acsl_mp_bitcnt_t;
enum __e_acsl_assert_data_type_t {
    E_ACSL_INT = 0,
    E_ACSL_REAL = 1,
    E_ACSL_PTR = 2,
    E_ACSL_ARRAY = 3,
    E_ACSL_FUN = 4,
    E_ACSL_STRUCT = 5,
    E_ACSL_UNION = 6,
    E_ACSL_OTHER = 1000
};
typedef enum __e_acsl_assert_data_type_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_type_t;
enum __e_acsl_assert_data_ikind_t {
    E_ACSL_IBOOL = 0,
    E_ACSL_ICHAR = 1,
    E_ACSL_ISCHAR = 2,
    E_ACSL_IUCHAR = 3,
    E_ACSL_IINT = 4,
    E_ACSL_IUINT = 5,
    E_ACSL_ISHORT = 6,
    E_ACSL_IUSHORT = 7,
    E_ACSL_ILONG = 8,
    E_ACSL_IULONG = 9,
    E_ACSL_ILONGLONG = 10,
    E_ACSL_IULONGLONG = 11,
    E_ACSL_IMPZ = 12
};
typedef enum __e_acsl_assert_data_ikind_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_ikind_t;
enum __e_acsl_assert_data_rkind_t {
    E_ACSL_RFLOAT = 0,
    E_ACSL_RDOUBLE = 1,
    E_ACSL_RLONGDOUBLE = 2,
    E_ACSL_RMPQ = 3
};
typedef enum __e_acsl_assert_data_rkind_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_rkind_t;
union __e_acsl_assert_data_int_value_t {
   _Bool value_bool ;
   char value_char ;
   signed char value_schar ;
   unsigned char value_uchar ;
   int value_int ;
   unsigned int value_uint ;
   short value_short ;
   unsigned short value_ushort ;
   long value_long ;
   unsigned long value_ulong ;
   long long value_llong ;
   unsigned long long value_ullong ;
   struct __e_acsl_mpz_struct *value_mpz ;
};
typedef union __e_acsl_assert_data_int_value_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_int_value_t;
union __e_acsl_assert_data_real_value_t {
   float value_float ;
   double value_double ;
   long double value_ldouble ;
   struct __e_acsl_mpq_struct *value_mpq ;
};
typedef union __e_acsl_assert_data_real_value_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_real_value_t;
struct __e_acsl_assert_data_int_content_t {
   int is_enum ;
   __e_acsl_assert_data_ikind_t kind ;
   __e_acsl_assert_data_int_value_t value ;
};
typedef struct __e_acsl_assert_data_int_content_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_int_content_t;
struct __e_acsl_assert_data_real_content_t {
   __e_acsl_assert_data_rkind_t kind ;
   __e_acsl_assert_data_real_value_t value ;
};
typedef struct __e_acsl_assert_data_real_content_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_real_content_t;
union __e_acsl_assert_data_content_t {
   __e_acsl_assert_data_int_content_t int_content ;
   __e_acsl_assert_data_real_content_t real_content ;
   uintptr_t value_ptr ;
   uintptr_t value_array ;
};
typedef union __e_acsl_assert_data_content_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_content_t;
struct __e_acsl_assert_data_value_t {
   char const *name ;
   __e_acsl_assert_data_type_t type ;
   __e_acsl_assert_data_content_t content ;
   struct __e_acsl_assert_data_value_t *next ;
};
typedef struct __e_acsl_assert_data_value_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_value_t;
struct __e_acsl_assert_data_t {
   int blocking ;
   char const *kind ;
   char const *name ;
   char const *pred_txt ;
   char const *file ;
   char const *fct ;
   int line ;
   __e_acsl_assert_data_value_t *values ;
};
typedef struct __e_acsl_assert_data_t __attribute__((__FC_BUILTIN__)) __e_acsl_assert_data_t;
struct __e_acsl_contract_t;
typedef struct __e_acsl_contract_t __attribute__((__FC_BUILTIN__)) __e_acsl_contract_t;
struct sched_param {
   int sched_priority ;
};
typedef int pthread_t;
struct __anonstruct_pthread_attr_t_6 {
   int __detachstate ;
   int __schedpolicy ;
   struct sched_param __schedparam ;
   int __inheritsched ;
   int __scope ;
   void *__stackaddr ;
   unsigned long __stacksize ;
};
typedef struct __anonstruct_pthread_attr_t_6 pthread_attr_t;
/*@ ghost extern int __e_acsl_init; */

/*@ requires \valid_read(data) ∧ \initialized(data);
    assigns \nothing;
    
    behavior blocking:
      assumes data->blocking ≢ 0;
      requires predicate ≢ 0;
    
    behavior non_blocking:
      assumes data->blocking ≡ 0;
      check requires predicate ≢ 0;
    
    complete behaviors non_blocking, blocking;
    disjoint behaviors non_blocking, blocking;
 */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_assert(int predicate,
                                                      __e_acsl_assert_data_t *data);

extern size_t __e_acsl_heap_allocation_size;

extern size_t __e_acsl_heap_allocated_blocks;

/*@ ghost extern int __fc_heap_status; */

/*@ requires \valid(data);
    requires data->values ≡ \null ∨ \valid(data->values);
    assigns data->values;
    assigns data->values \from (indirect: __fc_heap_status), value;
 */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_assert_register_int(__e_acsl_assert_data_t *data,
                                                                   char const *name,
                                                                   int is_enum,
                                                                   int value);

/*@ requires \valid(data);
    assigns \nothing; */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_assert_clean(__e_acsl_assert_data_t *data);

/*@
axiomatic dynamic_allocation {
  predicate is_allocable{L}(ℤ n) 
    reads __fc_heap_status;
  
  axiom never_allocable{L}:
    ∀ ℤ i; i < 0 ∨ i > 0xfffffffful ⇒ ¬is_allocable(i);
  
  }
 */
/*@ assigns \nothing; */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_memory_init(int *argc_ref,
                                                           char ***argv,
                                                           size_t ptr_size);

/*@ assigns \nothing; */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_memory_clean(void);

long valid_nstring(char *s, long n, int wrtbl);

long valid_nwstring(wchar_t *s, long n, int wrtbl);

__inline static long valid_string__fc_inline(char *s, int wrtbl)
{
  long tmp;
  tmp = valid_nstring(s,(long)(-1),wrtbl);
  return tmp;
}

__inline static long valid_wstring__fc_inline(wchar_t *s, int wrtbl)
{
  long tmp;
  tmp = valid_nwstring(s,(long)(-1),wrtbl);
  return tmp;
}

extern  __attribute__((__FC_BUILTIN__)) int __e_acsl_sound_verdict;

int owi_i32(void) __attribute__((__import_name__("i32_symbol"),
                                 __import_module__("symbolic")));

void exit(int);

int status = 0;
/*@ exits \old(cond) ≡ 0 ∧ status ≡ \old(val) ∧ \exit_status ≡ 0;
    ensures \old(cond) ≢ 0 ∧ status ≡ \old(status);
 */
void __gen_e_acsl_may_exit(int cond, int val);

void may_exit(int cond, int val)
{
  if (! cond) {
    status = val;
    exit(0);
  }
  return;
}

int main(void)
{
  int __retres;
  __e_acsl_memory_init((int *)0,(char ***)0,8UL);
  int cond = owi_i32();
  int val = owi_i32();
  __gen_e_acsl_may_exit(cond,val);
  __retres = 0;
  __e_acsl_memory_clean();
  return __retres;
}

/*@ exits \old(cond) ≡ 0 ∧ status ≡ \old(val) ∧ \exit_status ≡ 0;
    ensures \old(cond) ≢ 0 ∧ status ≡ \old(status);
 */
void __gen_e_acsl_may_exit(int cond, int val)
{
  int __gen_e_acsl_at_2;
  int __gen_e_acsl_at;
  __gen_e_acsl_at = status;
  __gen_e_acsl_at_2 = cond;
  may_exit(cond,val);
  {
    int __gen_e_acsl_and;
    __e_acsl_assert_data_t __gen_e_acsl_assert_data = {.values = (void *)0};
    __e_acsl_assert_register_int(& __gen_e_acsl_assert_data,"\\old(cond)",0,
                                 __gen_e_acsl_at_2);
    if (__gen_e_acsl_at_2 != 0) {
      __e_acsl_assert_register_int(& __gen_e_acsl_assert_data,"status",0,
                                   status);
      __e_acsl_assert_register_int(& __gen_e_acsl_assert_data,
                                   "\\old(status)",0,__gen_e_acsl_at);
      __gen_e_acsl_and = status == __gen_e_acsl_at;
    }
    else __gen_e_acsl_and = 0;
    __gen_e_acsl_assert_data.blocking = 1;
    __gen_e_acsl_assert_data.kind = "Postcondition";
    __gen_e_acsl_assert_data.pred_txt = "\\old(cond) \342\211\242 0 \342\210\247 status \342\211\241 \\old(status)";
    __gen_e_acsl_assert_data.file = "exit.c";
    __gen_e_acsl_assert_data.fct = "may_exit";
    __gen_e_acsl_assert_data.line = 7;
    __e_acsl_assert(__gen_e_acsl_and,& __gen_e_acsl_assert_data);
    __e_acsl_assert_clean(& __gen_e_acsl_assert_data);
    return;
  }
}


