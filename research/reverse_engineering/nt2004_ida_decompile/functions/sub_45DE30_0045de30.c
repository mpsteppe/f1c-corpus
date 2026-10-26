int __thiscall sub_45DE30(_DWORD *this, char a2)
{
  int i; // esi
  int result; // eax

  *this = 0;
  if ( a2 )
  {
    this[1] = 0;
    this[2] = 0;
    this[3] = 0;
    this[4] = 0;
  }
  for ( i = 0; i < 49; ++i )
    result = sub_45DDD0(this, i);
  return result;
}
