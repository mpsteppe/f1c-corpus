void __thiscall sub_57E220(int this, int a2)
{
  double v2; // st7
  int v5; // eax
  double v6; // st6
  int v7; // eax
  double v8; // st6
  int v9; // eax
  double v10; // st6
  int v11; // eax
  double v12; // st6
  double v13; // st7
  float v14; // [esp+4h] [ebp-40h]
  float v15; // [esp+8h] [ebp-3Ch]
  float v16; // [esp+Ch] [ebp-38h]
  float v17; // [esp+1Ch] [ebp-28h]
  float v18; // [esp+1Ch] [ebp-28h]
  float v19; // [esp+20h] [ebp-24h]
  float v20; // [esp+24h] [ebp-20h]
  float v21; // [esp+28h] [ebp-1Ch]
  float v22; // [esp+2Ch] [ebp-18h] BYREF
  float v23; // [esp+30h] [ebp-14h]
  float v24; // [esp+34h] [ebp-10h]
  float v25; // [esp+38h] [ebp-Ch]
  float v26; // [esp+3Ch] [ebp-8h]
  float v27; // [esp+40h] [ebp-4h]
  float v28; // [esp+48h] [ebp+4h]
  int v29; // [esp+48h] [ebp+4h]

  v2 = 0.0;
  v14 = 0.0;
  v15 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  if ( *(_DWORD *)(this + 14804) )
  {
    v28 = 0.5;
  }
  else
  {
    if ( a2 == 35 )
    {
      sub_57DFE0((char *)this);
      v2 = (float)0.0;
    }
    v28 = 0.82999998;
  }
  v5 = *(_DWORD *)(this + 0x4000);
  if ( v5 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(v5 + 84) + 48) == a2 && *(float *)(this + 16228) < (double)v28 )
    {
      v6 = (v28 - *(float *)(this + 16228)) * *(float *)(this + 16224) * *(float *)&dword_B70CF0;
      v16 = v6;
      if ( v6 > 0.0 )
      {
        v2 = v16;
        v14 = v6;
        v17 = *(float *)&dword_B70D38 * *(float *)(this + 16220)
            + *(float *)&dword_B70D14 * *(float *)(this + 16228)
            + 1.05;
        v15 = v17 * v16;
        v22 = v16 * *(float *)(this + 16160);
        v25 = v22;
        v19 = v22;
        v23 = v16 * *(float *)(this + 16164);
        v26 = v23;
        v20 = v23;
        v24 = v16 * *(float *)(this + 16168);
        v27 = v24;
        v21 = v24;
      }
    }
  }
  v7 = *(_DWORD *)(this + 16636);
  if ( v7 && *(_DWORD *)(*(_DWORD *)(v7 + 84) + 48) == a2 && *(float *)(this + 16480) < (double)v28 )
  {
    v8 = (v28 - *(float *)(this + 16480)) * *(float *)(this + 16476) * *(float *)&dword_B70CF0;
    if ( v8 > v14 )
      v14 = v8;
    if ( v8 > 0.0 )
    {
      v2 = v2 + v8;
      v15 = (*(float *)&dword_B70D38 * *(float *)(this + 16472)
           + *(float *)&dword_B70D14 * *(float *)(this + 16480)
           + 1.05)
          * v8
          + v15;
      v22 = v8 * *(float *)(this + 16412);
      v25 = v22;
      v23 = v8 * *(float *)(this + 16416);
      v26 = v23;
      v24 = v8 * *(float *)(this + 16420);
      v27 = v24;
      v19 = v22 + v19;
      v20 = v23 + v20;
      v21 = v24 + v21;
    }
  }
  v9 = *(_DWORD *)(this + 16888);
  if ( v9 && *(_DWORD *)(*(_DWORD *)(v9 + 84) + 48) == a2 && *(float *)(this + 16732) < (double)v28 )
  {
    v10 = (v28 - *(float *)(this + 16732)) * *(float *)(this + 16728) * *(float *)&dword_B70CF0;
    if ( v10 > v14 )
      v14 = v10;
    if ( v10 > 0.0 )
    {
      v2 = v2 + v10;
      v15 = (*(float *)&dword_B70D38 * *(float *)(this + 16724)
           + *(float *)&dword_B70D14 * *(float *)(this + 16732)
           + 1.05)
          * v10
          + v15;
      v22 = v10 * *(float *)(this + 16664);
      v25 = v22;
      v23 = v10 * *(float *)(this + 16668);
      v26 = v23;
      v24 = v10 * *(float *)(this + 16672);
      v27 = v24;
      v19 = v22 + v19;
      v20 = v23 + v20;
      v21 = v24 + v21;
    }
  }
  v11 = *(_DWORD *)(this + 17140);
  if ( v11 && *(_DWORD *)(*(_DWORD *)(v11 + 84) + 48) == a2 && *(float *)(this + 16984) < (double)v28 )
  {
    v12 = (v28 - *(float *)(this + 16984)) * *(float *)(this + 16980) * *(float *)&dword_B70CF0;
    if ( v12 > v14 )
      v14 = v12;
    if ( v12 > 0.0 )
    {
      v2 = v2 + v12;
      v15 = (*(float *)&dword_B70D38 * *(float *)(this + 16976)
           + *(float *)&dword_B70D14 * *(float *)(this + 16984)
           + 1.05)
          * v12
          + v15;
      v22 = v12 * *(float *)(this + 16916);
      v25 = v22;
      v23 = v12 * *(float *)(this + 16920);
      v26 = v23;
      v24 = v12 * *(float *)(this + 16924);
      v27 = v24;
      v19 = v22 + v19;
      v20 = v23 + v20;
      v21 = v24 + v21;
    }
  }
  if ( v14 > 0.001 )
  {
    v13 = 1.0 / v2;
    v25 = v19 * v13;
    v22 = v25;
    v26 = v20 * v13;
    v23 = v26;
    v27 = v13 * v21;
    v24 = v27;
    if ( v14 <= 1.0 )
      v29 = LODWORD(v14);
    else
      v29 = 1065353216;
    v18 = v15 * v13;
    sub_58C6C0(this + 8, a2, 2, v29, LODWORD(v18), &v22);
  }
}
