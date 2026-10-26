int __thiscall sub_5207A0(void *this)
{
  int result; // eax

  switch ( (unsigned int)this )
  {
    case 0u:
      result = 0;
      break;
    case 1u:
      result = 1;
      break;
    case 2u:
      result = 2;
      break;
    case 3u:
      result = 3;
      break;
    default:
      JUMPOUT(0x5207C1);
  }
  return result;
}
