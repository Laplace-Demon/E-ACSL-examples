#include <stdlib.h>

typedef struct _list { int element; struct _list* next; } list;

list* GList;

/*@
inductive sorted_decreasing{L} (list* root) {
  case sorted_nil{L}: sorted_decreasing(\null);
  case sorted_singleton{L}:
    \forall list* root;
      \valid(root) && root->next == \null ==>
        sorted_decreasing(root);
  case sorted_next{L}:
    \forall list* root;
      \valid(root) && \valid(root->next) &&
        sorted_decreasing(root->next) && root->element >= root->next->element ==>
          sorted_decreasing(root);
}
*/

/* global invariant glist_sorted : sorted_decreasing(GList); */

/*@
axiomatic Count{
  logic integer count{L} (int x, list* l);

  axiom count_nil{L} : \forall int x; count(x, \null) == 0;

  axiom count_cons_head{L} :
    \forall int x, list* l;
      \valid(l) && l->element == x ==>
        count(x, l) == count(x, l->next) + 1;
  
  axiom count_cons_tail{L} :
    \forall int x, list* l;
      \valid(l) && l->element != x ==>
        count(x, l) == count(x, l->next);
}
*/

list* new_list(int element, list* next) {
  list* ptr = (list *)malloc(sizeof(list));
  if (ptr == NULL) exit(1);
  ptr->element = element;
  ptr->next = next;
  return ptr;
}

/*@ ensures \forall int y; y != x ==>
               count(y, GList) == count(y, \old(GList));
    ensures count(x, GList) == count(x, \old(GList)) + 1;
*/
void insert_GList(int x) {
  if (GList == NULL || GList->element < x) GList = new_list(x, GList);
  else {
    list* ptr = GList;
    while (ptr->next != NULL && ptr->next->element > x) ptr = ptr->next;
    ptr->next = new_list(x, ptr->next);
  }
}

