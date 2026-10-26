int __thiscall sub_56EE40(_DWORD *this)
{
  int v2; // ebx
  int v3; // ebp
  int v4; // edi
  _DWORD *v5; // eax
  int v6; // edx
  int *v7; // edi
  unsigned int v8; // ecx
  unsigned int v9; // edx
  int v10; // edx
  int v11; // edi
  int v12; // ebx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // ebp
  double v17; // st7
  _DWORD *v18; // ecx
  double v19; // st6
  double v20; // st5
  double v21; // st4
  double v22; // st3
  double v23; // st2
  double *v24; // eax
  double *v25; // eax
  double v26; // rt1
  double v27; // st6
  double *v28; // eax
  int result; // eax
  int v30; // ebx
  int v31; // ebp
  int v32; // edi
  int v33; // eax
  double v34; // st7
  int *v35; // edi
  double v36; // [esp+10h] [ebp-30h] BYREF
  double v37; // [esp+18h] [ebp-28h]
  double v38; // [esp+20h] [ebp-20h]
  double v39; // [esp+28h] [ebp-18h]
  double v40; // [esp+30h] [ebp-10h]
  double v41; // [esp+38h] [ebp-8h]

  v2 = 0;
  if ( (int)this[2] > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this[3];
      v5 = (_DWORD *)(this[11] + 8 * *(_DWORD *)(*(_DWORD *)(v4 + v3 + 8) + 48));
      v6 = v5[1];
      v7 = (int *)(v3 + v4);
      LODWORD(v36) = *v5;
      HIDWORD(v36) = v6;
      v8 = v5[2];
      v9 = v5[3];
      v5 += 2;
      v37 = COERCE_DOUBLE(__PAIR64__(v9, v8));
      v10 = v5[3];
      LODWORD(v38) = v5[2];
      HIDWORD(v38) = v10;
      AccumulateAngularMomentum(v7[1], (double *)(v7[2] + 24), &v36);
      F_3DVectorSubtractWithCrossProduct(v7[3], (double *)(v7[4] + 24), &v36);
      ++v2;
      v3 += 48;
    }
    while ( v2 < this[2] );
  }
  v11 = 0;
  if ( (int)this[4] > 0 )
  {
    v12 = 0;
    do
    {
      v13 = this[5];
      v14 = *(_DWORD *)(v13 + v12 + 8);
      v15 = *(_DWORD *)(v14 + 124);
      v16 = this[11];
      v17 = *(double *)(v16 + 8 * v15);
      v18 = (_DWORD *)(v12 + v13);
      v19 = *(double *)(v16 + 8 * v15 + 8);
      v12 += 48;
      v20 = v19 * *(double *)(v14 + 96) + v17 * *(double *)(v14 + 72);
      v21 = v19 * *(double *)(v14 + 104) + v17 * *(double *)(v14 + 80);
      v22 = v19 * *(double *)(v14 + 112);
      v23 = v17 * *(double *)(v14 + 88);
      v24 = (double *)(v18[1] + 332);
      v41 = v22 + v23;
      *v24 = v20 + *v24;
      v24[1] = v21 + v24[1];
      v24[2] = v41 + v24[2];
      v25 = (double *)v18[4];
      v39 = v19 * v25[12] + v17 * v25[9];
      v40 = v19 * v25[13] + v17 * v25[10];
      v26 = v19 * v25[14];
      v27 = v17 * v25[11];
      v28 = (double *)(v18[3] + 332);
      ++v11;
      *v28 = *v28 - v39;
      v28[1] = v28[1] - v40;
      v28[2] = v28[2] - (v26 + v27);
    }
    while ( v11 < this[4] );
  }
  result = this[6];
  v30 = 0;
  if ( result > 0 )
  {
    v31 = 0;
    do
    {
      v32 = this[7];
      v33 = *(_DWORD *)(v32 + v31 + 8);
      v34 = *(double *)(this[11] + 8 * *(_DWORD *)(v33 + 48));
      v35 = (int *)(v31 + v32);
      v36 = v34 * *(double *)(v33 + 64);
      v37 = v34 * *(double *)(v33 + 72);
      v38 = v34 * *(double *)(v33 + 80);
      AccumulateAngularMomentum(v35[1], (double *)(v33 + 24), &v36);
      F_3DVectorSubtractWithCrossProduct(v35[3], (double *)(v35[4] + 24), &v36);
      result = this[6];
      ++v30;
      v31 += 72;
    }
    while ( v30 < result );
  }
  return result;
}
