int __stdcall sub_58C090(int a1, float *a2, float *a3, float *a4)
{
  int result; // eax

  result = (int)a2;
  *a2 = flt_903E8C;
  *a3 = flt_903E90;
  *a4 = flt_903E94;
  switch ( a1 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 57:
      *(_DWORD *)a2 = dword_903E74;
      result = dword_903E78;
      *(_DWORD *)a3 = dword_903E78;
      *(_DWORD *)a4 = dword_903E7C;
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 52:
    case 53:
    case 54:
    case 55:
    case 58:
      *(_DWORD *)a2 = dword_903E80;
      result = dword_903E84;
      *(_DWORD *)a3 = dword_903E84;
      *(_DWORD *)a4 = dword_903E88;
      break;
    default:
      return result;
  }
  return result;
}
