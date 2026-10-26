int __thiscall sub_5E8360(float *this, int a2, int a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]
  int v6; // [esp+10h] [ebp+8h]

  v4 = BYTE2(a3);
  v5 = (unsigned __int8)a3;
  result = a2 - 1;
  v6 = BYTE1(a3);
  switch ( a2 )
  {
    case 1:
      this[22] = (double)v4 * 0.0039215689;
      this[23] = (double)v6 * 0.0039215689;
      this[24] = (double)v5 * 0.0039215689;
      break;
    case 2:
      this[18] = (double)v4 * 0.0039215689;
      this[19] = (double)v6 * 0.0039215689;
      this[20] = (double)v5 * 0.0039215689;
      break;
    case 3:
      this[26] = (double)v4 * 0.0039215689;
      this[27] = (double)v6 * 0.0039215689;
      this[28] = (double)v5 * 0.0039215689;
      break;
    case 4:
      this[30] = (double)v4 * 0.0039215689;
      this[31] = (double)v6 * 0.0039215689;
      this[32] = (double)v5 * 0.0039215689;
      break;
    default:
      return result;
  }
  return result;
}
