char *__stdcall sub_4BFC20(const char *a1, char *Buffer, char *a3)
{
  char *v3; // eax
  char *result; // eax
  const char *v5; // ecx
  const char *v6; // eax
  const char *v7; // ecx
  const char *v8; // eax
  char v9[509]; // [esp+4h] [ebp-200h] BYREF
  __int16 v10; // [esp+201h] [ebp-3h]
  char v11; // [esp+203h] [ebp-1h]

  if ( a1 )
  {
    v9[0] = byte_629120;
    memset(&v9[1], 0, 0x1FCu);
    v10 = 0;
    v11 = 0;
    strcpy(v9, a1);
    v3 = &v9[strlen(v9)];
    if ( v3 > v9 )
    {
      while ( *v3 != 46 )
      {
        if ( --v3 <= v9 )
          goto LABEL_7;
      }
      *v3 = 0;
    }
LABEL_7:
    if ( Buffer )
      sprintf(Buffer, "%s%s%s", v9, aPbox, aBmp_0);
    result = a3;
    if ( a3 )
      return (char *)sprintf(a3, "%s%s%s", v9, aPlpop, aBmp_0);
  }
  else
  {
    v5 = (const char *)dword_62A0B8;
    if ( !dword_62A0B8 )
      v5 = &byte_629120;
    v6 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v6 = &byte_629120;
    sprintf(Buffer, "%s%s%s%s", v6, v5, aPbox00, aBmp_0);
    v7 = (const char *)dword_62A0B8;
    if ( !dword_62A0B8 )
      v7 = &byte_629120;
    v8 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v8 = &byte_629120;
    return (char *)sprintf(a3, "%s%s%s%s", v8, v7, aPlpop00, aBmp_0);
  }
  return result;
}
