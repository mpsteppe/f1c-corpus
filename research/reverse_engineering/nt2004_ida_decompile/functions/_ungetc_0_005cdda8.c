int __cdecl ungetc_0(int Character, FILE *Stream)
{
  int flag; // eax
  int v4; // eax

  if ( Character == -1 )
    return -1;
  flag = Stream->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( !Stream->_base )
    _getbuf(Stream);
  if ( Stream->_ptr == Stream->_base )
  {
    if ( Stream->_cnt )
      return -1;
    ++Stream->_ptr;
  }
  if ( (Stream->_flag & 0x40) != 0 )
  {
    if ( *--Stream->_ptr != (_BYTE)Character )
    {
      ++Stream->_ptr;
      return -1;
    }
  }
  else
  {
    *--Stream->_ptr = Character;
  }
  v4 = Stream->_flag;
  ++Stream->_cnt;
  LOBYTE(v4) = v4 & 0xEE | 1;
  Stream->_flag = v4;
  return (unsigned __int8)Character;
}
