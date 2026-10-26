_DWORD *__stdcall sub_503CE0(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax

  switch ( a1 )
  {
    case 1:
      result = a2;
      *a2 = 640;
      *a3 = 1080;
      *a4 = 90;
      break;
    case 2:
      result = a2;
      *a2 = 640;
      *a3 = 1080;
      *a4 = 130;
      break;
    case 3:
      result = a2;
      *a2 = 640;
      *a3 = 1080;
      *a4 = 170;
      break;
    case 4:
      result = a2;
      *a2 = 640;
      *a3 = 1080;
      *a4 = 210;
      break;
    case 5:
      result = a2;
      *a2 = 640;
      *a3 = 1080;
      *a4 = 250;
      break;
    default:
      result = a2;
      *a2 = 640;
      *a3 = 1080;
      *a4 = 50;
      break;
  }
  return result;
}
