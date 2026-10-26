bool __thiscall sub_4D6190(_DWORD *this, float a2, float a3)
{
  int v3; // ecx
  long double v4; // st7
  double v6; // st6
  double v7; // st6
  float v8; // [esp+0h] [ebp-4h]
  float v9; // [esp+8h] [ebp+4h]

  v3 = this[329] - 1;
  switch ( v3 )
  {
    case 0:
      v8 = 0.049087387;
      break;
    case 1:
      v8 = 0.024543693;
      break;
    case 2:
      v8 = 0.016362462;
      break;
    case 3:
      v8 = 0.012271847;
      break;
    default:
      v8 = 0.098174773;
      break;
  }
  v4 = fabs(a2);
  if ( v4 <= v8 )
    return 1;
  switch ( v3 )
  {
    case 0:
      v6 = 0.088799998;
      break;
    case 1:
      v6 = 0.066699997;
      break;
    case 2:
      v6 = 0.022500001;
      break;
    case 3:
      v6 = 0.015;
      break;
    default:
      v6 = 0.1;
      break;
  }
  v9 = v8 + v8;
  v7 = v6 * a3;
  if ( v9 > v7 )
    v7 = v9;
  return v4 <= v7;
}
