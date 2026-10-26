int __thiscall sub_4AC060(int this)
{
  int v2; // eax

  switch ( *(_DWORD *)(this + 864) )
  {
    case 0x10A:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x10F:
    case 0x110:
    case 0x111:
    case 0x112:
    case 0x113:
    case 0x114:
    case 0x115:
      v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 10);
      goto LABEL_4;
    case 0x12B:
    case 0x12C:
    case 0x12D:
    case 0x133:
    case 0x134:
    case 0x135:
    case 0x1A4:
    case 0x1A5:
    case 0x1A8:
    case 0x1A9:
    case 0x1AB:
    case 0x1AC:
    case 0x1AD:
    case 0x1AE:
    case 0x1AF:
    case 0x1B0:
    case 0x1B1:
    case 0x1B3:
    case 0x1B4:
    case 0x1B5:
    case 0x1B6:
    case 0x1C3:
    case 0x1C4:
      v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 6);
LABEL_4:
      if ( v2 )
        sub_4A0FF0();
      break;
    default:
      break;
  }
  if ( *(_DWORD *)(this + 864) == 307 || *(_DWORD *)(this + 864) == 427 || *(_DWORD *)(this + 864) == 452 )
    *(_BYTE *)(this + 816) = 1;
  return 0;
}
