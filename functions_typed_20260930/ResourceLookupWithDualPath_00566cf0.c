bool __thiscall sub_566CF0(int *this, const char *a2)
{
  if ( this[4] )
    return StringLengthDispatch(*this, a2) != -1;
  else
    return StringWriteToFile(a2, *this) != -1;
}

