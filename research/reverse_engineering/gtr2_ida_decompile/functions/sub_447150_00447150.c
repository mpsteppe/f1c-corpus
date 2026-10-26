int __thiscall sub_447150(_DWORD *this, int a2, float a3)
{
  _DWORD *v3; // edi
  int v4; // ebx
  long double v5; // st7
  long double v6; // st6
  double v7; // st6
  double v8; // st7
  int v9; // ecx
  double *v10; // esi
  double *v11; // eax
  _DWORD *v12; // ecx
  double *v13; // edx
  double *v14; // edi
  double *v15; // eax
  double v16; // st7
  double v17; // st6
  double v18; // st5
  double v19; // st7
  double v20; // st6
  double v21; // st5
  double v22; // st7
  double v23; // st6
  double v24; // st5
  bool v25; // cc
  double v26; // st7
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v31; // [esp+4h] [ebp-18h]
  int v33; // [esp+Ch] [ebp-10h]
  int v34; // [esp+10h] [ebp-Ch]
  double v35; // [esp+14h] [ebp-8h]

  v3 = this;
  v35 = a3 * 0.08726646259971647;
  v4 = (int)&this[320 * a2 + 178];
  BYTE1(this[320 * a2 + 292]) = 1;
  v5 = flt_BE08A4[(unsigned __int8)dword_BE08A0] * 3.141592653589793;
  v34 = v4;
  ++dword_BE08A0;
  v6 = sin(v5) * v35;
  if ( !a2 || a2 == 3 )
    *(long double *)&this[320 * a2 + 296] = v6 + *(double *)&this[320 * a2 + 296];
  else
    *(long double *)&this[320 * a2 + 296] = *(double *)&this[320 * a2 + 296] - v6;
  if ( *(double *)&this[320 * a2 + 296] >= -0.1745329251994329 )
  {
    if ( *(double *)&this[320 * a2 + 296] <= 0.1745329251994329 )
      goto LABEL_10;
    v7 = 0.1745329251994329;
  }
  else
  {
    v7 = -0.1745329251994329;
  }
  *(double *)&this[320 * a2 + 296] = v7;
LABEL_10:
  *(long double *)&this[320 * a2 + 298] = cos(v5) * v35 + *(double *)&this[320 * a2 + 298];
  if ( *(double *)&this[320 * a2 + 298] >= -0.1745329251994329 )
  {
    if ( *(double *)&this[320 * a2 + 298] <= 0.1745329251994329 )
      goto LABEL_15;
    v8 = 0.1745329251994329;
  }
  else
  {
    v8 = -0.1745329251994329;
  }
  *(double *)&this[320 * a2 + 298] = v8;
LABEL_15:
  sub_446A80();
  v33 = 0;
  if ( (int)v3[1565] > 0 )
  {
    v31 = 0;
    while ( 1 )
    {
      v9 = v3[1566];
      v10 = *(double **)(v4 + 352);
      v11 = *(double **)(v9 + v31 + 4);
      v12 = (_DWORD *)(v31 + v9);
      if ( v11 == v10 )
        break;
      if ( (double *)v12[3] == v10 )
      {
        v13 = (double *)v12[4];
        v14 = (double *)v12[2];
LABEL_21:
        if ( v13 && v14 )
        {
          v15 = *(double **)(v4 + 356);
          if ( (v31 == 112 || v31 == 168) && this[1458] )
            v15 = (double *)this[1458];
          v16 = v10[6] * v13[2] + v10[5] * v13[1] + *v13 * v10[4];
          v17 = v10[7] * *v13 + v10[9] * v13[2] + v10[8] * v13[1];
          v18 = v10[10] * *v13 + v10[12] * v13[2] + v10[11] * v13[1];
          *v14 = v18 * v15[10] + v17 * v15[7] + v16 * v15[4];
          v14[1] = v18 * v15[11] + v17 * v15[8] + v16 * v15[5];
          v14[2] = v18 * v15[12] + v17 * v15[9] + v16 * v15[6];
          v19 = v10[6] * v13[5] + v10[5] * v13[4] + v13[3] * v10[4];
          v20 = v10[7] * v13[3] + v10[9] * v13[5] + v10[8] * v13[4];
          v21 = v10[10] * v13[3] + v10[12] * v13[5] + v10[11] * v13[4];
          v14[3] = v21 * v15[10] + v20 * v15[7] + v19 * v15[4];
          v14[4] = v21 * v15[11] + v20 * v15[8] + v19 * v15[5];
          v14[5] = v21 * v15[12] + v20 * v15[9] + v19 * v15[6];
          v22 = v10[6] * v13[8] + v10[5] * v13[7] + v13[6] * v10[4];
          v23 = v10[7] * v13[6] + v10[9] * v13[8] + v10[8] * v13[7];
          v24 = v10[10] * v13[6] + v10[12] * v13[8] + v10[11] * v13[7];
          v14[6] = v24 * v15[10] + v23 * v15[7] + v22 * v15[4];
          v14[7] = v24 * v15[11] + v23 * v15[8] + v22 * v15[5];
          v14[8] = v24 * v15[12] + v23 * v15[9] + v22 * v15[6];
          sub_61D020();
          v4 = v34;
        }
        v3 = this;
      }
      v25 = ++v33 < v3[1565];
      v31 += 56;
      if ( !v25 )
        goto LABEL_30;
    }
    v13 = (double *)v12[2];
    v14 = (double *)v12[4];
    goto LABEL_21;
  }
LABEL_30:
  v26 = v35 + *(double *)(v4 + 488);
  *(double *)(v4 + 488) = v26;
  if ( v26 > 0.015 )
  {
    v27 = v3[2348];
    v28 = *(_DWORD *)(v27 + 19384);
    v29 = v27 + 19272;
    if ( !v28 )
      *(_DWORD *)(v29 + 112) = 4;
  }
  return sub_4FB7E0(v3[2348] + 14824, 1, 8);
}
