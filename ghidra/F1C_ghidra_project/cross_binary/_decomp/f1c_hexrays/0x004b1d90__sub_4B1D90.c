// f1c  0x004b1d90  size=80
void *__thiscall sub_4B1D90(_DWORD *this, int a2, int a3, int a4, int a5, int a6, char a7)
{
  sub_566650(a2);
  this[8] = a5;
  this[6] = a3;
  this[7] = a4;
  if ( a6 )
    sub_566650(a6);
  if ( a7 )
    this[5] = a3;
  return sub_4A1B70(this);
}
