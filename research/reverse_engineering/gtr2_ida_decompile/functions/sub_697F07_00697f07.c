int __stdcall sub_697F07(double *a1, double *a2, int a3)
{
  __int64 v3; // rax
  double v4; // st7
  double v5; // st7
  double v7; // st7
  char v8; // c0

  switch ( *(_DWORD *)a1 )
  {
    case 0:
      if ( *(_DWORD *)a2 <= 2u )
      {
        *((_DWORD *)a1 + 2) = *((_DWORD *)a2 + 2) != 0;
        return 0;
      }
      if ( *(_DWORD *)a2 == 3 )
      {
        *((_DWORD *)a1 + 2) = 0.0 != a2[1];
        return 0;
      }
      return -2147467259;
    case 1:
    case 2:
      if ( *(_DWORD *)a2 )
      {
        if ( *(_DWORD *)a2 == 1 || *(_DWORD *)a2 == 2 )
        {
          LODWORD(v3) = *((_DWORD *)a2 + 2);
        }
        else
        {
          if ( *(_DWORD *)a2 != 3 )
            return -2147467259;
          v7 = a2[1];
          if ( v8 )
            v5 = v7 - 0.000001;
          else
            v5 = v7 + 0.000001;
          v3 = (__int64)v5;
        }
      }
      else
      {
        LODWORD(v3) = *((_DWORD *)a2 + 2) != 0;
      }
LABEL_33:
      *((_DWORD *)a1 + 2) = v3;
      return 0;
    case 3:
      if ( *(_DWORD *)a2 )
      {
        switch ( *(_DWORD *)a2 )
        {
          case 1:
            v4 = (double)*((int *)a2 + 2);
            break;
          case 2:
            v4 = (double)*((unsigned int *)a2 + 2);
            break;
          case 3:
            v4 = a2[1];
            break;
          default:
            return -2147467259;
        }
      }
      else
      {
        v4 = (double)(*((_DWORD *)a2 + 2) != 0);
      }
      a1[1] = v4;
      return 0;
    case 4:
      if ( *(_DWORD *)a2 == 4 )
      {
LABEL_13:
        LODWORD(v3) = *((_DWORD *)a2 + 2);
        goto LABEL_33;
      }
      break;
    case 5:
      break;
    default:
      return -2147467259;
  }
  if ( *(_DWORD *)a2 == 4 )
  {
    *(_DWORD *)a1 = 4;
    goto LABEL_13;
  }
  if ( *(_DWORD *)a2 != 5 )
    return -2147467259;
  *((_DWORD *)a1 + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)a1 + 3) = *((_DWORD *)a2 + 3);
  return 0;
}
