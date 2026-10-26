bool __thiscall sub_6440F0(FILE **this, int Offset)
{
  return fseek(this[1], Offset, 1) == 0;
}
