int __thiscall HTMLSeasonOutput(int *this)
{
  int result; // eax
  int v3; // ebx
  int i; // esi
  char *v5; // eax

  StateCleanupNotification(this);
  UIMenuItemCreator(this, (int)&word_5BEB48, 0, 0, 0, 0);
  result = VehicleFieldAccessor(dword_7C73E0);
  v3 = result;
  for ( i = 0; i < v3; ++i )
  {
    v5 = IndexedListEntryAccessor(dword_7C73E0, i);
    result = UIMenuItemCreator(this, (int)v5, 0, 0, 0, 0);
  }
  return result;
}

