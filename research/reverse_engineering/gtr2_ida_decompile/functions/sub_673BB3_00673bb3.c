int __stdcall sub_673BB3(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // esi

  if ( 4 * a5 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = *(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0;
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 384))(a1, a2, a3, a5);
}
