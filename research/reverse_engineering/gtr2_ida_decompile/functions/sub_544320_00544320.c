int __thiscall sub_544320(int this)
{
  double v2; // st7
  int result; // eax
  int v4; // ebx
  int v5; // ecx
  float *v6; // esi
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st7
  double v12; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c3
  double v15; // st7
  int v16; // eax
  int v17; // ebx
  int v18; // edx
  float v19; // eax
  float v20; // [esp+0h] [ebp-44h]
  float v21; // [esp+14h] [ebp-30h]
  float v22; // [esp+18h] [ebp-2Ch]
  int v23; // [esp+1Ch] [ebp-28h]
  float v24; // [esp+20h] [ebp-24h]
  float v25; // [esp+24h] [ebp-20h]
  float v26; // [esp+28h] [ebp-1Ch]
  float v27; // [esp+38h] [ebp-Ch]
  float v28; // [esp+3Ch] [ebp-8h]
  float v29; // [esp+40h] [ebp-4h]

  if ( dword_BE1204 == 2 )
    v2 = sub_5210A0(&dword_BE120C);
  else
    v2 = dbl_FB1D18;
  result = *(_DWORD *)(this + 108);
  v4 = 0;
  v22 = v2;
  v23 = 0;
  if ( result > 0 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(this + 112);
      v6 = *(float **)(v5 + 4 * v4);
      if ( v22 > (double)v6[3] || v22 < (double)v6[2] )
      {
        v18 = *(_DWORD *)(this + 108) - 1;
        *(_DWORD *)(this + 108) = v18;
        *(_DWORD *)(v5 + 4 * *((_DWORD *)v6 + 1)) = *(_DWORD *)(v5 + 4 * v18);
        *(float *)(*(_DWORD *)(*(_DWORD *)(this + 112) + 4 * *((_DWORD *)v6 + 1)) + 4) = v6[1];
        v19 = *v6;
        v6[1] = NAN;
        sub_5FCB20(LODWORD(v19));
        v17 = v4 - 1;
        goto LABEL_20;
      }
      v21 = v22 - v6[2];
      if ( dword_BE1204 == 2 )
        v7 = sub_5210D0(&dword_BE120C) == 5 ? 0.0 : sub_5210C0(&dword_BE120C);
      else
        v7 = dbl_FB1D10;
      v6[11] = v7 * v6[14] + v6[11];
      v6[12] = v7 * v6[15] + v6[12];
      v8 = v7;
      v9 = 1.0 - 1.5 * v7;
      v6[13] = v8 * v6[16] + v6[13];
      v6[14] = v9 * v6[14];
      v6[16] = v9 * v6[16];
      v10 = v21 * v6[26];
      v24 = v10 * *(float *)(this + 24);
      v25 = v10 * *(float *)(this + 28);
      v26 = v10 * *(float *)(this + 32);
      v27 = v24 + *(float *)(this + 12);
      v28 = v25 + *(float *)(this + 16);
      v29 = v26 + *(float *)(this + 20);
      sub_5FCCB0(*(_DWORD *)v6, *((_DWORD *)v6 + 11), *((_DWORD *)v6 + 12), *((_DWORD *)v6 + 13));
      sub_5FCD10(*(_DWORD *)v6, LODWORD(v27), LODWORD(v28), LODWORD(v29));
      v12 = v21;
      if ( !(v13 | v14) )
        break;
      if ( v12 <= v6[5] )
      {
        v15 = v21 * v6[8];
        goto LABEL_17;
      }
      v16 = sub_4015C0(v6[10]);
LABEL_18:
      sub_5FC760(*(_DWORD *)v6, &byte_FFFFFF[0x1000000 * v16]);
      v17 = v23;
LABEL_20:
      result = *(_DWORD *)(this + 108);
      v4 = v17 + 1;
      v23 = v4;
      if ( v4 >= result )
        return result;
    }
    v15 = 1.0 - (v12 - v6[6]) * v6[9];
LABEL_17:
    v20 = v15 * v6[10];
    v16 = sub_4015C0(v20);
    goto LABEL_18;
  }
  return result;
}
