void __thiscall sub_4ABA40(int this)
{
  int v2; // eax
  int v3; // ecx
  double v4; // st7
  int v5; // edx
  const char *v6; // eax
  CHAR *v7; // edx
  int v8; // edx
  const char *v9; // eax
  CHAR *v10; // eax
  int v11; // edx
  const char *v12; // eax
  CHAR *v13; // eax
  const char *v14; // eax
  int *v15; // eax
  CHAR *v16; // ecx
  unsigned __int8 v17; // cl
  double v18; // st7
  int v19; // edx
  _DWORD *v20; // ecx
  double v21; // st7
  double v22; // st6
  double v23; // st6
  double v24; // st7
  double v25; // st7
  double v26; // st7
  int v27; // eax
  bool v28; // cf
  double v29; // st7
  float v30; // ebp
  double v31; // st6
  double v32; // st7
  float v33; // ebx
  char *v34; // ecx
  _DWORD *v35; // eax
  char *v36; // ecx
  _DWORD *v37; // eax
  char *v38; // ecx
  float v39; // [esp+8h] [ebp-22Ch] BYREF
  float v40; // [esp+Ch] [ebp-228h] BYREF
  float v41; // [esp+10h] [ebp-224h] BYREF
  float v42; // [esp+14h] [ebp-220h] BYREF
  int v43; // [esp+18h] [ebp-21Ch]
  float v44; // [esp+1Ch] [ebp-218h]
  float v45; // [esp+20h] [ebp-214h]
  float v46; // [esp+24h] [ebp-210h]
  float v47; // [esp+28h] [ebp-20Ch]
  int v48; // [esp+2Ch] [ebp-208h]
  int v49; // [esp+30h] [ebp-204h]
  char Buffer[509]; // [esp+34h] [ebp-200h] BYREF
  __int16 v51; // [esp+231h] [ebp-3h]
  char v52; // [esp+233h] [ebp-1h]

  if ( dword_76887C
    && *(float *)(this + 280) >= (double)*(float *)(this + 284)
    && (v2 = *(_DWORD *)(this + 392)) != 0
    && (v3 = *(_DWORD *)(this + 260)) != 0 )
  {
    v49 = *(_DWORD *)(v3 + 172);
    v48 = v49;
    if ( *(_DWORD *)(this + 396) != v2 )
    {
      v4 = (double)*(int *)(this + 88);
      *(_DWORD *)(this + 396) = v2;
      v39 = 0.0;
      v40 = 0.0;
      v41 = 0.0;
      v42 = 0.0;
      *(_BYTE *)(this + 248) = 0;
      *(float *)(this + 180) = v4 * 0.00125;
      sub_5A3FD0(*(_DWORD *)(v2 + 232), *(_DWORD *)(v2 + 236));
      v5 = *(_DWORD *)(this + 392);
      v6 = *(const char **)(v5 + 184);
      if ( !v6 )
        v6 = &byte_629120;
      if ( strlen(v6) )
      {
        v7 = *(CHAR **)(v5 + 184);
        if ( !v7 )
          v7 = &byte_629120;
        sub_5A41F0(v7, &v39, &v41, 1);
        *(_BYTE *)(this + 248) = 1;
      }
      v8 = *(_DWORD *)(this + 392);
      v9 = *(const char **)(v8 + 192);
      if ( !v9 )
        v9 = &byte_629120;
      if ( strlen(v9) )
      {
        v10 = *(CHAR **)(v8 + 192);
        if ( !v10 )
          v10 = &byte_629120;
        sub_5A41F0(v10, &v40, &v42, 1);
        if ( SLODWORD(v39) <= SLODWORD(v40) )
          v39 = v40;
        if ( SLODWORD(v41) <= SLODWORD(v42) )
          v41 = v42;
        *(_BYTE *)(this + 248) = 2;
      }
      v11 = *(_DWORD *)(this + 392);
      v12 = *(const char **)(v11 + 200);
      if ( !v12 )
        v12 = &byte_629120;
      if ( strlen(v12) )
      {
        v13 = *(CHAR **)(v11 + 200);
        if ( !v13 )
          v13 = &byte_629120;
        sub_5A41F0(v13, &v40, &v42, 1);
        if ( SLODWORD(v39) <= SLODWORD(v40) )
          v39 = v40;
        if ( SLODWORD(v41) <= SLODWORD(v42) )
          v41 = v42;
        *(_BYTE *)(this + 248) = 3;
      }
      *(float *)(this + 252) = (double)SLODWORD(v39) * 0.00125;
      *(float *)(this + 256) = (double)SLODWORD(v41) * 0.0016666667;
      Buffer[0] = byte_629120;
      memset(&Buffer[1], 0, 0x1FCu);
      v51 = 0;
      v52 = 0;
      v14 = (const char *)dword_62A098;
      if ( !dword_62A098 )
        v14 = &byte_629120;
      sprintf(Buffer, "%s%s", v14, aOptionsMas);
      v15 = *(int **)(this + 392);
      v16 = (CHAR *)v15[53];
      if ( !v16 )
        v16 = &byte_629120;
      sub_506C20(*(_DWORD *)(this + 260) + 36, v15[52], (int)v16, 1.0, 1.0, 1.0, 0.0, 0.0, v15[55], (int)Buffer);
    }
    v17 = *(_BYTE *)(this + 248);
    if ( v17 )
    {
      v18 = *(float *)(this + 280) - *(float *)(this + 284);
      if ( v18 < *(float *)(this + 288) )
        v41 = v18 / *(float *)(this + 288) * (v18 / *(float *)(this + 288));
      else
        v41 = 1.0;
      v19 = v17;
      v20 = *(_DWORD **)(this + 392);
      v45 = v41 * *(float *)(this + 256);
      v21 = *(float *)(this + 256) * 0.25;
      v22 = *(float *)(this + 256);
      v43 = v19;
      v23 = v22 * 0.0;
      v47 = v21 * v41;
      v46 = v41 * v23;
      *(float *)&v43 = (v23 + *(float *)(this + 256)) * (double)v19 + v23;
      v42 = (v21 + v21 + *(float *)(this + 252)) * v41;
      v44 = *(float *)&v43 * v41;
      v24 = *(float *)(this + 180);
      v40 = (double)(int)v20[4] * 0.00125;
      if ( v24 >= v40 )
        v24 = v40;
      v40 = (double)(int)v20[3] * 0.00125;
      if ( v24 <= v40 )
        v24 = v40;
      LODWORD(v39) = v20[2] + 3;
      v40 = v24 - v42 * 0.5;
      v39 = (double)SLODWORD(v39) * 0.0016666667;
      if ( 1.0 - *(float *)&v43 < v39 )
      {
        v43 = v20[1] - 3;
        v39 = (double)v43 * 0.0016666667 - v44;
      }
      if ( v40 < 0.0 )
        v40 = 0.0;
      v25 = 1.0 - v42;
      if ( v25 < v40 )
        v40 = v25;
      if ( v39 < 0.0 )
        v39 = 0.0;
      v26 = 1.0 - v44;
      if ( v26 < v39 )
        v39 = v26;
      sub_506AE0(v40, v39, 1.0, 0);
      sub_5069A0(v42, v44);
      sub_506960(0);
      v27 = *(_DWORD *)(this + 392);
      v28 = *(_BYTE *)(this + 248) == 0;
      v47 = v47 / v42;
      v29 = 1.0 / v44;
      v30 = v47;
      v31 = v46 * v29;
      *(float *)&v43 = v31;
      v32 = v31 + v29 * v45;
      v42 = *(float *)&v43 + v32;
      v46 = v32 + v42;
      v45 = (double)dword_6152E8 * *(float *)(v27 + 232) * v41 * 0.00125;
      v33 = v45;
      v44 = (double)dword_6152EC * *(float *)(v27 + 236) * v41 * 0.0016666667;
      if ( !v28 )
      {
        v34 = *(char **)(v27 + 184);
        if ( !v34 )
          v34 = &byte_629120;
        sub_5070D0(v34, v47, *(float *)&v43, *(_DWORD *)(v27 + 240), *(_DWORD *)(v27 + 220), v45, v44, 0, 0);
      }
      if ( *(_BYTE *)(this + 248) >= 2u )
      {
        v35 = *(_DWORD **)(this + 392);
        v36 = (char *)v35[48];
        if ( !v36 )
          v36 = &byte_629120;
        sub_5070D0(v36, v30, v42, v35[60], v35[55], v33, v44, 0, 0);
      }
      if ( *(_BYTE *)(this + 248) >= 3u )
      {
        v37 = *(_DWORD **)(this + 392);
        v38 = (char *)v37[50];
        if ( !v38 )
          v38 = &byte_629120;
        sub_5070D0(v38, v30, v46, v37[60], v37[55], v33, v44, 0, 0);
      }
    }
    sub_5A3FD0(v49, v48);
  }
  else
  {
    *(_DWORD *)(this + 396) = 0;
    *(_DWORD *)(this + 180) = 0;
    *(_DWORD *)(this + 252) = 0;
    *(_DWORD *)(this + 256) = 0;
    *(_BYTE *)(this + 248) = 0;
  }
}
