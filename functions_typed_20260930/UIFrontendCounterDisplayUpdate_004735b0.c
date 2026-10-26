int __thiscall sub_4735B0(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int v4; // eax
  _BYTE v5[32]; // [esp+4h] [ebp-20h] BYREF

  v1 = dword_7D0110;
  if ( dword_7D0110 == this[199] )
    return 0;
  this[199] = dword_7D0110;
  if ( !v1 )
  {
    v2 = UIListIndexedAccessor(0);
    StringFormatWithBufferOverflowCheck(v5, v2);
    EditBufferStringUpdate(v5);
    return 0;
  }
  if ( v1 != dword_7D011C )
  {
    StringFormatWithBufferOverflowCheck(v5, "%d", v1);
    EditBufferStringUpdate(v5);
    return 0;
  }
  v4 = UIListIndexedAccessor(1);
  StringFormatWithBufferOverflowCheck(v5, v4);
  EditBufferStringUpdate(v5);
  return 0;
}

