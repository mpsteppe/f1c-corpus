// f1c  0x004b66e0  size=204
bool __thiscall sub_4B66E0(_DWORD *this, float a2, float a3)
{
  int v3; // ecx
  long double v4; // st7
  long double v5; // st6
  long double v7; // st7
  double v8; // st6
  float v9; // [esp+4h] [ebp+4h]

  v3 = this[619] - 1;
  switch ( v3 )
  {
    case 0:
      v4 = 0.045000002;
      break;
    case 1:
      v4 = 0.022;
      break;
    case 2:
      v4 = 0.0099999998;
      break;
    case 3:
      v4 = 0.0070000002;
      break;
    default:
      v4 = 0.066;
      break;
  }
  v5 = fabs(a2);
  v9 = v5;
  if ( v5 <= v4 )
    return 1;
  v7 = fabs(a3);
  if ( v7 <= 7.5 )
  {
    if ( v7 < 2.0 )
      return 0;
  }
  else
  {
    v7 = 7.5;
  }
  switch ( v3 )
  {
    case 0:
      v8 = 0.029999999;
      break;
    case 1:
      v8 = 0.015;
      break;
    case 2:
      v8 = 0.0080000004;
      break;
    case 3:
      v8 = 0.0049999999;
      break;
    default:
      v8 = 0.045000002;
      break;
  }
  return v9 <= v8 * v7;
}
