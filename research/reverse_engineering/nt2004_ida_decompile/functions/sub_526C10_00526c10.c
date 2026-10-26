int __stdcall sub_526C10(int a1)
{
  int v2; // eax
  char ArgList[256]; // [esp+0h] [ebp-100h] BYREF

  if ( !dword_7DA98C )
    return 1;
  v2 = (byte_62A154 == 0) + 1;
  dword_7DA9A0 = ((byte_62A154 == 0) + 1) & 1;
  switch ( dword_62A160 )
  {
    case 2:
      v2 |= 0x20u;
      break;
    case 3:
      v2 |= 0x100u;
      break;
    case 4:
      v2 |= 0x40u;
      break;
    case 6:
      v2 |= 0x400u;
      break;
    case 16:
      v2 |= 0x100000u;
      break;
  }
  if ( byte_62A156 )
    v2 |= 0x80u;
  dword_7DA998 = a1;
  if ( sub_5A9820(dword_7DA990, dword_6152E8, dword_6152EC, dword_6152F0, v2, dword_7DA99C) )
  {
    sub_591C90(0, ArgList);
    if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_26, 481) )
      sub_500FE0((int)&unk_7D7920, "CUBE error : %s", ArgList);
  }
  return 0;
}
