char *__thiscall sub_4DBF10(void *this)
{
  char *result; // eax

  switch ( (unsigned int)this )
  {
    case 1u:
      result = aEngine_0;
      break;
    case 2u:
      result = aGearbox;
      break;
    case 3u:
      result = aClutch;
      break;
    case 4u:
      result = aSuspension_0;
      break;
    case 5u:
      result = aBrakes;
      break;
    case 6u:
      result = aAccident;
      break;
    case 7u:
      result = aStall;
      break;
    case 8u:
      result = aFuel_0;
      break;
    default:
      result = (char *)&off_6100C0;
      break;
  }
  return result;
}
