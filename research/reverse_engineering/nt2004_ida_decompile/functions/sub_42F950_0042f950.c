int __thiscall sub_42F950(_DWORD *this, int a2)
{
  int result; // eax
  signed int j; // esi
  signed int i; // esi

  result = a2;
  if ( this[3] != a2 )
  {
    this[3] = a2;
    if ( dword_75CBA8 == 5 )
    {
      switch ( a2 )
      {
        case 0:
        case 2:
        case 4:
          for ( i = 0; i < (int)NumOfElements; ++i )
            sub_4EDFE0(0);
          result = sub_4F9F50(&unk_7D7428);
          break;
        case 3:
          for ( j = 0; j < (int)NumOfElements; ++j )
            sub_4DEB50(0);
          result = sub_45D100(aBeginningPaceL, 3, 16909060, 0);
          break;
        case 5:
          sub_4F9F50(&unk_7D7428);
          result = sub_4EED40(dword_75AACC);
          if ( (_BYTE)result )
            result = sub_4DF490(0.0, 1);
          break;
        default:
          return result;
      }
    }
  }
  return result;
}
