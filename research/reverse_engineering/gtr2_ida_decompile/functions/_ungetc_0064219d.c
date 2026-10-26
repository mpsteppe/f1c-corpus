int __cdecl ungetc(int Character, FILE *Stream)
{
  int flag; // eax
  char *v3; // eax
  int v5; // eax

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
  v3 = --Stream->_ptr;
  if ( (Stream->_flag & 0x40) != 0 )
  {
    if ( *v3 != (_BYTE)Character )
    {
      Stream->_ptr = v3 + 1;
      return -1;
    }
  }
  else
  {
    *v3 = Character;
  }
  v5 = Stream->_flag;
  ++Stream->_cnt;
  Stream->_flag = v5 & 0xFFFFFFEE | 1;
  return (unsigned __int8)Character;
}
