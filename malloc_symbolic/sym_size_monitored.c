
#include <owi.h>

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
    requires data->values ≡ \null ∨ \valid(data->values);
    assigns data->values;
    assigns data->values \from (indirect: __fc_heap_status), value;
 */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_assert_register_long(__e_acsl_assert_data_t *data,
                                                                    char const *name,
                                                                    int is_enum,
                                                                    long value);

/*@ requires \valid(data);
    requires data->values ≡ \null ∨ \valid(data->values);
    assigns data->values;
    assigns data->values \from (indirect: __fc_heap_status), value;
 */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_assert_register_ulong(
                                                                    __e_acsl_assert_data_t *data,
                                                                    char const *name,
                                                                    int is_enum,
                                                                    unsigned long value);

/*@ requires \valid(data);
    requires data->values ≡ \null ∨ \valid(data->values);
    assigns data->values;
    assigns data->values \from (indirect: __fc_heap_status), ptr;
 */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_assert_register_ptr(__e_acsl_assert_data_t *data,
                                                                   char const *name,
                                                                   void *ptr);

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

/*@ ensures \result ≡ \old(ptr);
    assigns \result;
    assigns \result \from *((char *)ptr + (0 .. size - 1)), ptr, size;
 */
 __attribute__((__FC_BUILTIN__)) void *__e_acsl_store_block(void *ptr,
                                                            size_t size);

/*@ assigns \nothing; */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_delete_block(void *ptr);

/*@ assigns \nothing; */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_initialize(void *ptr,
                                                          size_t size);

/*@ assigns \nothing; */
 __attribute__((__FC_BUILTIN__)) void __e_acsl_full_init(void *ptr);

/*@ assigns \result;
    assigns \result \from *((char *)ptr + (0 .. size - 1)), ptr, size;
    
    behavior valid:
      assumes \valid_read((char *)ptr + (0 .. size - 1));
      assumes
        size ≤ 0 ∨
        ¬\separated(
            (char *)ptr + (0 .. size - 1),
            (char *)\base_addr(base) + (0 .. \block_length(base) - 1)
            );
      ensures \result ≡ 1;
    
    behavior invalid_ptr:
      assumes ¬\valid_read((char *)ptr + (0 .. size - 1));
      ensures \result ≡ 0;
    
    behavior separated_ptr:
      assumes size > 0;
      assumes
        \separated(
          (char *)ptr + (0 .. size - 1),
          (char *)\base_addr(base) + (0 .. \block_length(base) - 1)
          );
      ensures \result ≡ 0;
    
    complete behaviors separated_ptr, invalid_ptr, valid;
    disjoint behaviors separated_ptr, invalid_ptr, valid;
 */
 __attribute__((__FC_BUILTIN__)) int __e_acsl_valid_read(void *ptr,
                                                         size_t size,
                                                         void *base,
                                                         void *addrof_base);

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

typedef unsigned long size_t;
/*@ assigns __e_acsl_heap_allocation_size, __e_acsl_heap_allocated_blocks;
    assigns __e_acsl_heap_allocation_size
      \from (indirect: size), __e_acsl_heap_allocation_size;
    assigns __e_acsl_heap_allocated_blocks
      \from (indirect: size), __e_acsl_heap_allocated_blocks;
    
    behavior allocation:
      assumes can_allocate: is_allocable(size);
      assigns __e_acsl_heap_allocation_size, __e_acsl_heap_allocated_blocks;
      assigns __e_acsl_heap_allocation_size
        \from (indirect: size), __e_acsl_heap_allocation_size;
      assigns __e_acsl_heap_allocated_blocks
        \from (indirect: size), __e_acsl_heap_allocated_blocks;
    
    behavior no_allocation:
      assumes cannot_allocate: ¬is_allocable(size);
      assigns __e_acsl_heap_allocation_size, __e_acsl_heap_allocated_blocks;
      assigns __e_acsl_heap_allocation_size
        \from (indirect: size), __e_acsl_heap_allocation_size;
      assigns __e_acsl_heap_allocated_blocks
        \from size, __e_acsl_heap_allocated_blocks;
 */
void *malloc(size_t);

int owi_i32(void) __attribute__((__import_name__("i32_symbol"),
                                 __import_module__("symbolic")));

void __e_acsl_assert(int predicate,  __e_acsl_assert_data_t *data) {
    owi_assert(predicate);
}

/*@ ensures ∀ int i; 0 ≤ i ≤ \old(size) ⇒ *(\old(buffer) + i) ≡ 1;
 */
void __gen_e_acsl_memset_one(int size, int *buffer);

void memset_one(int size, int *buffer)
{
  // __e_acsl_store_block((void *)(& buffer),8UL);
  int i = 0;
  while (i < size) {
    // __e_acsl_initialize((void *)(buffer + i),sizeof(int));
    *(buffer + i) = 1;
    i ++;
  }
  // __e_acsl_delete_block((void *)(& buffer));
  return;
}

int main(void)
{
  int __retres;
  // __e_acsl_memory_init((int *)0,(char ***)0,8UL);
  int size = owi_i32();

owi_assume(size > 10);
owi_assume(size < 20);

  int *buffer = malloc((unsigned long)size * sizeof(int));
  // __e_acsl_store_block((void *)(& buffer),8UL);
  // __e_acsl_full_init((void *)(& buffer));
  __gen_e_acsl_memset_one(size,buffer);
  __retres = 0;
  // __e_acsl_delete_block((void *)(& buffer));
  // __e_acsl_memory_clean();
  return __retres;
}

/*@ ensures ∀ int i; 0 ≤ i ≤ \old(size) ⇒ *(\old(buffer) + i) ≡ 1;
 */
void __gen_e_acsl_memset_one(int size, int *buffer)
{
  int *__gen_e_acsl_at_2;
  long __gen_e_acsl_at;
  // __e_acsl_store_block((void *)(& buffer),8UL);
  __gen_e_acsl_at = (long)size;
  __gen_e_acsl_at_2 = buffer;
  memset_one(size,buffer);
  {
    int __gen_e_acsl_forall;
    long __gen_e_acsl_i;
    __e_acsl_assert_data_t __gen_e_acsl_assert_data = {.values = (void *)0};
    __gen_e_acsl_forall = 1;
    __gen_e_acsl_i = 0L;

    while (1) {
      if (__gen_e_acsl_i <= __gen_e_acsl_at) ; else break;
      {
        int __gen_e_acsl_valid_read;
        __e_acsl_assert_data_t __gen_e_acsl_assert_data_2 =
          {.values = (void *)0};
        // __gen_e_acsl_valid_read = __e_acsl_valid_read((void *)(__gen_e_acsl_at_2 + __gen_e_acsl_i),
        //                                               sizeof(int),
        //                                               (void *)__gen_e_acsl_at_2,
        //                                               (void *)(& __gen_e_acsl_at_2));
        // __e_acsl_assert_register_ptr(& __gen_e_acsl_assert_data_2,
        //                              "__gen_e_acsl_at_2",
        //                              (void *)__gen_e_acsl_at_2);
        // __e_acsl_assert_register_long(& __gen_e_acsl_assert_data_2,
        //                               "__gen_e_acsl_i",0,__gen_e_acsl_i);
        // __e_acsl_assert_register_ulong(& __gen_e_acsl_assert_data_2,
        //                                "sizeof(int)",0,sizeof(int));
        __gen_e_acsl_assert_data_2.blocking = 1;
        __gen_e_acsl_assert_data_2.kind = "RTE";
        __gen_e_acsl_assert_data_2.pred_txt = "\\valid_read(__gen_e_acsl_at_2 + __gen_e_acsl_i)";
        __gen_e_acsl_assert_data_2.file = "sym_size.c";
        __gen_e_acsl_assert_data_2.fct = "memset_one";
        __gen_e_acsl_assert_data_2.line = 5;
        __gen_e_acsl_assert_data_2.name = "mem_access";
        // __e_acsl_assert(__gen_e_acsl_valid_read,& __gen_e_acsl_assert_data_2);
        // __e_acsl_assert_clean(& __gen_e_acsl_assert_data_2);
        if (*(__gen_e_acsl_at_2 + __gen_e_acsl_i) == 1) ;
        else {
          __gen_e_acsl_forall = 0;
          goto e_acsl_end_loop1;
        }
      }
      __gen_e_acsl_i ++;
    }
    e_acsl_end_loop1: ;
    // __e_acsl_assert_register_int(& __gen_e_acsl_assert_data,
    //                              "\342\210\200 int i; 0 \342\211\244 i \342\211\244 \\old(size) \342\207\222 *(\\old(buffer) + i) \342\211\241 1",
    //                              0,__gen_e_acsl_forall);
    __gen_e_acsl_assert_data.blocking = 1;
    __gen_e_acsl_assert_data.kind = "Postcondition";
    __gen_e_acsl_assert_data.pred_txt = "\342\210\200 int i; 0 \342\211\244 i \342\211\244 \\old(size) \342\207\222 *(\\old(buffer) + i) \342\211\241 1";
    __gen_e_acsl_assert_data.file = "sym_size.c";
    __gen_e_acsl_assert_data.fct = "memset_one";
    __gen_e_acsl_assert_data.line = 5;
    __e_acsl_assert(__gen_e_acsl_forall,& __gen_e_acsl_assert_data);
    // __e_acsl_assert_clean(& __gen_e_acsl_assert_data);
    // __e_acsl_delete_block((void *)(& buffer));
    return;
  }
}


