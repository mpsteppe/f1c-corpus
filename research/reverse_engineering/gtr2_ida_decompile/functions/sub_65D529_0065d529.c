signed int __thiscall sub_65D529(_DWORD *this)
{
  signed int result; // eax
  _DWORD *v3; // ecx
  int *v4; // eax
  int v5; // eax
  _DWORD v6[8]; // [esp+4h] [ebp-20h] BYREF

  if ( !this[26] )
    return -2005530516;
  while ( 1 )
  {
    result = sub_65D1E3(this, v6);
    if ( result < 0 )
      break;
    if ( v6[0] == 13 )
    {
      v3 = (_DWORD *)this[26];
      this[26] = v3[1];
      v3[1] = 0;
      sub_659FA8(v3, 1);
      v4 = (int *)this[26];
      if ( v4 )
        v5 = *v4;
      else
        v5 = 1;
      this[166] = v5;
      return 0;
    }
  }
  return result;
}
