int __stdcall sub_6D7400(int a1)
{
  int v1; // esi
  int v2; // ebx
  int v3; // edi
  int result; // eax
  int v5; // edx
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  _DWORD *v9; // edx
  int v10; // esi
  bool v11; // cc
  int v12; // [esp+Ch] [ebp-20h]
  _DWORD *v13; // [esp+14h] [ebp-18h]
  int v14; // [esp+18h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp-10h]
  _DWORD *v16; // [esp+20h] [ebp-Ch]
  char *v17; // [esp+24h] [ebp-8h]
  int v18; // [esp+28h] [ebp-4h]

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 244);
  v3 = *(_DWORD *)(a1 + 348);
  result = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 20 * v2 * *(_DWORD *)(a1 + 60));
  v5 = *(_DWORD *)(a1 + 68);
  v18 = result;
  v14 = 0;
  if ( *(int *)(a1 + 60) > 0 )
  {
    v12 = 20 * v2;
    v6 = (_DWORD *)(v5 + 8);
    v16 = (_DWORD *)(v5 + 8);
    v17 = (char *)(result + 4 * v2);
    v13 = (_DWORD *)(v3 + 8);
    while ( 1 )
    {
      v7 = (_DWORD *)(*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)(v1 + 4) + 8))(
                       v1,
                       1,
                       8 * *(_DWORD *)(v1 + 240) * v6[5] / *v6,
                       3 * v2);
      qmemcpy(v17, v7, 12 * v2);
      if ( v2 > 0 )
      {
        v8 = (_DWORD *)(v18 + 16 * v2);
        v9 = &v7[2 * v2];
        v10 = v18 - (_DWORD)v7;
        v15 = v2;
        do
        {
          *(_DWORD *)((char *)v7 + v10) = *v9;
          *v8 = *v7;
          ++v9;
          ++v7;
          ++v8;
          --v15;
        }
        while ( v15 );
      }
      *v13 = v17;
      v17 += v12;
      ++v13;
      result = v14 + 1;
      v11 = v14 + 1 < *(_DWORD *)(a1 + 60);
      v18 += v12;
      ++v14;
      v16 += 21;
      if ( !v11 )
        break;
      v1 = a1;
      v6 = v16;
    }
  }
  return result;
}
