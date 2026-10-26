void __thiscall sub_4CB620(int this, float a2, float *a3, float *a4, float a5, int a6, int a7)
{
  long double v9; // st7
  float *v10; // esi
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  int v17; // eax
  float v18; // [esp+8h] [ebp-4Ch]
  float v19; // [esp+8h] [ebp-4Ch]
  float v20; // [esp+Ch] [ebp-48h]
  float v21; // [esp+Ch] [ebp-48h]
  float v22; // [esp+10h] [ebp-44h]
  float v23; // [esp+10h] [ebp-44h]
  float v24; // [esp+14h] [ebp-40h]
  float v25; // [esp+14h] [ebp-40h]
  float v26; // [esp+18h] [ebp-3Ch]
  float v27; // [esp+18h] [ebp-3Ch]
  float v28; // [esp+18h] [ebp-3Ch]
  float v29; // [esp+1Ch] [ebp-38h]
  float v30; // [esp+1Ch] [ebp-38h]
  float v31; // [esp+1Ch] [ebp-38h]
  double v32[3]; // [esp+20h] [ebp-34h] BYREF
  int v33; // [esp+38h] [ebp-1Ch]
  int v34; // [esp+3Ch] [ebp-18h]
  int v35; // [esp+40h] [ebp-14h]
  int v36; // [esp+44h] [ebp-10h]
  double v37; // [esp+48h] [ebp-Ch]
  int v38; // [esp+50h] [ebp-4h]
  float v39; // [esp+60h] [ebp+Ch]

  v9 = sqrt(*a4 * *a4 + a4[1] * a4[1] + a4[2] * a4[2]);
  v39 = v9;
  if ( v9 >= 1.0 && *(int *)(this + 88) > 0 )
  {
    v10 = (float *)sub_4CB540((_DWORD *)this);
    v11 = a2 + v10[7];
    v10[2] = a2;
    v10[3] = v11;
    v12 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 64.0;
    v13 = (v12 + 190.0) * a5;
    v10[10] = v13;
    if ( v39 < (double)*(float *)(this + 72) )
      v10[10] = v39 / *(float *)(this + 72) * v13;
    *((_DWORD *)v10 + 17) = a7;
    v14 = *(float *)(this + 76) / v39;
    v24 = *a4;
    v26 = a4[1];
    v29 = a4[2];
    v18 = *a3;
    v20 = a3[1];
    v22 = a3[2];
    v33 = 0;
    v34 = 1070596096;
    v35 = 0x40000000;
    v36 = 1201543096;
    v38 = a6;
    v27 = v26 * v14;
    v30 = v29 * v14;
    v19 = v24 * v14 + v18;
    v21 = v27 + v20;
    v23 = v30 + v22;
    v32[0] = v19;
    v32[1] = v21;
    v32[2] = v23;
    if ( sub_44C550(dbl_7C9360, v32, v10 + 21) )
    {
      v15 = v37;
    }
    else
    {
      v10[21] = 0.0;
      v15 = v21 - 0.25;
      v10[22] = 1.0;
      v10[23] = 0.0;
    }
    v10[11] = v19;
    v10[12] = v15;
    v10[13] = v23;
    v25 = *a4 * 0.1;
    v28 = a4[1] * 0.1;
    v16 = a4[2];
    v10[14] = v25;
    v10[15] = v28;
    v10[26] = v39;
    v17 = *((_DWORD *)v10 + 11);
    v31 = v16 * 0.1;
    v10[16] = v31;
    sub_558C60(*(_DWORD *)v10, v17, *((_DWORD *)v10 + 12), *((_DWORD *)v10 + 13));
    sub_558CB0(*(_DWORD *)v10, *(_DWORD *)(this + 12), *(_DWORD *)(this + 16), *(_DWORD *)(this + 20));
    sub_558CF0(*(_DWORD *)v10, 0xFFFFFF);
  }
}
