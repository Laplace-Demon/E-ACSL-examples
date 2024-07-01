#include <eacsl.h>
#include <owi.h>

int main(void) {
    int value = owi_i32();

    __e_acsl_contract_t *__gen_e_acsl_contract;
    int __gen_e_acsl_active_bhvrs;
    __gen_e_acsl_contract = __e_acsl_contract_init(4UL);
    __e_acsl_contract_set_behavior_assumes(__gen_e_acsl_contract,0UL,
                                           value < 0);
    __e_acsl_contract_set_behavior_assumes(__gen_e_acsl_contract,1UL,
                                           value >= 0);
    __e_acsl_contract_set_behavior_assumes(__gen_e_acsl_contract,2UL,
                                           value % 2 == 1);
    __e_acsl_contract_set_behavior_assumes(__gen_e_acsl_contract,3UL,
                                           value % 2 == 0);

    int __gen_e_acsl_active_bhvrs1, __gen_e_acsl_active_bhvrs2;

    __gen_e_acsl_active_bhvrs1 = __e_acsl_contract_partial_count_behaviors
    ((__e_acsl_contract_t const *)__gen_e_acsl_contract,2UL,1,0);
    __gen_e_acsl_active_bhvrs2 = __e_acsl_contract_partial_count_behaviors
    ((__e_acsl_contract_t const *)__gen_e_acsl_contract,2UL,2,3);

    owi_assert(__gen_e_acsl_active_bhvrs1 >= 1);
    owi_assert(__gen_e_acsl_active_bhvrs1 <= 1);
    owi_assert(__gen_e_acsl_active_bhvrs2 >= 1);
    owi_assert(__gen_e_acsl_active_bhvrs2 <= 1);

    return 0;
}
