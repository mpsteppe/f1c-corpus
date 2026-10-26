int __stdcall sub_6738F9(int a1, int a2, int a3, float *a4, int a5)
{
  float *v5; // eax
  int v6; // esi

  if ( 4 * a5 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = (float)(*(_DWORD *)((char *)v5 + a3 - (_DWORD)a4) != 0);
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 436))(a1, a2, a3, a5);
}
