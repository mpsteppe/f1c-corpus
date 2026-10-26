int __thiscall sub_57A3D0(int *this, char *Buffer, size_t ElementCount)
{
  if ( this[4] )
    return sub_5365A0(*this, Buffer, ElementCount);
  else
    return sub_5BED6F(Buffer, 1u, ElementCount, (FILE *)*this);
}
