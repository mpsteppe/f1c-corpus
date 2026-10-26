int __thiscall sub_460710(_DWORD *this)
{
  int result; // eax
  _BYTE v2[140]; // [esp+4h] [ebp-8Ch] BYREF

  if ( this[4081] != 1 )
  {
    ThunkToFUN00461480(v2);
    FunctionCallWrapper_23e0(v2);
    BitfieldSetClearAt0x88(4, 1);
    ShortComputation_23b0(v2);
    return EmptyStub_0170(v2);
  }
  return result;
}

