int __thiscall sub_61D2B0(_DWORD *this)
{
  double *v1; // eax
  double *v2; // edx
  double v3; // st7
  double *v4; // eax
  double *v5; // edx
  double v6; // st7
  int v7; // eax
  double *v8; // edx
  double v9; // st7
  int v10; // eax
  double v11; // st7
  double *v12; // edx
  double *v13; // ebp
  long double v14; // st7
  double v15; // rax
  double *v16; // ecx
  long double v18; // [esp+18h] [ebp-58h]
  double v19; // [esp+20h] [ebp-50h]
  long double v20; // [esp+20h] [ebp-50h]
  double v21; // [esp+40h] [ebp-30h]
  double v22; // [esp+48h] [ebp-28h]
  double v23; // [esp+50h] [ebp-20h]
  double v24; // [esp+58h] [ebp-18h]
  double v25; // [esp+60h] [ebp-10h]

  v1 = (double *)this[2];
  v2 = (double *)this[1];
  v3 = v2[6];
  v2 += 4;
  v1[3] = v3 * v1[2] + v2[1] * v1[1] + *v2 * *v1;
  v1[4] = v2[5] * v1[2] + v2[4] * v1[1] + v2[3] * *v1;
  v1[5] = v2[8] * v1[2] + v2[7] * v1[1] + v2[6] * *v1;
  v4 = (double *)this[4];
  v5 = (double *)this[3];
  v6 = v5[6];
  v5 += 4;
  v4[3] = v6 * v4[2] + v5[1] * v4[1] + *v5 * *v4;
  v4[4] = v5[5] * v4[2] + v5[4] * v4[1] + v5[3] * *v4;
  v4[5] = v5[8] * v4[2] + v5[7] * v4[1] + v5[6] * *v4;
  v7 = this[3];
  v8 = (double *)this[4];
  v9 = *(double *)(v7 + 8) + v8[3];
  v7 += 8;
  v8 += 3;
  v21 = v9;
  v22 = *(double *)(v7 + 8) + v8[1];
  v23 = *(double *)(v7 + 16) + v8[2];
  v10 = this[1];
  v11 = *(double *)(v10 + 8);
  v10 += 8;
  v12 = (double *)this[2];
  v24 = v11 + v12[3] - v21;
  v25 = v12[4] + *(double *)(v10 + 8) - v22;
  v19 = v12[5] + *(double *)(v10 + 16) - v23;
  v13 = v12 + 8;
  v14 = 1.0 / sqrt(v19 * v19 + v25 * v25 + v24 * v24);
  v15 = v24 * v14;
  *v13 = v24 * v14;
  v18 = v25 * v14;
  v13[1] = v18;
  v20 = v19 * v14;
  v13[2] = v20;
  v16 = (double *)(this[4] + 64);
  *v16 = v24 * v14;
  v16[1] = v18;
  v16[2] = v20;
  return LODWORD(v15);
}
