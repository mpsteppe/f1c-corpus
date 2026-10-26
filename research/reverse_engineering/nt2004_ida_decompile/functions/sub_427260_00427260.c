int __thiscall sub_427260(_DWORD *this)
{
  int result; // eax

  result = this[6060];
  if ( result )
  {
    result = this[5858];
    if ( *(_DWORD *)(result + 328) != 1 )
    {
      sub_427F50(0);
      sub_4C1920(this + 4147);
      result = dword_7D7540;
      if ( dword_7D7540 )
      {
        this[6006] = 18;
      }
      else
      {
        result = this[6006];
        if ( result == 18 || result == 19 || result == 7 || result == 11 )
          this[6006] = 5;
      }
    }
  }
  return result;
}
