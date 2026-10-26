_DWORD *__thiscall sub_5830C0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi

  v3 = (_DWORD *)OperatorNewNhMallocWrapper(8316);
  if ( v3 )
  {
    v4 = v3 + 1;
    *v3 = 2;
    NTimeCallbackLoopWithSEH_a6eb(v3 + 1, 4156, 2, SocketAddressInit, EmptyStub_aa60);
    *this = v4;
  }
  else
  {
    *this = 0;
  }
  return this;
}
