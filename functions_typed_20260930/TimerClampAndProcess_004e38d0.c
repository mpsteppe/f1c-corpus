int __thiscall sub_4E38D0(_DWORD *this)
{
  int v2; // eax
  int result; // eax
  int v4; // edi
  _DWORD *v5; // ebx

  v2 = this[746];
  if ( v2 >= 0 )
  {
    if ( v2 > 11 )
      this[746] = 11;
  }
  else
  {
    this[746] = 0;
  }
  result = this[746];
  v4 = 0;
  if ( result > 0 )
  {
    v5 = this + 747;
    do
    {
      DualArrayDestructor(v5);
      result = this[746];
      ++v4;
      v5 += 187;
    }
    while ( v4 < result );
  }
  this[746] = 0;
  return result;
}

