int __thiscall sub_54FCC0(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  switch ( a2 )
  {
    case 0:
      this[33] = 191;
      goto LABEL_6;
    case 1:
      this[33] = 127;
      this[33] = 191;
      break;
    case 2:
      this[33] = 63;
      this[33] = 191;
      break;
    case 3:
      this[33] = 0;
      this[33] = 191;
      break;
    default:
LABEL_6:
      this[33] = 191;
      break;
  }
  return result;
}

