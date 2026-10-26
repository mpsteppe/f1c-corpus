int __stdcall sub_58F940(int a1)
{
  int v2; // edx
  int v3; // eax
  char ArgList[256]; // [esp+0h] [ebp-100h] BYREF

  if ( !dword_FB1CE4 )
    return 1;
  v2 = (byte_91CB5C == 0) + 1;
  dword_FB1CF8 = ((byte_91CB5C == 0) + 1) & 1;
  v3 = 0;
  switch ( dword_91CB68 )
  {
    case 2:
      v3 = 1;
      break;
    case 3:
      v3 = 4;
      break;
    case 4:
      v3 = 2;
      break;
    case 5:
      v3 = 8;
      break;
    case 6:
      v3 = 16;
      break;
    default:
      break;
  }
  if ( byte_91CB5E )
    v2 |= 0x40u;
  dword_FB1CF0 = a1;
  if ( sub_5FB420(dword_FB1CE0, dword_FB1CE8, dword_903EB8[0], dword_903EBC, dword_903EC0, v2, v3, dword_FB1CF4) )
  {
    sub_5D8CB0(0, ArgList);
    if ( sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vidman.cpp", 529) )
      sub_561210((int)byte_FAE910, "CUBE error : %s", ArgList);
  }
  return 0;
}
