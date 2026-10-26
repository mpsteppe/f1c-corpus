// f1c  0x00460470  size=168
int __thiscall sub_460470(_DWORD *this)
{
  int v1; // eax
  int result; // eax
  float v3; // [esp+0h] [ebp-1C0h]
  _BYTE v4[432]; // [esp+10h] [ebp-1B0h] BYREF

  v1 = this[4081];
  if ( v1 > 0 && v1 <= 2 )
    return sub_460520(-1);
  v3 = dbl_8AFEA0;
  sub_4B33B0(4, 3, 0, 0, LODWORD(v3), 1);
  result = sub_462250(v4, 2, -1, -1);
  if ( dword_7C569C != 5 )
  {
    result = sub_4D7A50(1, aDDevF119992002_1, 4371);
    if ( (_BYTE)result )
      return sub_4D7AA0(&unk_8AD25C, aSendingServerO);
  }
  return result;
}
