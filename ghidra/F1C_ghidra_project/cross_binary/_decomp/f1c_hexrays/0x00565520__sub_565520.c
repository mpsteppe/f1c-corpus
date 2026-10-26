// f1c  0x00565520  size=200
int __thiscall sub_565520(int this, int a2, LPCSTR lpSrcStr, LPCSTR a4)
{
  int v5; // edx
  int v6; // ecx
  char v7; // al
  int v8; // eax
  char *v9; // eax
  const CHAR *v10; // edx
  char v11; // cl
  char *v12; // eax
  const CHAR *v13; // edx
  char v14; // cl

  v5 = 0;
  if ( !*(_BYTE *)(this + 408) )
    goto LABEL_8;
  v6 = this + 408;
  do
  {
    v7 = *(_BYTE *)++v6;
    if ( v7 == 61 )
      ++v5;
  }
  while ( v7 );
  if ( v5 == 1 )
    v8 = sub_5653F0(a2);
  else
LABEL_8:
    v8 = sub_565400((char *)this, a2);
  if ( !v8 )
    return 0;
  strcpy((char *)this, *(const char **)(this + 384));
  v9 = (char *)sub_5897CA(this, asc_5D251C);
  if ( v9 )
  {
    if ( lpSrcStr )
    {
      v10 = (const CHAR *)(lpSrcStr - v9);
      do
      {
        v11 = *v9;
        v9[(_DWORD)v10] = *v9;
        ++v9;
      }
      while ( v11 );
      sub_589901(lpSrcStr);
      v12 = (char *)sub_5897CA(0, asc_5D251C);
      if ( v12 )
      {
        if ( a4 )
        {
          v13 = (const CHAR *)(a4 - v12);
          do
          {
            v14 = *v12;
            v12[(_DWORD)v13] = *v12;
            ++v12;
          }
          while ( v14 );
          sub_589901(a4);
        }
      }
    }
  }
  return 1;
}
