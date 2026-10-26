int __thiscall sub_446D80(int this)
{
  double *v2; // ecx
  double *v3; // eax
  double v4; // st7
  double v5; // st6
  long double v6; // st5
  long double v7; // st4
  double v8; // st3
  double v10; // [esp+20h] [ebp-70h]
  double v11; // [esp+28h] [ebp-68h]
  double v12; // [esp+30h] [ebp-60h]
  double v13; // [esp+30h] [ebp-60h]
  double v14; // [esp+38h] [ebp-58h]
  long double v15; // [esp+40h] [ebp-50h] BYREF
  long double v16; // [esp+48h] [ebp-48h]
  double v17; // [esp+50h] [ebp-40h]
  long double v18; // [esp+58h] [ebp-38h]
  long double v19; // [esp+60h] [ebp-30h] BYREF
  long double v20; // [esp+68h] [ebp-28h]
  double v21; // [esp+70h] [ebp-20h]
  double v22; // [esp+78h] [ebp-18h] BYREF
  double v23; // [esp+80h] [ebp-10h]
  double v24; // [esp+88h] [ebp-8h]

  v2 = *(double **)(this + 6312);
  v22 = v2[6] * *(double *)(this + 504) + v2[5] * *(double *)(this + 496) + v2[4] * *(double *)(this + 488);
  v23 = v2[7] * *(double *)(this + 488) + v2[9] * *(double *)(this + 504) + v2[8] * *(double *)(this + 496);
  v24 = v2[10] * *(double *)(this + 488) + v2[12] * *(double *)(this + 504) + v2[11] * *(double *)(this + 496);
  v10 = v22 + v2[1];
  v11 = v23 + v2[2];
  v12 = v24 + v2[3];
  sub_43A590(v2, &v22, &v15);
  v3 = *(double **)(this + 512);
  v4 = v10 - v3[1];
  v5 = v11 - v3[2];
  v13 = v12 - v3[3];
  v6 = v15 - v3[13];
  v7 = v16 - v3[14];
  v17 = v17 - v3[15];
  v8 = v3[22];
  v14 = v8 * *(double *)(this + 520);
  v18 = sqrt(v14 * v8) * *(double *)(this + 528);
  v15 = v6 * v18;
  v16 = v7 * v18;
  v17 = v17 * v18;
  v19 = v15 + v4 * v14;
  v20 = v7 * v18 + v5 * v14;
  v21 = v17 + v13 * v14;
  v3[39] = v19 + v3[39];
  v3[40] = v20 + v3[40];
  v3[41] = v21 + v3[41];
  return sub_6194F0(&v22, &v19);
}
