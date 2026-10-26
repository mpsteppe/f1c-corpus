void __cdecl _lock(int a1)
{
  if ( !dword_912CB0[2 * a1] && !_mtinitlocknum(a1) )
    _amsg_exit(0x11u);
  EnterCriticalSection((LPCRITICAL_SECTION)dword_912CB0[2 * a1]);
}
