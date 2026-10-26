int __thiscall sub_41BE20(void *this)
{
  int result; // eax

  result = 1;
  switch ( (unsigned int)this )
  {
    case 1u:
    case 2u:
    case 0xBu:
    case 0xCu:
    case 0x15u:
    case 0x17u:
      result = 2;
      break;
    default:
      return result;
  }
  return result;
}
