/*@ behavior left:
      assumes x ≥ y;
      ensures \result ≡ \old(x);
    
    behavior right:
      assumes x ≤ y;
      ensures \result ≡ \old(y);
    
    complete behaviors right, left;
    disjoint behaviors right, left;
 */
int __gen_e_acsl_max(int x, int y);

int max(int x, int y)
{
  int tmp;
  if (x > y) tmp = x; else tmp = y;
  return tmp;
}

int main(void)
{
  int __retres;
  int x = owi_i32();
  int y = owi_i32();
  __gen_e_acsl_max(x,y);
  __retres = 0;
  return __retres;
}

/*@ behavior left:
      assumes x ≥ y;
      ensures \result ≡ \old(x);
    
    behavior right:
      assumes x ≤ y;
      ensures \result ≡ \old(y);
    
    complete behaviors right, left;
    disjoint behaviors right, left;
 */
int __gen_e_acsl_max(int x, int y)
{
  int __gen_e_acsl_at_2;
  int __gen_e_acsl_at;
  int __retres;
  {
    __gen_e_acsl_at = x;
    __gen_e_acsl_at_2 = y;
    int bhvr_number = (int) (x >= y) + (int) (x <= y);
    if (bhvr_number != 1) {
      owi_assert(bhvr_number >= 1);
      owi_assert(bhvr_number <= 1);
    }
  }
  __retres = max(x,y);
  {
    if (x >= y) {
      owi_assert(__retres == __gen_e_acsl_at);
    }
    if (x <= y) {
      owi_assert(__retres == __gen_e_acsl_at_2);
    }
    return __retres;
  }
}
