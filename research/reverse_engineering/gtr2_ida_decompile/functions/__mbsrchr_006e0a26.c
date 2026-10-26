unsigned __int8 *__cdecl _mbsrchr(const unsigned __int8 *String, unsigned int C)
{
  unsigned __int8 *v2; // esi
  _DWORD *v3; // eax
  const unsigned __int8 *v5; // edx
  unsigned __int8 v6; // bl
  int v7; // ecx
  bool v8; // zf

  v2 = 0;
  v3 = (_DWORD *)_getptd()[24];
  if ( v3 != dword_FBB260 )
    v3 = (_DWORD *)sub_640F4B();
  if ( !v3[2] )
    return (unsigned __int8 *)strrchr((const char *)String, C);
  v5 = String;
  do
  {
    v6 = *v5;
    v7 = *v5;
    if ( (*((_BYTE *)v3 + (unsigned __int8)v7 + 29) & 4) != 0 )
    {
      v6 = *++v5;
      if ( *v5 )
      {
        if ( C == (v6 | (v7 << 8)) )
          v2 = (unsigned __int8 *)(v5 - 1);
        goto LABEL_14;
      }
      v8 = v2 == 0;
    }
    else
    {
      v8 = C == v7;
    }
    if ( v8 )
      v2 = (unsigned __int8 *)v5;
LABEL_14:
    ++v5;
  }
  while ( v6 );
  return v2;
}
