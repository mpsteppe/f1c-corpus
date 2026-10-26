unsigned __int64 __thiscall sub_441760(int this, int a2, int a3)
{
  double *v4; // eax
  double v5; // st7
  double v6; // st6
  double v7; // st5
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double *v11; // edx
  double v12; // st7
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  long double v16; // st7
  double v17; // st7
  long double v18; // st6
  unsigned __int64 result; // rax
  double v20; // kr18_8
  long double v21; // [esp+90h] [ebp-80h]
  double v22; // [esp+98h] [ebp-78h]
  double v23; // [esp+A0h] [ebp-70h]
  double v24; // [esp+A8h] [ebp-68h]
  double v25; // [esp+B0h] [ebp-60h]
  double v26; // [esp+B8h] [ebp-58h]
  double v27; // [esp+C0h] [ebp-50h]
  double v28; // [esp+C8h] [ebp-48h]
  double v29; // [esp+C8h] [ebp-48h]
  double v30; // [esp+D0h] [ebp-40h]
  double v31; // [esp+D0h] [ebp-40h]
  double v32; // [esp+D8h] [ebp-38h]
  double v33; // [esp+D8h] [ebp-38h]
  double v34; // [esp+E0h] [ebp-30h]
  double v35; // [esp+E8h] [ebp-28h]
  double v36; // [esp+F0h] [ebp-20h]

  sub_441010((int)"fl_steering");
  sub_441010((int)"fr_steering");
  v4 = *(double **)(this + 6312);
  v5 = v28 - v4[1];
  v6 = v30 - v4[2];
  v7 = v32 - v4[3];
  v34 = v7 * v4[10] + v6 * v4[7] + v5 * v4[4];
  v35 = v7 * v4[11] + v6 * v4[8] + v5 * v4[5];
  v36 = v7 * v4[12] + v6 * v4[9] + v5 * v4[6];
  v8 = v25 - v4[1];
  v9 = v26 - v4[2];
  v10 = v27 - v4[3];
  v29 = v10 * v4[10] + v9 * v4[7] + v8 * v4[4];
  v11 = *(double **)(this + 6400);
  v31 = v10 * v4[11] + v9 * v4[8] + v8 * v4[5];
  v33 = v10 * v4[12] + v9 * v4[9] + v8 * v4[6];
  *(double *)(this + 6384) = *(double *)*(_DWORD *)(this + 6380);
  *(double *)(this + 6408) = *v11;
  *(double *)(this + 112) = (double)*(int *)(a2 + 5252) * *(double *)(a2 + 5240) + *(double *)(a2 + 5232);
  v12 = (double)(*(_DWORD *)(a2 + 5248) - 1) * *(double *)(a2 + 5240) + *(double *)(a2 + 5232);
  *(double *)(this + 96) = v12;
  if ( v14 | v15 )
    *(double *)(this + 104) = 0.0;
  else
    *(double *)(this + 104) = 1.0 / v12;
  *(double *)(this + 120) = *(double *)(this + 104) * *(double *)(this + 112);
  v21 = fabs(sin(*(double *)(this + 96)));
  *(double *)(this + 168) = *(double *)(this + 96) * -0.5;
  *(double *)(this + 184) = 0.0;
  sub_441010((int)"fl_fore_upper");
  sub_441010((int)"fl_fore_lower");
  v16 = 1.0 / sqrt((v24 - v27) * (v24 - v27) + (v23 - v26) * (v23 - v26) + (v22 - v25) * (v22 - v25));
  *(long double *)(this + 6392) = ((v36 - v24) * ((v22 - v25) * v16 * 0.0 - (v23 - v26) * v16 * -1.0)
                                 + (v35 - v23) * ((v24 - v27) * v16 * -1.0 - (v22 - v25) * v16 * 0.0)
                                 + ((v23 - v26) * v16 * 0.0 - (v24 - v27) * v16 * 0.0) * (v34 - v22))
                                * v21;
  sub_441010((int)"fr_fore_upper");
  sub_441010((int)"fr_fore_lower");
  v17 = v22 - v25;
  v18 = 1.0 / sqrt((v24 - v27) * (v24 - v27) + (v23 - v26) * (v23 - v26) + v17 * v17);
  v20 = v33 - v24;
  result = __PAIR64__(LODWORD(v20), HIDWORD(v20));
  *(long double *)(this + 6416) = ((v33 - v24) * (v18 * v17 * 0.0 - (v23 - v26) * v18 * -1.0)
                                 + (v31 - v23) * ((v24 - v27) * v18 * -1.0 - v18 * v17 * 0.0)
                                 + ((v23 - v26) * v18 * 0.0 - (v24 - v27) * v18 * 0.0) * (v29 - v22))
                                * v21;
  return result;
}
