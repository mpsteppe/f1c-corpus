int __cdecl sub_517E92(int a1, int a2)
{
  int v2; // esi

  if ( !a1 || !a2 )
    return 0;
  v2 = MallocWrapperForNhMalloc(a2);
  if ( !v2 )
    GuardedCallWithLongjmp(a1, (int)"Out of Memory");
  return v2;
}

