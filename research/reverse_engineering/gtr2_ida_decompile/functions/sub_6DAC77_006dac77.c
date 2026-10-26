LPVOID __stdcall sub_6DAC77(int a1, int a2, int a3)
{
  HANDLE ProcessHeap; // eax

  ProcessHeap = GetProcessHeap();
  return HeapAlloc(ProcessHeap, 8u, a3 * a2);
}
