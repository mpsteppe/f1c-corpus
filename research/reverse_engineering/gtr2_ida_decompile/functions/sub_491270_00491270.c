float *__thiscall sub_491270(_DWORD *this)
{
  double v1; // st7
  float *result; // eax

  v1 = 1.0;
  switch ( this[218] )
  {
    case 1:
      result = (float *)this[217];
      *result = 0.69999999;
      break;
    case 2:
      result = (float *)this[217];
      *result = 0.85000002;
      break;
    case 3:
      result = (float *)this[217];
      *result = 1.0;
      break;
    case 4:
      result = (float *)this[217];
      *result = 1.3;
      break;
    case 5:
      v1 = 2.0;
      goto LABEL_7;
    default:
LABEL_7:
      result = (float *)this[217];
      *result = v1;
      break;
  }
  return result;
}
