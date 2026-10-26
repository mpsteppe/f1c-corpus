int __cdecl sub_635155(int a1)
{
  void *v1; // eax

  v1 = *(void **)(_getptd() + 100);
  if ( v1 != off_91290C )
    v1 = (void *)__updatetlocinfo();
  return ((int (__cdecl *)(void *, int))loc_63508D)(v1, a1);
}
