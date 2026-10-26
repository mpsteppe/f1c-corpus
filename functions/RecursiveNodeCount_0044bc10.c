int __stdcall sub_44BC10(int a1)
{
  int v2; // ebx

  if ( a1 < 3 )
    return a1 > 0;
  v2 = RecursiveNodeCount(a1 - a1 / 2);
  return v2 + RecursiveNodeCount(a1 / 2) + 1;
}
