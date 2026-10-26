int __cdecl _powhlp(double a1, double a2, double *a3)
{
  double v3; // st7
  int v4; // esi
  double *v5; // eax
  double v6; // st7
  int v7; // ecx

  v3 = a1;
  v4 = 0;
  if ( a1 < 0.0 )
    v3 = -a1;
  if ( HIDWORD(a2) == 2146435072 )
  {
    if ( !LODWORD(a2) )
    {
      if ( v3 <= 1.0 )
      {
        v5 = a3;
        if ( v3 >= 1.0 )
          goto LABEL_7;
LABEL_18:
        v6 = 0.0;
        goto LABEL_31;
      }
LABEL_16:
      v6 = dbl_913458;
      goto LABEL_30;
    }
  }
  else if ( a2 == -INFINITY )
  {
    if ( v3 <= 1.0 )
    {
      v5 = a3;
      if ( v3 < 1.0 )
      {
        v6 = dbl_913458;
        goto LABEL_31;
      }
LABEL_7:
      v6 = dbl_913460;
      v4 = 1;
LABEL_31:
      *v5 = v6;
      return v4;
    }
    v6 = 0.0;
LABEL_30:
    v5 = a3;
    goto LABEL_31;
  }
  if ( HIDWORD(a1) == 2146435072 )
  {
    if ( !LODWORD(a1) )
    {
      if ( a2 <= 0.0 )
      {
        v5 = a3;
        if ( a2 >= 0.0 )
        {
          v6 = 1.0;
          goto LABEL_31;
        }
        goto LABEL_18;
      }
      goto LABEL_16;
    }
  }
  else if ( a1 == -INFINITY )
  {
    v7 = _d_inttype(a2);
    if ( a2 <= 0.0 )
    {
      if ( a2 >= 0.0 )
      {
        v6 = 1.0;
      }
      else if ( v7 == 1 )
      {
        v6 = dbl_913478;
      }
      else
      {
        v6 = 0.0;
      }
    }
    else
    {
      v6 = dbl_913458;
      if ( v7 == 1 )
        v6 = -dbl_913458;
    }
    goto LABEL_30;
  }
  return v4;
}
