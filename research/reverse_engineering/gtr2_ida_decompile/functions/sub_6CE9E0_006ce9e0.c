int __stdcall sub_6CE9E0(int a1, int a2)
{
  _DWORD *v2; // edi
  int v3; // eax
  int v4; // ecx
  int result; // eax
  int v6; // ebx
  _DWORD *v7; // esi
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // ebx
  int v11; // edi
  unsigned int v12; // edx
  unsigned int v13; // eax
  void (__stdcall *v14)(int, _DWORD *, int, int, int); // [esp+4h] [ebp-24h]
  int v15; // [esp+8h] [ebp-20h]
  unsigned int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  int v18; // [esp+14h] [ebp-14h]
  int v19; // [esp+14h] [ebp-14h]
  unsigned int v20; // [esp+18h] [ebp-10h]
  _DWORD *v21; // [esp+1Ch] [ebp-Ch]
  int v22; // [esp+20h] [ebp-8h]
  int v23; // [esp+24h] [ebp-4h]

  v2 = (_DWORD *)a1;
  v18 = *(_DWORD *)(a1 + 432);
  v16 = *(_DWORD *)(a1 + 324) - 1;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 148);
    v4 = *(_DWORD *)(a1 + 156);
    if ( v3 >= v4 && (v3 != v4 || *(_DWORD *)(a1 + 152) > *(_DWORD *)(a1 + 160)) )
      break;
    result = (**(int (__stdcall ***)(int))(a1 + 440))(a1);
    if ( !result )
      return result;
  }
  v6 = 0;
  v7 = *(_DWORD **)(a1 + 220);
  v17 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v21 = (_DWORD *)(v18 + 72);
    do
    {
      if ( v7[12] )
      {
        v15 = (*(int (__stdcall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(v2[1] + 32))(
                v2,
                *v21,
                v7[3] * v2[40],
                v7[3],
                0);
        if ( v2[40] < v16 || (v23 = v7[8] % v7[3]) == 0 )
          v23 = v7[3];
        v14 = *(void (__stdcall **)(int, _DWORD *, int, int, int))(v2[113] + 4 * v6 + 4);
        v8 = 0;
        v22 = *(_DWORD *)(a2 + 4 * v6);
        v19 = 0;
        if ( v23 > 0 )
        {
          v9 = v7[7];
          do
          {
            v10 = *(_DWORD *)(v15 + 4 * v8);
            v11 = 0;
            v20 = 0;
            if ( v9 )
            {
              do
              {
                v14(a1, v7, v10, v22, v11);
                v9 = v7[7];
                v11 += v7[9];
                v10 += 128;
                ++v20;
              }
              while ( v20 < v9 );
              v8 = v19;
            }
            v22 += 4 * v7[9];
            v19 = ++v8;
          }
          while ( v8 < v23 );
          v2 = (_DWORD *)a1;
          v6 = v17;
        }
      }
      ++v6;
      v7 += 21;
      v17 = v6;
      ++v21;
    }
    while ( v6 < v2[9] );
  }
  v12 = v2[81];
  v13 = v2[40] + 1;
  v2[40] = v13;
  return 4 - (v13 < v12);
}
