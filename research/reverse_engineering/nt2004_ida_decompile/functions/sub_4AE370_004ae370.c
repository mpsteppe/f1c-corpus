char __thiscall sub_4AE370(_DWORD *this, char *String2, int a3, _DWORD *a4, _DWORD *a5)
{
  const char **v6; // eax

  *a4 = 0;
  *a5 = 0;
  v6 = sub_4AD420(this, String2);
  if ( !v6 )
  {
    v6 = (const char **)this[91];
    if ( !v6 )
      return 0;
  }
  if ( !a3 )
    return 0;
  sub_505C10(a4, a5, v6[6], v6[7]);
  return 1;
}
