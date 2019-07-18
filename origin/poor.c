remove_list_entry(entry)
{
  prev = NULL;
  walk = head;

  // Walk the list

  while (walk != entry) {
    prev = walk;
    walk = walk->next;
  }

  // Remove the entry by updating the
  // head of the previous entry

  if (!prev)
    head = entry->next;
  else
    prev->next = entry->next;
}
