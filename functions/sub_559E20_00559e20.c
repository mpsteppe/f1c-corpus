int __thiscall sub_559E20(int this, int a2, LPCSTR lpSrcStr, LPCSTR a4)
{
  int v5; // edx
  int v6; // ecx
  char v7; // al
  BOOL v8; // eax
  const char *v9; // ecx
  char *v10; // esi
  char *v11; // eax
  const CHAR *v12; // edx
  char v13; // cl
  char *v14; // eax
  const CHAR *v15; // edx
  char v16; // cl

  v5 = 0;
  if ( !*(_BYTE *)(this + 12) )
    goto LABEL_8;
  v6 = this + 12;
  do
  {
    v7 = *(_BYTE *)++v6;
    if ( v7 == 61 )
      ++v5;
  }
  while ( v7 );
  if ( v5 == 1 )
    v8 = StringTableLookup_9d10((_DWORD *)this, a2);
  else
LABEL_8:
    v8 = sub_559D80((_DWORD *)this, a2);
  if ( !v8 )
    return 0;
  v9 = *(const char **)(this + 780);
  v10 = (char *)(this + 396);
  strcpy(v10, v9);
  v11 = (char *)sub_5897CA(v10, asc_5D251C);
  if ( v11 )
  {
    if ( lpSrcStr )
    {
      v12 = (const CHAR *)(lpSrcStr - v11);
      do
      {
        v13 = *v11;
        v11[(_DWORD)v12] = *v11;
        ++v11;
      }
      while ( v13 );
      sub_589901(lpSrcStr);
      v14 = (char *)sub_5897CA(0, asc_5D251C);
      if ( v14 )
      {
        if ( a4 )
        {
          v15 = (const CHAR *)(a4 - v14);
          do
          {
            v16 = *v14;
            v14[(_DWORD)v15] = *v14;
            ++v14;
          }
          while ( v16 );
          sub_589901(a4);
        }
      }
    }
  }
  return 1;
}
