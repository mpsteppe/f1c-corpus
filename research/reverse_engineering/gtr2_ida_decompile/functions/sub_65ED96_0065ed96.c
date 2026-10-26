int __thiscall sub_65ED96(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( !a2 )
  {
    if ( !this[19] )
    {
      sub_65DD1F((_DWORD *)*this, (int)(this + 4), 0, "internal error: production failed");
      this[19] = 1;
    }
    this[20] = 1;
    return 0;
  }
  return result;
}
