int __thiscall sub_449700(int *this)
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
  int v14; // esi
  int v15; // ecx
  int v16; // edx
  int v17; // esi

  v2 = (_DWORD *)this[3];
  if ( v2 )
    sub_448DA0(v2);
  v3 = (_DWORD *)this[4];
  if ( v3 )
    sub_448DA0(v3);
  v4 = 0;
  if ( *this > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this[2];
      v7 = *(double *)(*(_DWORD *)(v6 + v5) + 16) + *(double *)(*(_DWORD *)(v6 + v5 + 8) + 16);
      v8 = *(_DWORD *)(v6 + v5 + 4);
      v9 = (_DWORD *)(v5 + v6);
      ++v4;
      v5 += 32;
      *(double *)(v8 + 4) = v7 * 0.5;
      *(double *)(v9[3] + 4) = (*(double *)(v9[4] + 16) + *(double *)(v9[2] + 16)) * 0.5;
      *(double *)(v9[5] + 4) = (*(double *)(v9[4] + 16) + *(double *)(*v9 + 16)) * 0.5;
    }
    while ( v4 < *this );
  }
  v10 = this[4];
  if ( v10 )
    sub_448DE0(v10);
  result = *this;
  v12 = 0;
  if ( *this > 0 )
  {
    v13 = 0;
    do
    {
      v14 = this[2];
      v15 = *(_DWORD *)(v14 + v13 + 8);
      v16 = *(_DWORD *)(v14 + v13);
      v17 = v13 + v14;
      sub_448480(*(char **)(v17 + 4), v16, v15);
      sub_448480(*(char **)(v17 + 12), *(_DWORD *)(v17 + 8), *(_DWORD *)(v17 + 16));
      sub_448480(*(char **)(v17 + 20), *(_DWORD *)(v17 + 16), *(_DWORD *)v17);
      result = *this;
      ++v12;
      v13 += 32;
    }
    while ( v12 < *this );
  }
  return result;
}
