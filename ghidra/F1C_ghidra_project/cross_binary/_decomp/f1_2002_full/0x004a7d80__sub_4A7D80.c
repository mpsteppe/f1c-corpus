// f1_2002_full  0x004a7d80  size=78
void *__thiscall sub_4A7D80(_BYTE *this, const char *a2, char a3, char a4, char a5, const char *a6, char a7)
{
  sub_55B160((int)(this + 4), a2);
  this[21] = a3;
  this[22] = a4;
  this[23] = a5;
  if ( a6 )
    sub_55B160((int)(this + 12), a6);
  if ( a7 )
    this[20] = a3;
  return sub_49A890(this);
}
