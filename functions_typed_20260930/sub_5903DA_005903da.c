int __cdecl sub_5903DA(unsigned int *a1)
{
  unsigned __int8 *v1; // esi
  int result; // eax
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  v1 = (unsigned __int8 *)a1;
  if ( a1 && *(_BYTE *)a1 && sub_58FB90(a1, byte_5B94D4) )
  {
    if ( sub_58FB90(a1, &off_5B94D0) )
      return sub_587ECE(v1);
    result = dword_8D3FB8(dword_8D3FB4, 11, v3, 8);
  }
  else
  {
    result = dword_8D3FB8(dword_8D3FB4, 4100, v3, 8);
  }
  if ( !result )
    return result;
  v1 = v3;
  return sub_587ECE(v1);
}

