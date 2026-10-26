FILE **__thiscall std::filebuf::close(FILE **this)
{
  if ( !this[20] || fclose(this[20]) )
    return 0;
  std::filebuf::_Init(0, 2);
  return this;
}
