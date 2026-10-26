int __thiscall sub_416220(_DWORD *this)
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
      sub_45A950(this + 4);
      if ( *this == -1 )
      {
        sub_4E0970(this);
      }
      else
      {
        sub_417BE0(this);
        sub_4E0780(this);
      }
      result = sub_4E0800(this);
      break;
    default:
      return result;
  }
  return result;
}
