int __stdcall sub_673943(int a1, int a2, int a3, float *a4, int a5)
{
  int v5; // edx
  float *v6; // eax

  v5 = 4 * a5;
  if ( 4 * a5 )
  {
    v6 = a4;
    do
    {
      *v6 = (float)*(int *)((char *)v6 + a3 - (_DWORD)a4);
      ++v6;
      --v5;
    }
    while ( v5 );
  }
  return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)a1 + 436))(a1, a2, a3, a5);
}
