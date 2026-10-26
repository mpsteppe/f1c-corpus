int __usercall sub_51954E@<eax>(_DWORD *a1@<edi>)
{
  int v1; // ecx
  int result; // eax
  int v3; // esi
  _DWORD *v4; // ebx
  int *v5; // edx
  int *v6; // ebx
  int *v7; // ecx
  int *v8; // eax
  int v9; // esi
  int v10; // edx
  int v11; // [esp+4h] [ebp-1Ch]
  int v12; // [esp+8h] [ebp-18h]
  int v13; // [esp+Ch] [ebp-14h]
  _DWORD *v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int *v17; // [esp+1Ch] [ebp-4h]

  v1 = a1[96];
  v16 = 0;
  result = a1[49];
  v3 = a1[69];
  v11 = v1;
  v12 = v3;
  if ( (int)a1[8] > 0 )
  {
    v4 = (_DWORD *)(result + 12);
    v14 = (_DWORD *)(result + 12);
    do
    {
      v15 = *v4 * v4[6] / a1[69];
      v13 = *(_DWORD *)(4 * v16 + *(_DWORD *)(v1 + 56));
      v5 = *(int **)(4 * v16 + *(_DWORD *)(v1 + 60));
      if ( v15 > 0 )
      {
        v6 = &v5[v15 * (v3 + 2)];
        v7 = &v5[-v15];
        v8 = &v5[v15 * (v3 + 1)];
        v17 = v5;
        v9 = v13 - (_DWORD)v5;
        do
        {
          *(int *)((char *)v7 + v9) = *(int *)((char *)v8 + v9);
          *v7 = *v8;
          *(int *)((char *)v6 + v9) = *(int *)((char *)v17 + v9);
          v10 = *v17++;
          *v6 = v10;
          ++v8;
          ++v7;
          ++v6;
          --v15;
        }
        while ( v15 );
        v3 = v12;
        v1 = v11;
        v4 = v14;
      }
      result = ++v16;
      v4 += 21;
      v14 = v4;
    }
    while ( v16 < a1[8] );
  }
  return result;
}

