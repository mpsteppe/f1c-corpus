_DWORD *sub_58E0C7()
{
  DWORD LastError; // edi
  _DWORD *Value; // esi
  _DWORD *v2; // eax
  DWORD CurrentThreadId; // eax

  LastError = GetLastError();
  Value = TlsGetValue(dwTlsIndex);
  if ( !Value )
  {
    v2 = sub_58AB58(1, 116);
    Value = v2;
    if ( v2 && TlsSetValue(dwTlsIndex, v2) )
    {
      TwoFieldInitializer_e0b4((int)Value);
      CurrentThreadId = GetCurrentThreadId();
      Value[1] = -1;
      *Value = CurrentThreadId;
    }
    else
    {
      CRTAmsgExit(0x10u);
    }
  }
  SetLastError(LastError);
  return Value;
}

