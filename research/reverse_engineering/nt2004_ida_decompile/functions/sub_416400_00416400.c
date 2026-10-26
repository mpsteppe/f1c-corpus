int __thiscall sub_416400(_DWORD *this, float a2)
{
  int result; // eax

  result = this[8];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = sub_45C060(a2);
      break;
    case 6:
      sub_51CDC0(a2);
      result = sub_51B7F0(this[9]);
      break;
    default:
      return result;
  }
  return result;
}
