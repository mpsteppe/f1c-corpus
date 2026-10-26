int __stdcall sub_698043(_DWORD *a1, double *a2, int a3)
{
  double v5; // st7
  char v6; // c0
  double v7; // st7
  __int64 v8; // rax

  if ( *(_DWORD *)a2 )
  {
    if ( *(_DWORD *)a2 == 1 || *(_DWORD *)a2 == 2 )
    {
      LODWORD(v8) = *((_DWORD *)a2 + 2);
    }
    else
    {
      if ( *(_DWORD *)a2 != 3 )
        return -2147467259;
      v5 = a2[1];
      if ( v6 )
        v7 = v5 - 0.000001;
      else
        v7 = v5 + 0.000001;
      v8 = (__int64)v7;
    }
  }
  else
  {
    LODWORD(v8) = *((_DWORD *)a2 + 2) != 0;
  }
  *a1 = v8;
  return 0;
}
