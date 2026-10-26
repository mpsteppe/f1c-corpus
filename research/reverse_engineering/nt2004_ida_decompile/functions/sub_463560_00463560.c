int __thiscall sub_463560(int *this)
{
  int result; // eax
  char v3; // si
  char v4; // si
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  result = *this;
  if ( *(_DWORD *)(*this + 30148) )
  {
    result = sub_5B9F90();
    if ( result <= 0 || result > 2 )
    {
      sub_5B9F60(*(_DWORD *)(*this + 30148));
      if ( dword_769848 == 1 )
      {
        v5[0] = 1;
        v5[1] = 4;
        v5[2] = 5;
        v5[3] = 8;
        v5[4] = 10;
        v5[5] = 11;
        v5[6] = 19;
        result = sub_5B9D70(1, v5, 7, 0);
        v4 = result;
        if ( dword_75CBA8 != 5 )
        {
          result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 6457);
          if ( (_BYTE)result )
            result = sub_500FE0((int)&unk_7D7920, aStartingIntern, v4);
        }
      }
      else
      {
        v3 = dword_7699BC[0];
        result = sub_5B9D90(*(_DWORD *)dword_7699BC, *(_DWORD *)dword_7699BC + 99);
        if ( dword_75CBA8 != 5 )
        {
          result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 6434);
          if ( (_BYTE)result )
          {
            result = sub_500FE0((int)&unk_7D7920, aStartingLanUpd, v3);
            byte_764DC4 = 1;
            return result;
          }
        }
      }
      byte_764DC4 = 1;
    }
  }
  return result;
}
