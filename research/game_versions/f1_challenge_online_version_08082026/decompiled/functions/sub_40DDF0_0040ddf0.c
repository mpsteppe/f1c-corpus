char __thiscall sub_40DDF0(_DWORD *this)
{
  int v2; // eax
  char result; // al

  switch ( *this )
  {
    case 0xFFFFFFFF:
    case 0:
    case 1:
      goto LABEL_5;
    case 2:
    case 3:
    case 4:
    case 5:
      v2 = sub_5679C0(aCinematicevent);
      if ( !sub_40D4C0(this[34], v2) )
        goto LABEL_4;
      result = 1;
      this[38] = 0;
      this[39] = 0;
      *this = 2;
      break;
    default:
LABEL_4:
      *this = -1;
LABEL_5:
      result = 0;
      break;
  }
  return result;
}
