void __stdcall sub_6016E0(char *a1, int a2, signed int a3, int a4, int a5, int a6)
{
  int v7; // ebx

  if ( a6 == 8 && a4 > 0 )
  {
    v7 = a4;
    do
    {
      if ( a3 > 0 )
      {
        memset32(a1, a5, a3);
        a1 += 4 * a3;
      }
      a1 += 4 * ((a2 >> 2) - a3);
      --v7;
    }
    while ( v7 );
  }
}
