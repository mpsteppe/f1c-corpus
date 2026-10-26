int __thiscall sub_42F560(_DWORD *this, float a2, char a3)
{
  int result; // eax

  result = (this[65] + 1) % 64;
  this[65] = result;
  if ( a3 )
  {
    result = LODWORD(a2);
    memset32(this, SLODWORD(a2), 0x40u);
  }
  else
  {
    *(float *)&this[result] = a2;
  }
  return result;
}
