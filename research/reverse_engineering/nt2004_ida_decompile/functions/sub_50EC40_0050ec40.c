int __thiscall sub_50EC40(_DWORD *this)
{
  int v2; // eax
  int result; // eax
  int v4; // edi
  _DWORD *v5; // ebx

  v2 = this[867];
  if ( v2 >= 0 )
  {
    if ( v2 > 15 )
      this[867] = 15;
  }
  else
  {
    this[867] = 0;
  }
  result = this[867];
  v4 = 0;
  if ( result > 0 )
  {
    v5 = this + 868;
    do
    {
      sub_508930(v5);
      result = this[867];
      ++v4;
      v5 += 187;
    }
    while ( v4 < result );
  }
  this[867] = 0;
  return result;
}
