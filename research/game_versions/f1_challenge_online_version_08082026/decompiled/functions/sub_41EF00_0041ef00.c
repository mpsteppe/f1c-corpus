char __thiscall sub_41EF00(char *this)
{
  int v2; // eax
  int v3; // eax
  char *i; // ecx

  if ( !this )
    return 0;
  v2 = sub_4C2850(&unk_7D2DB0);
  v3 = sub_4C11D0(v2);
  if ( v3 < 0 )
    return 0;
  for ( i = &this[4 * v3 + 216]; *(_DWORD *)i != 10; i -= 4 )
  {
    if ( --v3 < 0 )
      return 0;
  }
  return 1;
}
