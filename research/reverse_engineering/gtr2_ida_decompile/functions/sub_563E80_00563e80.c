_DWORD *__stdcall sub_563E80(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax

  switch ( a1 )
  {
    case 1:
      result = a2;
      *a2 = 50;
      *a3 = 590;
      *a4 = 90;
      break;
    case 2:
      result = a2;
      *a2 = 50;
      *a3 = 590;
      *a4 = 130;
      break;
    case 3:
      result = a2;
      *a2 = 640;
      *a3 = 1230;
      *a4 = 50;
      break;
    case 4:
      result = a2;
      *a2 = 640;
      *a3 = 1230;
      *a4 = 90;
      break;
    case 5:
      result = a2;
      *a2 = 640;
      *a3 = 1230;
      *a4 = 130;
      break;
    default:
      result = a2;
      *a2 = 50;
      *a3 = 590;
      *a4 = 50;
      break;
  }
  return result;
}
