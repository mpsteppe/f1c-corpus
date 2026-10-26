char __thiscall sub_4F0540(_DWORD *this)
{
  int v2; // eax
  bool v3; // zf
  char result; // al

  v2 = sub_40C4B0(&dword_6291CC);
  if ( !this[1] )
    return 0;
  if ( !v2 )
    return 0;
  v3 = sub_59EEA0(v2) == 0;
  result = 1;
  if ( v3 )
    return 0;
  return result;
}
