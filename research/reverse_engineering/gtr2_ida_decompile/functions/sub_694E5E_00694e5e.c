int __stdcall sub_694E5E(int a1, int a2)
{
  int v2; // edi
  int v3; // eax

  v2 = *(_DWORD *)(a2 + 28);
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    v3 = strcmp(*(const char **)(a1 + 8), *(const char **)(v2 + 16));
    if ( !v3 )
      break;
    if ( v3 >= 0 )
      v2 = *(_DWORD *)(v2 + 12);
    else
      v2 = *(_DWORD *)(v2 + 8);
    if ( !v2 )
      return 0;
  }
  return *(_DWORD *)(v2 + 20);
}
