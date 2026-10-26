char __thiscall sub_567F40(_DWORD *this, int a2, int a3)
{
  char v4; // bl
  int v6[7]; // [esp+8h] [ebp-1Ch] BYREF

  v4 = 0;
  ZeroInitSmallStruct(v6);
  AudioStreamOpen(v6, a2, 0);
  if ( v6[0] )
  {
    HashTableListInsert(this, (int)v6);
    v4 = FileSettingsDataLoad(v6, a3);
    ConditionalFileHandleCloseWithFlagDispatch(v6);
  }
  SubCallWithConditionalFieldFree(v6);
  return v4;
}
