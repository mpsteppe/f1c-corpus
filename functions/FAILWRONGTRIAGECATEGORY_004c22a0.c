char __thiscall sub_4C22A0(void *this, int a2)
{
  char v2; // bl
  _DWORD v5[7]; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = 0;
  if ( a2 )
  {
    ZeroInitSmallStruct(v5);
    if ( (unsigned __int8)AudioStreamOpen(a2, 1) )
    {
      v2 = GameOptionsWriter((int)this, v5);
      ConditionalFileHandleCloseWithFlagDispatch(v5);
    }
    SubCallWithConditionalFieldFree(v5);
  }
  return v2;
}
