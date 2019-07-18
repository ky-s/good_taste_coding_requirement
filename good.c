#include <stdio.h>
#include <stdlib.h>

/*
 * entry_t
 */
typedef struct _entry_t {
  struct _entry_t  *next;
  unsigned int     num;
} entry_t;

entry_t *head = NULL;

void add_list_entry(entry_t *entry)
{
  entry_t **indirect = &head;

  entry->next = NULL;

  while ((*indirect) != NULL)
    indirect = &(*indirect)->next;

  *indirect = entry;
}

void remove_list_entry(entry_t *entry)
{
  // The *indirect* pointer points to the
  // *address* of the thing we'll update

  entry_t **indirect = &head;

  // Walk the list, looking for the thing that
  // points to the entry we want to remove

  while ((*indirect) != entry)
    indirect = &(*indirect)->next;

  // .. and just remove it

  *indirect = entry->next;
}

// print
void print_list(void)
{
  entry_t *entry = head;

  printf("----------------------------------------------\n");
  printf("head is %p\n", head);
  printf("----------------------------------------------\n");
  while (entry != NULL) {
    printf("%p : num = %d next = %p\n", entry, entry->num, entry->next);
    entry = entry->next;
  }
  printf("\n");
}

/*
 * the main
 */
int main(void) {
  entry_t e1, e2, e3;

  e1.next = e2.next = e3.next = NULL;
  e1.num = 1;
  e2.num = 2;
  e3.num = 3;

  add_list_entry(&e1);
  add_list_entry(&e2);
  add_list_entry(&e3);

  print_list();             // e1->e2->e3

  remove_list_entry(&e3);

  print_list();             // e1->e2

  add_list_entry(&e3);
  remove_list_entry(&e2);

  print_list();             // e1->e3

  add_list_entry(&e2);
  remove_list_entry(&e1);

  print_list();             // e3->e2

  remove_list_entry(&e3);

  print_list();             // e2

  remove_list_entry(&e2);   // (nil)

  print_list();

  return 0;
}
