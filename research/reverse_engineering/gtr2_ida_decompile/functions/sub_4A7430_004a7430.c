_DWORD *__thiscall sub_4A7430(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  sub_4D9E90();
  this[69] = a2;
  *this = &off_6FF050;
  switch ( a2 )
  {
    case 267:
      this[70] = &dword_B6FAFC;
      result = this;
      break;
    case 268:
      this[70] = &dword_B6FA0C;
      result = this;
      break;
    case 269:
      this[70] = &dword_B6FBBC;
      result = this;
      break;
    case 270:
      this[70] = &dword_B6F97C;
      result = this;
      break;
    case 271:
      this[70] = &dword_B6F9E8;
      result = this;
      break;
    case 272:
      this[70] = &unk_B6FA30;
      result = this;
      break;
    case 273:
      this[70] = &dword_B6F9C4;
      result = this;
      break;
    case 274:
      this[70] = &dword_B6FA54;
      result = this;
      break;
    case 275:
      this[70] = &dword_B6F910;
      goto LABEL_12;
    case 276:
      this[70] = &dword_B6FB50;
      result = this;
      break;
    default:
LABEL_12:
      result = this;
      break;
  }
  return result;
}
