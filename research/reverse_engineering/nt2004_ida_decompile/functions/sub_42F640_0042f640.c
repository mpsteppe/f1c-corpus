char *__thiscall sub_42F640(void *this)
{
  char *result; // eax

  switch ( (unsigned int)this )
  {
    case 1u:
    case 3u:
      result = aReady;
      break;
    case 2u:
      result = aGarage;
      break;
    case 4u:
    case 5u:
    case 6u:
    case 7u:
      result = aOnTrack;
      break;
    default:
      result = aNotReady;
      break;
  }
  return result;
}
