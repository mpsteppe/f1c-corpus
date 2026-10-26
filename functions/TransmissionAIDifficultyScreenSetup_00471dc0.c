int __thiscall TransmissionAIDifficultyScreenSetup(_DWORD *this)
{
  char *v2; // eax
  char v4[32]; // [esp+4h] [ebp-20h] BYREF

  this[201] = dword_7D0410;
  this[200] = &dword_7D1FD8;
  v2 = UIListIndexedAccessor(this, dword_7D1FD8);
  StringFormatWithBufferOverflowCheck(v4, (int)v2);
  EditBufferStringUpdate(this, v4);
  return 0;
}
