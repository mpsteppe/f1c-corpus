int __thiscall sub_471440(_DWORD *this)
{
  _DWORD *v1; // eax
  int v2; // eax
  _BYTE v4[32]; // [esp+4h] [ebp-20h] BYREF

  v1 = (_DWORD *)(36 * dword_7D0410 + 8187528);
  this[200] = v1;
  v2 = UIListIndexedAccessor(*v1);
  StringFormatWithBufferOverflowCheck(v4, v2);
  EditBufferStringUpdate(v4);
  return 0;
}

