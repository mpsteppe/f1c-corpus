void __thiscall sub_4DE730(int this)
{
  int v2; // ecx
  int v3; // eax
  double v4; // st7
  double v5; // st7
  int v6; // ecx
  int v7; // edx
  const char *v8; // eax
  const CHAR *v9; // eax
  int v10; // edx
  const char *v11; // eax
  const CHAR *v12; // eax
  int v13; // edx
  const char *v14; // eax
  const CHAR *v15; // eax
  const char *v16; // eax
  _DWORD *v17; // eax
  const CHAR *v18; // ecx
  unsigned __int8 v19; // cl
  double v20; // st7
  _DWORD *v21; // ecx
  double v22; // st7
  double v23; // st6
  double v24; // st7
  double v25; // st7
  double v26; // st7
  int v27; // eax
  double v28; // st7
  double v29; // st6
  double v30; // st7
  const CHAR *v31; // ecx
  int v32; // eax
  const CHAR *v33; // ecx
  int v34; // eax
  const CHAR *v35; // ecx
  int v36; // esi
  float v37; // [esp+0h] [ebp-254h]
  float v38; // [esp+4h] [ebp-250h]
  float v39; // [esp+4h] [ebp-250h]
  float v40; // [esp+4h] [ebp-250h]
  float v41; // [esp+8h] [ebp-24Ch]
  float v42; // [esp+8h] [ebp-24Ch]
  float v43; // [esp+Ch] [ebp-248h]
  float v44; // [esp+Ch] [ebp-248h]
  int v45; // [esp+10h] [ebp-244h]
  int v46; // [esp+10h] [ebp-244h]
  float v47; // [esp+10h] [ebp-244h]
  float v48; // [esp+14h] [ebp-240h]
  float v49; // [esp+14h] [ebp-240h]
  float v50; // [esp+18h] [ebp-23Ch]
  float v51; // [esp+18h] [ebp-23Ch]
  float v52; // [esp+1Ch] [ebp-238h]
  float v53; // [esp+1Ch] [ebp-238h]
  float v54; // [esp+20h] [ebp-234h]
  int v55; // [esp+24h] [ebp-230h]
  int v56; // [esp+28h] [ebp-22Ch] BYREF
  int v57; // [esp+2Ch] [ebp-228h] BYREF
  int v58; // [esp+30h] [ebp-224h] BYREF
  _DWORD v59[3]; // [esp+34h] [ebp-220h] BYREF
  unsigned int v60; // [esp+40h] [ebp-214h]
  int v61; // [esp+4Ch] [ebp-208h]
  int v62; // [esp+50h] [ebp-204h]
  char Buffer[509]; // [esp+54h] [ebp-200h] BYREF
  __int16 v64; // [esp+251h] [ebp-3h]
  char v65; // [esp+253h] [ebp-1h]

  if ( dword_B72188
    && *(float *)(this + 280) >= (double)*(float *)(this + 284)
    && (v2 = *(_DWORD *)(this + 392)) != 0
    && (v3 = *(_DWORD *)(this + 260)) != 0 )
  {
    v61 = *(_DWORD *)(v3 + 152);
    v62 = v61;
    if ( *(_DWORD *)(this + 396) != v2 )
    {
      v4 = (double)*(int *)(this + 88);
      *(_DWORD *)(this + 396) = v2;
      v56 = 0;
      v57 = 0;
      v58 = 0;
      v59[0] = 0;
      *(_BYTE *)(this + 248) = 0;
      *(float *)(this + 180) = v4 * 0.00125;
      v5 = *(float *)(v2 + 236);
      v6 = *(_DWORD *)(v2 + 232);
      *(float *)(v3 + 156) = v5;
      *(_DWORD *)(v3 + 152) = v6;
      v7 = *(_DWORD *)(this + 392);
      v8 = *(const char **)(v7 + 184);
      if ( !v8 )
        v8 = WindowName;
      v60 = strlen(v8);
      if ( v60 )
      {
        v9 = *(const CHAR **)(v7 + 184);
        if ( !v9 )
          v9 = WindowName;
        sub_5F0380(v9, &v56, &v58, 1);
        *(_BYTE *)(this + 248) = 1;
      }
      v10 = *(_DWORD *)(this + 392);
      v11 = *(const char **)(v10 + 192);
      if ( !v11 )
        v11 = WindowName;
      v60 = strlen(v11);
      if ( v60 )
      {
        v12 = *(const CHAR **)(v10 + 192);
        if ( !v12 )
          v12 = WindowName;
        sub_5F0380(v12, &v57, v59, 1);
        if ( v56 <= v57 )
          v56 = v57;
        if ( v58 <= v59[0] )
          v58 = v59[0];
        *(_BYTE *)(this + 248) = 2;
      }
      v13 = *(_DWORD *)(this + 392);
      v14 = *(const char **)(v13 + 200);
      if ( !v14 )
        v14 = WindowName;
      v60 = strlen(v14);
      if ( v60 )
      {
        v15 = *(const CHAR **)(v13 + 200);
        if ( !v15 )
          v15 = WindowName;
        sub_5F0380(v15, &v57, v59, 1);
        if ( v56 <= v57 )
          v56 = v57;
        if ( v58 <= v59[0] )
          v58 = v59[0];
        *(_BYTE *)(this + 248) = 3;
      }
      memset(Buffer, 0, sizeof(Buffer));
      *(float *)(this + 252) = (double)v56 * 0.00125;
      v64 = 0;
      v65 = 0;
      *(float *)(this + 256) = (double)v58 * 0.0016666667;
      v16 = *(const char **)dword_91CAB0;
      if ( !*(_DWORD *)dword_91CAB0 )
        v16 = WindowName;
      sprintf(Buffer, "%s%s", v16, "uiassets.GTR");
      v17 = *(_DWORD **)(this + 392);
      v18 = (const CHAR *)v17[53];
      if ( !v18 )
        v18 = WindowName;
      sub_568830(
        this + 184,
        *(_DWORD *)(this + 260) + 20,
        v17[52],
        v18,
        1065353216,
        1065353216,
        1065353216,
        0,
        0,
        v17[55],
        Buffer);
    }
    v19 = *(_BYTE *)(this + 248);
    if ( v19 )
    {
      v20 = *(float *)(this + 280) - *(float *)(this + 284);
      if ( v20 < *(float *)(this + 288) )
        v41 = v20 / *(float *)(this + 288) * (v20 / *(float *)(this + 288));
      else
        v41 = 1.0;
      v45 = v19;
      v21 = *(_DWORD **)(this + 392);
      v50 = v41 * *(float *)(this + 256);
      v22 = *(float *)(this + 256) * 0.25;
      v23 = *(float *)(this + 256) * 0.0;
      v54 = v22 * v41;
      *(float *)&v46 = (v23 + *(float *)(this + 256)) * (double)v45 + v23;
      v43 = (v22 + v22 + *(float *)(this + 252)) * v41;
      v48 = *(float *)&v46 * v41;
      v24 = *(float *)(this + 180);
      v38 = (double)(int)v21[4] * 0.00125;
      if ( v24 >= v38 )
        v24 = v38;
      v39 = (double)(int)v21[3] * 0.00125;
      if ( v24 <= v39 )
        v24 = v39;
      v40 = v24 - v43 * 0.5;
      v37 = (double)(v21[2] + 3) * 0.0016666667;
      if ( 1.0 - *(float *)&v46 < v37 )
      {
        v46 = v21[1] - 3;
        v37 = (double)v46 * 0.0016666667 - v48;
      }
      if ( v40 < 0.0 )
        v40 = 0.0;
      v25 = 1.0 - v43;
      if ( v25 < v40 )
        v40 = v25;
      if ( v37 < 0.0 )
        v37 = 0.0;
      v26 = 1.0 - v48;
      if ( v26 < v37 )
        v37 = v26;
      sub_5687B0(v40, v37, 1.0, 0);
      sub_568770(v43, v48);
      sub_568750(this + 184, 0);
      v27 = *(_DWORD *)(this + 392);
      v52 = v41 * v23;
      v53 = v52 / v41;
      v28 = 1.0 / *(float *)&v46;
      v29 = v50 * v28;
      v44 = v29;
      v30 = v29 + v28 * v48;
      v42 = v44 + v30;
      v49 = (double)*(int *)dword_903EB8 * *(float *)(v27 + 232) * v40 * 0.00125;
      v47 = (double)dword_903EBC * *(float *)(v27 + 236) * v40 * 0.0016666667;
      if ( *(_BYTE *)(this + 248) )
      {
        v31 = *(const CHAR **)(v27 + 184);
        if ( !v31 )
          v31 = WindowName;
        sub_568D20((int)v31, v53, v44, *(float *)(v27 + 240), *(_DWORD *)(v27 + 220), v49, v47, 0, 0);
      }
      if ( *(_BYTE *)(this + 248) >= 2u )
      {
        v32 = *(_DWORD *)(this + 392);
        v33 = *(const CHAR **)(v32 + 192);
        if ( !v33 )
          v33 = WindowName;
        sub_568D20((int)v33, v53, v42, *(float *)(v32 + 240), *(_DWORD *)(v32 + 220), v49, v47, 0, 0);
      }
      if ( *(_BYTE *)(this + 248) >= 3u )
      {
        v34 = *(_DWORD *)(this + 392);
        v35 = *(const CHAR **)(v34 + 200);
        if ( !v35 )
          v35 = WindowName;
        v51 = v30 + v42;
        sub_568D20((int)v35, v53, v51, *(float *)(v34 + 240), *(_DWORD *)(v34 + 220), v49, v47, 0, 0);
      }
    }
    v36 = *(_DWORD *)(this + 260);
    *(float *)(v36 + 152) = v54;
    *(_DWORD *)(v36 + 156) = v55;
  }
  else
  {
    *(_DWORD *)(this + 396) = 0;
    *(_DWORD *)(this + 180) = 0;
    *(_BYTE *)(this + 248) = 0;
    *(_DWORD *)(this + 252) = 0;
    *(_DWORD *)(this + 256) = 0;
  }
}
