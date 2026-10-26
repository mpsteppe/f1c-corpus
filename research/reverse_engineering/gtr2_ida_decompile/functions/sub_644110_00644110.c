bool __thiscall sub_644110(FILE **this, int Offset)
{
  return fseek(this[1], Offset, 0) == 0;
}
