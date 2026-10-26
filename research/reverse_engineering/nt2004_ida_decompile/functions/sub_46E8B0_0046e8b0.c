char __fastcall sub_46E8B0(int a1, int a2)
{
  float v3; // eax
  int v4; // ecx
  int v5; // eax
  float v6; // ecx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  long double v11; // st7
  float v12; // eax
  int v13; // edx
  float v14; // edx
  float v16; // [esp+0h] [ebp-5Ch]
  float v17; // [esp+8h] [ebp-54h]
  float v18; // [esp+8h] [ebp-54h]
  float v19; // [esp+10h] [ebp-4Ch] BYREF
  int v20; // [esp+14h] [ebp-48h] BYREF
  float v21; // [esp+18h] [ebp-44h] BYREF
  int v22; // [esp+1Ch] [ebp-40h]
  float v23; // [esp+20h] [ebp-3Ch] BYREF
  float v24; // [esp+24h] [ebp-38h] BYREF
  int v25; // [esp+28h] [ebp-34h] BYREF
  int v26; // [esp+2Ch] [ebp-30h] BYREF
  int v27; // [esp+30h] [ebp-2Ch] BYREF
  int v28; // [esp+34h] [ebp-28h]
  int v29; // [esp+38h] [ebp-24h] BYREF
  int v30; // [esp+3Ch] [ebp-20h]
  float v31; // [esp+40h] [ebp-1Ch]
  int v32[3]; // [esp+44h] [ebp-18h] BYREF
  float v33[3]; // [esp+50h] [ebp-Ch] BYREF

  LOBYTE(v3) = *(_BYTE *)(a1 + 420);
  if ( !LOBYTE(v3) )
    return LOBYTE(v3);
  v3 = *(float *)(a1 + 268);
  if ( v3 == 0.0 )
    return LOBYTE(v3);
  if ( !*(_DWORD *)(a1 + 340) && (sub_46F1B0(), !*(_DWORD *)(a1 + 340)) || *(_BYTE *)(a1 + 360) )
  {
    v9 = *(_DWORD *)(a1 + 48);
    v25 = 0;
    *(float *)&v20 = 0.0;
    v21 = 0.0;
    v19 = 0.0;
    v24 = 0.0;
    v23 = 0.0;
    sub_4AE720(v9, a2);
    sub_4AE870(&v27, &v26);
    v10 = *(_DWORD *)(a1 + 308);
    v28 = v27 - *(_DWORD *)(a1 + 304);
    v22 = v26 - v10;
    sub_593DA0(&v25, &v20, &v21, &v19, &v24, &v23);
    v11 = *(float *)(a1 + 336);
    v12 = *(float *)(a1 + 332);
    v19 = *(float *)(a1 + 336);
    v13 = *(int *)(a1 + 328);
    v21 = v12;
    LOBYTE(v12) = *(_BYTE *)(a1 + 285);
    v20 = v13;
    if ( LOBYTE(v12) )
    {
      if ( *(_BYTE *)(a1 + 284) && dword_768948 )
      {
        v17 = -((double)v22 * 0.0074999998);
        v16 = (double)v28 * 0.0074999998;
        sub_59E090(v16, 0.0, v17);
        v11 = v19;
      }
      else
      {
        v18 = (double)v22 * 0.025;
        sub_46F020(v18);
        v11 = v19;
      }
      goto LABEL_33;
    }
    if ( *(_BYTE *)(a1 + 284) )
    {
      v11 = v11 - (double)v22 * 0.0055;
      v19 = v11;
      if ( dword_768948 )
      {
        if ( v11 > 6.2831855 )
        {
          do
            v11 = v11 - 6.2831855;
          while ( v11 > 6.2831855 );
          v19 = v11;
        }
        if ( v11 >= -6.2831855 )
          goto LABEL_33;
        do
          v11 = v11 + 6.2831855;
        while ( v11 < -6.2831855 );
        goto LABEL_32;
      }
      if ( v11 < -0.78539819 )
      {
        v11 = -0.78539819;
LABEL_32:
        v19 = v11;
        goto LABEL_33;
      }
      if ( v11 > -0.098174773 )
      {
        v11 = -0.098174773;
        goto LABEL_32;
      }
    }
LABEL_33:
    *(float *)&v20 = sin(v11) * *(float *)(a1 + 292);
    v21 = cos(v11) * *(float *)(a1 + 292);
    sub_5934A0(v25, v20, v21, v19, v24, v23);
    v14 = v21;
    v3 = v19;
    *(float *)(a1 + 328) = *(float *)&v20;
    *(_DWORD *)(a1 + 308) = v26;
    *(float *)(a1 + 332) = v14;
    *(float *)(a1 + 336) = v3;
    return LOBYTE(v3);
  }
  v4 = *(_DWORD *)(a1 + 48);
  memset(v32, 0, sizeof(v32));
  *(float *)&v22 = sub_4AE720(v4, a2);
  sub_459B40(*(_DWORD ***)(a1 + 340), (int)v32, (int)v32, (int)v32, v22, v22);
  sub_459BC0(*(_DWORD **)(a1 + 340), &v29, v33);
  if ( *(float *)(a1 + 344) == *(float *)&v29 && *(float *)(a1 + 348) == *(float *)&v30 && *(float *)(a1 + 352) == v31 )
  {
    v7 = *(_DWORD *)(a1 + 280);
    *(_BYTE *)(a1 + 360) = 1;
    if ( v7 )
    {
      sub_59E170(
        *(_DWORD *)(a1 + 388),
        *(_DWORD *)(a1 + 392),
        *(_DWORD *)(a1 + 396),
        *(float *)(a1 + 400),
        *(float *)(a1 + 404),
        *(float *)(a1 + 408));
      *(_DWORD *)(a1 + 324) = *(_DWORD *)(a1 + 404);
    }
    if ( *(_DWORD *)(a1 + 268) )
      sub_5934A0(
        *(_DWORD *)(a1 + 364),
        *(_DWORD *)(a1 + 368),
        *(float *)(a1 + 372),
        *(float *)(a1 + 376),
        *(float *)(a1 + 380),
        *(float *)(a1 + 384));
    v8 = *(_DWORD *)(a1 + 372);
    v3 = *(float *)(a1 + 376);
    *(_DWORD *)(a1 + 328) = *(_DWORD *)(a1 + 368);
    *(_DWORD *)(a1 + 332) = v8;
    *(float *)(a1 + 336) = v3;
  }
  else
  {
    v5 = v30;
    v6 = v31;
    *(float *)(a1 + 344) = *(float *)&v29;
    *(_DWORD *)(a1 + 348) = v5;
    *(float *)(a1 + 352) = v6;
    sub_409050((float *)&v29, v33);
    LOBYTE(v3) = sub_5934A0(v29, v30, v31, v33[0], v33[1], v33[2]);
    if ( *(_DWORD *)(a1 + 280) )
    {
      LOBYTE(v3) = sub_59E170(
                     *(_DWORD *)(a1 + 388),
                     *(_DWORD *)(a1 + 392),
                     *(_DWORD *)(a1 + 396),
                     *(float *)(a1 + 400),
                     *(float *)(a1 + 404),
                     *(float *)(a1 + 408));
      *(_DWORD *)(a1 + 324) = *(_DWORD *)(a1 + 404);
    }
  }
  return LOBYTE(v3);
}
