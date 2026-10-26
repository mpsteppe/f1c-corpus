int __thiscall sub_472CC0(_DWORD **this)
{
  int v1; // eax
  _BYTE v3[32]; // [esp+4h] [ebp-20h] BYREF

  v1 = UIListIndexedAccessor(*this[199]);
  StringFormatWithBufferOverflowCheck(v3, v1);
  return EditBufferStringUpdate(v3);
}
