char __thiscall sub_4EADE0(_DWORD *this, char *Source)
{
  char v3; // bl
  CHAR *v4; // eax
  CHAR *v5; // eax
  CHAR *v6; // eax
  int v7; // eax
  CHAR ***v8; // ecx
  CHAR **i; // eax
  CHAR *v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  CHAR ***v14; // eax
  int v15; // eax
  int *v16; // ecx
  int v17; // esi
  CHAR *v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int *v22; // eax
  int v23; // eax
  int *v24; // ecx
  int v25; // esi
  CHAR *v26; // eax
  CHAR *v27; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int *v31; // eax
  int v32; // eax
  int *v33; // ecx
  int j; // eax
  int v35; // ecx
  CHAR *v36; // eax
  CHAR *v37; // eax
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  int *v41; // eax
  int v42; // edx
  const char *v43; // eax
  CHAR *v44; // edx
  char v46; // [esp-18h] [ebp-58h]
  char v47; // [esp-8h] [ebp-48h]
  double v48; // [esp+0h] [ebp-40h]
  double v49; // [esp+0h] [ebp-40h]
  char v50; // [esp+4h] [ebp-3Ch]
  char v51; // [esp+4h] [ebp-3Ch]
  char v52; // [esp+4h] [ebp-3Ch]
  double v53; // [esp+8h] [ebp-38h]
  char v54; // [esp+10h] [ebp-30h]
  char v55; // [esp+10h] [ebp-30h]
  char ArgList[4]; // [esp+24h] [ebp-1Ch] BYREF

  v3 = 0;
  sub_57A080(ArgList);
  if ( this[24] && (unsigned __int8)sub_57A110(Source, 0, 1, 1) )
  {
    v4 = *(CHAR **)(this[24] + 4);
    if ( !v4 )
      v4 = &byte_629120;
    sub_57A400((int)ArgList, aSkinS, (char)v4);
    sub_57A400((int)ArgList, asc_5FC03C, v50);
    v5 = *(CHAR **)(this[24] + 20);
    if ( !v5 )
      v5 = &byte_629120;
    sub_57A400((int)ArgList, aModelS, (char)v5);
    v6 = *(CHAR **)(this[24] + 28);
    if ( !v6 )
      v6 = &byte_629120;
    sub_57A400((int)ArgList, aStyleS, (char)v6);
    v7 = this[24];
    v8 = *(CHAR ****)(v7 + 36);
    *(_DWORD *)(v7 + 44) = v8;
    if ( v8 )
    {
      for ( i = *v8; i; i = *v14 )
      {
        v10 = *i;
        if ( !v10 )
          v10 = &byte_629120;
        sub_57A400((int)ArgList, aMasfileS, (char)v10);
        v11 = this[24];
        v12 = *(_DWORD *)(v11 + 44);
        v13 = v11 + 36;
        if ( v12 )
          *(_DWORD *)(v13 + 8) = *(_DWORD *)(v12 + 4);
        v14 = *(CHAR ****)(v13 + 8);
        if ( !v14 )
          break;
      }
    }
    sub_57A400((int)ArgList, asc_5FB9D8, v54);
    v15 = this[24];
    v16 = *(int **)(v15 + 52);
    *(_DWORD *)(v15 + 60) = v16;
    if ( v16 )
    {
      v17 = *v16;
      if ( *v16 )
      {
        do
        {
          v18 = *(CHAR **)(v17 + 12);
          if ( !v18 )
            v18 = &byte_629120;
          sub_57A400((int)ArgList, aLayerS, (char)v18);
          sub_57A400((int)ArgList, asc_5FC484, v51);
          sub_57A400((int)ArgList, aColorDDD, BYTE2(*(_DWORD *)(v17 + 20)));
          sub_57A400((int)ArgList, asc_611020, v46);
          v19 = this[24];
          v20 = *(_DWORD *)(v19 + 60);
          v21 = v19 + 52;
          if ( v20 )
            *(_DWORD *)(v21 + 8) = *(_DWORD *)(v20 + 4);
          v22 = *(int **)(v21 + 8);
          if ( !v22 )
            break;
          v17 = *v22;
        }
        while ( *v22 );
      }
    }
    v23 = this[24];
    v24 = *(int **)(v23 + 84);
    *(_DWORD *)(v23 + 92) = v24;
    if ( v24 )
    {
      v25 = *v24;
      if ( *v24 )
      {
        do
        {
          v26 = *(CHAR **)v25;
          if ( !*(_DWORD *)v25 )
            v26 = &byte_629120;
          sub_57A400((int)ArgList, aWordS, (char)v26);
          sub_57A400((int)ArgList, asc_5FC484, v52);
          v27 = *(CHAR **)(v25 + 20);
          if ( !v27 )
            v27 = &byte_629120;
          sub_57A400((int)ArgList, aFontS, (char)v27);
          sub_57A400((int)ArgList, aColorDDD, BYTE2(*(_DWORD *)(v25 + 28)));
          v48 = *(float *)(v25 + 8);
          sub_57A400((int)ArgList, aPos2f2f, SLOBYTE(v48));
          v53 = *(float *)(v25 + 16);
          sub_57A400((int)ArgList, aOri2f, SLOBYTE(v53));
          v49 = *(float *)(v25 + 32);
          sub_57A400((int)ArgList, aSize2f2f, SLOBYTE(v49));
          sub_57A400((int)ArgList, asc_611020, v47);
          v28 = this[24];
          v29 = *(_DWORD *)(v28 + 92);
          v30 = v28 + 84;
          if ( v29 )
            *(_DWORD *)(v30 + 8) = *(_DWORD *)(v29 + 4);
          v31 = *(int **)(v30 + 8);
          if ( !v31 )
            break;
          v25 = *v31;
        }
        while ( *v31 );
      }
    }
    v32 = this[24];
    v33 = *(int **)(v32 + 68);
    *(_DWORD *)(v32 + 76) = v33;
    if ( v33 )
    {
      for ( j = *v33; j; j = *v41 )
      {
        v35 = *(_DWORD *)(j + 8);
        if ( v35 == 1 )
        {
          v36 = *(CHAR **)j;
          if ( !v36 )
            v36 = &byte_629120;
          sub_57A400((int)ArgList, aDecalS, (char)v36);
        }
        else if ( v35 == 2 )
        {
          v37 = *(CHAR **)(j + 12);
          if ( !v37 )
            v37 = &byte_629120;
          sub_57A400((int)ArgList, aStampS, (char)v37);
        }
        v38 = this[24];
        v39 = *(_DWORD *)(v38 + 76);
        v40 = v38 + 68;
        if ( v39 )
          *(_DWORD *)(v40 + 8) = *(_DWORD *)(v39 + 4);
        v41 = *(int **)(v40 + 8);
        if ( !v41 )
          break;
      }
    }
    v42 = this[24];
    v43 = *(const char **)(v42 + 112);
    if ( !v43 )
      v43 = &byte_629120;
    if ( strlen(v43) )
    {
      v44 = *(CHAR **)(v42 + 112);
      if ( !v44 )
        v44 = &byte_629120;
      sub_57A400((int)ArgList, aAlphastampS, (char)v44);
    }
    sub_57A400((int)ArgList, asc_5FBF2C, v55);
    v3 = 1;
    sub_57A360(ArgList);
  }
  sub_57A0A0(ArgList);
  return v3;
}
