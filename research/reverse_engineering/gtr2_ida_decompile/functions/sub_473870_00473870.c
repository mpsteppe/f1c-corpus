const char *__stdcall sub_473870(int a1)
{
  const char *result; // eax

  switch ( a1 )
  {
    case 1:
      result = "Incompatible game versions.";
      break;
    case 2:
      result = "The game is full.";
      break;
    case 3:
      result = "You can only join during practice sessions.";
      break;
    case 4:
      result = "Bad password.";
      break;
    case 5:
      result = "Join timed out.";
      break;
    default:
      result = "No join failure.";
      break;
  }
  return result;
}
