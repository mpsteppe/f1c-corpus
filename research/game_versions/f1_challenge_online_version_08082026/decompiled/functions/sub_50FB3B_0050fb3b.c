char __cdecl sub_50FB3B(int a1)
{
  int v2; // eax
  void (__cdecl **v3)(int); // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx

  if ( *(_DWORD *)(a1 + 16) == 202 )
  {
    sub_516F76(a1);
    if ( *(_BYTE *)(a1 + 64) )
    {
      *(_DWORD *)(a1 + 16) = 207;
      return 1;
    }
    *(_DWORD *)(a1 + 16) = 203;
  }
  v2 = *(_DWORD *)(a1 + 16);
  if ( v2 != 203 )
  {
    if ( v2 != 204 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 18;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 16);
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    return sub_50FA0E(a1);
  }
  if ( !*(_BYTE *)(*(_DWORD *)(a1 + 396) + 16) )
  {
LABEL_17:
    *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 124);
    return sub_50FA0E(a1);
  }
  while ( 1 )
  {
    v3 = *(void (__cdecl ***)(int))(a1 + 8);
    if ( v3 )
      (*v3)(a1);
    v4 = (**(int (__cdecl ***)(int))(a1 + 396))(a1);
    if ( !v4 )
      return 0;
    if ( v4 == 2 )
      goto LABEL_17;
    v5 = *(_DWORD *)(a1 + 8);
    if ( v5 && (v4 == 3 || v4 == 1) )
    {
      ++*(_DWORD *)(v5 + 4);
      v6 = *(_DWORD *)(a1 + 8);
      v7 = *(_DWORD *)(v6 + 8);
      if ( *(_DWORD *)(v6 + 4) >= v7 )
        *(_DWORD *)(v6 + 8) = v7 + *(_DWORD *)(a1 + 280);
    }
  }
}
