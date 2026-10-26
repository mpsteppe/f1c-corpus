int __cdecl fclose(FILE *Stream)
{
  int v1; // edi

  v1 = -1;
  if ( (Stream->_flag & 0x40) != 0 )
  {
    Stream->_flag = 0;
  }
  else
  {
    _lock_file(Stream);
    v1 = _fclose_lk(Stream);
    _unlock_file(Stream);
  }
  return v1;
}
