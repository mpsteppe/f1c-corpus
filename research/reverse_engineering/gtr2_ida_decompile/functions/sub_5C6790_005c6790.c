int __fastcall sub_5C6790(int a1, int a2, float a3, _DWORD *a4)
{
  int i; // esi
  int v5; // esi

  for ( i = (a1 + a2) >> 1; i - a1 >= 10; i = (a1 + a2) >> 1 )
  {
    if ( a3 > (double)*(float *)(a4[2] + 8 * i + 4) )
      a1 = i;
    else
      a2 = i;
  }
  if ( a1 > a2 )
    return -1;
  while ( 1 )
  {
    if ( a1 < *a4 - 1 )
    {
      v5 = a4[2] + 8 * a1;
      if ( *(float *)(v5 + 4) <= (double)a3 && *(float *)(v5 + 12) >= (double)a3 )
        break;
    }
    if ( ++a1 > a2 )
      return -1;
  }
  return a1;
}
