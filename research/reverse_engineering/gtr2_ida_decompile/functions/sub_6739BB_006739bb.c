int __stdcall sub_6739BB(int a1, int a2, char *a3, float *a4, int a5)
{
  float *v5; // eax
  int v6; // esi

  if ( 4 * a5 )
  {
    v5 = a4;
    v6 = 4 * a5;
    do
    {
      *v5 = (float)(*(_DWORD *)((char *)v5 + a3 - (char *)a4) != 0);
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  qmemcpy((void *)(16 * a2 + (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 12))(a1)), a3, 16 * a5);
  return 0;
}
