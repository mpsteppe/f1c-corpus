int __cdecl fputc(int Character, FILE *Stream)
{
  int v3; // edi

  _lock_file(Stream);
  if ( --Stream->_cnt < 0 )
  {
    v3 = _flsbuf(Character, Stream);
  }
  else
  {
    v3 = (unsigned __int8)Character;
    *Stream->_ptr++ = Character;
  }
  _unlock_file(Stream);
  return v3;
}
