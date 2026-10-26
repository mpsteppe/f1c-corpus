int __thiscall sub_61DE90(int *this)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ebp
  double v9; // st7
  _DWORD *v10; // ecx
  double v11; // st6
  double v12; // st5
  double v13; // st4
  double v14; // st3
  double v15; // st2
  double *v16; // eax
  double *v17; // eax
  double v18; // rt1
  double v19; // st6
  double *v20; // eax
  int v21; // ebx
  int v22; // ebp
  int v23; // edi
  int v24; // eax
  double v25; // st7
  int v26; // edi
  double v27[3]; // [esp+1Ch] [ebp-30h] BYREF
  double v28; // [esp+34h] [ebp-18h]
  double v29; // [esp+3Ch] [ebp-10h]
  double v30; // [esp+44h] [ebp-8h]

  if ( this[2] > 0 )
    return off_16C97B0();
  v3 = 0;
  if ( this[4] > 0 )
  {
    v4 = 0;
    do
    {
      v5 = this[5];
      v6 = *(_DWORD *)(v5 + v4 + 8);
      v7 = *(_DWORD *)(v6 + 124);
      v8 = this[11];
      v9 = *(double *)(v8 + 8 * v7);
      v10 = (_DWORD *)(v4 + v5);
      v11 = *(double *)(v8 + 8 * v7 + 8);
      v4 += 56;
      v12 = v11 * *(double *)(v6 + 96) + v9 * *(double *)(v6 + 72);
      v13 = v11 * *(double *)(v6 + 104) + v9 * *(double *)(v6 + 80);
      v14 = v11 * *(double *)(v6 + 112);
      v15 = v9 * *(double *)(v6 + 88);
      v16 = (double *)(v10[1] + 336);
      v30 = v14 + v15;
      *v16 = v12 + *v16;
      v16[1] = v13 + v16[1];
      v16[2] = v30 + v16[2];
      v17 = (double *)v10[4];
      v28 = v11 * v17[12] + v9 * v17[9];
      v29 = v11 * v17[13] + v9 * v17[10];
      v18 = v11 * v17[14];
      v19 = v9 * v17[11];
      v20 = (double *)(v10[3] + 336);
      ++v3;
      *v20 = *v20 - v28;
      v20[1] = v20[1] - v29;
      v20[2] = v20[2] - (v18 + v19);
    }
    while ( v3 < this[4] );
  }
  result = this[6];
  v21 = 0;
  if ( result > 0 )
  {
    v22 = 0;
    do
    {
      v23 = this[7];
      v24 = *(_DWORD *)(v23 + v22 + 8);
      v25 = *(double *)(this[11] + 8 * *(_DWORD *)(v24 + 48));
      v26 = v22 + v23;
      v27[0] = v25 * *(double *)(v24 + 64);
      v27[1] = v25 * *(double *)(v24 + 72);
      v27[2] = v25 * *(double *)(v24 + 80);
      sub_619450(*(double **)(v26 + 4), (double *)(v24 + 24), v27);
      sub_6194F0(*(double **)(v26 + 12), (double *)(*(_DWORD *)(v26 + 16) + 24), v27);
      result = this[6];
      ++v21;
      v22 += 80;
    }
    while ( v21 < result );
  }
  return result;
}
