int __thiscall DualCallWrapper_af00(_DWORD *this)
{
  SessionEntryListCleanup(this);
  UIListSelectionHandler(this, 0, 1);
  return 0;
}

