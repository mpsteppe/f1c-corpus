int __thiscall sub_470F20(_DWORD *this)
{
  int result; // eax
  _DWORD *v3; // ecx
  int v4; // eax
  _BYTE v5[32]; // [esp+4h] [ebp-20h] BYREF

  result = 36 * dword_7D0410 + 8188032;
  this[206] = result;
  if ( result )
  {
    v3 = (_DWORD *)this[206];
    this[200] = dword_7D0410;
    v4 = UIListIndexedAccessor(*v3);
    StringFormatWithBufferOverflowCheck(v5, v4);
    return EditBufferStringUpdate(v5);
  }
  return result;
}

