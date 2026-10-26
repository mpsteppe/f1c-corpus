int __thiscall sub_442C90(char *this)
{
  char *v1; // esi
  char *v2; // ebx
  int v3; // ebp
  int v4; // ecx
  int v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // st5
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // st4
  double v17; // st5
  bool v18; // zf
  int v19; // eax
  double v20; // st4
  double v21; // st6
  double v22; // st7
  char v23; // al
  double v24; // st7
  double v25; // st7
  char v26; // al
  double v27; // st7
  double v28; // st7
  double *v29; // ebp
  char *v30; // ebx
  double v31; // st7
  int result; // eax
  int v33; // [esp+20h] [ebp-C0h]
  double v34; // [esp+20h] [ebp-C0h]
  double v35; // [esp+20h] [ebp-C0h]
  int v36; // [esp+20h] [ebp-C0h]
  double v37; // [esp+28h] [ebp-B8h]
  double v38; // [esp+28h] [ebp-B8h]
  double v39; // [esp+28h] [ebp-B8h]
  char *v41; // [esp+34h] [ebp-ACh]
  double v42[3]; // [esp+38h] [ebp-A8h] BYREF
  double v43[3]; // [esp+50h] [ebp-90h] BYREF
  double v44[3]; // [esp+68h] [ebp-78h] BYREF
  char v45; // [esp+80h] [ebp-60h] BYREF
  char v46; // [esp+90h] [ebp-50h] BYREF

  v1 = this;
  v41 = &v45;
  v2 = this + 1040;
  v33 = 4;
  do
  {
    if ( !v2[124] )
    {
      v3 = *((_DWORD *)v2 - 9);
      if ( !v3 )
        v3 = *((_DWORD *)v1 + 1287);
      Matrix3x3VectorMultiply((double *)(v3 + 28), (double *)v2 - 4, (double *)v2 - 1);
      v4 = *((_DWORD *)v1 + 1404);
      v42[0] = *((double *)v2 - 1) + *(double *)(v3 + 4);
      v42[1] = *(double *)(v3 + 12) + *(double *)v2;
      v42[2] = *(double *)(v3 + 20) + *((double *)v2 + 1);
      Matrix3x3VectorMultiply((double *)(v4 + 28), (double *)v2 + 2, (double *)v2 + 5);
      v5 = *((_DWORD *)v1 + 1404);
      v6 = *(double *)(v5 + 4) + *((double *)v2 + 5);
      v7 = *(double *)(v5 + 12) + *((double *)v2 + 6);
      v44[2] = *(double *)(v5 + 20) + *((double *)v2 + 7);
      v42[0] = v42[0] - v6;
      v8 = v42[1] - v7;
      v37 = sqrt((v42[2] - v44[2]) * (v42[2] - v44[2]) + v8 * v8 + v42[0] * v42[0]);
      v42[0] = v42[0] * (1.0 / v37);
      v9 = v8;
      v10 = 1.0 / v37;
      v42[1] = v9 * v10;
      v42[2] = (v42[2] - v44[2]) * v10;
      qmemcpy(v41, v42, 0x18u);
      v11 = *(double *)(v3 + 132) * *((double *)v2 + 1) - *(double *)(v3 + 140) * *(double *)v2;
      v12 = *(double *)(v3 + 140) * *((double *)v2 - 1) - *(double *)(v3 + 124) * *((double *)v2 + 1);
      v43[2] = *(double *)v2 * *(double *)(v3 + 124) - *(double *)(v3 + 132) * *((double *)v2 - 1);
      v43[0] = v11 + *(double *)(v3 + 100);
      v13 = v12 + *(double *)(v3 + 108);
      v14 = v43[2] + *(double *)(v3 + 116);
      v15 = *(double *)(v5 + 132) * *((double *)v2 + 7) - *(double *)(v5 + 140) * *((double *)v2 + 6);
      v16 = *(double *)(v5 + 140) * *((double *)v2 + 5) - *((double *)v2 + 7) * *(double *)(v5 + 124);
      v44[2] = *((double *)v2 + 6) * *(double *)(v5 + 124) - *(double *)(v5 + 132) * *((double *)v2 + 5);
      v44[0] = v15 + *(double *)(v5 + 100);
      v17 = v16 + *(double *)(v5 + 108);
      v44[2] = v44[2] + *(double *)(v5 + 116);
      v43[0] = v43[0] - v44[0];
      v43[1] = v13 - v17;
      ConstraintEnforce((double *)(v2 - 388), v37, v42[2] * (v14 - v44[2]) + v42[1] * v43[1] + v43[0] * v42[0]);
      v1 = this;
    }
    v2 += 1124;
    v18 = v33 == 1;
    v41 += 24;
    --v33;
  }
  while ( !v18 );
  if ( dword_7CE958 )
  {
    v19 = *((_DWORD *)v1 + 1404);
    v20 = *(double *)(v19 + 100) * *(double *)(v19 + 100)
        + *(double *)(v19 + 108) * *(double *)(v19 + 108)
        + *(double *)(v19 + 116) * *(double *)(v19 + 116);
    v21 = v20 * *((double *)v1 + 649);
    *((double *)v1 + 146) = v21 + *((double *)v1 + 146);
    *(double *)(v1 + 2292) = v21 + *(double *)(v1 + 2292);
    v22 = v20 * *((double *)v1 + 650);
    *((double *)v1 + 427) = v22 + *((double *)v1 + 427);
    *(double *)(v1 + 4540) = v22 + *(double *)(v1 + 4540);
  }
  if ( !v1[1164] && !v1[2288] )
  {
    v23 = v1[5216];
    v24 = (*(double *)(v1 + 1140) - *(double *)(v1 + 1156) - (*((double *)v1 + 283) - *((double *)v1 + 285)))
        * *((double *)v1 + 647);
    v38 = v24 + *((double *)v1 + 146);
    *((double *)v1 + 146) = v38;
    v34 = *(double *)(v1 + 2292) - v24;
    *(double *)(v1 + 2292) = v34;
    if ( v23 )
    {
      v25 = PiecewiseFunctionEval(
              (double *)(v1 + 5220),
              (*((double *)v1 + 283) + *(double *)(v1 + 1140)) * 0.5,
              (*((double *)v1 + 284) + *(double *)(v1 + 1148)) * 0.5)
          * 0.5;
      *((double *)v1 + 146) = v38 + v25;
      *(double *)(v1 + 2292) = v34 + v25;
    }
  }
  if ( !v1[3412] && !v1[4536] )
  {
    v26 = v1[5216];
    v27 = (*(double *)(v1 + 3388) - *(double *)(v1 + 3404) - (*((double *)v1 + 564) - *((double *)v1 + 566)))
        * *((double *)v1 + 648);
    v39 = v27 + *((double *)v1 + 427);
    *((double *)v1 + 427) = v39;
    v35 = *(double *)(v1 + 4540) - v27;
    *(double *)(v1 + 4540) = v35;
    if ( v26 )
    {
      v28 = PiecewiseFunctionEval(
              (double *)(v1 + 5340),
              (*((double *)v1 + 564) + *(double *)(v1 + 3388)) * 0.5,
              (*((double *)v1 + 565) + *(double *)(v1 + 3396)) * 0.5)
          * 0.5;
      *((double *)v1 + 427) = v39 + v28;
      *(double *)(v1 + 4540) = v35 + v28;
    }
  }
  v29 = (double *)&v46;
  v30 = v1 + 1004;
  v36 = 4;
  do
  {
    if ( !v30[160] )
    {
      v31 = *(double *)(v30 + 164);
      v43[0] = v31 * *(v29 - 2);
      v43[1] = v31 * *(v29 - 1);
      v43[2] = v31 * *v29;
      qmemcpy(v44, v43, sizeof(v44));
      AccumulateAngularMomentum(v30 + 28, v44);
      F_3DVectorSubtractWithCrossProduct(v30 + 76, v44);
    }
    v30 += 1124;
    v29 += 3;
    result = --v36;
  }
  while ( v36 );
  return result;
}
