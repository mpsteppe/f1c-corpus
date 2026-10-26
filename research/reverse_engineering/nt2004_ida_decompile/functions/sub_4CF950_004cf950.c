unsigned int __thiscall sub_4CF950(int *this, float *a2)
{
  unsigned int result; // eax
  double v3; // st7
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]

  v4 = (double)(((*this >> 20) & 0x3FF) - 511) * 0.0013837706;
  result = (unsigned int)*this >> 30;
  v3 = (double)(((*this >> 10) & 0x3FF) - 511) * 0.0013837706;
  v5 = (double)((*this & 0x3FF) - 511) * 0.0013837706;
  v6 = sqrt(1.0 - v4 * v4 - v3 * v3 - v5 * v5);
  switch ( result )
  {
    case 0u:
      result = (unsigned int)a2;
      *a2 = v6;
      a2[2] = v3;
      a2[1] = v4;
      a2[3] = v5;
      break;
    case 1u:
      result = (unsigned int)a2;
      *a2 = v4;
      a2[2] = v3;
      a2[1] = v6;
      a2[3] = v5;
      break;
    case 2u:
      result = (unsigned int)a2;
      *a2 = v4;
      a2[1] = v3;
      a2[2] = v6;
      a2[3] = v5;
      break;
    case 3u:
      result = (unsigned int)a2;
      *a2 = v4;
      a2[1] = v3;
      a2[2] = v5;
      a2[3] = v6;
      break;
    default:
      return result;
  }
  return result;
}
