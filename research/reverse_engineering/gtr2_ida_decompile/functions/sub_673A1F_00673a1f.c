int __stdcall sub_673A1F(int a1, int a2, char *a3, float *a4, int a5)
{
  int v5; // edx
  float *v6; // eax

  v5 = 4 * a5;
  if ( 4 * a5 )
  {
    v6 = a4;
    do
    {
      *v6 = (float)*(int *)((char *)v6 + a3 - (char *)a4);
      ++v6;
      --v5;
    }
    while ( v5 );
  }
  qmemcpy((void *)(16 * a2 + (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 12))(a1)), a3, 16 * a5);
  return 0;
}
