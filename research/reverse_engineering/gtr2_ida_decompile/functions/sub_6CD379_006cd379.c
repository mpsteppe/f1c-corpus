void __stdcall sub_6CD379(int *a1, unsigned int *a2)
{
  unsigned int v2; // ecx
  int i; // edx
  int v4; // eax

  if ( *a2 > 1 )
  {
    sub_682274((int (__stdcall *)(int, int, int))sub_6CD35F, a1, *a2, 0);
    v2 = 1;
    for ( i = 1; v2 < *a2; ++v2 )
    {
      v4 = a1[v2];
      if ( v4 != a1[v2 - 1] )
        a1[i++] = v4;
    }
    *a2 = i;
  }
}
