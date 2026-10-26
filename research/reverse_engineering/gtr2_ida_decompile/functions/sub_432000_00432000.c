void __stdcall sub_432000(int a1, int a2, char a3)
{
  int v3; // eax
  int v4; // eax

  while ( (double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2 > ((double)*(int *)(a1 + 20)
                                                                           * *(double *)(a1 + 8)
                                                                           + *(double *)a1)
                                                                          * 1.0001 )
  {
    if ( a3 && (v3 = *(_DWORD *)(a2 + 20), v3 > 0) )
    {
      *(_DWORD *)(a2 + 20) = v3 - 1;
    }
    else
    {
      v4 = *(_DWORD *)(a1 + 20);
      if ( v4 >= *(_DWORD *)(a1 + 16) - 1 )
        return;
      *(_DWORD *)(a1 + 20) = v4 + 1;
    }
  }
}
