char __thiscall sub_4ADC00(_DWORD *this, char *String2)
{
  int v2; // esi
  const char *v3; // eax

  v2 = this[83];
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    v3 = *(const char **)v2;
    if ( !*(_DWORD *)v2 )
      v3 = &byte_629120;
    if ( !_strcmpi(v3, String2) )
      break;
    v2 = *(_DWORD *)(v2 + 40);
    if ( !v2 )
      return 0;
  }
  sub_4B0930(1);
  return 1;
}
