void __stdcall sub_523470(_DWORD *a1, float a2, int a3)
{
  long double v3; // st7
  float *v4; // edi
  long double v5; // rt0
  double v6; // st7
  int v7; // eax
  double v8; // st7
  int v9; // eax
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st6
  double v14; // st6
  float v15; // [esp+8h] [ebp-58h]
  float v16; // [esp+Ch] [ebp-54h]
  float v17; // [esp+10h] [ebp-50h]
  float v18; // [esp+14h] [ebp-4Ch]
  float v19; // [esp+18h] [ebp-48h]
  float v20; // [esp+20h] [ebp-40h]
  float v21; // [esp+2Ch] [ebp-34h]
  double v22; // [esp+30h] [ebp-30h] BYREF
  double v23; // [esp+38h] [ebp-28h]
  double v24; // [esp+40h] [ebp-20h]
  double v25; // [esp+48h] [ebp-18h]
  double v26; // [esp+50h] [ebp-10h]
  double v27; // [esp+58h] [ebp-8h]
  int vars0; // [esp+60h] [ebp+0h]

  *(_DWORD *)a3 = *a1;
  *(_DWORD *)(a3 + 4) = a1[1];
  *(_DWORD *)(a3 + 8) = a1[2];
  v3 = fmod(a2 - 1.5707964, 6.283185482025146);
  v4 = (float *)(a3 + 12);
  vars0 = 0;
  v5 = sin(v3);
  v21 = cos(v3);
  v19 = v5 + v5;
  *(float *)(a3 + 12) = v19;
  *(_DWORD *)(a3 + 16) = 0;
  v20 = v21 + v21;
  v6 = *(float *)a3;
  *(float *)(a3 + 20) = v20;
  v22 = v6;
  v23 = *(float *)(a3 + 4);
  v24 = *(float *)(a3 + 8);
  v25 = 1.0;
  v26 = 9.999999933815813e36;
  v7 = sub_45D190(dbl_B68610, (int)&v22);
  if ( v7 )
  {
    v15 = v27;
    v8 = *(float *)a3 - *v4;
    vars0 = v7;
    v22 = v8;
    v23 = *(float *)(a3 + 4);
    v24 = *(float *)(a3 + 8) - *(float *)(a3 + 20);
    v25 = 5.0;
    v26 = 9.999999933815813e36;
    v9 = sub_45D190(dbl_B68610, (int)&v22);
    if ( v9 )
      v16 = v27;
    else
      v16 = v15;
    v10 = *v4;
    vars0 = v9;
    v22 = v10 + *(float *)a3;
    v23 = *(float *)(a3 + 4);
    v24 = *(float *)(a3 + 20) + *(float *)(a3 + 8);
    v25 = 5.0;
    v26 = 9.999999933815813e36;
    if ( sub_45D190(dbl_B68610, (int)&v22) )
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
    *(float *)(a3 + 4) = v14 + 0.1;
    *(float *)(a3 + 16) = (v11 - v16) * 0.5;
  }
}
