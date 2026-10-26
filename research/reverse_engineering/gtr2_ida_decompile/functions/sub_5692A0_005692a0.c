int __thiscall sub_5692A0(_DWORD *this, int a2)
{
  int result; // eax

  switch ( a2 )
  {
    case 5:
      this[952] = 1;
      break;
    case 6:
      this[952] = 2;
      break;
    case 7:
      this[952] = 3;
      break;
    default:
      this[952] = 0;
      break;
  }
  result = -1;
  this[158] = -1;
  this[232] = -1;
  this[306] = -1;
  this[380] = -1;
  return result;
}
