int __thiscall sub_5E82E0(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v4; // eax
  int result; // eax

  v3 = a2;
  if ( a2 == 99 )
    v3 = this[63];
  v4 = v3 - 1;
  if ( v4 )
  {
    result = v4 - 1;
    if ( result )
    {
      if ( !--result )
      {
        result = a3;
        this[201] = a3;
      }
    }
    else
    {
      this[134] = a3;
    }
  }
  else
  {
    result = a3;
    this[67] = a3;
  }
  return result;
}
