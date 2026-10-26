char *__thiscall sub_4BB730(void *this)
{
  char *result; // eax

  switch ( (unsigned int)this )
  {
    case 1u:
      result = aEngine;
      break;
    case 2u:
      result = aGearbox;
      break;
    case 3u:
    case 7u:
      result = aClutch;
      break;
    case 4u:
      result = aSuspension;
      break;
    case 5u:
      result = aBrakes;
      break;
    case 6u:
      result = aAccident;
      break;
    case 8u:
      result = aElectronics;
      break;
    case 9u:
      result = aFuel_0;
      break;
    default:
      result = (char *)&unk_5D2524;
      break;
  }
  return result;
}

