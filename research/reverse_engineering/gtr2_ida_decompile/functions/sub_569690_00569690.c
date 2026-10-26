int __fastcall sub_569690(const char *ArgList, int a2, int a3, char *a4)
{
  const char *v6; // eax
  const char *v7; // esi
  char *v8; // edi
  FILE *v11; // ebx
  int v12; // edi
  char *v13; // eax
  int v14; // eax
  const CHAR *v15; // eax
  const CHAR *v16; // eax
  const char *v17; // eax
  FILE *v18; // esi
  const char *v19; // eax
  char *v20; // eax
  char *v21; // esi
  int v22; // ebp
  int i; // edi
  const char *v24; // esi
  char *v25; // edi
  const char *v26; // ecx
  const char *v27; // eax
  const char *v28; // ecx
  int v29; // kr0C_4
  char *j; // eax
  int v31; // eax
  bool v32; // zf
  signed int v33; // ebp
  signed int k; // edi
  int v35; // [esp+1Ch] [ebp-A1Ch]
  float v36; // [esp+20h] [ebp-A18h]
  char *Block; // [esp+24h] [ebp-A14h]
  char *FileName; // [esp+28h] [ebp-A10h]
  int v39; // [esp+30h] [ebp-A08h]
  BOOL v40; // [esp+34h] [ebp-A04h] BYREF
  _BYTE v41[88]; // [esp+38h] [ebp-A00h] BYREF
  int v42; // [esp+90h] [ebp-9A8h] BYREF
  char Buffer[124]; // [esp+94h] [ebp-9A4h] BYREF
  char v44[256]; // [esp+110h] [ebp-928h] BYREF
  char v45[4]; // [esp+210h] [ebp-828h] BYREF
  char v46[512]; // [esp+214h] [ebp-824h] BYREF
  int v47; // [esp+414h] [ebp-624h]
  char v48; // [esp+418h] [ebp-620h]
  int v49; // [esp+420h] [ebp-618h]
  char v50[4]; // [esp+424h] [ebp-614h]
  char Str[4]; // [esp+428h] [ebp-610h] BYREF
  char v52[512]; // [esp+42Ch] [ebp-60Ch] BYREF
  char v53[508]; // [esp+62Ch] [ebp-40Ch] BYREF
  char v54[524]; // [esp+828h] [ebp-210h] BYREF
  int v55; // [esp+A34h] [ebp-4h]
  void *retaddr; // [esp+A38h] [ebp+0h]

  sub_613B30(v41);
  memset(v52, 0, sizeof(v52));
  v47 = 0;
  *(_DWORD *)Str = 0;
  v49 = 0;
  *(_DWORD *)v50 = 0;
  v48 = 1;
  v6 = *(const char **)(dword_BE1BD8 + 2824 * a2 + 32);
  v55 = 0;
  v7 = v6;
  if ( !v6 )
    v7 = WindowName;
  strcpy(v53, v7);
  if ( !byte_B71194 && strlen(v7) > 4 )
  {
    v52[strlen(v7) + 508] = 0;
    v8 = &v52[511];
    while ( *++v8 )
      ;
    strcpy(v8, "_2DW.CAS");
  }
  if ( !(unsigned __int8)sub_614460(v53, 1) && !(unsigned __int8)sub_614460(v7, 1) )
  {
    if ( sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehgfx.cpp", 1332) )
      sub_561210((int)byte_FAE910, "Could not open %s", v7);
    v55 = -1;
    return sub_614140(v41);
  }
  v11 = fopen(ArgList, "w");
  if ( !v11 )
  {
    if ( dword_B640C0 != 5 && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehgfx.cpp", 1343) )
      sub_561210((int)byte_FAE910, "Could not open %s", ArgList);
    sub_613C30(v41);
LABEL_112:
    v55 = -1;
    return sub_614140(v41);
  }
  if ( a4 )
  {
    v12 = sub_62AD30(a4);
    if ( v12 )
    {
      while ( sub_62AF80(512) )
      {
        if ( sub_612EB0(v46) != 3 )
          fprintf(v11, "%s\n", v52);
      }
      sub_62AAB0(v12);
    }
    v13 = &a4[strlen(a4)];
    if ( v13 > a4 )
    {
      while ( *v13 != 92 )
      {
        if ( --v13 <= a4 )
          goto LABEL_30;
      }
      ++v13;
    }
LABEL_30:
    sprintf(Buffer, "%s", v13);
    _stricmp(Buffer, "EXPO.SET");
    v40 = 0;
  }
  else
  {
    v14 = dword_923E84[5654 * a3];
    v40 = !v14 || v14 >= 3;
  }
  v36 = sub_5529A0(dword_FADD40);
  FileName = (char *)operator new(0x100u);
  *FileName = 0;
  v54[520] = 1;
  if ( byte_FADD28 )
    v36 = sub_54B400(dword_BE27B0);
  if ( v36 != -1.0 )
  {
    sub_53A560(v36, &v42, 64);
    v15 = *(const CHAR **)dword_91CA70;
    if ( !*(_DWORD *)dword_91CA70 )
      v15 = WindowName;
    sub_615860(v15);
    v16 = (const CHAR *)dword_91CAE8;
    if ( !dword_91CAE8 )
      v16 = WindowName;
    sub_615A50(v16);
    sub_615A50("OBJ");
    sub_615A50(&v42);
    sub_615A50(&dword_6F52E8);
    v17 = FileName;
    if ( !FileName )
      v17 = WindowName;
    v18 = fopen(v17, "r");
    if ( v18 )
    {
      fprintf(v11, "MASFILE=");
      v19 = FileName;
      if ( !FileName )
        v19 = WindowName;
      fprintf(v11, v19, 0);
      fprintf(v11, word_6F2E64);
      fclose(v18);
    }
  }
  if ( !sub_613DE0(Str, 512) )
  {
LABEL_110:
    fprintf(v11, word_6F2E64);
    fclose(v11);
    sub_613C30(&v40);
    if ( FileName )
      j_j__free(FileName);
    goto LABEL_112;
  }
  while ( sub_612EB0(v45) == 3 )
  {
LABEL_109:
    if ( !sub_613DE0(Str, 512) )
      goto LABEL_110;
  }
  v20 = strstr(Str, "<");
  v21 = v20;
  if ( !v20 )
  {
    fprintf(v11, "%s\n", Str);
    goto LABEL_109;
  }
  v22 = v20 - Str;
  for ( i = 0; i < v22; ++i )
    fputc(Str[i], v11);
  v24 = v21 + 1;
  v25 = strstr(Str, ">");
  if ( !v25 && dword_B640C0 != 5 && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehgfx.cpp", 1472) )
    sub_561210((int)byte_FAE910, "< does not have matching > in %s", &v52[508]);
  *v25 = 0;
  if ( !_stricmp(v24, "ID") )
  {
    fprintf(v11, "%03d", retaddr);
    return off_16C952C(a3, a4);
  }
  if ( !_stricmp(v24, "VEHDIR") )
  {
    v26 = (const char *)dword_91CAE8;
    if ( !dword_91CAE8 )
      v26 = WindowName;
    v27 = *(const char **)dword_91CA70;
    if ( !*(_DWORD *)dword_91CA70 )
      v27 = WindowName;
    sprintf(v54, "%s%s", v27, v26);
    fprintf(v11, "%s", v54);
    return off_16C952C(a3, a4);
  }
  if ( !_stricmp(v24, "TEAMDIR") )
  {
    v28 = *(const char **)Block;
    if ( !*(_DWORD *)Block )
      v28 = WindowName;
    strcpy(v44, v28);
    v29 = strlen(v44);
    if ( v29 > 0 )
    {
      for ( j = &Buffer[v29 + 123]; j >= v44; *j-- = 0 )
      {
        if ( *j == 92 )
          break;
      }
    }
    fprintf(v11, "%s", v44);
    return off_16C952C(a3, a4);
  }
  if ( !_stricmp(v24, "NOTSPIN") )
  {
    if ( v35 && v35 != 5 )
      return off_16C952C(a3, a4);
LABEL_96:
    fprintf(v11, "//");
    return off_16C952C(a3, a4);
  }
  if ( !_stricmp(v24, "SPIN") )
  {
    v31 = v35;
    goto LABEL_79;
  }
  if ( !_stricmp(v24, "LOW") )
  {
    if ( v35 == 1 )
      return off_16C952C(a3, a4);
    goto LABEL_96;
  }
  if ( !_stricmp(v24, "MED") )
  {
    if ( v35 == 2 )
      return off_16C952C(a3, a4);
    goto LABEL_96;
  }
  if ( !_stricmp(v24, "HIGH") )
  {
    if ( v35 == 3 )
      return off_16C952C(a3, a4);
    goto LABEL_96;
  }
  if ( !_stricmp(v24, "MAX") )
  {
    if ( v35 == 4 )
      return off_16C952C(a3, a4);
    goto LABEL_96;
  }
  if ( !_stricmp(v24, "EXPO") )
  {
    if ( v35 == 5 )
      return off_16C952C(a3, a4);
    goto LABEL_96;
  }
  if ( !_stricmp(v24, "DASHLOW") )
  {
    v31 = v39;
LABEL_79:
    v32 = v31 == 0;
LABEL_80:
    if ( v32 )
      return off_16C952C(a3, a4);
    goto LABEL_96;
  }
  if ( !_stricmp(v24, "DASHHIGH") )
  {
    v32 = v39 == 1;
    goto LABEL_80;
  }
  if ( !_stricmp(v24, "RIMTYPE") )
  {
    fprintf(v11, Block + 384);
  }
  else if ( !_stricmp(v24, "TYRETYPE") )
  {
    fprintf(v11, Block + 448);
  }
  else
  {
    v33 = strlen(v24);
    for ( k = 0; k < v33; ++k )
      fputc(Block[v24[k] - 9], v11);
  }
  return off_16C952C(a3, a4);
}
