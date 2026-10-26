int __thiscall sub_564740(LPVOID *lpMem)
{
  int i; // edi

  for ( i = 0; i < (int)lpMem[1]; ++i )
    BatchLoopWithMemoryCleanup(*((LPVOID *)*lpMem + i));
  sub_58AA6F(*lpMem);
  return sub_58AA6F(lpMem);
}
