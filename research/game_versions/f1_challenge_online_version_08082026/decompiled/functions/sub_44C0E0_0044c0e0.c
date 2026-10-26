char *__thiscall sub_44C0E0(_DWORD *this, int a2)
{
  _DWORD *v2; // ebp
  const char *v3; // edx
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // edx
  const char *v7; // ecx
  const CHAR *v8; // ecx
  int v9; // eax
  const CHAR *v10; // ecx
  int v11; // esi
  const char *v12; // ecx
  int v13; // eax
  int *v14; // ecx
  int v15; // edx
  char v16; // al
  char *v17; // eax
  char *v18; // eax
  unsigned int v19; // kr0C_4
  char *i; // eax
  unsigned int v21; // esi
  unsigned int v22; // kr10_4
  signed int v23; // ecx
  const CHAR *v24; // eax
  char *result; // eax
  char *v26; // [esp+Ch] [ebp-62Ch]
  char *v28[5]; // [esp+24h] [ebp-614h] BYREF
  CHAR SrcStr[256]; // [esp+38h] [ebp-600h] BYREF
  CHAR v30[256]; // [esp+138h] [ebp-500h] BYREF
  CHAR PathName[1024]; // [esp+238h] [ebp-400h] BYREF

  v2 = this;
  if ( dword_8B8F24 )
    sub_53AC70(2, 0);
  sub_44C470(v2);
  sub_44C430();
  v3 = (const char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v3 = byte_5EA438;
  v4 = &v3[strlen(v3)];
  if ( v4 > v3 )
  {
    while ( *v4 != 92 )
    {
      if ( --v4 <= v3 )
        goto LABEL_10;
    }
    ++v4;
  }
LABEL_10:
  v26 = (char *)sub_587C03(256);
  *v26 = 0;
  v5 = (char *)dword_5EC438;
  if ( !dword_5EC438 )
    v5 = byte_5EA438;
  sub_566650(v5);
  sub_5665B0(aHat);
  sub_5665B0(v4);
  v6 = v26;
  if ( !v26 )
    v6 = byte_5EA438;
  v7 = &v6[strlen(v6)];
  if ( v7 > v6 )
  {
    while ( *v7 != 46 )
    {
      if ( --v7 <= v6 )
        goto LABEL_19;
    }
    *v7 = 0;
  }
LABEL_19:
  sub_5665B0(aHat_0);
  if ( byte_7CFEE8 )
    goto LABEL_36;
  v8 = v26;
  if ( !v26 )
    v8 = byte_5EA438;
  v9 = sub_449A20(v8);
  v10 = (const CHAR *)dword_7CE5D0;
  v11 = v9;
  if ( !dword_7CE5D0 )
    v10 = byte_5EA438;
  if ( sub_449A20(v10) >= v9 )
    goto LABEL_36;
  v12 = (const char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v12 = byte_5EA438;
  strcpy(SrcStr, v12);
  sub_589901(SrcStr);
  v13 = sub_587C20(SrcStr, aScn_0);
  if ( !v13 )
    goto LABEL_36;
  v14 = &dword_5C448C;
  v15 = v13 - (_DWORD)&dword_5C448C;
  do
  {
    v16 = *(_BYTE *)v14;
    *((_BYTE *)v14 + v15) = *(_BYTE *)v14;
    v14 = (int *)((char *)v14 + 1);
  }
  while ( v16 );
  if ( sub_449A20(SrcStr) >= v11 )
    goto LABEL_36;
  sub_4CEEF0(v30, 256);
  if ( sub_449A20(v30) >= v11 )
    goto LABEL_36;
  v17 = v26;
  if ( !v26 )
    v17 = byte_5EA438;
  if ( sub_44BE70(v2, (int)v17) )
  {
    sub_44C470(v2);
LABEL_36:
    v18 = v26;
    if ( !v26 )
      v18 = byte_5EA438;
    sub_566650(v18);
    v19 = strlen(byte_5EA438) + 1;
    if ( (int)(v19 - 1) > 0 )
    {
      for ( i = &byte_5EA438[v19 - 2]; i >= byte_5EA438; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v21 = 0;
    v22 = strlen(byte_5EA438) + 1;
    v23 = v22 - 1;
    if ( (int)(v22 - 1) > 0 )
    {
      do
      {
        if ( v21 >= 0x400 )
          break;
        if ( PathName[v21 + byte_5EA438 - PathName] == 92 )
        {
          sub_587DD0(PathName, byte_5EA438, v21);
          PathName[v21] = 0;
          sub_589671(PathName);
          v23 = v22 - 1;
        }
        ++v21;
      }
      while ( (int)v21 < v23 );
      v2 = this;
    }
    sub_589671(byte_5EA438);
    sub_4492B0(v28);
    sub_44BB60(v2, a2, v28);
    sub_44B910((int)v2, (int *)v28);
    v24 = v26;
    if ( !v26 )
      v24 = byte_5EA438;
    sub_44BC50(v2, v24, (int *)v28);
    sub_449340(v28);
  }
  sub_44BA40((int)v2);
  if ( dword_8B8F24 )
    sub_53AC70(1, 0);
  result = v26;
  if ( v26 )
    return (char *)sub_587BCF(v26);
  return result;
}
