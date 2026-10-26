int __cdecl _heap_init(int a1)
{
  hHeap = HeapCreate(a1 == 0, 0x1000u, 0);
  if ( !hHeap )
    return 0;
  dword_FBB4C0 = __heap_select();
  if ( dword_FBB4C0 == 3 && !__sbh_heap_init(1016) )
  {
    HeapDestroy(hHeap);
    return 0;
  }
  return 1;
}
