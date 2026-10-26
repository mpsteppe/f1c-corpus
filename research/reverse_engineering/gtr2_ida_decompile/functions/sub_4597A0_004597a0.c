int __thiscall sub_4597A0(int *this)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  double v7; // st7
  int v8; // esi
  _DWORD *v9; // eax
  int v10; // ecx
  int result; // eax
  int v12; // ebx
  int v13; // ebp
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // esi
  float **v18; // eax
  float *v19; // edx
  float *v20; // ecx
  float *v21; // esi
  float *v22; // edx
  float *v23; // ecx
  double v24; // st7
  float *v25; // eax

  v2 = (_DWORD *)this[3];
  if ( v2 )
    sub_458E10(v2);
  v3 = (_DWORD *)this[4];
  if ( v3 )
    sub_458E10(v3);
  v4 = 0;
  if ( *this > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this[2];
      v7 = *(double *)(*(_DWORD *)(v6 + v5) + 24) + *(double *)(*(_DWORD *)(v6 + v5 + 8) + 24);
      v8 = *(_DWORD *)(v6 + v5 + 4);
      v9 = (_DWORD *)(v5 + v6);
      ++v4;
      v5 += 32;
      *(double *)(v8 + 8) = v7 * 0.5;
      *(double *)(v9[3] + 8) = (*(double *)(v9[4] + 24) + *(double *)(v9[2] + 24)) * 0.5;
      *(double *)(v9[5] + 8) = (*(double *)(v9[4] + 24) + *(double *)(*v9 + 24)) * 0.5;
    }
    while ( v4 < *this );
  }
  v10 = this[4];
  if ( v10 )
    sub_458E50(v10);
  result = *this;
  v12 = 0;
  if ( *this > 0 )
  {
    v13 = 0;
    do
    {
      v14 = this[2];
      v15 = *(_DWORD *)(v14 + v13);
      v16 = *(_DWORD *)(v14 + v13 + 8);
      v17 = *(_DWORD *)(v14 + v13 + 4);
      v18 = (float **)(v13 + v14);
      ++v12;
      v13 += 32;
      *(float *)v17 = (*(float *)v15 + *(float *)v16) * 0.5;
      *(double *)(v17 + 8) = (*(double *)(v15 + 8) + *(double *)(v16 + 8)) * 0.5;
      *(float *)(v17 + 16) = (*(float *)(v15 + 16) + *(float *)(v16 + 16)) * 0.5;
      v19 = v18[2];
      v20 = v18[4];
      v21 = v18[3];
      *v21 = (*v19 + *v20) * 0.5;
      *((double *)v21 + 1) = (*((double *)v19 + 1) + *((double *)v20 + 1)) * 0.5;
      v21[4] = (v19[4] + v20[4]) * 0.5;
      v22 = v18[4];
      v23 = *v18;
      v24 = *v22 + **v18;
      v25 = v18[5];
      *v25 = v24 * 0.5;
      *((double *)v25 + 1) = (*((double *)v22 + 1) + *((double *)v23 + 1)) * 0.5;
      v25[4] = (v22[4] + v23[4]) * 0.5;
      result = *this;
    }
    while ( v12 < *this );
  }
  return result;
}
