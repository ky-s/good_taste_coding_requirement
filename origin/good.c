remove_list_entry(entry)
{
  // The *indirect* pointer points to the
  // *address* of the thing we'll update

  indirect = &head;

  // Walk the list, looking for the thing that
  // points to the entry we want to remove

  while ((*indirect) != entry)
    indirect = &(*indirect)->next;

  // .. and just remove it

  *indirect = entry->next;
}
