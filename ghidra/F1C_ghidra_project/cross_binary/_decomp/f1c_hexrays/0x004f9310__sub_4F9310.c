// f1c  0x004f9310  size=270
int __stdcall sub_4F9310(int a1)
{
  int v2; // eax
  char v3[256]; // [esp+0h] [ebp-100h] BYREF

  if ( !dword_8AFE68 )
    return 1;
  v2 = (byte_5EC4A4 == 0) + 1;
  dword_8AFE7C = ((byte_5EC4A4 == 0) + 1) & 1;
  switch ( dword_5EC4B0 )
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
  if ( byte_5EC4A6 )
    v2 |= 0x80u;
  dword_8AFE74 = a1;
  if ( sub_55BFF0(dword_8AFE6C, dword_5D6D60, dword_5D6D64, dword_5D6D68, v2, dword_8AFE78) )
  {
    sub_53C5B0(0, v3);
    if ( sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_26, 484) )
      sub_4D7AA0((int)dword_8AD25C, (int)"CUBE error : %s", v3);
  }
  return 0;
}
