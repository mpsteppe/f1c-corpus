_DWORD *__thiscall sub_4C9060(_DWORD *this, char a2)
{
  *this = &off_5ACE3C;
  TripleVTableDestructorRelease(this);
  *this = &off_5ACE2C;
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
