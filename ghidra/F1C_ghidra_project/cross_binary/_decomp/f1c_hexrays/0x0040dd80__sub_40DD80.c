// f1c  0x0040dd80  size=69
char __thiscall sub_40DD80(_DWORD **this)
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
      v2 = sub_40C870(this[1]);
      this[35] = (_DWORD *)v2;
      this[36] = (_DWORD *)v2;
      this[37] = (_DWORD *)dword_7C54DC;
      *this = (_DWORD *)4;
      goto LABEL_3;
    case 4u:
LABEL_3:
      result = 1;
      break;
    default:
      *this = (_DWORD *)-1;
LABEL_5:
      result = 0;
      break;
  }
  return result;
}
