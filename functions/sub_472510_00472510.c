int __thiscall sub_472510(_DWORD *this)
{
  char *v2; // eax
  char v4[32]; // [esp+4h] [ebp-20h] BYREF

  this[201] = dword_7D0410;
  this[200] = &dword_7CFFCC;
  v2 = UIListIndexedAccessor(this, dword_7CFFCC);
  StringFormatWithBufferOverflowCheck(v4, (int)v2);
  TireCompoundClamp(byte_7CE498);
  EditBufferStringUpdate(this, v4);
  return 0;
}
