int __thiscall sub_416610(_DWORD *this, int a2, float a3)
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
      sub_4161C0(this);
      result = sub_45AAE0(a2, a3);
      break;
    case 6:
      result = sub_518070(a2, 1);
      break;
    default:
      return result;
  }
  return result;
}
