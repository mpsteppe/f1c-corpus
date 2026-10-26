void __cdecl _unlock(int a1)
{
  LeaveCriticalSection(*(&dword_625940 + a1));
}
