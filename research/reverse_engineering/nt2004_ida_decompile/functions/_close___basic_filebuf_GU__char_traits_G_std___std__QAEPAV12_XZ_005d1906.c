FILE **__thiscall std::basic_filebuf<unsigned short>::close(FILE **this)
{
  if ( !this[20] || fclose(this[20]) )
    return 0;
  std::basic_filebuf<unsigned short>::_Init(0, 2);
  return this;
}
