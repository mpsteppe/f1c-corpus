void __thiscall sub_448B50(_DWORD *this, int a2, double *a3)
{
  int v4; // edx
  unsigned int v5; // ecx
  double *v6; // ecx
  double *v7; // edx
  long double v8; // st7
  long double v9; // st7
  double v10; // st6
  double *v11; // edx
  double v12; // [esp+18h] [ebp-50h]
  double v13; // [esp+20h] [ebp-48h] BYREF
  long double v14; // [esp+28h] [ebp-40h]
  long double v15; // [esp+30h] [ebp-38h]
  double v16[3]; // [esp+38h] [ebp-30h] BYREF
  double v17[3]; // [esp+50h] [ebp-18h] BYREF

  if ( *(_BYTE *)a2 )
  {
    v4 = *(_DWORD *)(a2 + 108);
    LODWORD(v13) = *(_DWORD *)(a2 + 104);
    v5 = *(_DWORD *)(a2 + 112);
    HIDWORD(v13) = v4;
    v14 = COERCE_DOUBLE(__PAIR64__(*(_DWORD *)(a2 + 116), v5));
    v15 = *(double *)(a2 + 120);
    v6 = (double *)this[1578];
    v16[0] = v15 * v6[6] + v14 * v6[5] + v13 * v6[4];
    v16[1] = v15 * v6[9] + v13 * v6[7] + v14 * v6[8];
    v16[2] = v15 * v6[12] + v13 * v6[10] + v14 * v6[11];
    sub_43A590(v6, v16, &v13);
    v7 = (double *)this[1578];
    v8 = v15 * v7[10] + v14 * v7[7] + v13 * v7[4];
    v15 = v15 * v7[12] + v14 * v7[9] + v13 * v7[6];
    v9 = v8 - *a3;
    v10 = v15 - a3[2];
    if ( v10 < 0.0 )
    {
      v12 = v10 * v10;
      v13 = 0.0;
      v14 = sub_439470((double *)(a2 + 72), v9, v10) * *(double *)(a2 + 56) * v12;
      v15 = v12 * *(double *)(a2 + 64);
      sub_43A4D0(v11, &v13, v17);
      sub_619450(v16, v17);
    }
  }
}
