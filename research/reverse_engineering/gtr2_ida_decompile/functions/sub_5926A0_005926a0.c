double __fastcall sub_5926A0(int a1)
{
  double v1; // st7
  int v3; // [esp+0h] [ebp-4h]

  v3 = a1;
  switch ( a1 )
  {
    case 0:
      v1 = 12.0;
      v3 = 1;
      break;
    case 1:
      v1 = 11.0;
      v3 = 2;
      break;
    case 2:
      v1 = 13.0;
      v3 = 2;
      break;
    case 3:
    case 4:
      v1 = 13.0;
      v3 = 3;
      break;
    case 5:
      v1 = 9.5;
      v3 = 4;
      break;
    case 6:
      v1 = 14.0;
      v3 = 4;
      break;
    default:
      v1 = *(float *)&a1;
      break;
  }
  return (double)v3 * 86400.0 + v1 * 3600.0;
}
