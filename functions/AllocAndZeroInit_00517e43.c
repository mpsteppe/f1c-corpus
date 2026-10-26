void *__cdecl sub_517E43(int a1)
{
  unsigned int v1; // esi
  void *v2; // edx

  if ( a1 == 2 )
  {
    v1 = 64;
  }
  else
  {
    if ( a1 != 1 )
      return 0;
    v1 = 412;
  }
  v2 = (void *)MallocWrapperForNhMalloc(v1);
  if ( v2 )
    memset(v2, 0, v1);
  return v2;
}
