char *__thiscall sub_4A47E0(void *this)
{
  char *result; // eax

  switch ( (unsigned int)this )
  {
    case 0u:
      result = aStopGo;
      break;
    case 1u:
      result = aFuel;
      break;
    case 2u:
      result = aTyres;
      break;
    case 3u:
      result = aWing_1;
      break;
    case 4u:
      result = aDamage;
      break;
    default:
      result = aError_0;
      break;
  }
  return result;
}
