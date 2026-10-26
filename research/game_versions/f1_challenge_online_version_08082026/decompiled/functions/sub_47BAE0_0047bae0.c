int __thiscall sub_47BAE0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v5; // eax

  v3 = this[59];
  if ( a2 > 0 )
  {
    this[59] = a2 + v3;
    v5 = sub_47BC90(this) - 1;
    if ( this[59] > v5 )
      this[59] = v5;
  }
  else
  {
    this[59] = a2 + v3;
    if ( a2 + v3 < 0 )
    {
      this[59] = 0;
      return sub_47BD90(this);
    }
  }
  return sub_47BD90(this);
}
