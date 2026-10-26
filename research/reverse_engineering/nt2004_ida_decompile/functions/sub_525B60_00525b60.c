int __stdcall sub_525B60(int a1, float *a2, float *a3, float *a4)
{
  int result; // eax

  result = (int)a2;
  *a2 = flt_614D54;
  *a3 = flt_614D58;
  *a4 = flt_614D5C;
  switch ( a1 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 44:
      *(_DWORD *)a2 = dword_614D3C;
      result = dword_614D40;
      *(_DWORD *)a3 = dword_614D40;
      *(_DWORD *)a4 = dword_614D44;
      break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 39:
    case 40:
    case 41:
    case 42:
      *(_DWORD *)a2 = dword_614D48;
      result = dword_614D4C;
      *(_DWORD *)a3 = dword_614D4C;
      *(_DWORD *)a4 = dword_614D50;
      break;
    default:
      return result;
  }
  return result;
}
