int __thiscall sub_487060(_DWORD *this, int a2)
{
  int v3; // ebx
  __int16 v5; // [esp+Ch] [ebp-4h] BYREF
  _BYTE v6[2]; // [esp+Eh] [ebp-2h] BYREF

  v3 = this[3];
  if ( a2 >= ShortComputation_adb0(this + 28) )
  {
    if ( this[50] && (unsigned __int8)LinkedListIndexedFieldReader(a2, &v5, v6) )
      return v3 + v5;
  }
  else if ( (unsigned __int8)LinkedListIndexedFieldReader(a2, &v5, v6) )
  {
    return v3 + v5;
  }
  return -1;
}
