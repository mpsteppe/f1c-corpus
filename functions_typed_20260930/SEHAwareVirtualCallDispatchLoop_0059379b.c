void __cdecl sub_59379B(int a1, int a2, int a3, int a4)
{
  int i; // esi
  int v5; // eax

  for ( i = *(_DWORD *)(a1 + 8); i != a4; i = *(_DWORD *)(*(_DWORD *)(a3 + 8) + 8 * i) )
  {
    if ( i <= -1 || i >= *(_DWORD *)(a3 + 4) )
      SEHGuardedFunctionPointerCall();
    v5 = *(_DWORD *)(*(_DWORD *)(a3 + 8) + 8 * i + 4);
    if ( v5 )
      sub_593C50(v5, a1, 259);
  }
  *(_DWORD *)(a1 + 8) = i;
}

