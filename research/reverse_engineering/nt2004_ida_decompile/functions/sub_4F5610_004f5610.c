void __thiscall sub_4F5610(int this)
{
  switch ( *(_DWORD *)(this + 4) )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      sub_4F37D0(this);
      break;
    case 5:
      sub_4F2E10(this);
      break;
    case 6:
    case 7:
    case 0x11:
      sub_4F55C0((_DWORD *)this);
      break;
    case 8:
      sub_4F5470(this);
      break;
    case 9:
      nullsub_6((void *)this);
      break;
    case 0xF:
      sub_4F4880((float *)this);
      break;
    case 0x10:
      sub_4F4150(this);
      break;
    default:
      return;
  }
}
