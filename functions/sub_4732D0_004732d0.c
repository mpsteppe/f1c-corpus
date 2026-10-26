int __thiscall sub_4732D0(int this)
{
  char *v2; // eax
  char v4[32]; // [esp+4h] [ebp-20h] BYREF

  *(_DWORD *)(this + 804) = dword_7D0410;
  *(_DWORD *)(this + 800) = &unk_7D0158;
  DrivingModeParameterSetup((int)byte_7CE498);
  v2 = UIListIndexedAccessor((_DWORD *)this, **(_DWORD **)(this + 800));
  StringFormatWithBufferOverflowCheck(v4, (int)v2);
  EditBufferStringUpdate((_DWORD *)this, v4);
  return 0;
}
