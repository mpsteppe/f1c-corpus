// f1c  0x0042a110  size=102
int __thiscall sub_42A110(_DWORD *this)
{
  int result; // eax

  if ( dword_7C56A4 == 7 )
  {
    result = dword_8ACF8C - 1;
    if ( this[4111] != dword_8ACF8C - 1 )
    {
      result = sub_4A5C40(this + 3251);
      if ( !result || result == 4 || this[4121] == 1 )
      {
        sub_4A5E40(this + 3251);
        return sub_42AC70(1);
      }
    }
  }
  else
  {
    sub_4A5E40(this + 3251);
    return sub_42AC70(1);
  }
  return result;
}
