void __thiscall sub_4F2BC0(int this, float a2, float *a3, float *a4, float a5, int a6, int a7, int a8)
{
  long double v10; // st7
  float *v11; // esi
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  float v16; // edx
  double v17; // st7
  double v18; // st7
  int v19; // ecx
  float v20; // [esp+8h] [ebp-4Ch]
  float v21; // [esp+8h] [ebp-4Ch]
  float v22; // [esp+Ch] [ebp-48h]
  float v23; // [esp+Ch] [ebp-48h]
  float v24; // [esp+10h] [ebp-44h]
  float v25; // [esp+14h] [ebp-40h]
  float v26; // [esp+14h] [ebp-40h]
  float v27; // [esp+18h] [ebp-3Ch]
  float v28; // [esp+18h] [ebp-3Ch]
  float v29; // [esp+18h] [ebp-3Ch]
  float v30; // [esp+1Ch] [ebp-38h]
  float v31; // [esp+1Ch] [ebp-38h]
  float v32; // [esp+1Ch] [ebp-38h]
  double v33[3]; // [esp+20h] [ebp-34h] BYREF
  int v34; // [esp+38h] [ebp-1Ch]
  int v35; // [esp+3Ch] [ebp-18h]
  int v36; // [esp+40h] [ebp-14h]
  int v37; // [esp+44h] [ebp-10h]
  double v38; // [esp+48h] [ebp-Ch]
  int v39; // [esp+50h] [ebp-4h]
  float v40; // [esp+60h] [ebp+Ch]

  v10 = sqrt(*a4 * *a4 + a4[1] * a4[1] + a4[2] * a4[2]);
  v40 = v10;
  if ( v10 >= 1.0 && *(int *)(this + 96) > 0 )
  {
    v11 = (float *)sub_4F2AE0((_DWORD *)this);
    v12 = a2 + v11[7];
    *((_DWORD *)v11 + 24) = a8 & 0xFFFFFF;
    v11[3] = v12;
    v11[2] = a2;
    v13 = flt_7D3C54[(unsigned __int8)dword_7D3C50++] * 64.0;
    v14 = (v13 + 190.0) * a5;
    v11[10] = v14;
    if ( v40 < (double)*(float *)(this + 80) )
      v11[10] = v40 / *(float *)(this + 80) * v14;
    *((_DWORD *)v11 + 17) = a7;
    v15 = *(float *)(this + 84) / v40;
    v25 = *a4;
    v27 = a4[1];
    v30 = a4[2];
    v16 = a3[2];
    v20 = *a3;
    v22 = a3[1];
    v34 = 0;
    v35 = 1070596096;
    v36 = 0x40000000;
    v37 = 1201543096;
    v39 = a6;
    v28 = v27 * v15;
    v31 = v30 * v15;
    v21 = v25 * v15 + v20;
    v23 = v28 + v22;
    v24 = v31 + v16;
    v33[0] = v21;
    v33[1] = v23;
    v33[2] = v24;
    if ( sub_44E990(dbl_760B48, v33, v11 + 21) )
    {
      v17 = v38;
    }
    else
    {
      v11[21] = 0.0;
      v17 = v23 - 0.25;
      v11[22] = 1.0;
      v11[23] = 0.0;
    }
    v11[11] = v21;
    v11[12] = v17;
    v11[13] = v24;
    v26 = *a4 * 0.1;
    v29 = a4[1] * 0.1;
    v18 = a4[2];
    v11[14] = v26;
    v11[15] = v29;
    v11[26] = v40;
    v19 = *((_DWORD *)v11 + 11);
    v32 = v18 * 0.1;
    v11[16] = v32;
    sub_5B0B40(*(_DWORD *)v11, v19, *((_DWORD *)v11 + 12), *((_DWORD *)v11 + 13));
    sub_5B0B90(*(_DWORD *)v11, *(_DWORD *)(this + 12), *(_DWORD *)(this + 16), *(_DWORD *)(this + 20));
    sub_5B0C30(*(_DWORD *)v11, *((_DWORD *)v11 + 24));
  }
}
