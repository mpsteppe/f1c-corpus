size_t __cdecl fwrite(const void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v4; // edi
  size_t v5; // ebx
  unsigned int cnt; // eax
  size_t v8; // edi
  size_t v9; // edi
  unsigned int v10; // eax
  size_t v11; // eax
  int bufsiz; // [esp+Ch] [ebp-4h]

  v4 = ElementCount * ElementSize;
  v5 = ElementCount * ElementSize;
  if ( !(ElementCount * ElementSize) )
    return 0;
  if ( (Stream->_flag & 0x10C) != 0 )
    bufsiz = Stream->_bufsiz;
  else
    bufsiz = 4096;
  while ( 1 )
  {
    if ( (Stream->_flag & 0x108) != 0 )
    {
      cnt = Stream->_cnt;
      if ( cnt )
      {
        v8 = v5;
        if ( v5 >= cnt )
          v8 = Stream->_cnt;
        memcpy_0(Stream->_ptr, Buffer, v8);
        Stream->_cnt -= v8;
        Stream->_ptr += v8;
        v5 -= v8;
        Buffer = (char *)Buffer + v8;
LABEL_18:
        v4 = ElementCount * ElementSize;
        goto LABEL_22;
      }
    }
    if ( v5 >= bufsiz )
      break;
    if ( sub_637022(*(char *)Buffer, Stream) == -1 )
      goto LABEL_24;
    Buffer = (char *)Buffer + 1;
    --v5;
    bufsiz = Stream->_bufsiz;
    if ( bufsiz <= 0 )
      bufsiz = 1;
LABEL_22:
    if ( !v5 )
      return ElementCount;
  }
  if ( (Stream->_flag & 0x108) != 0 && _flush(Stream) )
  {
LABEL_24:
    v11 = v4;
    return (v11 - v5) / ElementSize;
  }
  v9 = v5;
  if ( bufsiz )
    v9 = v5 - v5 % bufsiz;
  v10 = sub_638801(Stream->_file, Buffer, v9);
  if ( v10 != -1 )
  {
    Buffer = (char *)Buffer + v10;
    v5 -= v10;
    if ( v10 >= v9 )
      goto LABEL_18;
  }
  Stream->_flag |= 0x20u;
  v11 = ElementCount * ElementSize;
  return (v11 - v5) / ElementSize;
}
