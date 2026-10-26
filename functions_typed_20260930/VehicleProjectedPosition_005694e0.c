double *__thiscall sub_5694E0(int this, double *a2, double *a3, double *a4, double *a5, double *a6)
{
  double v6; // st7
  double v7; // st6
  double *result; // eax
  double v9; // st5
  double v10; // st4
  double v11; // st3
  double v12; // st2
  double v13; // st7
  double v14; // [esp+0h] [ebp-48h]
  double v15; // [esp+8h] [ebp-40h]
  double v16; // [esp+10h] [ebp-38h]
  double v17; // [esp+18h] [ebp-30h]
  double v18; // [esp+20h] [ebp-28h]
  double v19; // [esp+28h] [ebp-20h]
  double v20; // [esp+38h] [ebp-10h]
  double v21; // [esp+40h] [ebp-8h]

  v6 = *a2 - *(double *)(this + 4);
  v7 = a2[1] - *(double *)(this + 12);
  result = a3;
  v9 = a2[2] - *(double *)(this + 20);
  v17 = v6 * *(double *)(this + 124) + *(double *)(this + 100);
  v18 = v7 * *(double *)(this + 132) + *(double *)(this + 108);
  v19 = v9 * *(double *)(this + 140) + *(double *)(this + 116);
  *a4 = v17 * *a3 + v18 * a3[1] + v19 * a3[2];
  v10 = v7 * result[2] - v9 * result[1];
  v11 = v9 * *result - v6 * result[2];
  v12 = v6 * result[1] - v7 * *result;
  v14 = v12 * *(double *)(this + 252) + v11 * *(double *)(this + 244) + v10 * *(double *)(this + 236);
  v15 = v12 * *(double *)(this + 276) + v11 * *(double *)(this + 268) + v10 * *(double *)(this + 260);
  v16 = v12 * *(double *)(this + 300) + v11 * *(double *)(this + 292) + v10 * *(double *)(this + 284);
  *a5 = (v15 * v9 - v16 * v7) * *a3
      + (v16 * v6 - v9 * v14) * a3[1]
      + (v7 * v14 - v15 * v6) * a3[2]
      + *(double *)(this + 180);
  if ( a6 )
  {
    v13 = *a4;
    v20 = v13 * a3[1];
    v21 = v13 * a3[2];
    *a6 = v17 - v13 * *a3;
    a6[1] = v18 - v20;
    a6[2] = v19 - v21;
  }
  return result;
}

