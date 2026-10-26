char __thiscall SwitchMaps0x1a20x1acToBitmask(_DWORD *this, _DWORD *a2)
{
  char result; // al

  switch ( this[199] )
  {
    case 0x1A2:
      result = 1;
      *a2 = 1;
      break;
    case 0x1A3:
      result = 1;
      *a2 = 2;
      break;
    case 0x1A4:
      result = 1;
      *a2 = 4;
      break;
    case 0x1A5:
      result = 1;
      *a2 = 8;
      break;
    case 0x1A6:
      result = 1;
      *a2 = 16;
      break;
    case 0x1A7:
      result = 1;
      *a2 = 32;
      break;
    case 0x1A8:
      result = 1;
      *a2 = 64;
      break;
    case 0x1A9:
      result = 1;
      *a2 = 128;
      break;
    case 0x1AA:
      result = 1;
      *a2 = 256;
      break;
    case 0x1AB:
      result = 1;
      *a2 = 512;
      break;
    case 0x1AC:
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

