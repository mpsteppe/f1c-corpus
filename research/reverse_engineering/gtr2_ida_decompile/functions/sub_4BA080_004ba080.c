int __thiscall sub_4BA080(int this, int *a2, _DWORD *a3, const CHAR **a4, _DWORD *a5)
{
  int v6; // ecx
  double v7; // st7
  int v8; // ecx
  int v9; // kr00_4
  int v10; // eax
  int v11; // ecx
  const CHAR ***v12; // eax
  const CHAR **v13; // eax
  const CHAR *v14; // eax
  int v15; // eax
  int v16; // ebx
  const CHAR *v17; // eax
  const char *v18; // eax
  char *v19; // eax
  const CHAR *v20; // edi
  int v21; // eax
  const char *v22; // eax
  int v24; // eax
  const CHAR **v25; // eax
  const CHAR *v26; // eax
  int v27; // eax
  const CHAR ***v28; // eax
  const CHAR **v29; // eax
  const CHAR *v30; // eax
  int v31; // [esp+28h] [ebp-64Ch]
  int v32; // [esp+2Ch] [ebp-648h]
  int v33; // [esp+30h] [ebp-644h]
  int v34; // [esp+34h] [ebp-640h]
  const CHAR *Block; // [esp+38h] [ebp-63Ch]
  const char **v36; // [esp+3Ch] [ebp-638h]
  char v37[4]; // [esp+44h] [ebp-630h] BYREF
  char v38[4]; // [esp+48h] [ebp-62Ch] BYREF
  int v39; // [esp+4Ch] [ebp-628h]
  int v40; // [esp+54h] [ebp-620h] BYREF
  char v41[4]; // [esp+58h] [ebp-61Ch] BYREF
  char v42[512]; // [esp+5Ch] [ebp-618h] BYREF
  int v43; // [esp+25Ch] [ebp-418h] BYREF
  char String1[8]; // [esp+260h] [ebp-414h] BYREF
  int v45; // [esp+268h] [ebp-40Ch]
  int v46; // [esp+26Ch] [ebp-408h]
  int v47; // [esp+270h] [ebp-404h]
  _BYTE v48[1001]; // [esp+274h] [ebp-400h] BYREF
  __int16 v49; // [esp+65Dh] [ebp-17h]
  char v50; // [esp+65Fh] [ebp-15h]

  memset(v48, 0, 0x200u);
  v6 = *(_DWORD *)(this + 48);
  v43 = 0;
  v47 = 0;
  v45 = 0;
  v46 = 0;
  String1[0] = 1;
  v7 = sub_4DE460(v6);
  v8 = *(_DWORD *)(this + 12);
  v9 = *(_DWORD *)(this + 16) - v8;
  *(float *)(this + 268) = v7 + *(float *)(this + 268);
  v10 = v8 + v9 / 2;
  v11 = *(_DWORD *)(this + 4);
  v39 = v10;
  *a2 = v11;
  *a3 = *(_DWORD *)(this + 8);
  v12 = *(const CHAR ****)(this + 288);
  *(_DWORD *)(this + 296) = v12;
  if ( v12 )
  {
    v13 = *v12;
    v36 = v13;
    if ( v13 )
    {
      v14 = *v13;
      if ( !v14 )
        v14 = WindowName;
      sub_630FE0(v48, v14, 511);
      v48[511] = 0;
      sub_612EB0(v42);
    }
  }
  else
  {
    v36 = 0;
  }
  sub_4DE540(v41, &v40);
  v15 = *(_DWORD *)(this + 272) - v40;
  *(_DWORD *)(this + 272) = v40;
  if ( *(_BYTE *)(this + 284) )
  {
    if ( v15 )
    {
      *(_DWORD *)(this + 276) += v15;
      *(_BYTE *)(this + 285) = 1;
    }
    else if ( !*(_BYTE *)(this + 285) )
    {
      *(_DWORD *)(this + 276) -= 10;
    }
  }
  v16 = sub_4CF8C0(this);
  Block = (const CHAR *)v16;
  if ( !v16 )
  {
    v17 = **(const CHAR ***)(*(_DWORD *)(this + 48) + 364);
    if ( !v17 )
      v17 = WindowName;
    v16 = (int)v17;
    Block = v17;
  }
  sub_409FB0((_DWORD *)(this + 52));
  if ( v36 )
  {
    while ( 1 )
    {
      v18 = *v36;
      if ( !*v36 )
        v18 = WindowName;
      v19 = sub_41D840(&byte_91CC38, v18);
      sub_4DF1D0(v16, v19, v38, v37);
      v20 = &Block[-(v34 / 2)];
      if ( (int)v20 < (int)*a4 )
        *a4 = v20;
      if ( *a5 < (int)&v20[v34] )
        *a5 = &v20[v34];
      if ( v32 < 600 )
        break;
LABEL_47:
      v27 = *(_DWORD *)(this + 296);
      v31 = v32 + 1;
      if ( v27 )
        *(_DWORD *)(this + 296) = *(_DWORD *)(v27 + 4);
      v28 = *(const CHAR ****)(this + 296);
      if ( !v28 )
        goto LABEL_54;
      v29 = *v28;
      if ( !v29 )
        goto LABEL_54;
      v30 = *v29;
      if ( !v30 )
        v30 = WindowName;
      sub_630FE0(&v43, v30, 511);
      v48[487] = 0;
      sub_612EB0(v37);
    }
    if ( !_stricmp(String1, "<LOGO>") )
    {
      v21 = *(_DWORD *)(this + 296);
      if ( v21 )
        *(_DWORD *)(this + 296) = *(_DWORD *)(v21 + 4);
      memset(&v48[492], 0, 509);
      v49 = 0;
      v50 = 0;
      v22 = *(const char **)dword_91CAB0;
      if ( !*(_DWORD *)dword_91CAB0 )
        v22 = WindowName;
      sub_41D810(&v48[492], 0x1FFu, "%s%s", v22, "uiassets.GTR");
      return off_16C9560(a2, a3, a4, a5);
    }
    if ( !_stricmp(String1, "<HEADER>") )
    {
      v24 = sub_4CF8E0(this);
    }
    else
    {
      if ( !_stricmp(String1, "<HEADER2>") )
      {
        v16 = sub_4CF900(this);
        if ( !v16 )
        {
          v25 = *(const CHAR ***)(*(_DWORD *)(this + 48) + 364);
LABEL_43:
          v26 = *v25;
          if ( !v26 )
            v26 = WindowName;
          v16 = (int)v26;
        }
LABEL_46:
        sub_4DF1B0(*(_DWORD *)(this + 48), v16);
        goto LABEL_47;
      }
      if ( v32 <= *a2 || v32 + v33 >= *a3 || !v16 )
      {
        v16 = sub_4CF8C0(this);
        if ( !v16 )
        {
          v25 = *(const CHAR ***)(*(_DWORD *)(this + 48) + 364);
          goto LABEL_43;
        }
        goto LABEL_46;
      }
      sub_4E0730(*(_DWORD *)(this + 48));
      v24 = sub_4CF8C0(this);
    }
    v16 = v24;
    if ( !v24 )
    {
      v25 = *(const CHAR ***)(*(_DWORD *)(this + 48) + 364);
      goto LABEL_43;
    }
    goto LABEL_46;
  }
LABEL_54:
  if ( *(float *)(this + 268) > 2.0 )
    *(_BYTE *)(this + 285) = 0;
  if ( *(float *)(this + 268) > 0.0099999998 && !*(_BYTE *)(this + 285) )
  {
    --*(_DWORD *)(this + 276);
    *(_DWORD *)(this + 268) = 0;
  }
  if ( v31 < *a2 )
    *(_DWORD *)(this + 276) = *a3;
  return 0;
}
