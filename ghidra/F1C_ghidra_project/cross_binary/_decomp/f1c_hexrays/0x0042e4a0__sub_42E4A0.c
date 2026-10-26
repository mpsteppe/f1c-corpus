// f1c  0x0042e4a0  size=143
void __stdcall sub_42E4A0(int a1, int a2, char a3)
{
  int v3; // esi
  int i; // edi

  v3 = *(_DWORD *)(a2 + 20);
  for ( i = *(_DWORD *)(a1 + 20);
        (double)v3 * *(double *)(a2 + 8) + *(double *)a2 > ((double)i * *(double *)(a1 + 8) + *(double *)a1) * 1.0001;
        v3 = *(_DWORD *)(a2 + 20) )
  {
    if ( a3 && v3 > 0 )
    {
      *(_DWORD *)(a2 + 20) = v3 - 1;
    }
    else
    {
      if ( i >= *(_DWORD *)(a1 + 16) - 1 )
        return;
      *(_DWORD *)(a1 + 20) = i + 1;
    }
    i = *(_DWORD *)(a1 + 20);
  }
}
