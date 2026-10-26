char __thiscall sub_491450(_DWORD *this, _DWORD *a2)
{
  char result; // al

  switch ( this[69] )
  {
    case 0x1C9:
      result = 1;
      *a2 = 1;
      break;
    case 0x1CA:
      result = 1;
      *a2 = 2;
      break;
    case 0x1CB:
      result = 1;
      *a2 = 4;
      break;
    case 0x1CC:
      result = 1;
      *a2 = 8;
      break;
    case 0x1CD:
      result = 1;
      *a2 = 16;
      break;
    case 0x1CE:
      result = 1;
      *a2 = 32;
      break;
    case 0x1CF:
      result = 1;
      *a2 = 64;
      break;
    case 0x1D0:
      result = 1;
      *a2 = 128;
      break;
    case 0x1D1:
      result = 1;
      *a2 = 256;
      break;
    case 0x1D2:
      result = 1;
      *a2 = 512;
      break;
    case 0x1D3:
      result = 1;
      *a2 = 1024;
      break;
    default:
      *a2 = -1;
      result = 0;
      break;
  }
  return result;
}
