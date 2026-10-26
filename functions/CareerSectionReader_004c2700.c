char __thiscall sub_4C2700(_DWORD *this, int a2)
{
  char v2; // bl
  _DWORD v5[7]; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = 0;
  if ( a2 )
  {
    ZeroInitSmallStruct(v5);
    if ( (unsigned __int8)sub_566940(a2, 0, 1, 1) )
    {
      v2 = CareerStatsWriter(this, v5, (int)aCareer);
      ConditionalFileHandleCloseWithFlagDispatch(v5);
    }
    SubCallWithConditionalFieldFree(v5);
  }
  return v2;
}
