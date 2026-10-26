char sub_48F5B5()
{
  unsigned int v0; // kr00_4
  int v1; // eax
  char result; // al

  v0 = __getcallerseflags();
  v1 = *(_DWORD *)__ROR4__(dword_16C6DC4, loc_479010);
  __writeeflags(v0);
  switch ( v1 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}
