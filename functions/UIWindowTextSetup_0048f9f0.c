int __thiscall sub_48F9F0(_DWORD *this)
{
  char *v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // esi
  _BYTE v7[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v8; // [esp+49h] [ebp-3h]
  char v9; // [esp+4Bh] [ebp-1h]

  v7[0] = byte_5EA438[0];
  memset(&v7[1], 0, 0x3Cu);
  v8 = 0;
  v9 = 0;
  v2 = (char *)this[46];
  if ( !v2 )
    v2 = byte_5EA438;
  sub_587DD0(v7, v2, 63);
  v9 = 0;
  v3 = sub_5897CA(v7, &word_5C32D8);
  if ( v3 )
    this[85] = SingleFunctionCallWrapper_7f59(v3);
  v4 = sub_5897CA(0, &word_5C32D8);
  if ( v4 )
    this[84] = SingleFunctionCallWrapper_7f59(v4);
  result = sub_5897CA(0, &word_5C32D8);
  v6 = result;
  if ( result )
  {
    if ( !sub_588410(result, &byte_5CC21C) )
      this[56] = 0;
    if ( !sub_588410(v6, aC_0) )
      this[56] = 1;
    result = sub_588410(v6, aR);
    if ( !result )
      this[56] = 2;
  }
  return result;
}
