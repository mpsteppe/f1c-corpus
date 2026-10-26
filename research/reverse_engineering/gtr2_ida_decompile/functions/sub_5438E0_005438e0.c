void __thiscall sub_5438E0(int this, float a2, float *a3, float *a4, float a5, int a6, int a7)
{
  long double v9; // st7
  float *v10; // esi
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st6
  double v18; // st7
  double v19; // st7
  int v20; // edx
  float v21; // [esp+8h] [ebp-50h]
  float v22; // [esp+8h] [ebp-50h]
  float v23; // [esp+Ch] [ebp-4Ch]
  float v24; // [esp+Ch] [ebp-4Ch]
  float v25; // [esp+10h] [ebp-48h]
  float v26; // [esp+10h] [ebp-48h]
  float v27; // [esp+14h] [ebp-44h]
  float v28; // [esp+14h] [ebp-44h]
  float v29; // [esp+18h] [ebp-40h]
  float v30; // [esp+18h] [ebp-40h]
  float v31; // [esp+18h] [ebp-40h]
  float v32; // [esp+1Ch] [ebp-3Ch]
  float v33; // [esp+1Ch] [ebp-3Ch]
  float v34; // [esp+1Ch] [ebp-3Ch]
  double v35[6]; // [esp+20h] [ebp-38h] BYREF
  int v36; // [esp+50h] [ebp-8h]
  float v37; // [esp+64h] [ebp+Ch]

  v9 = sqrt(*a4 * *a4 + a4[1] * a4[1] + a4[2] * a4[2]);
  v37 = v9;
  if ( v9 >= 1.0 && *(int *)(this + 96) > 0 )
  {
    v10 = (float *)sub_5424A0();
    v11 = a2 + v10[7];
    v10[2] = a2;
    v10[3] = v11;
    v12 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 64.0;
    v13 = (v12 + 190.0) * a5;
    v10[10] = v13;
    if ( v37 < (double)*(float *)(this + 80) )
      v10[10] = v37 / *(float *)(this + 80) * v13;
    *((_DWORD *)v10 + 17) = a7;
    v14 = *(float *)(this + 84) / v37;
    v27 = *a4;
    v29 = a4[1];
    v32 = a4[2];
    v21 = *a3;
    v23 = a3[1];
    v25 = a3[2];
    v36 = a6;
    v30 = v29 * v14;
    v33 = v32 * v14;
    v15 = v27 * v14 + v21;
    v22 = v15;
    v16 = v15;
    v17 = v30 + v23;
    v26 = v33 + v25;
    v35[0] = v16;
    v35[1] = v17;
    v35[2] = v26;
    v35[3] = 0.25;
    v35[4] = 9.999999933815813e36;
    if ( sub_45D210(dbl_B68610, v35, v10 + 21) )
    {
      v18 = v35[5];
    }
    else
    {
      v10[21] = 0.0;
      v24 = v17;
      v18 = v24 - 0.25;
      v10[22] = 1.0;
      v10[23] = 0.0;
    }
    v10[12] = v18;
    v10[11] = v22;
    v10[13] = v26;
    v28 = *a4 * 0.1;
    v31 = a4[1] * 0.1;
    v19 = a4[2];
    v10[14] = v28;
    v10[15] = v31;
    v10[26] = v37;
    v20 = *((_DWORD *)v10 + 11);
    v34 = v19 * 0.1;
    v10[16] = v34;
    sub_5FCCB0(*(_DWORD *)v10, v20, *((_DWORD *)v10 + 12), *((_DWORD *)v10 + 13));
    sub_5FCD10(*(_DWORD *)v10, *(_DWORD *)(this + 12), *(_DWORD *)(this + 16), *(_DWORD *)(this + 20));
    sub_5FC760(*(_DWORD *)v10, byte_FFFFFF);
  }
}
