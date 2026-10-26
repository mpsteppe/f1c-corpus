int __stdcall sub_6D6180(int *a1)
{
  int *v1; // edi
  int result; // eax
  int v3; // esi
  int v4; // eax
  unsigned __int16 *v5; // ebx
  char *v6; // esi
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  unsigned __int16 *v10; // ecx
  __int16 *v11; // edi
  _WORD *v12; // eax
  int v13; // edx
  int v14; // ebx
  int v15; // esi
  int v16; // ebx
  int v17; // esi
  int v18; // ebx
  float *v19; // ecx
  double *v20; // edx
  unsigned __int16 *v21; // eax
  int v22; // esi
  double v23; // st7
  unsigned __int16 *v24; // eax
  int v25; // esi
  float *v26; // ecx
  double v27; // st7
  int v28; // esi
  double v29; // st7
  int v30; // esi
  double v31; // st7
  int v32; // esi
  double v33; // st7
  int v34; // esi
  double v35; // st7
  int v36; // esi
  int v37; // eax
  bool v38; // cc
  char *v39; // [esp+4h] [ebp-10h]
  int v40; // [esp+4h] [ebp-10h]
  int v41; // [esp+4h] [ebp-10h]
  int v42; // [esp+4h] [ebp-10h]
  int v43; // [esp+4h] [ebp-10h]
  int v44; // [esp+4h] [ebp-10h]
  int v45; // [esp+4h] [ebp-10h]
  int v46; // [esp+8h] [ebp-Ch]
  int *v47; // [esp+Ch] [ebp-8h]
  int v48; // [esp+10h] [ebp-4h]

  v1 = a1;
  v48 = a1[92];
  result = a1[17];
  v46 = 0;
  if ( a1[15] > 0 )
  {
    v47 = (int *)(result + 16);
    do
    {
      v3 = *v47;
      if ( *v47 < 0 || v3 >= 4 || !v1[v3 + 18] )
      {
        v4 = *v1;
        *(_DWORD *)(v4 + 20) = 52;
        *(_DWORD *)(v4 + 24) = v3;
        (*(void (__stdcall **)(int *))v4)(v1);
      }
      v5 = (unsigned __int16 *)v1[v3 + 18];
      switch ( v1[49] )
      {
        case 0:
        case 3:
        case 5:
          if ( !*(_DWORD *)(v48 + 4 * v3 + 12) )
            *(_DWORD *)(v48 + 4 * v3 + 12) = (*(int (__stdcall **)(int *, int, int))v1[1])(v1, 1, 128);
          v6 = *(char **)(v48 + 4 * v3 + 12);
          v7 = (char *)v5 - v6;
          v8 = 64;
          do
          {
            *(_WORD *)v6 = 8 * *(_WORD *)&v6[v7];
            v6 += 2;
            --v8;
          }
          while ( v8 );
          break;
        case 1:
        case 4:
        case 6:
          if ( !*(_DWORD *)(v48 + 4 * v3 + 12) )
            *(_DWORD *)(v48 + 4 * v3 + 12) = (*(int (__stdcall **)(int *, int, int))v1[1])(v1, 1, 128);
          v9 = *(_DWORD *)(v48 + 4 * v3 + 12);
          v10 = v5 + 3;
          v11 = &word_747F20;
          v12 = (_WORD *)(v9 + 2);
          v39 = (char *)v5 - v9;
          v13 = -v9;
          do
          {
            v14 = *(unsigned __int16 *)&v39[(_DWORD)v12];
            *(v12 - 1) = (*v11 * *(v10 - 3) + 1024) >> 11;
            v15 = v14 * *(__int16 *)((char *)&word_747F20 + (_DWORD)v12 + v13);
            v16 = *(v10 - 1);
            *v12 = (v15 + 1024) >> 11;
            v17 = v16 * *(__int16 *)((char *)&word_747F22 + (_DWORD)v12 + v13);
            v18 = *v10;
            v12[1] = (v17 + 1024) >> 11;
            v12[2] = (v18 * *(__int16 *)((char *)&word_747F24 + (_DWORD)v12 + v13) + 1024) >> 11;
            v11 += 4;
            v12 += 4;
            v10 += 4;
          }
          while ( (int)v11 < (int)&flt_747FA0 );
          v1 = a1;
          break;
        case 2:
          if ( !*(_DWORD *)(v48 + 4 * v3 + 32) )
            *(_DWORD *)(v48 + 4 * v3 + 32) = (*(int (__stdcall **)(int *, int, int))v1[1])(v1, 1, 256);
          v19 = *(float **)(v48 + 4 * v3 + 32);
          v20 = (double *)&unk_747E18;
          v21 = v5;
          do
          {
            v22 = v21[1];
            v23 = (double)*v21;
            v24 = v21 + 1;
            v40 = v22;
            v25 = v24[1];
            v24 += 5;
            v26 = v19 + 6;
            *(v26 - 6) = 1.0 / (v23 * *v20 * 8.0);
            v27 = (double)v40;
            v41 = v25;
            v28 = *(v24 - 3);
            *(v26 - 5) = 1.0 / (v27 * *v20 * 11.09631876);
            v29 = (double)v41;
            v42 = v28;
            v30 = *(v24 - 2);
            *(v26 - 4) = 1.0 / (v29 * *v20 * 10.45250372);
            v31 = (double)v42;
            v43 = v30;
            v32 = *(v24 - 1);
            *(v26 - 3) = 1.0 / (v31 * *v20 * 9.407004816000001);
            v33 = (double)v43;
            v44 = v32;
            v34 = *v24;
            *(v26 - 2) = 1.0 / (v33 * *v20 * 8.0);
            v35 = (double)v44;
            v45 = v34;
            *(v26 - 1) = 1.0 / (v35 * *v20 * 6.285559664);
            v36 = v24[1];
            *v26 = 1.0 / ((double)v45 * *v20++ * 4.3295688);
            v21 = v24 + 2;
            v19 = v26 + 2;
            *(v19 - 1) = 1.0 / ((double)v36 * *(v20 - 1) * 2.207195032);
          }
          while ( (int)v20 < (int)&qword_747E58 );
          break;
        default:
          v37 = *v1;
          *(_DWORD *)(v37 + 20) = 48;
          (*(void (__stdcall **)(int *))v37)(v1);
          break;
      }
      result = v46 + 1;
      v38 = ++v46 < v1[15];
      v47 += 21;
    }
    while ( v38 );
  }
  return result;
}
