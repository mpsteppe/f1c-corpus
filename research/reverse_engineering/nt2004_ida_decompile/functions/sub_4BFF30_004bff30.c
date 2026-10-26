char *__thiscall sub_4BFF30(void *this)
{
  char *result; // eax

  switch ( (unsigned int)this )
  {
    case 0u:
      result = aServePenalty;
      break;
    case 1u:
      result = aFuel;
      break;
    case 2u:
      result = aTires;
      break;
    case 3u:
      result = aDamage;
      break;
    case 4u:
      result = aTireCompound;
      break;
    case 5u:
      result = aLeftFrontTire;
      break;
    case 6u:
      result = aRightFrontTire;
      break;
    case 7u:
      result = aLeftRearTire;
      break;
    case 8u:
      result = aRightRearTire;
      break;
    case 9u:
      result = aWedge;
      break;
    case 0xAu:
      result = aTrackBar;
      break;
    case 0xBu:
      result = aGrilleTape;
      break;
    default:
      result = aError_0;
      break;
  }
  return result;
}
