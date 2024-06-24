typedef struct _list { int element; struct _list* next; } list;

/*@
inductive reachable{L} (list* root, list* node) {
  case root_reachable{L}:
    \forall list* root; reachable(root, root);
  case next_reachable{L}:
    \forall list* root, *node;
    \valid(root) ==> reachable(root->next, node) ==>
    reachable(root, node);
}
*/

/*@ predicate finite{L} (list* root) = reachable(root, \null); */

/*@
axiomatic Length {
  logic integer length{L} (list* l);

  axiom length_nil{L} : length(\null) == 0;

  axiom length_cons{L} :
    \forall list* l;
    finite(l) && \valid(l) ==>
      length(l) == length(l->next) + 1;
}
*/

/*@ requires   \valid(root);
    assigns    \nothing;
    terminates finite(root);
    ensures
      \forall list* node;
        \valid(node) && reachable(root, node) ==>
          \result >= node->element;
    ensures
      \exists list* node;
        \valid(node) && reachable(root, node) && \result == node->element;
*/
int max_list(list* root) {
  int max = root->element;
  while (root->next) {
    root = root-> next;
    max = max > root->element ? max : root->element;
  }
  return max;
}