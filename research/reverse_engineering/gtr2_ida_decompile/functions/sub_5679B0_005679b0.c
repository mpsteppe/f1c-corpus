_DWORD *__fastcall sub_5679B0(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6, _DWORD *a7)
{
  _DWORD *result; // eax

  result = a5;
  switch ( (unsigned int)a5 )
  {
    case 0u:
      result = a6;
      *a6 = a1;
      *a7 = a2;
      return result;
    case 1u:
      result = a7;
      *a6 = a1 - a3;
      *a7 = a2;
      return result;
    case 2u:
      result = a7;
      *a6 = a1 - a3 / 2;
      *a7 = a2;
      return result;
    case 3u:
      goto LABEL_7;
    case 4u:
      result = a7;
      *a6 = a1 - a3;
      *a7 = a2 - a4;
      return result;
    case 5u:
      a1 -= a3 / 2;
LABEL_7:
      result = a7;
      *a6 = a1;
      *a7 = a2 - a4;
      return result;
    case 6u:
      goto LABEL_10;
    case 7u:
      a1 -= a3;
      goto LABEL_10;
    case 8u:
      a1 -= a3 / 2;
LABEL_10:
      *a6 = a1;
      result = a7;
      *a7 = a2 - a4 / 2;
      break;
    default:
      return result;
  }
  return result;
}
