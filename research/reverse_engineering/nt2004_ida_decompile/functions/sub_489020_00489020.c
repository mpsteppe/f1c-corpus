char __thiscall sub_489020(_DWORD *this, _DWORD *a2)
{
  char result; // al

  switch ( this[216] )
  {
    case 0x1F8:
      result = 1;
      *a2 = 1;
      break;
    case 0x1F9:
      result = 1;
      *a2 = 2;
      break;
    case 0x1FA:
      result = 1;
      *a2 = 4;
      break;
    case 0x1FB:
      result = 1;
      *a2 = 8;
      break;
    case 0x1FC:
      JUMPOUT(0x489092);
    case 0x1FD:
      result = 1;
      *a2 = 32;
      break;
    case 0x1FE:
      result = 1;
      *a2 = 64;
      break;
    case 0x1FF:
      result = 1;
      *a2 = 128;
      break;
    case 0x200:
      result = 1;
      *a2 = 256;
      break;
    case 0x201:
      result = 1;
      *a2 = 512;
      break;
    case 0x202:
      result = 1;
      *a2 = 1024;
      break;
    case 0x203:
      result = 1;
      *a2 = 2048;
      break;
    default:
      *a2 = -1;
      result = 0;
      break;
  }
  return result;
}
