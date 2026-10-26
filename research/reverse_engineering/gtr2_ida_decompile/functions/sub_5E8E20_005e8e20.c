float *__thiscall sub_5E8E20(float *this, int a2, float *a3)
{
  float *result; // eax

  result = a3;
  if ( a3 )
  {
    switch ( a2 )
    {
      case 1:
        *a3 = this[25];
        break;
      case 2:
        if ( (*(_DWORD *)this & 0x40000) != 0 )
          *a3 = *((float *)dword_FB27AC + 21) * this[21];
        else
          *a3 = this[21];
        break;
      case 3:
        *a3 = this[29];
        break;
      case 4:
        *a3 = this[33];
        break;
      default:
        return result;
    }
  }
  return result;
}
