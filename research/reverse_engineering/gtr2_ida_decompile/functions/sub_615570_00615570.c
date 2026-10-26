int __fastcall sub_615570(int a1, int a2, double a3, int a4)
{
  int result; // eax
  unsigned int v5; // esi

  result = a4 - a2 + 1;
  if ( result >= 4 )
  {
    v5 = ((unsigned int)(a4 - a2 - 3) >> 2) + 1;
    result = a1 + 8 * a2 + 16;
    a2 += 4 * v5;
    do
    {
      result += 32;
      --v5;
      *(double *)(result - 48) = a3 * *(double *)(result - 48);
      *(double *)(result - 40) = a3 * *(double *)(result - 40);
      *(double *)(result - 32) = a3 * *(double *)(result - 32);
      *(double *)(result - 24) = a3 * *(double *)(result - 24);
    }
    while ( v5 );
  }
  for ( ; a2 <= a4; *(double *)(a1 + 8 * a2 - 8) = a3 * *(double *)(a1 + 8 * a2 - 8) )
    ++a2;
  return result;
}
