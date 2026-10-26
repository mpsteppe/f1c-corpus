void __thiscall sub_57E710(int this, int a2, float a3)
{
  double v3; // st7
  int v4; // eax
  double v6; // st7
  int v7; // eax
  double v8; // st6
  double v9; // st6
  int v10; // eax
  double v11; // st6
  double v12; // st6
  int v13; // eax
  double v14; // st6
  double v15; // st6
  double v16; // st7
  float v17; // [esp+0h] [ebp-3Ch]
  float v18; // [esp+8h] [ebp-34h]
  float v19; // [esp+8h] [ebp-34h]
  float v20; // [esp+18h] [ebp-24h]
  float v21; // [esp+1Ch] [ebp-20h]
  float v22; // [esp+20h] [ebp-1Ch]
  float v23; // [esp+24h] [ebp-18h] BYREF
  float v24; // [esp+28h] [ebp-14h]
  float v25; // [esp+2Ch] [ebp-10h]
  float v26; // [esp+30h] [ebp-Ch]
  float v27; // [esp+34h] [ebp-8h]
  float v28; // [esp+38h] [ebp-4h]
  int v29; // [esp+40h] [ebp+4h]
  float v30; // [esp+40h] [ebp+4h]
  int v31; // [esp+44h] [ebp+8h]

  v3 = 0.0;
  v4 = *(_DWORD *)(this + 0x4000);
  v17 = 0.0;
  v18 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  v22 = 0.0;
  if ( v4 && *(_DWORD *)(*(_DWORD *)(v4 + 84) + 44) == a2 )
  {
    if ( *(float *)&dword_B70D5C >= (double)a3 )
      v6 = a3;
    else
      v6 = *(float *)&dword_B70D5C;
    v3 = v6 * *(float *)(this + 16224) * *(float *)&dword_B70D80;
    *(float *)&v29 = v3;
    if ( v3 > 0.0 )
      v17 = v3;
    v19 = *(float *)&dword_B70DC8 * a3 + *(float *)&dword_B70DA4;
    v18 = v19 * *(float *)&v29;
    v23 = *(float *)&v29 * *(float *)(this + 16160);
    v26 = v23;
    v24 = *(float *)&v29 * *(float *)(this + 16164);
    v27 = v24;
    v25 = *(float *)&v29 * *(float *)(this + 16168);
    v28 = v25;
    v20 = v23;
    v21 = v24;
    v22 = v25;
  }
  v7 = *(_DWORD *)(this + 16636);
  if ( v7 && *(_DWORD *)(*(_DWORD *)(v7 + 84) + 44) == a2 )
  {
    if ( *(float *)&dword_B70D5C >= (double)a3 )
      v8 = a3;
    else
      v8 = *(float *)&dword_B70D5C;
    v9 = v8 * *(float *)(this + 16476) * *(float *)&dword_B70D80;
    if ( v9 > v17 )
      v17 = v9;
    v3 = v3 + v9;
    v18 = (*(float *)&dword_B70DC8 * a3 + *(float *)&dword_B70DA4) * v9 + v18;
    v23 = v9 * *(float *)(this + 16412);
    v26 = v23;
    v24 = v9 * *(float *)(this + 16416);
    v27 = v24;
    v25 = v9 * *(float *)(this + 16420);
    v28 = v25;
    v20 = v23 + v20;
    v21 = v24 + v21;
    v22 = v25 + v22;
  }
  v10 = *(_DWORD *)(this + 16888);
  if ( v10 && *(_DWORD *)(*(_DWORD *)(v10 + 84) + 44) == a2 )
  {
    if ( *(float *)&dword_B70D5C >= (double)a3 )
      v11 = a3;
    else
      v11 = *(float *)&dword_B70D5C;
    v12 = v11 * *(float *)(this + 16728) * *(float *)&dword_B70D80;
    if ( v12 > v17 )
      v17 = v12;
    v3 = v3 + v12;
    v18 = (*(float *)&dword_B70DC8 * a3 + *(float *)&dword_B70DA4) * v12 + v18;
    v23 = v12 * *(float *)(this + 16664);
    v26 = v23;
    v24 = v12 * *(float *)(this + 16668);
    v27 = v24;
    v25 = v12 * *(float *)(this + 16672);
    v28 = v25;
    v20 = v23 + v20;
    v21 = v24 + v21;
    v22 = v25 + v22;
  }
  v13 = *(_DWORD *)(this + 17140);
  if ( v13 && *(_DWORD *)(*(_DWORD *)(v13 + 84) + 44) == a2 )
  {
    if ( *(float *)&dword_B70D5C >= (double)a3 )
      v14 = a3;
    else
      v14 = *(float *)&dword_B70D5C;
    v15 = v14 * *(float *)(this + 16980) * *(float *)&dword_B70D80;
    if ( v15 > v17 )
      v17 = v15;
    v3 = v3 + v15;
    v18 = (*(float *)&dword_B70DC8 * a3 + *(float *)&dword_B70DA4) * v15 + v18;
    v23 = v15 * *(float *)(this + 16916);
    v26 = v23;
    v24 = v15 * *(float *)(this + 16920);
    v27 = v24;
    v25 = v15 * *(float *)(this + 16924);
    v28 = v25;
    v20 = v23 + v20;
    v21 = v24 + v21;
    v22 = v25 + v22;
  }
  if ( v17 > 0.001 )
  {
    if ( a2 == 23 )
      v17 = v17 * 0.125;
    v16 = 1.0 / v3;
    v26 = v20 * v16;
    v23 = v26;
    v27 = v21 * v16;
    v24 = v27;
    v28 = v16 * v22;
    v25 = v28;
    if ( v17 <= 1.0 )
      v31 = LODWORD(v17);
    else
      v31 = 1065353216;
    v30 = v18 * v16;
    sub_58C6C0(this + 8, a2, 1, v31, LODWORD(v30), &v23);
  }
}
