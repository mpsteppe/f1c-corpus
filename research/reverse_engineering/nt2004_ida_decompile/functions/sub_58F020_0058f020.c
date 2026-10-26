int __cdecl sub_58F020(int a1, char a2)
{
  int result; // eax

  result = 0;
  if ( *(_BYTE *)(a1 + 97) < 0xC8u )
  {
    *(_BYTE *)((unsigned __int8)(*(_BYTE *)(a1 + 97))++ + a1 + 98) = a2;
    return 1;
  }
  return result;
}
