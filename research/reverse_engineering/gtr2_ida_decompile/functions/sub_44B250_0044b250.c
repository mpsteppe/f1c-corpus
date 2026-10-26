void __thiscall sub_44B250(double *this, int a2, double *a3, double *a4, char a5)
{
  int v6; // ecx
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // [esp+10h] [ebp-98h]
  double v16; // [esp+10h] [ebp-98h]
  double v17; // [esp+10h] [ebp-98h]
  double v18; // [esp+10h] [ebp-98h]
  double v19; // [esp+10h] [ebp-98h]
  double v20; // [esp+10h] [ebp-98h]
  double v21; // [esp+10h] [ebp-98h]
  _BYTE v22[72]; // [esp+60h] [ebp-48h] BYREF

  v6 = *(_DWORD *)this;
  if ( !v6 )
  {
    *a3 = 0.0;
    a3[1] = 0.0;
    a3[2] = 0.0;
    *a4 = 0.0;
    a4[1] = 0.0;
    a4[2] = 0.0;
    return;
  }
  sub_43A3E0((double *)(a2 + 32), (double *)(a2 + 8), (double *)(v6 + 8), a3);
  *a3 = *a3 - this[1];
  a3[1] = a3[1] - this[2];
  a3[2] = a3[2] - this[3];
  v7 = flt_B71584;
  v15 = flt_B71584;
  *a3 = flt_B71584 * *a3;
  a3[1] = v7 * a3[1];
  a3[2] = v7 * a3[2];
  sub_61C060(v22);
  sub_43A2B0((int)v22, (int)a4);
  v8 = flt_B715CC * v15;
  *a4 = v8 * *a4;
  a4[1] = v8 * a4[1];
  a4[2] = v8 * a4[2];
  if ( !a5 )
    return;
  v16 = this[7];
  v9 = this[4];
  if ( v9 <= *a3 )
  {
    if ( *a3 <= v16 )
      goto LABEL_8;
    v9 = v16;
  }
  *a3 = v9;
LABEL_8:
  v17 = this[8];
  v10 = this[5];
  if ( v10 <= a3[1] )
  {
    if ( a3[1] <= v17 )
      goto LABEL_12;
    v10 = v17;
  }
  a3[1] = v10;
LABEL_12:
  v18 = this[9];
  v11 = this[6];
  if ( v11 <= a3[2] )
  {
    if ( a3[2] <= v18 )
      goto LABEL_16;
    v11 = v18;
  }
  a3[2] = v11;
LABEL_16:
  v19 = this[16];
  v12 = this[13];
  if ( v12 <= *a4 )
  {
    if ( *a4 <= v19 )
      goto LABEL_20;
    v12 = v19;
  }
  *a4 = v12;
LABEL_20:
  v20 = this[17];
  v13 = this[14];
  if ( v13 > a4[1] )
  {
LABEL_23:
    a4[1] = v13;
    goto LABEL_24;
  }
  if ( a4[1] > v20 )
  {
    v13 = v20;
    goto LABEL_23;
  }
LABEL_24:
  v21 = this[18];
  v14 = this[15];
  if ( v14 <= a4[2] )
  {
    if ( a4[2] <= v21 )
      return;
    v14 = v21;
  }
  a4[2] = v14;
}
