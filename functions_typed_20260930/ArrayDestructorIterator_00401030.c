int __stdcall sub_401030(int a1, int a2, int a3, int (__thiscall *a4)(int))
{
  int v4; // esi
  int result; // eax
  int v6; // edi

  v4 = a3 * a2 + a1;
  result = a3 - 1;
  if ( a3 - 1 >= 0 )
  {
    v6 = a3;
    do
    {
      v4 -= a2;
      result = a4(v4);
      --v6;
    }
    while ( v6 );
  }
  return result;
}

