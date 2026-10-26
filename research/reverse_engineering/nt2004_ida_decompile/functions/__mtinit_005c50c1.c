int _mtinit()
{
  DWORD *v0; // eax
  DWORD *v1; // esi
  DWORD CurrentThreadId; // eax

  _mtinitlocks();
  dwTlsIndex = TlsAlloc();
  if ( dwTlsIndex == -1 )
    return 0;
  v0 = (DWORD *)sub_5C1C71(1, 116);
  v1 = v0;
  if ( !v0 || !TlsSetValue(dwTlsIndex, v0) )
    return 0;
  _initptd(v1);
  CurrentThreadId = GetCurrentThreadId();
  v1[1] = -1;
  *v1 = CurrentThreadId;
  return 1;
}
