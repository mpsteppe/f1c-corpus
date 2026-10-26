void __stdcall sub_42B2F0(int a1, int a2)
{
  double v3; // st7
  float *v4; // edi
  double v5; // st7
  double v6; // st7
  int v7; // eax
  double v8; // st7
  int v9; // eax
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st6
  double v14; // st6
  float v15; // [esp+Ch] [ebp-54h]
  float v16; // [esp+10h] [ebp-50h]
  float v17; // [esp+14h] [ebp-4Ch]
  float v18; // [esp+18h] [ebp-48h]
  float v19; // [esp+1Ch] [ebp-44h]
  float v20; // [esp+20h] [ebp-40h]
  float v21; // [esp+24h] [ebp-3Ch]
  double v22; // [esp+28h] [ebp-38h] BYREF
  double v23; // [esp+30h] [ebp-30h]
  double v24; // [esp+38h] [ebp-28h]
  double v25; // [esp+40h] [ebp-20h]
  double v26; // [esp+48h] [ebp-18h]
  double v27; // [esp+50h] [ebp-10h]
  int v28; // [esp+58h] [ebp-8h]

  *(_DWORD *)a2 = *(_DWORD *)a1;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 8);
  v3 = *(float *)(a1 + 12) + *(float *)(a1 + 12);
  v4 = (float *)(a2 + 12);
  v28 = 0;
  v19 = v3;
  v20 = *(float *)(a1 + 16) + *(float *)(a1 + 16);
  v5 = *(float *)(a1 + 20);
  *(float *)(a2 + 12) = v19;
  *(float *)(a2 + 16) = v20;
  v21 = v5 + v5;
  v22 = *(float *)a2;
  v6 = *(float *)(a2 + 4);
  *(float *)(a2 + 20) = v21;
  v23 = v6;
  v24 = *(float *)(a2 + 8);
  v25 = 1.0;
  v26 = 9.999999933815813e36;
  v7 = sub_45D190(&v22);
  if ( v7 )
  {
    v15 = v27;
    v8 = *(float *)a2 - *v4;
    v28 = v7;
    v22 = v8;
    v23 = *(float *)(a2 + 4);
    v24 = *(float *)(a2 + 8) - *(float *)(a2 + 20);
    v25 = 5.0;
    v26 = 9.999999933815813e36;
    v9 = sub_45D190(&v22);
    if ( v9 )
      v16 = v27;
    else
      v16 = v15;
    v10 = *v4 + *(float *)a2;
    v28 = v9;
    v22 = v10;
    v23 = *(float *)(a2 + 4);
    v24 = *(float *)(a2 + 20) + *(float *)(a2 + 8);
    v25 = 5.0;
    v26 = 9.999999933815813e36;
    if ( sub_45D190(&v22) )
      v11 = v27;
    else
      v11 = v15;
    v12 = v15 + v15;
    v17 = v12;
    v13 = v12 - v16;
    if ( v11 > v13 + 0.34999999 || v11 < v13 - 0.34999999 )
    {
      if ( fabs(v16 - v15) >= fabs(v11 - v15) )
      {
        v16 = v17 - v11;
      }
      else
      {
        v18 = v13;
        v11 = v18;
      }
    }
    v14 = (v16 + v11) * 0.5;
    if ( v15 > v14 )
      v14 = v15;
    *(float *)(a2 + 4) = flt_B71614 + v14;
    *(float *)(a2 + 16) = (v11 - v16) * 0.5;
  }
}
