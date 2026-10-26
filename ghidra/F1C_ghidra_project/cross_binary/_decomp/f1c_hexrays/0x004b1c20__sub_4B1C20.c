// f1c  0x004b1c20  size=78
void *__thiscall sub_4B1C20(_BYTE *this, int a2, char a3, char a4, char a5, int a6, char a7)
{
  sub_566650(a2);
  this[21] = a3;
  this[22] = a4;
  this[23] = a5;
  if ( a6 )
    sub_566650(a6);
  if ( a7 )
    this[20] = a3;
  return sub_4A1B70(this);
}
