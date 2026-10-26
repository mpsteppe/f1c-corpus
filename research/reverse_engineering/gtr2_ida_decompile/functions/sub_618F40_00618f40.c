double *__thiscall sub_618F40(double *this, double *a2, double *a3, double *a4, double *a5, double *a6)
{
  double v7; // st4
  double v8; // st3
  double *result; // eax
  unsigned int v10; // ecx
  unsigned int v11; // edx
  double v12; // [esp+18h] [ebp-60h]
  double v13; // [esp+20h] [ebp-58h]
  double v14; // [esp+20h] [ebp-58h]
  double v15; // [esp+28h] [ebp-50h]
  double v16; // [esp+30h] [ebp-48h]
  double v17; // [esp+38h] [ebp-40h]
  double v18; // [esp+40h] [ebp-38h]
  double v19; // [esp+48h] [ebp-30h] BYREF
  double v20; // [esp+50h] [ebp-28h]
  double v21; // [esp+58h] [ebp-20h]
  int v22[2]; // [esp+60h] [ebp-18h] BYREF
  double v23; // [esp+68h] [ebp-10h]
  double v24; // [esp+70h] [ebp-8h]

  v12 = *a2 - this[1];
  v13 = a2[1] - this[2];
  v15 = a2[2] - this[3];
  v7 = v12 * this[16];
  v8 = v13 * this[17];
  v24 = v15 * this[18];
  v16 = v7 + this[13];
  v17 = v8 + this[14];
  v18 = v24 + this[15];
  *a4 = v16 * *a3 + v17 * a3[1] + v18 * a3[2];
  *(double *)v22 = v13 * a3[2] - v15 * a3[1];
  v23 = v15 * *a3 - v12 * a3[2];
  v24 = v12 * a3[1] - v13 * *a3;
  result = sub_46FE60(this, (double *)v22, &v19);
  *a5 = (v20 * v15 - v21 * v13) * *a3 + (v21 * v12 - v15 * v19) * a3[1] + (v19 * v13 - v20 * v12) * a3[2] + this[23];
  if ( a6 )
  {
    result = sub_43A250(a3, (double *)v22, *a4);
    v14 = result[1];
    v10 = *((_DWORD *)result + 4);
    v11 = *((_DWORD *)result + 5);
    *a6 = v16 - *result;
    a6[1] = v17 - v14;
    a6[2] = v18 - COERCE_DOUBLE(__PAIR64__(v11, v10));
  }
  return result;
}
