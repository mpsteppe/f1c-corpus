int __cdecl sub_5CA777(int a1)
{
  int v1; // eax
  int v2; // eax

  hHeap = HeapCreate(a1 == 0, 0x1000u, 0);
  if ( !hHeap )
    return 0;
  v1 = sub_5CA62F();
  dword_8003C8 = v1;
  if ( v1 == 3 )
  {
    v2 = __sbh_heap_init(1016);
  }
  else
  {
    if ( v1 != 2 )
      return 1;
    v2 = sub_5CBDD5();
  }
  if ( !v2 )
  {
    HeapDestroy(hHeap);
    return 0;
  }
  return 1;
}
