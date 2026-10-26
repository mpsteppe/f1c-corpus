_DWORD *__thiscall sub_498EB0(_DWORD *this)
{
  _DWORD *result; // eax
  int v3; // edx
  _DWORD *v4; // ecx
  int v5; // eax
  char *v6; // eax
  char v7[64]; // [esp+4h] [ebp-40h] BYREF

  result = (_DWORD *)this[210];
  if ( result )
  {
    v3 = this[212];
    if ( *result > v3 || (v3 = this[213], *result < v3) )
      *result = v3;
    v4 = (_DWORD *)this[210];
    this[211] = *(_DWORD *)dword_B72314;
    v5 = sub_4CFC00(*v4);
    sub_630FE0(v7, v5, 63);
    v7[63] = 0;
    v6 = sub_41D840(&byte_91CC38, v7);
    return (_DWORD *)sub_4CE770(v6);
  }
  return result;
}
