void __thiscall sub_457250(double **this, int a2)
{
  double *v3; // ecx
  int i; // ebx
  double *v5; // eax
  double *v6; // eax
  double *v7; // eax
  double *v8; // eax
  double *v9; // eax
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c2
  unsigned __int8 v17; // c0
  unsigned __int8 v18; // c2
  unsigned __int8 v20; // c0
  unsigned __int8 v21; // c2
  int v22; // ecx
  int v23; // edx
  double *v24; // eax
  double v25; // st7
  double *v26; // eax
  double v27; // st7
  double v28; // st6
  double v29; // st5
  double v30; // st4
  _DWORD *v31; // ecx
  double v32; // [esp+34h] [ebp-98h]
  double v33; // [esp+34h] [ebp-98h]
  double v34[12]; // [esp+54h] [ebp-78h] BYREF
  double v35[3]; // [esp+B4h] [ebp-18h] BYREF

  v3 = *this;
  if ( v3 )
  {
    v32 = v3[22] * -9.81;
    for ( i = 0; i < 0x10000; ++i )
    {
      v3[39] = 0.0;
      v3[40] = 0.0;
      v3[41] = 0.0;
      v3[42] = 0.0;
      v3[43] = 0.0;
      v3[44] = 0.0;
      v5 = *this + 39;
      *v5 = *v5;
      v5[1] = v32 + v5[1];
      v5[2] = v5[2];
      sub_43B3C0();
      sub_619590(0.00125);
      v6 = *this;
      v6[39] = 0.0;
      v6[40] = 0.0;
      v6[41] = 0.0;
      v6[42] = 0.0;
      v6[43] = 0.0;
      v6[44] = 0.0;
      v7 = *this + 39;
      *v7 = *v7;
      v7[1] = v32 + v7[1];
      v7[2] = v7[2];
      sub_43B3C0();
      sub_619760(0.0025);
      if ( 0.0025 < 1.0 )
      {
        sub_619A40(*this);
        sub_619590(0.0025 * 0.00125);
        v8 = *this;
        v8[39] = 0.0;
        v8[40] = 0.0;
        v8[41] = 0.0;
        v8[42] = 0.0;
        v8[43] = 0.0;
        v8[44] = 0.0;
        v9 = *this + 39;
        *v9 = *v9;
        v9[1] = v32 + v9[1];
        v9[2] = v9[2];
        sub_43B3C0();
        sub_619760(0.0025 * 0.0025);
      }
      v3 = *this;
      if ( v11 | v12 && v14 | v15 && v17 | v18 && v20 | v21 )
        break;
    }
    if ( i != 0x10000 )
    {
      sub_44B250((double *)this, a2, v34, v35, 0);
      sub_61B860(v35);
      v22 = 0;
      if ( (int)this[39] > 0 )
      {
        v23 = 0;
        do
        {
          v24 = this[40];
          v25 = v24[v23 + 7];
          v26 = &v24[v23];
          v27 = v25 - *((double *)this + 1);
          ++v22;
          v23 += 13;
          v28 = v26[8] - *((double *)this + 2);
          v29 = v26[9] - *((double *)this + 3);
          v33 = v34[10] * v29 + v34[7] * v28 + v34[4] * v27;
          v30 = v34[11] * v29 + v34[8] * v28 + v34[5] * v27;
          v26[7] = v34[9] * v29 + v34[6] * v28 + v34[3] * v27 + *((double *)this + 1);
          v26[8] = v33 + *((double *)this + 2);
          v26[9] = v30 + *((double *)this + 3);
          v26[7] = v26[7] - v34[0];
          v26[8] = v26[8] - v34[1];
          v26[9] = v26[9] - v34[2];
        }
        while ( v22 < (int)this[39] );
      }
      v31 = *this + 1;
      *v31 = this[2];
      v31[1] = this[3];
      v31[2] = this[4];
      v31[3] = this[5];
      v31[4] = this[6];
      v31[5] = this[7];
      sub_61B6E0(this + 20);
    }
  }
}
