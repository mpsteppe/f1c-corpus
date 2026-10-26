void __thiscall sub_442060(int *this, int a2, float a3)
{
  int *v3; // edi
  int v4; // esi
  long double v5; // st7
  long double v6; // st6
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  _DWORD *v11; // eax
  double *v12; // ebx
  double *v13; // eax
  int v14; // esi
  double *v15; // edi
  double *v16; // esi
  bool v17; // cc
  double v18; // st7
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  double *v22; // [esp+4h] [ebp-38h]
  int v23; // [esp+8h] [ebp-34h]
  int v24; // [esp+Ch] [ebp-30h]
  _DWORD *v25; // [esp+10h] [ebp-2Ch]
  int v26; // [esp+14h] [ebp-28h]
  double v28; // [esp+1Ch] [ebp-20h]
  double v29; // [esp+24h] [ebp-18h] BYREF
  double v30; // [esp+2Ch] [ebp-10h]
  double v31; // [esp+34h] [ebp-8h]

  v3 = this;
  v28 = a3 * 0.08726646259971647;
  v4 = (int)&this[281 * a2 + 163];
  BYTE1(this[281 * a2 + 276]) = 1;
  v5 = flt_8AAE74[(unsigned __int8)dword_8AAE70] * 3.141592653589793;
  v26 = v4;
  ++dword_8AAE70;
  v6 = sin(v5) * v28;
  if ( !a2 || a2 == 3 )
    *(long double *)&this[281 * a2 + 279] = v6 + *(double *)&this[281 * a2 + 279];
  else
    *(long double *)&this[281 * a2 + 279] = *(double *)&this[281 * a2 + 279] - v6;
  if ( *(double *)&this[281 * a2 + 279] >= -0.1745329251994329 )
  {
    if ( *(double *)&this[281 * a2 + 279] <= 0.1745329251994329 )
      goto LABEL_10;
    this[281 * a2 + 280] = 1069963032;
  }
  else
  {
    this[281 * a2 + 280] = -1077520616;
  }
  this[281 * a2 + 279] = 1256670343;
LABEL_10:
  *(long double *)&this[281 * a2 + 281] = cos(v5) * v28 + *(double *)&this[281 * a2 + 281];
  if ( *(double *)&this[281 * a2 + 281] >= -0.1745329251994329 )
  {
    if ( *(double *)&this[281 * a2 + 281] <= 0.1745329251994329 )
      goto LABEL_15;
    this[281 * a2 + 282] = 1069963032;
  }
  else
  {
    this[281 * a2 + 282] = -1077520616;
  }
  this[281 * a2 + 281] = 1256670343;
LABEL_15:
  sub_441450(this);
  v7 = 0;
  v23 = 0;
  if ( v3[1391] > 0 )
  {
    v24 = 0;
    while ( 1 )
    {
      v8 = v3[1392];
      v9 = *(_DWORD *)(v4 + 348);
      v10 = *(_DWORD *)(v8 + v7 + 4);
      v11 = (_DWORD *)(v7 + v8);
      v25 = v11;
      if ( v10 == v9 )
        break;
      if ( v11[3] == v9 )
      {
        v12 = (double *)v11[4];
        v13 = (double *)v11[2];
        goto LABEL_21;
      }
LABEL_28:
      v7 += 48;
      v17 = ++v23 < v3[1391];
      v24 = v7;
      if ( !v17 )
        goto LABEL_29;
    }
    v12 = (double *)v11[2];
    v13 = (double *)v11[4];
LABEL_21:
    v22 = v13;
    if ( v12 && v13 )
    {
      v14 = *(_DWORD *)(v4 + 352);
      if ( (v7 == 96 || v7 == 144) && v3[1287] )
        v14 = v3[1287];
      v15 = (double *)(v9 + 28);
      sub_435E00((double *)(v9 + 28), v12, &v29);
      v16 = (double *)(v14 + 28);
      sub_4388D0(v16, &v29, v22);
      sub_435E00(v15, v12 + 3, &v29);
      v22[3] = v31 * v16[6] + v30 * v16[3] + v29 * *v16;
      v22[4] = v31 * v16[7] + v30 * v16[4] + v29 * v16[1];
      v22[5] = v31 * v16[8] + v30 * v16[5] + v29 * v16[2];
      v29 = v15[2] * v12[8] + v15[1] * v12[7] + *v15 * v12[6];
      v30 = v15[5] * v12[8] + v15[4] * v12[7] + v15[3] * v12[6];
      v31 = v15[8] * v12[8] + v15[7] * v12[7] + v15[6] * v12[6];
      v22[6] = v31 * v16[6] + v30 * v16[3] + v29 * *v16;
      v22[7] = v31 * v16[7] + v30 * v16[4] + v29 * v16[1];
      v22[8] = v31 * v16[8] + v30 * v16[5] + v29 * v16[2];
      sub_56D020(v25);
      v7 = v24;
      v4 = v26;
      v3 = this;
    }
    goto LABEL_28;
  }
LABEL_29:
  v18 = v28 + *(double *)(v4 + 480);
  *(double *)(v4 + 480) = v18;
  if ( v18 > 0.015 )
  {
    v19 = v3[1984];
    v20 = *(_DWORD *)(v19 + 16488);
    v21 = v19 + 16436;
    if ( !v20 )
      *(_DWORD *)(v21 + 52) = 4;
  }
}
