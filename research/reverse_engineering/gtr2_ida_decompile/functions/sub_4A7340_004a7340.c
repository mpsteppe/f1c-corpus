int __thiscall sub_4A7340(int *this)
{
  int result; // eax
  char v3; // bl
  int v4; // edx

  result = this[70];
  if ( result )
  {
    v3 = byte_B7075C[24 * *(_DWORD *)dword_B72314];
    if ( (unsigned __int8)sub_4CD650(this) )
    {
      v4 = *this;
      if ( v3 )
        this[67] = 4;
      else
        this[67] = 5;
    }
    else
    {
      v4 = *this;
      if ( v3 )
        this[67] = 0;
      else
        this[67] = 1;
    }
    return (*(int (__thiscall **)(int *, int))(v4 + 44))(this, this[67]);
  }
  return result;
}
