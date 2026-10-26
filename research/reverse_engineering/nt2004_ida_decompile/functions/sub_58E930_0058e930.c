BOOL __cdecl sub_58E930(int a1, int a2)
{
  BOOL result; // eax
  char v3; // cl

  result = 1;
  if ( *(_WORD *)a1 == LOWORD(dword_800100[2 * a2]) )
  {
    v3 = *(_BYTE *)(a1 + 8);
    if ( v3 > 0 )
      return dword_800104[2 * a2] < v3;
  }
  return result;
}
