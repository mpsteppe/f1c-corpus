// f1c  0x00497ba0  size=149
_DWORD *__thiscall sub_497BA0(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  char *v3; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax

  if ( !a2 )
    return 0;
  v2 = (_DWORD *)this[65];
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    v3 = (char *)v2[1];
    if ( !v3 )
      v3 = byte_5EA438;
    if ( !sub_588410(v3, a2) )
      break;
    v2 = (_DWORD *)v2[4];
    if ( !v2 )
      return 0;
  }
  if ( !v2[3] )
  {
    v5 = (const char *)v2[1];
    if ( !v5 )
      v5 = byte_5EA438;
    v6 = sub_495890(v5);
    v2[3] = v6;
    if ( !v6 )
    {
      v7 = (const char *)v2[1];
      if ( !v7 )
        v7 = byte_5EA438;
      sub_58815F(&unk_7CDE38, "Unable to load surface \"%s\"", v7);
      sub_4986D0(&unk_7CDE38);
    }
  }
  return v2;
}
