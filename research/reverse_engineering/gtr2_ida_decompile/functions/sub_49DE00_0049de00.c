int __thiscall sub_49DE00(int this)
{
  int result; // eax

  switch ( *(_DWORD *)(this + 816) )
  {
    case 0x1D7:
      byte_B6DC18 = 0;
      sub_4CE740(&byte_B6DC18, 26);
      *(_DWORD *)(this + 808) = "WWWWWWWWWWWWWWWWW";
      return 0;
    case 0x1D8:
      byte_B6DC34 = 0;
      *(_DWORD *)(this + 788) = 0;
      sub_4CE740(&byte_B6DC34, 26);
      *(_DWORD *)(this + 808) = "WWWWWWWWWWWWWWW";
      return 0;
    case 0x1D9:
      byte_B6DC50[0] = 0;
      *(_DWORD *)(this + 788) = 0;
      sub_4CE740(byte_B6DC50, 15);
      return 0;
    case 0x1DA:
      byte_B6DC60 = 0;
      *(_DWORD *)(this + 788) = 0;
      sub_4CE740(&byte_B6DC60, 15);
      return 0;
    case 0x1DB:
      sub_4CE740(byte_B6DC70, 32);
      *(_DWORD *)(this + 788) = 2;
      return 0;
    case 0x1DC:
    case 0x1F5:
      *(_DWORD *)(this + 788) = 0;
      ((void (__thiscall *)(int, int))byte_4CE840)(this, 160);
      *(_BYTE *)(this + 273) = 1;
      return 0;
    case 0x1DE:
      byte_B6DC90 = 0;
      sub_4CE740(&byte_B6DC90, 64);
      return 0;
    case 0x1DF:
      sub_4CE740(&unk_B6DCF0, 255);
      goto LABEL_12;
    case 0x1E0:
      sub_4CE740(&unk_B6DDF0, 255);
      goto LABEL_12;
    case 0x1E1:
      byte_B6DEF0 = 0;
      sub_4CE740(&byte_B6DEF0, 32);
      return 0;
    case 0x1E2:
      byte_B6DF10 = 0;
      sub_4CE740(&byte_B6DF10, 32);
      goto LABEL_23;
    case 0x1E3:
      sub_4CE740(byte_B6DF30, 16);
      goto LABEL_12;
    case 0x1E4:
      sub_4CE740(byte_B6DF40, 16);
      goto LABEL_12;
    case 0x1E5:
      sub_4CE740(byte_B6DF50, 128);
LABEL_12:
      *(_DWORD *)(this + 788) = 0;
      result = 0;
      break;
    case 0x1E6:
    case 0x1E7:
    case 0x1E8:
    case 0x1E9:
    case 0x1EA:
    case 0x1EB:
    case 0x1EC:
    case 0x1ED:
    case 0x1EE:
    case 0x1EF:
      *(_DWORD *)(this + 788) = 0;
      ((void (__thiscall *)(int, int))byte_4CE840)(this, 160);
      *(_BYTE *)(this + 271) = 0;
      result = 0;
      break;
    case 0x1F0:
      *(_DWORD *)(this + 788) = 0;
      sub_4CE740(byte_B6DFD0, 32);
      result = 0;
      break;
    case 0x1F1:
      *(_DWORD *)(this + 788) = 0;
      *(_BYTE *)(this + 271) = 0;
      sub_4CE740(&unk_B6DFF0, 32);
      result = 0;
      break;
    case 0x1F2:
      *(_BYTE *)(this + 270) = 1;
      *(_DWORD *)(this + 788) = 0;
      *(_BYTE *)(this + 271) = 0;
      sub_4CE740(&byte_B6E010, 16);
      result = 0;
      break;
    case 0x1F3:
      *(_BYTE *)(this + 270) = 1;
      *(_DWORD *)(this + 788) = 0;
      sub_4CE740(&byte_B6E020, 16);
      result = 0;
      break;
    case 0x1F4:
      *(_DWORD *)(this + 788) = 0;
      sub_4CE740(&byte_B6E030, 64);
      result = 0;
      break;
    default:
LABEL_23:
      result = 0;
      break;
  }
  return result;
}
