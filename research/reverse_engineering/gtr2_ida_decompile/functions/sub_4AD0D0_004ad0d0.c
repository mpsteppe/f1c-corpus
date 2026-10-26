int __thiscall sub_4AD0D0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  const CHAR *v4; // eax
  const char *v5; // eax
  const char *v6; // esi
  const char *v7; // eax
  const CHAR *v8; // eax
  int v9; // esi
  char *v10; // eax
  const CHAR *v11; // eax
  double v12; // st7
  unsigned __int64 v13; // rax
  int v14; // ecx
  const CHAR *v15; // eax
  const CHAR *v16; // eax
  int v18; // [esp+18h] [ebp-228h] BYREF
  int v19; // [esp+1Ch] [ebp-224h]
  _DWORD *v20; // [esp+20h] [ebp-220h]
  int v21; // [esp+24h] [ebp-21Ch]
  int v22; // [esp+28h] [ebp-218h]
  char v23[2]; // [esp+2Ch] [ebp-214h] BYREF
  int v24; // [esp+2Eh] [ebp-212h]
  int v25; // [esp+32h] [ebp-20Eh]
  int v26; // [esp+36h] [ebp-20Ah]
  int v27; // [esp+3Ah] [ebp-206h]
  int v28; // [esp+3Eh] [ebp-202h]
  int v29; // [esp+42h] [ebp-1FEh]
  int v30; // [esp+46h] [ebp-1FAh]
  __int16 v31; // [esp+4Ah] [ebp-1F6h]
  char v32[3]; // [esp+50h] [ebp-1F0h] BYREF
  int v33; // [esp+53h] [ebp-1EDh]
  int v34; // [esp+57h] [ebp-1E9h]
  int v35; // [esp+5Bh] [ebp-1E5h]
  int v36; // [esp+5Fh] [ebp-1E1h]
  int v37; // [esp+63h] [ebp-1DDh]
  int v38; // [esp+67h] [ebp-1D9h]
  int v39; // [esp+6Bh] [ebp-1D5h]
  char v40; // [esp+6Fh] [ebp-1D1h]
  char v41[3]; // [esp+70h] [ebp-1D0h] BYREF
  int v42; // [esp+73h] [ebp-1CDh]
  int v43; // [esp+77h] [ebp-1C9h]
  int v44; // [esp+7Bh] [ebp-1C5h]
  int v45; // [esp+7Fh] [ebp-1C1h]
  int v46; // [esp+83h] [ebp-1BDh]
  int v47; // [esp+87h] [ebp-1B9h]
  int v48; // [esp+8Bh] [ebp-1B5h]
  char v49; // [esp+8Fh] [ebp-1B1h]
  char Buffer[2]; // [esp+90h] [ebp-1B0h] BYREF
  int v51; // [esp+92h] [ebp-1AEh]
  int v52; // [esp+96h] [ebp-1AAh]
  int v53; // [esp+9Ah] [ebp-1A6h]
  int v54; // [esp+9Eh] [ebp-1A2h]
  int v55; // [esp+A2h] [ebp-19Eh]
  int v56; // [esp+A6h] [ebp-19Ah]
  int v57; // [esp+AAh] [ebp-196h] BYREF
  __int16 v58; // [esp+AEh] [ebp-192h]
  _BYTE v59[62]; // [esp+B0h] [ebp-190h] BYREF
  __int16 v60; // [esp+EEh] [ebp-152h]
  char String[2]; // [esp+F0h] [ebp-150h] BYREF
  _BYTE v62[60]; // [esp+F2h] [ebp-14Eh] BYREF
  __int16 v63; // [esp+12Eh] [ebp-112h]
  int v64; // [esp+23Ch] [ebp-4h]

  v20 = this;
  v18 = 0;
  strcpy(v59, "-");
  memset(&v59[2], 0, 0x3Cu);
  v60 = 0;
  v51 = 0;
  v24 = 0;
  v52 = 0;
  v25 = 0;
  v53 = 0;
  v26 = 0;
  v54 = 0;
  v27 = 0;
  v55 = 0;
  v28 = 0;
  v56 = 0;
  v57 = 0;
  v29 = 0;
  v30 = 0;
  v58 = 0;
  v31 = 0;
  strcpy(String, "-");
  memset(v62, 0, sizeof(v62));
  v63 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  strcpy(v23, "-");
  strcpy(Buffer, "-");
  strcpy(v32, "/0");
  v39 = 0;
  v40 = 0;
  v2 = sub_4CF900(this);
  sub_630FE0(v32, v2, 31);
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v3 = this[61];
  v47 = 0;
  v48 = 0;
  v40 = 0;
  strcpy(v41, "/0");
  v49 = 0;
  v4 = *(const CHAR **)(v3 + 72);
  if ( !v4 )
    v4 = WindowName;
  sub_630FE0(v41, v4, 31);
  v49 = 0;
  v21 = 0;
  v22 = -1;
  v5 = (const char *)this[152];
  v64 = 0;
  v19 = 3;
  v6 = v5;
  if ( !v5 )
    v6 = WindowName;
  v7 = dword_B6F740;
  if ( !dword_B6F740 )
    v7 = WindowName;
  if ( strcmp(v7, v6) )
  {
    v8 = dword_B6F740;
    if ( !dword_B6F740 )
      v8 = WindowName;
    sub_615860(v8);
  }
  dword_B76314 = dword_B7630C;
  if ( dword_B7630C )
    v9 = *(_DWORD *)dword_B7630C;
  else
    v9 = 0;
  if ( v9 )
  {
    v10 = *(char **)v9;
    if ( !*(_DWORD *)v9 )
      v10 = (char *)WindowName;
    if ( sub_53A2B0((int)v59, 64, "VenueName", v10) )
    {
      v11 = *(const CHAR **)v9;
      if ( !*(_DWORD *)v9 )
        v11 = WindowName;
      sub_630FE0(v59, v11, 63);
      HIBYTE(v60) = 0;
    }
    sprintf(Buffer, "%d", *(_DWORD *)(v9 + 28));
    v12 = *(float *)(v9 + 32);
    v13 = (unsigned __int64)v12;
    v14 = (int)(unsigned __int64)v12 / 60;
    if ( v14 > 0 )
    {
      v19 = 60 * v14;
      v12 = v12 - (double)(60 * v14);
    }
    if ( *(float *)(v9 + 32) <= 0.0 )
      sprintf(v23, "-:--.---");
    else
      sprintf(v23, "%i:%06.3f", (int)v13 / 60, v12);
    v15 = *(const CHAR **)(v9 + 16);
    if ( !v15 )
      v15 = WindowName;
    sub_630FE0(String, v15, 63);
    HIBYTE(v63) = 0;
    _strupr(String);
    v16 = *(const CHAR **)v9;
    if ( !*(_DWORD *)v9 )
      v16 = WindowName;
    sub_615860(v16);
    v19 = *(_DWORD *)(v9 + 24);
    if ( dword_B76314 )
      dword_B76314 = *(_DWORD *)(dword_B76314 + 4);
  }
  sub_4CE140(v20, &v18);
  sub_4CFC00(v18);
  sub_41D840(&byte_91CC38, (const char *)&v57 + 2);
  return off_16C98BC();
}
