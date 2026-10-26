int __usercall sub_51641E@<eax>(int a1@<esi>, int a2, char a3)
{
  int v3; // ebx
  int result; // eax
  int i; // edi
  int v6; // ecx
  int v7; // [esp-4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 8) * *(_DWORD *)(a1 + 24);
  v8 = *(_DWORD *)(a1 + 8);
  result = *(_DWORD *)(a1 + 16);
  for ( i = 0; i < result; v3 += v9 )
  {
    result -= i;
    if ( *(_DWORD *)(a1 + 20) < result )
      result = *(_DWORD *)(a1 + 20);
    v6 = i + *(_DWORD *)(a1 + 24);
    if ( result >= *(_DWORD *)(a1 + 28) - v6 )
      result = *(_DWORD *)(a1 + 28) - v6;
    if ( result >= *(_DWORD *)(a1 + 4) - v6 )
      result = *(_DWORD *)(a1 + 4) - v6;
    if ( result <= 0 )
      break;
    v7 = v8 * result;
    v9 = v8 * result;
    if ( a3 )
      (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 44))(
        a2,
        a1 + 40,
        *(_DWORD *)(*(_DWORD *)a1 + 4 * i),
        v3,
        v7);
    else
      (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 40))(
        a2,
        a1 + 40,
        *(_DWORD *)(*(_DWORD *)a1 + 4 * i),
        v3,
        v7);
    i += *(_DWORD *)(a1 + 20);
    result = *(_DWORD *)(a1 + 16);
  }
  return result;
}

