int __thiscall sub_52E240(int *this, int a2)
{
  int result; // eax

  result = dword_FADE9C - 2;
  switch ( dword_FADE9C )
  {
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
      result = *this;
      if ( *(_DWORD *)(*this + 14820) != 1 && this[2] == 10 )
      {
        result = sub_54F270(&byte_FADF20, *this);
        if ( (_BYTE)result )
          result = sub_52C870(a2, 0);
      }
      break;
    default:
      return result;
  }
  return result;
}
