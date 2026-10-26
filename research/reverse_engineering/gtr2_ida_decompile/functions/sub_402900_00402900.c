double sub_402900()
{
  double v0; // st7
  double result; // st7
  float v2; // [esp+0h] [ebp-4h]

  v2 = 1.0;
  switch ( *(_DWORD *)dword_B640C8 )
  {
    case 0:
      v2 = 1.25;
      break;
    case 1:
      v2 = 0.80000001;
      break;
    case 2:
      v2 = 0.89999998;
      break;
    case 3:
    case 4:
      v2 = 1.05;
      break;
    case 5:
      v2 = 1.2;
      break;
    case 6:
      v2 = 1.35;
      break;
    default:
      break;
  }
  v0 = sub_592960(&dword_FB1EF8);
  if ( v0 >= 0.0 )
  {
    if ( v0 > 1.0 )
      v0 = 1.0;
  }
  else
  {
    v0 = 0.0;
  }
  result = v2 - v0;
  if ( result < 0.30000001 )
    return 0.30000001;
  return result;
}
