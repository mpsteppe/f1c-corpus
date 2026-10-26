int __stdcall sub_4F8280(int a1, float *a2, float *a3, float *a4)
{
  int result; // eax

  result = (int)a2;
  *a2 = flt_5D67C8;
  *a3 = flt_5D67CC;
  *a4 = flt_5D67D0;
  switch ( a1 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 43:
      *(_DWORD *)a2 = dword_5D67B0;
      result = dword_5D67B4;
      *(_DWORD *)a3 = dword_5D67B4;
      *(_DWORD *)a4 = dword_5D67B8;
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
    case 38:
    case 39:
    case 40:
    case 41:
    case 44:
      *(_DWORD *)a2 = dword_5D67BC;
      result = dword_5D67C0;
      *(_DWORD *)a3 = dword_5D67C0;
      *(_DWORD *)a4 = dword_5D67C4;
      break;
    default:
      return result;
  }
  return result;
}

