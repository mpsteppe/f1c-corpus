char __thiscall sub_414EF0(void **this)
{
  int v2; // eax
  char result; // al

  switch ( (unsigned int)*this )
  {
    case 0xFFFFFFFF:
    case 0u:
    case 1u:
    case 5u:
      goto LABEL_5;
    case 2u:
    case 3u:
      v2 = sub_40C460(this[1]);
      this[30] = (void *)v2;
      this[31] = (void *)v2;
      this[32] = (void *)dword_75AAC0;
      *this = (void *)4;
      goto LABEL_3;
    case 4u:
LABEL_3:
      result = 1;
      break;
    default:
      *this = (void *)-1;
LABEL_5:
      result = 0;
      break;
  }
  return result;
}
