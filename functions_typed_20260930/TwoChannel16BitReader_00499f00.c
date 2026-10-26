int __thiscall sub_499F00(char *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int result; // eax
  int v6; // ecx
  int v7; // ecx
  __int16 v8; // [esp+4h] [ebp-4h] BYREF
  __int16 v9; // [esp+6h] [ebp-2h] BYREF

  result = ShortComputation_adb0(this + 108);
  if ( result > 2 )
  {
    if ( (unsigned __int8)LinkedListIndexedFieldReader(0, &v8, &v9) )
    {
      v6 = v9;
      *a2 = v8;
      *a3 = v6;
    }
    result = LinkedListIndexedFieldReader(1, &v8, &v9);
    if ( (_BYTE)result )
    {
      result = (int)a4;
      v7 = v9;
      *a4 = v8;
      *a5 = v7;
    }
  }
  return result;
}

