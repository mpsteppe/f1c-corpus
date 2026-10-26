BOOL __stdcall sub_6DAC93(int a1, LPVOID lpMem)
{
  HANDLE ProcessHeap; // eax

  ProcessHeap = GetProcessHeap();
  return HeapFree(ProcessHeap, 0, lpMem);
}
