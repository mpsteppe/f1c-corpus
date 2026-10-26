int __stdcall sub_504AD0(int a1)
{
  int result; // eax

  result = dword_75CBB0;
  switch ( dword_75CBB0 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = sub_505020(a1);
      break;
    case 6:
      result = sub_5051A0(a1);
      break;
    case 7:
      result = sub_504ED0(a1);
      break;
    default:
      return result;
  }
  return result;
}
