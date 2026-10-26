int __thiscall sub_474AB0(_DWORD *this)
{
  char v3[32]; // [esp+4h] [ebp-20h] BYREF

  this[201] = dword_7D0410;
  this[200] = &dword_7CFC8C;
  StringFormatWithBufferOverflowCheck(v3, (int)"%d", dword_7CFC8C);
  EditBufferStringUpdate(this, v3);
  return 0;
}
