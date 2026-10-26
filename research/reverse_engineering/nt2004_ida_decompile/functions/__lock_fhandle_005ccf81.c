void __cdecl _lock_fhandle(int a1)
{
  int v1; // edi
  int v2; // esi

  v1 = 36 * (a1 & 0x1F);
  v2 = v1 + dword_8003E0[a1 >> 5];
  if ( !*(_DWORD *)(v2 + 8) )
  {
    _lock(17);
    if ( !*(_DWORD *)(v2 + 8) )
    {
      InitializeCriticalSection((LPCRITICAL_SECTION)(v2 + 12));
      ++*(_DWORD *)(v2 + 8);
    }
    _unlock(17);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(dword_8003E0[a1 >> 5] + v1 + 12));
}
