_DWORD *_getptd()
{
  DWORD LastError; // edi
  _DWORD *Value; // esi
  _DWORD *v2; // eax
  DWORD CurrentThreadId; // eax

  LastError = GetLastError();
  Value = TlsGetValue(dwTlsIndex);
  if ( !Value )
  {
    v2 = (_DWORD *)sub_5C1C71(1, 116);
    Value = v2;
    if ( !v2 || !TlsSetValue(dwTlsIndex, v2) )
      _amsg_exit(0x10u);
    _initptd((int)Value);
    CurrentThreadId = GetCurrentThreadId();
    Value[1] = -1;
    *Value = CurrentThreadId;
  }
  SetLastError(LastError);
  return Value;
}
