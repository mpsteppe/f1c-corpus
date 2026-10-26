int __thiscall sub_4A3080(void *this)
{
  int v2; // ebp
  int v3; // edi
  _DWORD *v4; // eax
  char *v5; // eax
  const char *v6; // eax
  _DWORD *v7; // eax
  const char *v8; // eax
  _DWORD *v9; // eax
  const char *v10; // eax
  _DWORD *v11; // eax
  const char *v12; // eax
  _DWORD *v13; // edi
  char *v14; // eax
  int v15; // eax
  int v16; // ebp
  char *v17; // edi
  const char *v18; // eax
  size_t v19; // edi
  const char *v20; // edi
  int v21; // ebp
  char *v22; // eax
  int v23; // eax
  int v24; // eax
  const char *v25; // eax
  int v26; // eax
  int result; // eax
  const char *v28; // eax
  float *v29; // edi
  const char *v30; // eax
  float v31; // edx
  const CHAR *v32; // edi
  int v33; // ecx
  const char *v34; // eax
  char *v35; // eax
  const char *v36; // eax
  size_t v37; // edi
  const char *v38; // eax
  char *v39; // eax
  char *v40; // ecx
  unsigned int v41; // kr00_4
  unsigned int v42; // ecx
  int v43; // [esp-10h] [ebp-3B4h]
  int v44; // [esp+4h] [ebp-3A0h] BYREF
  double v45; // [esp+8h] [ebp-39Ch]
  int v46; // [esp+10h] [ebp-394h]
  float v47; // [esp+20h] [ebp-384h]
  int v48; // [esp+24h] [ebp-380h]
  char v49; // [esp+28h] [ebp-37Ch] BYREF
  __int16 v50; // [esp+29h] [ebp-37Bh]
  char v51; // [esp+2Bh] [ebp-379h]
  int v52; // [esp+2Ch] [ebp-378h] BYREF
  int v53; // [esp+30h] [ebp-374h] BYREF
  int v54; // [esp+34h] [ebp-370h] BYREF
  int v55; // [esp+38h] [ebp-36Ch] BYREF
  int v56; // [esp+3Ch] [ebp-368h]
  char v57[2]; // [esp+40h] [ebp-364h] BYREF
  int v58; // [esp+42h] [ebp-362h]
  int v59; // [esp+46h] [ebp-35Eh]
  int v60; // [esp+4Ah] [ebp-35Ah]
  int v61; // [esp+4Eh] [ebp-356h]
  int v62; // [esp+52h] [ebp-352h]
  int v63; // [esp+56h] [ebp-34Eh]
  int v64; // [esp+5Ah] [ebp-34Ah]
  __int16 v65; // [esp+5Eh] [ebp-346h]
  int v66; // [esp+60h] [ebp-344h]
  int v67; // [esp+64h] [ebp-340h]
  char v68[64]; // [esp+68h] [ebp-33Ch] BYREF
  _WORD v69[31]; // [esp+A8h] [ebp-2FCh] BYREF
  __int16 v70; // [esp+E6h] [ebp-2BEh]
  char Buffer[256]; // [esp+E8h] [ebp-2BCh] BYREF
  char Destination[64]; // [esp+1E8h] [ebp-1BCh] BYREF
  char String1[4]; // [esp+228h] [ebp-17Ch] BYREF
  _BYTE v74[124]; // [esp+22Ch] [ebp-178h] BYREF
  char v75[48]; // [esp+2A8h] [ebp-FCh] BYREF
  char v76; // [esp+2D8h] [ebp-CCh] BYREF
  int v77; // [esp+3A0h] [ebp-4h]

  v58 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  v50 = 0;
  v63 = 0;
  v51 = 0;
  v64 = 0;
  v69[0] = 45;
  strcpy(v57, "-");
  v65 = 0;
  memset(&v69[1], 0, 0x3Cu);
  v2 = 0;
  v49 = 0;
  v70 = 0;
  v47 = -1.0;
  v56 = 0;
  v66 = 0;
  v67 = -1;
  v77 = 0;
  v3 = sub_53A250(0);
  sub_4D0AC0(v46);
  sub_630FE0(v74, 396 * dword_BE1CD4 + dword_BE1CD8 + 4, 127);
  v75[3] = 0;
  sub_4CE140(this, &v52);
  if ( v3 )
  {
    v4 = (_DWORD *)sub_616630("Location");
    v5 = sub_48D380(v4);
    HIDWORD(v45) = sub_41D840(&byte_91CC38, v5);
    v6 = (const char *)sub_4CFC00(1);
    sprintf(Buffer, "%s %s", v6, (const char *)HIDWORD(v45));
    sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    v7 = (_DWORD *)sub_616630("First Grand Prix");
    if ( v7 )
    {
      HIDWORD(v45) = sub_48D380(v7);
      v8 = (const char *)sub_4CFC00(2);
      sprintf(Buffer, "%s %s", v8, (const char *)HIDWORD(v45));
      sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    }
    v9 = (_DWORD *)sub_616630("Length");
    if ( v9 )
    {
      HIDWORD(v45) = sub_48D380(v9);
      v10 = (const char *)sub_4CFC00(3);
      sprintf(Buffer, "%s %s", v10, (const char *)HIDWORD(v45));
      sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    }
    if ( *(_DWORD *)dword_B72314 != 4 )
    {
      v11 = (_DWORD *)sub_616630("RaceLaps");
      if ( v11 )
      {
        HIDWORD(v45) = sub_48D380(v11);
        v12 = (const char *)sub_4CFC00(5);
        sprintf(Buffer, "%s %s", v12, (const char *)HIDWORD(v45));
        sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      }
    }
    v13 = (_DWORD *)sub_616630("Track Record");
    if ( v13 )
    {
      sub_4D93B0(&v49, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      v55 = 2604;
      v14 = sub_48D380(v13);
      sub_630FE0(v68, v14, 63);
      v68[63] = 0;
      v15 = sub_6331DF(v68, &v55);
      v16 = 0;
      if ( v15 )
      {
        v17 = v75;
        do
        {
          sub_630FE0(v17, v15, 47);
          v17[47] = 0;
          ++v16;
          v17 += 48;
          v15 = sub_6331DF(0, &v55);
        }
        while ( v15 );
      }
      v18 = (const char *)sub_4CFC00(4);
      sprintf(Buffer, "%s %s", v18, v75);
      sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      if ( v16 > 4 )
        v16 = 4;
      v48 = strlen((const char *)sub_4CFC00(4));
      v19 = (unsigned __int64)((double)v48 * 1.75);
      _strnset(Destination, 32, v19);
      Destination[v19] = 0;
      if ( v16 > 1 )
      {
        v20 = &v76;
        v21 = v16 - 1;
        do
        {
          sprintf(Buffer, "%s%s", Destination, v20);
          sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
          v20 += 48;
          --v21;
        }
        while ( v21 );
      }
      v2 = v56;
    }
    sub_4D93B0(&v49, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  }
  v54 = 0;
  v53 = 0;
  *(float *)&v52 = 0.0;
  if ( (unsigned __int8)sub_53A7E0((int)&v54, (int)&v53, (int)&v52, 0) )
  {
    v22 = sub_41D840(&byte_91CC38, "Championship status needed to unlock:");
    sub_41D810(v68, 0x3Fu, "%s", v22);
    v23 = sub_4CF900(this);
    sub_4D93B0(v68, 0, v23, 0, 0, 0, -1, -1, -1, -1);
    if ( v53 > 0 )
    {
      HIDWORD(v45) = v53;
      LODWORD(v45) = sub_4CFC00(9);
      v44 = (int)v40;
      v41 = __readeflags();
      v42 = dword_16C6ED4 ^ 0xB38025FF;
      __writeeflags(v41);
      _InterlockedExchange(&v44, v42);
      sub_41D810(v68, 0x3Fu, (char *)v44);
      v45 = NAN;
      v44 = -1;
      v24 = sub_4CF900(this);
      sub_4D93B0(v68, 0, v24, 0, 0, 0, -1, v44, LODWORD(v45), HIDWORD(v45));
    }
    if ( *(float *)&v52 > 0.0 )
    {
      v45 = *(float *)&v52;
      v25 = (const char *)sub_4CFC00(10);
      sub_41D810(v68, 0x3Fu, "   %s - %.0f ", v25, v45);
      v45 = NAN;
      v44 = -1;
      v26 = sub_4CF900(this);
      sub_4D93B0(v68, 0, v26, 0, 0, 0, -1, v44, LODWORD(v45), HIDWORD(v45));
    }
    result = v54;
    if ( v54 > 0 )
    {
      HIDWORD(v45) = v54;
      v28 = (const char *)sub_4CFC00(8);
      sub_41D810(v68, 0x3Fu, "   %s - %d ", v28, HIDWORD(v45));
      v45 = NAN;
      v44 = -1;
      v43 = sub_4CF900(this);
      return sub_4D93B0(v68, 0, v43, 0, 0, 0, -1, v44, LODWORD(v45), HIDWORD(v45));
    }
  }
  else
  {
    dword_B76314 = dword_B7630C;
    if ( dword_B7630C )
      v29 = *(float **)dword_B7630C;
    else
      v29 = 0;
    while ( v29 )
    {
      v30 = (const char *)*((_DWORD *)v29 + 2);
      if ( !v30 )
        v30 = WindowName;
      if ( !_stricmp(String1, v30) )
      {
        v2 += *((_DWORD *)v29 + 7);
        if ( (v47 > (double)v29[8] || v47 == -1.0) && v29[8] != 0.0 && dword_B72338 == *((_DWORD *)v29 + 6) )
        {
          v31 = v29[8];
          v32 = (const CHAR *)*((_DWORD *)v29 + 4);
          v47 = v31;
          if ( !v32 )
            v32 = WindowName;
          sub_630FE0(v69, v32, 63);
          HIBYTE(v70) = 0;
        }
      }
      if ( dword_B76314 && (dword_B76314 = *(_DWORD *)(dword_B76314 + 4)) != 0 )
        v29 = *(float **)dword_B76314;
      else
        v29 = 0;
    }
    v33 = (int)(unsigned __int64)v47 / 60;
    if ( v33 > 0 )
    {
      v48 = 60 * v33;
      v47 = v47 - (double)(60 * v33);
    }
    if ( v47 <= 0.0 )
      sprintf(v57, "-:--.---");
    else
      sprintf(v57, "%i:%06.3f", v33, v47);
    v34 = (const char *)sub_4CFC00(6);
    v35 = sub_41D840(&byte_91CC38, v34);
    sprintf(Buffer, "%s %s", v35, v57);
    sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    v36 = (const char *)sub_4CFC00(6);
    v37 = (unsigned __int64)((double)(int)strlen(sub_41D840(&byte_91CC38, v36)) * 1.75);
    _strnset(v68, 32, v37);
    v68[v37] = 0;
    sprintf(Buffer, "%s%s", v68, (const char *)v69);
    sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    v38 = (const char *)sub_4CFC00(7);
    v39 = sub_41D840(&byte_91CC38, v38);
    sprintf(Buffer, "%s%s %d", v68, v39, v2);
    return sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  }
  return result;
}
