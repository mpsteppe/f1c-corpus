int __thiscall sub_4B4AC0(_DWORD *this)
{
  int result; // eax
  int v2; // [esp-4h] [ebp-4h]

  result = this[13];
  if ( result )
  {
    v2 = this[13];
    if ( dword_765E70 == 2 )
      return sub_4B5AB0(1, v2);
    else
      return sub_4B5AB0(0, v2);
  }
  return result;
}
