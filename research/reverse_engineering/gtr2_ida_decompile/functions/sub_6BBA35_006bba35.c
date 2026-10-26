int __stdcall sub_6BBA35(int a1, _DWORD *a2, int a3)
{
  unsigned int v3; // edi
  bool v4; // zf

  if ( a2[10] != a3 )
  {
    v3 = 0;
    v4 = a2[7] == 0;
    a2[10] = a3;
    if ( !v4 )
    {
      do
        sub_6BBA35(a1, *(_DWORD *)(a1 + 4 * *(_DWORD *)(a2[8] + 4 * v3++)), a3);
      while ( v3 < a2[7] );
    }
  }
  return 0;
}
