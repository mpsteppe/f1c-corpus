void __thiscall sub_435E60(char *this, int a2, double *a3, long double *a4)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  long double v8; // st7
  long double v9; // st7
  long double v10; // st6
  long double v11; // st5
  long double v12; // st7
  int v13; // edx
  int v14; // eax
  long double v15; // st7
  long double v16; // st7
  double v17; // [esp+10h] [ebp-A8h]
  double v18; // [esp+10h] [ebp-A8h]
  double v19; // [esp+10h] [ebp-A8h]
  double v20; // [esp+10h] [ebp-A8h]
  double v21; // [esp+18h] [ebp-A0h]
  double v22; // [esp+18h] [ebp-A0h]
  double v23; // [esp+18h] [ebp-A0h]
  double v24; // [esp+20h] [ebp-98h]
  double v25[5]; // [esp+70h] [ebp-48h] BYREF
  long double v26; // [esp+98h] [ebp-20h]
  double v27; // [esp+A0h] [ebp-18h]
  long double v28; // [esp+B0h] [ebp-8h]

  if ( !*(_DWORD *)this )
  {
    *(_DWORD *)a3 = 0;
    *((_DWORD *)a3 + 1) = 0;
    *((_DWORD *)a3 + 2) = 0;
    *((_DWORD *)a3 + 3) = 0;
    *((_DWORD *)a3 + 4) = 0;
    *((_DWORD *)a3 + 5) = 0;
    *(_DWORD *)a4 = 0;
    *((_DWORD *)a4 + 1) = 0;
    *((_DWORD *)a4 + 2) = 0;
    *((_DWORD *)a4 + 3) = 0;
    *((_DWORD *)a4 + 4) = 0;
    *((_DWORD *)a4 + 5) = 0;
    return;
  }
  F_3DVectorTransformBy33Matrix(a2 + 4, *(_DWORD *)this + 4, a3);
  *a3 = *a3 - *(double *)(this + 4);
  a3[1] = a3[1] - *(double *)(this + 12);
  a3[2] = a3[2] - *(double *)(this + 20);
  v17 = flt_7CFB48;
  v5 = flt_7CFB48 * *a3;
  *a3 = v5;
  a3[1] = v17 * a3[1];
  a3[2] = v17 * a3[2];
  v21 = *(double *)(this + 52);
  v24 = *(double *)(this + 28);
  if ( v5 >= v24 )
  {
    if ( v5 > v21 )
      *a3 = v21;
  }
  else
  {
    *(_DWORD *)a3 = *((_DWORD *)this + 7);
    *((_DWORD *)a3 + 1) = HIDWORD(v24);
  }
  v6 = *(double *)(this + 36);
  v22 = *(double *)(this + 60);
  if ( v6 <= a3[1] )
  {
    if ( a3[1] > v22 )
      a3[1] = v22;
  }
  else
  {
    a3[1] = v6;
  }
  v7 = *(double *)(this + 44);
  v23 = *(double *)(this + 68);
  if ( v7 <= a3[2] )
  {
    if ( a3[2] > v23 )
      a3[2] = v23;
  }
  else
  {
    a3[2] = v7;
  }
  F_33MatrixMultiply(v25);
  v8 = v26;
  FloatConvertWrapper();
  v9 = -v8;
  *a4 = v9;
  if ( fabs(v26) == 1.0 )
  {
    v10 = -v27;
    *((_DWORD *)a4 + 4) = 0;
    v11 = v25[0];
    *((_DWORD *)a4 + 5) = 0;
    a4[1] = atan2(v10, v11);
  }
  else
  {
    a4[1] = atan2(v25[2], v28);
    a4[2] = atan2(v25[3], v25[4]);
  }
  v18 = flt_7CFB6C * v17;
  v12 = v9 * v18;
  *a4 = v12;
  a4[1] = v18 * a4[1];
  a4[2] = v18 * a4[2];
  v13 = *((_DWORD *)this + 25);
  if ( v12 < *(double *)(this + 100) )
  {
    v14 = *((_DWORD *)this + 26);
LABEL_22:
    *(_DWORD *)a4 = v13;
    *((_DWORD *)a4 + 1) = v14;
    goto LABEL_23;
  }
  if ( v12 > *(double *)(this + 124) )
  {
    v14 = *((_DWORD *)this + 32);
    v13 = *((_DWORD *)this + 31);
    goto LABEL_22;
  }
LABEL_23:
  v15 = *(double *)(this + 108);
  v19 = *(double *)(this + 132);
  if ( v15 <= a4[1] )
  {
    if ( a4[1] > v19 )
      a4[1] = v19;
  }
  else
  {
    a4[1] = v15;
  }
  v16 = *(double *)(this + 116);
  v20 = *(double *)(this + 140);
  if ( v16 <= a4[2] )
  {
    if ( a4[2] > v20 )
      a4[2] = v20;
  }
  else
  {
    a4[2] = v16;
  }
}

