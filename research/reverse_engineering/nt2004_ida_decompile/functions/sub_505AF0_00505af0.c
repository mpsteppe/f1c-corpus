int __fastcall sub_505AF0(int a1, int a2, const char *a3)
{
  int result; // eax
  int v4; // ecx
  char *i; // eax
  char *v6; // eax
  const char *v7; // esi
  BOOL v8; // esi
  int v9; // [esp+Ch] [ebp-404h] BYREF
  char v10[1021]; // [esp+10h] [ebp-400h] BYREF
  __int16 v11; // [esp+40Dh] [ebp-3h]
  char v12; // [esp+40Fh] [ebp-1h]

  result = 1;
  v9 = a2;
  if ( a1 && a3 )
  {
    v10[0] = byte_629120;
    memset(&v10[1], 0, 0x3FCu);
    v11 = 0;
    v12 = 0;
    strcpy(v10, a3);
    v4 = strlen(v10);
    if ( v4 > 0 )
    {
      for ( i = &v10[v4 - 1]; i >= v10; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v6 = &v10[strlen(v10) - 1];
    if ( v6 )
    {
      if ( *v6 == 92 )
        *v6 = 0;
    }
    v7 = &a3[strlen(a3)];
    if ( v7 > a3 )
    {
      while ( *v7 != 92 )
      {
        if ( --v7 <= a3 )
          goto LABEL_15;
      }
      ++v7;
    }
LABEL_15:
    sub_591F10(v10);
    v8 = sub_598D70(v9, v7) != 0;
    sub_592030(v10);
    return v8;
  }
  return result;
}
