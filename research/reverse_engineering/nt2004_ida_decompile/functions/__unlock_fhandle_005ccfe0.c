void __cdecl _unlock_fhandle(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(dword_8003E0[a1 >> 5] + 36 * (a1 & 0x1F) + 12));
}
