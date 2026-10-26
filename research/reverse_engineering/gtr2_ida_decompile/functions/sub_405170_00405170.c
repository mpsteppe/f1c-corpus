int __fastcall sub_405170(int a1, int a2, float a3, _DWORD *a4)
{
  int i; // esi
  int v5; // esi
  int j; // ecx
  int v7; // edi

  for ( i = (a1 + a2) >> 1; i - a1 >= 10; i = (a1 + a2) >> 1 )
  {
    if ( a3 > (double)*(float *)(16 * i + a4[2] + 12) )
      a1 = i;
    else
      a2 = i;
  }
  v5 = a1;
  if ( a1 > a2 )
    return -1;
  for ( j = 16 * a1; ; j += 16 )
  {
    if ( v5 < *a4 - 1 )
    {
      v7 = a4[2] + j;
      if ( *(float *)(v7 + 12) <= (double)a3 && *(float *)(v7 + 28) >= (double)a3 )
        break;
    }
    if ( ++v5 > a2 )
      return -1;
  }
  return v5;
}
