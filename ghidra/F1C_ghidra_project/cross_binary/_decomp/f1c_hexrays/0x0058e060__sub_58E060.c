// f1c  0x0058e060  size=84
int sub_58E060()
{
  DWORD *v0; // eax
  DWORD *v1; // esi
  DWORD CurrentThreadId; // eax

  sub_58DFC1();
  dwTlsIndex = TlsAlloc();
  if ( dwTlsIndex == -1 )
    return 0;
  v0 = (DWORD *)sub_58AB58(1, 116);
  v1 = v0;
  if ( !v0 || !TlsSetValue(dwTlsIndex, v0) )
    return 0;
  sub_58E0B4(v1);
  CurrentThreadId = GetCurrentThreadId();
  v1[1] = -1;
  *v1 = CurrentThreadId;
  return 1;
}
