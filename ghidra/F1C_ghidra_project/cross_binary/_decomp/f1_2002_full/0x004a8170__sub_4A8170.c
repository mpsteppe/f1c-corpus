// f1_2002_full  0x004a8170  size=85
void *__thiscall sub_4A8170(_WORD *this, const char *a2, __int16 a3, __int16 a4, __int16 a5, const char *a6, char a7)
{
  sub_55B160((int)(this + 2), a2);
  this[11] = a3;
  this[12] = a4;
  this[13] = a5;
  if ( a6 )
    sub_55B160((int)(this + 6), a6);
  if ( a7 )
    this[10] = a3;
  return sub_49A890(this);
}
