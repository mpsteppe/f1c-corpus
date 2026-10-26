int __thiscall sub_406100(_DWORD *this)
{
  int result; // eax
  _BYTE v2[4]; // [esp+0h] [ebp-Ch] BYREF
  _BYTE v3[4]; // [esp+4h] [ebp-8h] BYREF
  _BYTE v4[4]; // [esp+8h] [ebp-4h] BYREF

  result = this[22];
  if ( result )
  {
    if ( *(_DWORD *)(result + 16) )
    {
      sub_404FE0();
      return sub_407E10(v4, v3, v2);
    }
  }
  return result;
}
