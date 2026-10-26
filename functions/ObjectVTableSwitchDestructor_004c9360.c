_DWORD *__thiscall ObjectVTableSwitchDestructor(_DWORD *this, char a2)
{
  *this = &off_5ACE4C;
  sub_4C94D0(this);
  *this = &off_5ACE2C;
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
