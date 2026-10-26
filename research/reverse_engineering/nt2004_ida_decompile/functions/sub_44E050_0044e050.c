int __stdcall sub_44E050(int a1)
{
  int v2; // ebx

  if ( a1 < 3 )
    return a1 > 0;
  v2 = sub_44E050(a1 - a1 / 2);
  return v2 + sub_44E050(a1 / 2) + 1;
}
