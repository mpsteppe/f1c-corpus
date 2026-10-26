int __stdcall sub_6980A2(double *a1, double a2, int a3)
{
  char v5; // c0
  double v6; // st7
  __int64 v7; // rax

  if ( !*(_DWORD *)a1 )
  {
    LODWORD(v7) = 0.0 != a2;
LABEL_12:
    *((_DWORD *)a1 + 2) = v7;
    return 0;
  }
  if ( *(_DWORD *)a1 == 1 || *(_DWORD *)a1 == 2 )
  {
    if ( v5 )
      v6 = a2 - 0.000001;
    else
      v6 = a2 + 0.000001;
    v7 = (__int64)v6;
    goto LABEL_12;
  }
  if ( *(_DWORD *)a1 != 3 )
    return -2147467259;
  a1[1] = a2;
  return 0;
}
