int __cdecl sub_519D51(int a1, int a2)
{
  unsigned int v3; // ebx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  int v7; // edi
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // ebx
  unsigned int v11; // [esp+8h] [ebp-24h]
  void (__cdecl *v12)(int, int, int, int, int); // [esp+Ch] [ebp-20h]
  int v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]
  _DWORD *v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h]
  unsigned int v17; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  int v19; // [esp+28h] [ebp-4h]
  int v20; // [esp+34h] [ebp+8h]
  int v21; // [esp+34h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 280) - 1;
  v20 = *(_DWORD *)(a1 + 388);
  v11 = v3;
  while ( 1 )
  {
    v4 = *(_DWORD *)(a1 + 124);
    v5 = *(_DWORD *)(a1 + 132);
    if ( v4 >= v5 && (v4 != v5 || *(_DWORD *)(a1 + 128) > *(_DWORD *)(a1 + 136)) )
      break;
    result = (**(int (__cdecl ***)(int))(a1 + 396))(a1);
    if ( !result )
      return result;
  }
  v19 = 0;
  v7 = *(_DWORD *)(a1 + 196);
  if ( *(int *)(a1 + 32) > 0 )
  {
    v15 = (_DWORD *)(v20 + 72);
    do
    {
      if ( *(_BYTE *)(v7 + 48) )
      {
        v13 = (*(int (__cdecl **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)(a1 + 4) + 32))(
                a1,
                *v15,
                *(_DWORD *)(v7 + 12) * *(_DWORD *)(a1 + 136),
                *(_DWORD *)(v7 + 12),
                0);
        if ( *(_DWORD *)(a1 + 136) >= v3 )
        {
          v21 = *(_DWORD *)(v7 + 32) % *(_DWORD *)(v7 + 12);
          if ( !v21 )
            v21 = *(_DWORD *)(v7 + 12);
        }
        else
        {
          v21 = *(_DWORD *)(v7 + 12);
        }
        v12 = *(void (__cdecl **)(int, int, int, int, int))(*(_DWORD *)(a1 + 408) + 4 * v19 + 4);
        v8 = 0;
        v16 = *(_DWORD *)(4 * v19 + a2);
        v14 = 0;
        if ( v21 > 0 )
        {
          v9 = *(_DWORD *)(v7 + 28);
          do
          {
            v10 = 0;
            v17 = 0;
            for ( i = *(_DWORD *)(v13 + 4 * v8); v17 < v9; ++v17 )
            {
              v12(a1, v7, i, v16, v10);
              i += 128;
              v10 += *(_DWORD *)(v7 + 36);
              v9 = *(_DWORD *)(v7 + 28);
            }
            v16 += 4 * *(_DWORD *)(v7 + 36);
            v8 = ++v14;
          }
          while ( v14 < v21 );
          v3 = v11;
        }
      }
      ++v19;
      ++v15;
      v7 += 84;
    }
    while ( v19 < *(_DWORD *)(a1 + 32) );
  }
  return 4 - (++*(_DWORD *)(a1 + 136) < *(_DWORD *)(a1 + 280));
}

