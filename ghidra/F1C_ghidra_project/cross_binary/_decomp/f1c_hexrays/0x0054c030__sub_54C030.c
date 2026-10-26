// f1c  0x0054c030  size=124
void __thiscall sub_54C030(_DWORD *this, int a2, int a3, int a4, int a5)
{
  unsigned int v6; // eax

  if ( a4 == 1 )
  {
    if ( this[17] )
      sub_54C030(a2, a3, 1, 1);
    if ( a5 && this[19] )
      sub_54C030(a2, a3, 1, 1);
  }
  if ( a2 == 1 )
  {
    v6 = this[15] & 0xFFFFFFFD;
  }
  else
  {
    if ( a2 )
      goto LABEL_12;
    v6 = this[15] | 6;
  }
  this[15] = v6;
LABEL_12:
  if ( a3 == 1 )
  {
    this[15] &= ~4u;
  }
  else if ( !a3 )
  {
    this[15] |= 4u;
  }
}
