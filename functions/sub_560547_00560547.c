int __cdecl sub_560547(_DWORD *a1, int a2, int a3, _DWORD *a4, int a5, int a6, int a7, int a8, int **a9, int a10)
{
  unsigned int v10; // ebx
  int v11; // ecx
  char *v12; // esi
  char *v13; // edi
  int v14; // eax
  int *v15; // ebp
  signed int v16; // edx
  signed int v17; // ebx
  int v18; // eax
  int *v19; // ebp
  int v20; // eax
  int v21; // edx
  int v22; // ebx
  unsigned int v23; // ecx
  unsigned int v24; // ecx
  int v25; // edx
  bool v26; // cc
  int v28; // [esp+4h] [ebp-4h]

  v10 = a3 * a1[8] + 2 * a2;
  v11 = a6 * a4[8] + 2 * a5;
  dword_5DD82C = a1[8];
  dword_5DD830 = a4[8];
  v12 = (char *)(v10 + *a1);
  v13 = (char *)(v11 + *a4);
  dword_5DD838 = a8;
  dword_5DD834 = a7;
  dword_5DD840 = a8 * a7;
  v14 = **a9;
  v15 = *a9 + 1;
  if ( v14 )
    v14 = -1;
  if ( !a10 )
    v14 = ~v14;
  dword_5DD83C = v14;
  v16 = 0;
  v17 = v10 >> 1;
  v18 = *v15;
  v19 = v15 + 1;
  for ( dword_5DD83C = ~dword_5DD83C; ; dword_5DD83C = ~dword_5DD83C )
  {
    v16 += v18;
    if ( v16 >= v17 )
      break;
    v18 = *v19++;
  }
  v20 = v16 - v17;
  v21 = 0;
  while ( dword_5DD840 > 0 )
  {
    if ( v20 > 0 )
    {
      if ( v20 + v21 >= dword_5DD834 )
        v20 = dword_5DD834 - v21;
      if ( dword_5DD83C )
      {
        v22 = 2 * v20;
        v23 = (unsigned int)(2 * v20) >> 2;
        if ( v23 )
        {
          qmemcpy(v13, v12, 4 * v23);
          v12 += 4 * v23;
          v13 += 4 * v23;
        }
        v24 = v22 & 3;
        if ( (v22 & 3) != 0 )
        {
          qmemcpy(v13, v12, v24);
          v12 += v24;
          v13 += v24;
        }
        v12 -= v22;
        v13 -= v22;
      }
      if ( v20 + v21 < dword_5DD834 )
      {
        v12 += v20 + v20;
        v13 += v20 + v20;
        v21 += v20;
      }
      else
      {
        v25 = 2 * v21;
        v12 = &v12[dword_5DD82C - v25];
        v13 = &v13[dword_5DD830 - v25];
        v21 = 0;
      }
      v26 = dword_5DD840 <= v20;
      dword_5DD840 -= v20;
      if ( v26 )
        break;
    }
    v20 = *v19++;
    dword_5DD83C = ~dword_5DD83C;
  }
  return v28;
}
