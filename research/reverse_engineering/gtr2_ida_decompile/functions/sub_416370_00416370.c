int __thiscall sub_416370(_DWORD *this, float a2)
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
    case 6:
      result = sub_471860(this[9], LODWORD(a2));
      break;
    case 7:
      sub_583360(a2);
      result = sub_57D8A0(this[9]);
      break;
    default:
      return result;
  }
  return result;
}
