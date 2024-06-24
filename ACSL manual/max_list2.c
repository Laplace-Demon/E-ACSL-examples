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

/*@ type invariant finite_list(list* root) = finite(root); */

/*@ requires   \valid(root);
    assigns    \nothing;
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