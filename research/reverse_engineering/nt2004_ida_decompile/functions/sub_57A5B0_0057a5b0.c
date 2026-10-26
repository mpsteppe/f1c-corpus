int __thiscall sub_57A5B0(int *this, int Offset)
{
  if ( this[4] )
    return sub_5369D0(*this, Offset, 0);
  if ( fseek((FILE *)*this, Offset, 0) )
    return -1;
  return Offset;
}
