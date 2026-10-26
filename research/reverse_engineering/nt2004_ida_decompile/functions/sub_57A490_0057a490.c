char *__thiscall sub_57A490(int *this, char *Buffer, int MaxCount)
{
  if ( this[4] )
    return sub_5367E0(*this, Buffer, MaxCount);
  else
    return fgets(Buffer, MaxCount, (FILE *)*this);
}
