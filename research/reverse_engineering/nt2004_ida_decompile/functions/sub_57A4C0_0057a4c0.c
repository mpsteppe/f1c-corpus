bool __thiscall sub_57A4C0(int *this, char *Buffer)
{
  if ( this[4] )
    return sub_5368C0(*this, Buffer) != -1;
  else
    return fputs(Buffer, (FILE *)*this) != -1;
}
