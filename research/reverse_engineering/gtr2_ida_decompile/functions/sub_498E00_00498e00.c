int __thiscall sub_498E00(_DWORD *this)
{
  int v2; // eax

  switch ( this[216] )
  {
    case 0x1A5:
    case 0x1A8:
    case 0x1A9:
    case 0x1AC:
    case 0x1AD:
    case 0x1AF:
    case 0x1B1:
    case 0x1B3:
    case 0x1B5:
    case 0x1C3:
      this[207] = *(_DWORD *)this[210] <= dword_91CB60 ? 0 : 2;
      (*(void (__thiscall **)(_DWORD *))(*this + 184))(this);
      return 0;
    case 0x1AB:
    case 0x1AE:
    case 0x1B0:
    case 0x1B4:
      v2 = dword_91CB60;
      goto LABEL_5;
    case 0x1C4:
      v2 = dword_91CB64;
LABEL_5:
      this[207] = *(_DWORD *)this[210] <= v2 + 1 ? 0 : 2;
      goto LABEL_6;
    default:
LABEL_6:
      (*(void (__thiscall **)(_DWORD *))(*this + 184))(this);
      return 0;
  }
}
