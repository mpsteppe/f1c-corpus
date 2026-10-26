int __stdcall sub_6959E6(double *a1, double *a2, int a3)
{
  double v4; // st7
  double v5; // st7

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
    *a1 = v4;
  }
  else
  {
    if ( *((_DWORD *)a2 + 2) )
      v5 = 1.0;
    else
      v5 = 0.0;
    *a1 = v5;
  }
  return 0;
}
