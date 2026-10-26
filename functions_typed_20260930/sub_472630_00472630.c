int __thiscall sub_472630(_DWORD *this)
{
  char *v2; // eax
  char v4[32]; // [esp+4h] [ebp-20h] BYREF

  this[201] = dword_7D0410;
  this[200] = &dword_7CFFA8;
  v2 = UIListIndexedAccessor(this, dword_7CFFA8);
  StringFormatWithBufferOverflowCheck(v4, (int)v2);
  sub_4AE9F0((int)byte_7CE498);
  if ( *(_DWORD *)this[200] - 1 <= dword_5EC4A8 )
    this[196] = 0;
  else
    this[196] = 2;
  EditBufferStringUpdate(this, v4);
  return 0;
}

