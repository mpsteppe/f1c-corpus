int __thiscall sub_52D6D0(_DWORD *this, int a2)
{
  int result; // eax

  result = -1;
  if ( this[15] < a2 )
  {
    this[15] = a2;
    if ( dword_B71F24 == 6 )
    {
      this[a2 + 15] = this[13];
      this[this[15] + 20] = this[14];
      return this[14];
    }
  }
  return result;
}
