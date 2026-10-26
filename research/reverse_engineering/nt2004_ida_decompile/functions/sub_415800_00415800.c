int __thiscall sub_415800(_DWORD *this, int a2)
{
  int result; // eax

  result = this[8];
  switch ( result )
  {
    case 0:
    case 3:
      result = this[9];
      *(_DWORD *)(result + 212) = a2;
      break;
    case 1:
    case 4:
      result = a2;
      *(_DWORD *)(this[9] + 212) = a2;
      break;
    case 2:
    case 5:
      *(_DWORD *)(this[9] + 212) = a2;
      break;
    default:
      return result;
  }
  return result;
}
