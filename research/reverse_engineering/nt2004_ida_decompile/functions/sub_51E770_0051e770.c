int __thiscall sub_51E770(_DWORD *this, char a2)
{
  int result; // eax
  int v3; // edx

  result = 0;
  v3 = this[4125];
  if ( a2 )
  {
    if ( v3 )
    {
      this[4386] = 0;
      this[4387] = 0;
      this[4388] = 0;
    }
    else
    {
      dword_75EA10 = 2;
    }
  }
  else if ( !v3 )
  {
    dword_75EA10 = 0;
  }
  return result;
}
