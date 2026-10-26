int __thiscall sub_4D0130(__int16 *this, int a2, float *a3, float *a4)
{
  int v5; // eax
  double v6; // st7
  int v7; // ecx
  int result; // eax
  int v9; // [esp+8h] [ebp+4h]
  int v10; // [esp+Ch] [ebp+8h]

  v5 = (this[a2 + 4] >> 5) & 3;
  v9 = this[a2 + 4] & 0x1F;
  switch ( v5 )
  {
    case 0:
      v6 = (double)v9 * 0.00390625;
      goto LABEL_6;
    case 1:
      v6 = (double)v9 * 0.015625 + 0.125;
      goto LABEL_6;
    case 2:
      v6 = (double)v9 * -0.00390625;
      goto LABEL_6;
    case 3:
      v6 = (double)v9 * -0.015625 - 0.125;
LABEL_6:
      *a3 = v6;
      break;
    default:
      break;
  }
  v7 = this[a2 + 4];
  result = (v7 >> 13) & 7;
  v10 = (v7 >> 7) & 0x3F;
  switch ( result )
  {
    case 0:
      *a4 = (double)v10 * 0.0625;
      break;
    case 1:
      result = (int)a4;
      *a4 = (double)v10 * 0.25 + 4.0;
      break;
    case 2:
      *a4 = (double)v10 + 20.0;
      break;
    case 3:
      *a4 = (double)v10 * 4.0 + 84.0;
      break;
    case 4:
      result = (int)a4;
      *a4 = (double)v10 * -0.0625;
      break;
    case 5:
      *a4 = (double)v10 * -0.25 - 4.0;
      break;
    case 6:
      *a4 = (double)v10 * -1.0 - 20.0;
      break;
    case 7:
      result = (int)a4;
      *a4 = (double)v10 * -4.0 - 84.0;
      break;
    default:
      return result;
  }
  return result;
}
