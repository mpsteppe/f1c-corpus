// positive sp value has been detected, the output may be wrong!
char *ThreeCallChain()
{
  int *v0; // ecx
  int v1; // esi
  int v2; // eax

  MEMORY[0x5746985D]();
  v1 = (int)v0;
  v2 = GuardedAccessor(v0);
  return FilenameFromLinkedList(v1, v2);
}

