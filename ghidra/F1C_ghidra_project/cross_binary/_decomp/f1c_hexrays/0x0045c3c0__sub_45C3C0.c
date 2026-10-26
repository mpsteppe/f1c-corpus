// f1c  0x0045c3c0  size=16
char __thiscall sub_45C3C0(_BYTE *this, char a2, char a3)
{
  char result; // al

  result = a2;
  *this = a2;
  this[1] = a3;
  return result;
}
