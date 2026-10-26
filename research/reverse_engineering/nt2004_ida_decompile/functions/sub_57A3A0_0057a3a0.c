int __thiscall sub_57A3A0(int *this, void *Buffer, size_t ElementCount)
{
  if ( this[4] )
    return sub_536830(*this, (int)Buffer, ElementCount);
  else
    return sub_5BF5A6(Buffer, 1u, ElementCount, (FILE *)*this);
}
