void __thiscall sub_4464A0(_DWORD *this, int a2, double *a3)
{
  int v3; // esi
  double v4; // st7
  double v5; // st6
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  long double v10; // st7
  double v11; // st6
  double v12; // [esp+10h] [ebp-50h]
  long double v13[2]; // [esp+18h] [ebp-48h] BYREF
  double v14; // [esp+28h] [ebp-38h]
  double v15; // [esp+30h] [ebp-30h] BYREF
  double v16; // [esp+38h] [ebp-28h]
  double v17; // [esp+40h] [ebp-20h]
  double v18[3]; // [esp+48h] [ebp-18h] BYREF

  if ( *(_BYTE *)a2 )
  {
    qmemcpy(v18, (const void *)(a2 + 100), sizeof(v18));
    v3 = this[1541];
    sub_438520((double *)(v3 + 28), v18, &v15);
    v4 = v17 * *(double *)(v3 + 132) - v16 * *(double *)(v3 + 140);
    v5 = v15 * *(double *)(v3 + 140) - v17 * *(double *)(v3 + 124);
    v18[2] = v16 * *(double *)(v3 + 124) - v15 * *(double *)(v3 + 132);
    v18[0] = v4 + *(double *)(v3 + 100);
    v18[1] = v5 + *(double *)(v3 + 108);
    v18[2] = v18[2] + *(double *)(v3 + 116);
    sub_43B1D0((double *)(v3 + 28), v18, v13);
    v13[0] = v13[0] - *a3;
    v6 = v14 - a3[2];
    v14 = v6;
    if ( v8 | v9 )
    {
      v12 = v6 * v6;
      v10 = sub_438B50((double *)(a2 + 68), v13[0], v14) * *(double *)(a2 + 52) * v12;
      v11 = *(double *)(a2 + 60) * v12;
      v18[0] = v11 * *(double *)(v3 + 44) + v10 * *(double *)(v3 + 36) + *(double *)(v3 + 28) * 0.0;
      v18[1] = v11 * *(double *)(v3 + 68) + v10 * *(double *)(v3 + 60) + *(double *)(v3 + 52) * 0.0;
      v18[2] = v11 * *(double *)(v3 + 92) + v10 * *(double *)(v3 + 84) + *(double *)(v3 + 76) * 0.0;
      sub_57C860(&v15, v18);
    }
  }
}
