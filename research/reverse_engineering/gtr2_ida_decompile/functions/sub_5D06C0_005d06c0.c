int __fastcall sub_5D06C0(int a1, int a2, float a3, _DWORD *a4)
{
  int i; // esi
  int j; // esi
  int v6; // edi

  for ( i = (a1 + a2) >> 1; i - a1 >= 10; i = (a1 + a2) >> 1 )
  {
    if ( a3 > (double)*(float *)(a4[2] + 12 * i + 8) )
      a1 = i;
    else
      a2 = i;
  }
  if ( a1 > a2 )
    return -1;
  for ( j = 12 * a1; ; j += 12 )
  {
    if ( a1 < *a4 - 1 )
    {
      v6 = a4[2] + j;
      if ( *(float *)(v6 + 8) <= (double)a3 && *(float *)(v6 + 20) >= (double)a3 )
        break;
    }
    if ( ++a1 > a2 )
      return -1;
  }
  return a1;
}
