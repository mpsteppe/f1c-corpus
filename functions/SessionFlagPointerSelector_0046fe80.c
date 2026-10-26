_DWORD *__thiscall SessionFlagPointerSelector(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  UIComponentInit5(this);
  this[59] = 0;
  this[60] = -1;
  *this = &off_5A01A0;
  switch ( a2 )
  {
    case 1:
      this[58] = &unk_7CEB64;
      result = this;
      break;
    case 2:
      this[58] = &unk_7CEB7C;
      result = this;
      break;
    case 3:
      this[58] = &unk_7CEB94;
      result = this;
      break;
    case 4:
      this[58] = &unk_7CEBAC;
      result = this;
      break;
    case 5:
      this[58] = &byte_7CEBC4;
      result = this;
      break;
    case 6:
      this[58] = &unk_7CEBDC;
      result = this;
      break;
    default:
      this[58] = 0;
      result = this;
      break;
  }
  return result;
}
