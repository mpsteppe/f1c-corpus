int __stdcall sub_45A1C0(int a1)
{
  int v2; // ebx

  if ( a1 < 3 )
    return a1 > 0;
  v2 = sub_45A1C0(a1 - a1 / 2);
  return v2 + sub_45A1C0(a1 / 2) + 1;
}
