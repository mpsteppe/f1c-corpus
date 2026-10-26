float *__thiscall sub_4A2400(_DWORD *this)
{
  float *result; // eax

  switch ( this[75] )
  {
    case 0x104:
      result = &flt_B70A44;
      break;
    case 0x105:
      result = &flt_B7096C;
      break;
    case 0x106:
      result = &flt_B709FC;
      break;
    case 0x107:
      result = (float *)&dword_B70948;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
