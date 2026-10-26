_DWORD *__thiscall sub_4E2370(_BYTE *this, int a2)
{
  _DWORD *result; // eax
  int v3; // ecx

  this[2924] = 0;
  switch ( a2 )
  {
    case 4:
      this[2924] = 1;
      break;
    case 5:
      this[2924] = 2;
      break;
    case 6:
      this[2924] = 3;
      break;
    case 1:
      this[2924] = 0;
      break;
    case 2:
      this[2924] = 0;
      break;
    case 3:
      this[2924] = 0;
      break;
    default:
      *((_DWORD *)this + 731) = a2;
      break;
  }
  result = this + 492;
  v3 = 4;
  do
  {
    *result = -1;
    result += 74;
    --v3;
  }
  while ( v3 );
  return result;
}

