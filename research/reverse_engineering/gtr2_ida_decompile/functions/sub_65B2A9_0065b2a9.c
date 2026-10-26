int __thiscall sub_65B2A9(_DWORD *this, int a2)
{
  int result; // eax
  char v4; // [esp+0h] [ebp-4h]

  result = a2;
  if ( !a2 )
  {
    if ( !this[17] )
    {
      sub_65DD1F((int)(this + 6), (int)(this + 158), 0, "internal error: production failed", v4);
      this[17] = 1;
    }
    return 0;
  }
  return result;
}
