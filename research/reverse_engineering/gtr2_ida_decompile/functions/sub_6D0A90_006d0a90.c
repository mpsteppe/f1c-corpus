int __stdcall sub_6D0A90(int *a1)
{
  int *v1; // edi
  int result; // eax
  int v3; // ecx
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // eax
  unsigned __int16 *v7; // edi
  int v8; // ecx
  double *v9; // edx
  unsigned __int16 *v10; // eax
  unsigned __int16 *v11; // eax
  int v12; // ecx
  double v13; // st7
  int v14; // eax
  unsigned __int16 *v15; // edx
  _WORD *v16; // ecx
  __int16 *v17; // esi
  int v18; // eax
  char *v19; // ecx
  int v20; // edi
  int v21; // eax
  bool v22; // cc
  char *v23; // [esp+8h] [ebp-18h]
  _DWORD *v24; // [esp+Ch] [ebp-14h]
  int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+Ch] [ebp-14h]
  int v27; // [esp+Ch] [ebp-14h]
  int v28; // [esp+10h] [ebp-10h]
  int *v29; // [esp+14h] [ebp-Ch]
  int v30; // [esp+18h] [ebp-8h]
  int (__stdcall *v31)(int, int, int, int, int); // [esp+1Ch] [ebp-4h]

  v1 = a1;
  result = a1[113];
  v3 = a1[55];
  v4 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  if ( a1[9] > 0 )
  {
    v5 = (_DWORD *)(v3 + 36);
    v24 = (_DWORD *)(v3 + 36);
    v29 = (int *)(result + 44);
    do
    {
      switch ( *v5 )
      {
        case 1:
          v4 = 0;
          v31 = sub_6DD600;
          v30 = 0;
          break;
        case 2:
          v4 = 0;
          v31 = sub_6DD150;
          v30 = 0;
          break;
        case 4:
          v4 = 0;
          v31 = sub_6DCE40;
          v30 = 0;
          break;
        case 8:
          switch ( v1[18] )
          {
            case 0:
              v4 = 0;
              v31 = sub_6DBD20;
              v30 = 0;
              break;
            case 1:
            case 4:
            case 6:
              v4 = 1;
              v31 = sub_6DB8E0;
              v30 = 1;
              break;
            case 2:
              v4 = 2;
              v31 = sub_6DB510;
              v30 = 2;
              break;
            case 3:
              v4 = 0;
              v31 = sub_6DC6A0;
              v30 = 0;
              break;
            case 5:
              v4 = 0;
              v31 = sub_6DCE00;
              v30 = 0;
              break;
            default:
              v6 = *v1;
              *(_DWORD *)(*v1 + 20) = 48;
              goto LABEL_15;
          }
          break;
        default:
          v6 = *v1;
          *(_DWORD *)(v6 + 20) = 7;
          *(_DWORD *)(v6 + 24) = *v5;
LABEL_15:
          (*(void (__stdcall **)(int *))v6)(v1);
          break;
      }
      *(v29 - 10) = (int)v31;
      if ( v5[3] && *v29 != v4 )
      {
        v7 = (unsigned __int16 *)v5[10];
        if ( v7 )
        {
          *v29 = v4;
          if ( v4 )
          {
            if ( v4 == 1 )
            {
              v14 = v5[11];
              v15 = v7 + 3;
              v16 = (_WORD *)(v14 + 2);
              v17 = &word_747F20;
              v23 = (char *)v7 - v14;
              v18 = -v14;
              do
              {
                *(v16 - 1) = (*v17 * *(v15 - 3) + 2048) >> 12;
                *v16 = (*(unsigned __int16 *)((char *)v16 + (_DWORD)v23)
                      * *(__int16 *)((char *)&word_747F20 + (_DWORD)v16 + v18)
                      + 2048) >> 12;
                v16[1] = (*(v15 - 1) * *(__int16 *)((char *)&word_747F22 + (_DWORD)v16 + v18) + 2048) >> 12;
                v16[2] = (*v15 * *(__int16 *)((char *)&word_747F24 + (_DWORD)v16 + v18) + 2048) >> 12;
                v17 += 4;
                v16 += 4;
                v15 += 4;
              }
              while ( (int)v17 < (int)&flt_747FA0 );
              v5 = v24;
              v4 = v30;
            }
            else
            {
              v8 = v5[11];
              v9 = (double *)&unk_747E18;
              v10 = v7;
              do
              {
                v25 = *v10;
                v11 = v10 + 3;
                v12 = v8 + 12;
                *(float *)(v12 - 12) = (double)v25 * *v9;
                v26 = *(v11 - 2);
                v11 += 4;
                v12 += 16;
                v13 = (double)v26 * *v9++ * 1.387039845;
                *(float *)(v12 - 24) = v13;
                v27 = *(v11 - 5);
                v10 = v11 + 1;
                v8 = v12 + 4;
                *(float *)(v8 - 24) = (double)v27 * *(v9 - 1) * 1.306562965;
                *(float *)(v8 - 20) = (double)*(v10 - 5) * *(v9 - 1) * 1.175875602;
                *(float *)(v8 - 16) = (double)*(v10 - 4) * *(v9 - 1);
                *(float *)(v8 - 12) = (double)*(v10 - 3) * *(v9 - 1) * 0.785694958;
                *(float *)(v8 - 8) = (double)*(v10 - 2) * *(v9 - 1) * 0.5411961;
                *(float *)(v8 - 4) = (double)*(v10 - 1) * *(v9 - 1) * 0.275899379;
              }
              while ( (int)v9 < (int)&qword_747E58 );
            }
          }
          else
          {
            v19 = (char *)v5[11];
            v20 = (char *)v7 - v19;
            v21 = 64;
            do
            {
              *(_WORD *)v19 = *(_WORD *)&v19[v20];
              v19 += 2;
              --v21;
            }
            while ( v21 );
          }
        }
        v1 = a1;
      }
      result = v28 + 1;
      ++v29;
      v5 += 21;
      v22 = ++v28 < v1[9];
      v24 = v5;
    }
    while ( v22 );
  }
  return result;
}
