int __fastcall sub_564B10(int a1, int a2, int a3, int a4, int (__cdecl *a5)(int, int), _DWORD *a6)
{
  int v6; // edi
  int v7; // ebx
  int v9; // esi
  int v10; // eax

  v6 = a3 - 1;
  v7 = 0;
  *a6 = 0;
  while ( v7 <= v6 )
  {
    v9 = (v6 + v7) >> 1;
    v10 = a5(a2 + a4 * v9, a1);
    if ( v10 )
    {
      if ( v10 < 0 )
      {
        v7 = v9 + 1;
        continue;
      }
    }
    else
    {
      *a6 = 1;
    }
    v6 = v9 - 1;
  }
  return a2 + a4 * v7;
}
