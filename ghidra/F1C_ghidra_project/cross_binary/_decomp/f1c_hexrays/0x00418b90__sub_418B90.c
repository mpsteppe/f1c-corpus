// f1c  0x00418b90  size=108
bool __stdcall sub_418B90(int a1)
{
  bool result; // al

  result = 1;
  switch ( dword_7D0308 )
  {
    case 0:
      result = dword_5BF9A0[5 * a1] == 0x7FFFFFFF;
      break;
    case 1:
      result = dword_5BF9A0[5 * a1] >= 70;
      break;
    case 2:
      result = dword_5BF9A0[5 * a1] >= 40;
      break;
    case 3:
      result = dword_5BF9A0[5 * a1] > 0;
      break;
    default:
      return result;
  }
  return result;
}
