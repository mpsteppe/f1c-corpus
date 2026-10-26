_DWORD *__thiscall VTableSwitchDtor(_DWORD *this, char a2)
{
  *this = &off_5ACE5C;
  VtableDestructorNull(this);
  *this = &off_5ACE2C;
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
