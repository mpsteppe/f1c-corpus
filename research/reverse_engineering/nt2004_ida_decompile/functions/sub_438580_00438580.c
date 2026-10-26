void __thiscall sub_438580(char *this, int a2, double *a3, long double *a4)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  long double v8; // st7
  long double v9; // st6
  long double v10; // st5
  long double v11; // st7
  int v12; // edx
  int v13; // eax
  long double v14; // st7
  long double v15; // st7
  double v16; // [esp+10h] [ebp-A8h]
  double v17; // [esp+10h] [ebp-A8h]
  double v18; // [esp+10h] [ebp-A8h]
  double v19; // [esp+10h] [ebp-A8h]
  double v20; // [esp+18h] [ebp-A0h]
  double v21; // [esp+18h] [ebp-A0h]
  double v22; // [esp+18h] [ebp-A0h]
  double v23; // [esp+20h] [ebp-98h]
  double v24[5]; // [esp+70h] [ebp-48h] BYREF
  long double v25; // [esp+98h] [ebp-20h]
  double v26; // [esp+A0h] [ebp-18h]
  long double v27; // [esp+B0h] [ebp-8h]

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
  sub_4388F0(a2 + 4, *(_DWORD *)this + 4, a3);
  *a3 = *a3 - *(double *)(this + 4);
  a3[1] = a3[1] - *(double *)(this + 12);
  a3[2] = a3[2] - *(double *)(this + 20);
  v16 = flt_767F64;
  v5 = flt_767F64 * *a3;
  *a3 = v5;
  a3[1] = v16 * a3[1];
  a3[2] = v16 * a3[2];
  v20 = *(double *)(this + 52);
  v23 = *(double *)(this + 28);
  if ( v5 >= v23 )
  {
    if ( v5 > v20 )
      *a3 = v20;
  }
  else
  {
    *(_DWORD *)a3 = *((_DWORD *)this + 7);
    *((_DWORD *)a3 + 1) = HIDWORD(v23);
  }
  v6 = *(double *)(this + 36);
  v21 = *(double *)(this + 60);
  if ( v6 <= a3[1] )
  {
    if ( a3[1] > v21 )
      a3[1] = v21;
  }
  else
  {
    a3[1] = v6;
  }
  v7 = *(double *)(this + 44);
  v22 = *(double *)(this + 68);
  if ( v7 <= a3[2] )
  {
    if ( a3[2] > v22 )
      a3[2] = v22;
  }
  else
  {
    a3[2] = v7;
  }
  sub_57F4D0(v24);
  v8 = -asin(v25);
  *a4 = v8;
  if ( fabs(v25) == 1.0 )
  {
    v9 = -v26;
    *((_DWORD *)a4 + 4) = 0;
    v10 = v24[0];
    *((_DWORD *)a4 + 5) = 0;
    a4[1] = atan2(v9, v10);
  }
  else
  {
    a4[1] = atan2(v24[2], v27);
    a4[2] = atan2(v24[3], v24[4]);
  }
  v17 = flt_767F88 * v16;
  v11 = v8 * v17;
  *a4 = v11;
  a4[1] = v17 * a4[1];
  a4[2] = v17 * a4[2];
  v12 = *((_DWORD *)this + 25);
  if ( v11 < *(double *)(this + 100) )
  {
    v13 = *((_DWORD *)this + 26);
LABEL_22:
    *(_DWORD *)a4 = v12;
    *((_DWORD *)a4 + 1) = v13;
    goto LABEL_23;
  }
  if ( v11 > *(double *)(this + 124) )
  {
    v13 = *((_DWORD *)this + 32);
    v12 = *((_DWORD *)this + 31);
    goto LABEL_22;
  }
LABEL_23:
  v14 = *(double *)(this + 108);
  v18 = *(double *)(this + 132);
  if ( v14 <= a4[1] )
  {
    if ( a4[1] > v18 )
      a4[1] = v18;
  }
  else
  {
    a4[1] = v14;
  }
  v15 = *(double *)(this + 116);
  v19 = *(double *)(this + 140);
  if ( v15 <= a4[2] )
  {
    if ( a4[2] > v19 )
      a4[2] = v19;
  }
  else
  {
    a4[2] = v15;
  }
}
