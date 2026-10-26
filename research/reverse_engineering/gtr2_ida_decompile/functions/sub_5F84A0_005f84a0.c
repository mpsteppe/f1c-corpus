int __stdcall sub_5F84A0(int *a1, int a2)
{
  int result; // eax
  int v3; // esi
  int *v4; // ebx

  sub_5FDFB0(a1, 0);
  result = sub_5F6450(a1, a2);
  v3 = 0;
  if ( a2 > 0 )
  {
    v4 = a1 + 86;
    do
    {
      result = sub_60AA40(v3++, -1, 0, 0, 0, 0.0, 1120403456, 1);
      ++v4;
    }
    while ( v3 < a2 );
  }
  return result;
}
