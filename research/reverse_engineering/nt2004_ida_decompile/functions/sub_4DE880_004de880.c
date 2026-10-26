int __thiscall sub_4DE880(_DWORD *this, float a2)
{
  int result; // eax

  result = dword_7D7540 - 2;
  switch ( dword_7D7540 )
  {
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
      if ( *(_DWORD *)(*this + 16584) != 1 )
      {
        result = sub_4DEB10(this);
        if ( (_BYTE)result )
        {
          result = sub_4F8410(*this);
          if ( (_BYTE)result )
            result = sub_4DF490(a2, 0);
        }
      }
      break;
    default:
      return result;
  }
  return result;
}
