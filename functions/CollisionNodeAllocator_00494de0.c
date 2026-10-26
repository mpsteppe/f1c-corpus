int __stdcall sub_494DE0(int a1)
{
  int v1; // edi
  int v2; // esi
  int v3; // eax

  v1 = sub_53CFE0(&a1, a1, 67585);
  if ( !v1 )
  {
    v2 = a1;
    if ( a1 )
    {
      v3 = OperatorNewNhMallocWrapper(12);
      if ( v3 )
      {
        *(_DWORD *)v3 = v2;
        *(_DWORD *)(v3 + 4) = 0;
        *(_BYTE *)(v3 + 8) = 0;
      }
      else
      {
        v3 = 0;
      }
      if ( dword_7CDDF0 )
      {
        *(_DWORD *)(dword_7CDDF4 + 4) = v3;
      }
      else
      {
        dword_7CDDF0 = v3;
        dword_7CDDF8 = v3;
      }
      dword_7CDDF4 = v3;
      ++dword_7CDDFC;
    }
  }
  return v1;
}
