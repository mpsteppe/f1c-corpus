int __thiscall sub_5472D0(float *this, int a2, int *a3)
{
  int result; // eax

  result = a2 - 1;
  switch ( a2 )
  {
    case 1:
      if ( a3 )
      {
        result = CRTFtol(this[24] * 255.0);
        *a3 = result;
      }
      break;
    case 2:
      if ( a3 )
      {
        result = CRTFtol(this[20] * 255.0);
        *a3 = result;
      }
      break;
    case 3:
      if ( a3 )
      {
        result = CRTFtol(this[28] * 255.0);
        *a3 = result;
      }
      break;
    case 4:
      if ( a3 )
      {
        result = CRTFtol(this[32] * 255.0);
        *a3 = result;
      }
      break;
    default:
      return result;
  }
  return result;
}
