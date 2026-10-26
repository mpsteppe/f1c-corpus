int __thiscall sub_47C770(_DWORD *this)
{
  int v1; // eax
  _BYTE v3[32]; // [esp+4h] [ebp-20h] BYREF

  v1 = dword_7CF230;
  if ( dword_7CF230 <= 16 )
    this[196] = 0;
  else
    this[196] = 2;
  StringFormatWithBufferOverflowCheck(v3, "%d", v1);
  return EditBufferStringUpdate(v3);
}
