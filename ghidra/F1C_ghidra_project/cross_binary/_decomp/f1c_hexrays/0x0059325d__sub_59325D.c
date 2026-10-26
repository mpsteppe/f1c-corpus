// f1c  0x0059325d  size=93
int __cdecl sub_59325D(int a1)
{
  int v1; // eax
  int v2; // eax

  hHeap = HeapCreate(a1 == 0, 0x1000u, 0);
  if ( !hHeap )
    return 0;
  v1 = sub_593115();
  dword_8D4908 = v1;
  if ( v1 == 3 )
  {
    v2 = sub_593DD3(1016);
  }
  else
  {
    if ( v1 != 2 )
      return 1;
    v2 = sub_59491A();
  }
  if ( !v2 )
  {
    HeapDestroy(hHeap);
    return 0;
  }
  return 1;
}
