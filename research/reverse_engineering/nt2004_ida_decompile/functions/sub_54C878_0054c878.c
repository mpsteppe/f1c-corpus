char __cdecl sub_54C878(int a1)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 16);
  if ( (v1 == 205 || v1 == 206) && !*(_BYTE *)(a1 + 64) )
  {
    if ( *(_DWORD *)(a1 + 120) < *(_DWORD *)(a1 + 96) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 66;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 380) + 4))(a1);
    *(_DWORD *)(a1 + 16) = 210;
  }
  else if ( v1 == 207 )
  {
    *(_DWORD *)(a1 + 16) = 210;
  }
  else if ( v1 != 210 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 18;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 16);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  do
  {
    if ( *(_BYTE *)(*(_DWORD *)(a1 + 396) + 17) )
    {
      (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 20) + 24))(a1);
      sub_5538CA(a1);
      return 1;
    }
  }
  while ( (**(int (__cdecl ***)(int))(a1 + 396))(a1) );
  return 0;
}
