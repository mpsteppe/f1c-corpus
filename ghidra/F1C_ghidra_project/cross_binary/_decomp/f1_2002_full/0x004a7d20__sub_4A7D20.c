// f1_2002_full  0x004a7d20  size=78
void *__thiscall sub_4A7D20(_DWORD *this, const char *a2, int a3, int a4, int a5, const char *a6, char a7)
{
  sub_55B160((int)(this + 1), a2);
  this[6] = a3;
  this[7] = a4;
  this[8] = a5;
  if ( a6 )
    sub_55B160((int)(this + 3), a6);
  if ( a7 )
    this[5] = a3;
  return sub_49A890(this);
}
