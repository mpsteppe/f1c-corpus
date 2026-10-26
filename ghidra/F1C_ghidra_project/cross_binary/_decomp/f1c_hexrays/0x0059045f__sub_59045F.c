// f1c  0x0059045f  size=98
BOOL __cdecl sub_59045F(int a1, int a2)
{
  int v2; // eax
  char *v3; // esi
  BOOL result; // eax
  _BYTE v5[120]; // [esp+0h] [ebp-78h] BYREF

  v2 = a1 & 0x3FF;
  BYTE1(v2) |= 4u;
  result = 0;
  if ( dword_8D3FB8(v2, 1, v5, 120) )
  {
    if ( a1 == sub_5905DD(v5) )
      return 1;
    if ( !a2 )
      return 1;
    v3 = (char *)sub_590616(dword_8D3FA8);
    if ( v3 != sub_58E1B0((_DWORD *)dword_8D3FA8) )
      return 1;
  }
  return result;
}
