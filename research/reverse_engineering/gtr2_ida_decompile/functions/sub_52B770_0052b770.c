const char *__thiscall sub_52B770(void *this)
{
  const char *result; // eax

  switch ( (unsigned int)this )
  {
    case 1u:
      result = "Engine";
      break;
    case 2u:
      result = "Gearbox";
      break;
    case 3u:
    case 7u:
      result = "Clutch";
      break;
    case 4u:
      result = "Suspension";
      break;
    case 5u:
      result = "Brakes";
      break;
    case 6u:
      result = "Accident";
      break;
    case 8u:
      result = "Electronics";
      break;
    case 9u:
      result = "Fuel";
      break;
    default:
      result = (const char *)&off_71C270;
      break;
  }
  return result;
}
