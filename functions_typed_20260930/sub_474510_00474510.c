int __thiscall sub_474510(_DWORD *this)
{
  int v1; // eax
  _BYTE v3[32]; // [esp+4h] [ebp-20h] BYREF

  this[200] = dword_7D0410;
  this[201] = &dword_7CFDE8;
  v1 = UIListIndexedAccessor(dword_7CFDE8);
  StringFormatWithBufferOverflowCheck(v3, v1);
  EditBufferStringUpdate(v3);
  return 0;
}

