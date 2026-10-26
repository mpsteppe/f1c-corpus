int __stdcall sub_4C5BB0(int a1, char a2, int a3)
{
  char *v3; // eax
  char *v4; // edi
  char v5; // cl
  int v7; // [esp+4h] [ebp-204h] BYREF
  char v8[509]; // [esp+8h] [ebp-200h] BYREF
  __int16 v9; // [esp+205h] [ebp-3h]
  char v10; // [esp+207h] [ebp-1h]

  v8[0] = byte_5EA438[0];
  memset(&v8[1], 0, 0x1FCu);
  v9 = 0;
  v10 = 0;
  sub_587DD0(v8, a1, 511);
  v10 = 0;
  v3 = &v8[strlen(v8)];
  if ( v3 > v8 )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= v8 )
        goto LABEL_6;
    }
    *v3 = 0;
  }
LABEL_6:
  v4 = &v8[strlen(v8) + 1];
  v5 = byte_5C5D28;
  *(_DWORD *)--v4 = dword_5C5D24;
  v4[4] = v5;
  if ( (unsigned __int8)UtilityFunction_8a60(a3, &v7) == 1 )
    return v7;
  else
    return -1;
}
