int __cdecl setvbuf(FILE *Stream, char *Buffer, int Mode, size_t Size)
{
  size_t v5; // edi
  int flag; // ecx
  char *p_charbuf; // eax
  int v8; // [esp+8h] [ebp-4h]

  v8 = 0;
  if ( Mode != 4 && ((int)Size < 2 || Mode && Mode != 64) )
    return -1;
  v5 = Size & 0xFFFFFFFE;
  _lock_file(Stream);
  _flush(Stream);
  _freebuf((int)Stream);
  LOWORD(Stream->_flag) &= 0xC2F3u;
  flag = Stream->_flag;
  if ( (Mode & 4) != 0 )
  {
    Stream->_flag = flag | 4;
    p_charbuf = (char *)&Stream->_charbuf;
    v5 = 2;
LABEL_13:
    Stream->_cnt = 0;
    Stream->_bufsiz = v5;
    Stream->_base = p_charbuf;
    Stream->_ptr = p_charbuf;
    goto LABEL_14;
  }
  p_charbuf = Buffer;
  if ( Buffer )
  {
    BYTE1(flag) |= 5u;
    Stream->_flag = flag;
    goto LABEL_13;
  }
  p_charbuf = (char *)malloc(v5);
  if ( p_charbuf )
  {
    LOWORD(Stream->_flag) |= 0x408u;
    goto LABEL_13;
  }
  ++dword_7FF178;
  v8 = -1;
LABEL_14:
  _unlock_file(Stream);
  return v8;
}
