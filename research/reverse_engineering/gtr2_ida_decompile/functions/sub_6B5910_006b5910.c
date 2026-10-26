int __userpurge sub_6B5910@<eax>(int a1@<esi>, int a2, int a3)
{
  int v3; // edx
  int result; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // ebx
  int v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 8) * *(_DWORD *)(a1 + 24);
  v8 = *(_DWORD *)(a1 + 8);
  result = *(_DWORD *)(a1 + 16);
  v5 = 0;
  v9 = v3;
  if ( result > 0 )
  {
    while ( 1 )
    {
      result -= v5;
      if ( *(_DWORD *)(a1 + 20) < result )
        result = *(_DWORD *)(a1 + 20);
      v6 = v5 + *(_DWORD *)(a1 + 24);
      if ( result >= *(_DWORD *)(a1 + 28) - v6 )
        result = *(_DWORD *)(a1 + 28) - v6;
      if ( result >= *(_DWORD *)(a1 + 4) - v6 )
        result = *(_DWORD *)(a1 + 4) - v6;
      if ( result <= 0 )
        break;
      v7 = v8 * result;
      if ( a3 )
        (*(void (__stdcall **)(int, int, _DWORD, int, int))(a1 + 52))(
          a2,
          a1 + 48,
          *(_DWORD *)(*(_DWORD *)a1 + 4 * v5),
          v3,
          v7);
      else
        (*(void (__stdcall **)(int, int, _DWORD, int, int))(a1 + 48))(
          a2,
          a1 + 48,
          *(_DWORD *)(*(_DWORD *)a1 + 4 * v5),
          v3,
          v7);
      v9 += v7;
      result = *(_DWORD *)(a1 + 16);
      v5 += *(_DWORD *)(a1 + 20);
      if ( v5 >= result )
        break;
      v3 = v9;
    }
  }
  return result;
}
