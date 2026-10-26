_DWORD *__thiscall ConditionalFreeByFlag(_DWORD *this, char a2)
{
  VtableEntryNotifyCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
