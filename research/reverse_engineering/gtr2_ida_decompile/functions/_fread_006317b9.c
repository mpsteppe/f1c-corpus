size_t __cdecl fread(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v5; // edi
  size_t v6; // ecx
  unsigned int cnt; // eax
  size_t v9; // edi
  unsigned int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int bufsiz; // [esp+Ch] [ebp-4h]
  size_t Buffera; // [esp+18h] [ebp+8h]

  v5 = ElementCount * ElementSize;
  v6 = ElementCount * ElementSize;
  Buffera = ElementCount * ElementSize;
  if ( !(ElementCount * ElementSize) )
    return 0;
  if ( (Stream->_flag & 0x10C) != 0 )
    bufsiz = Stream->_bufsiz;
  else
    bufsiz = 4096;
  while ( 1 )
  {
    if ( (Stream->_flag & 0x10C) != 0 )
    {
      cnt = Stream->_cnt;
      if ( cnt )
      {
        v9 = v6;
        if ( v6 >= cnt )
          v9 = Stream->_cnt;
        memcpy_0(Buffer, Stream->_ptr, v9);
        Buffera -= v9;
        Stream->_cnt -= v9;
        Stream->_ptr += v9;
        Buffer = (char *)Buffer + v9;
        v5 = ElementCount * ElementSize;
        goto LABEL_20;
      }
    }
    if ( v6 >= bufsiz )
      break;
    v12 = _filbuf(Stream);
    if ( v12 == -1 )
      return (v5 - Buffera) / ElementSize;
    *(_BYTE *)Buffer = v12;
    Buffer = (char *)Buffer + 1;
    --Buffera;
    bufsiz = Stream->_bufsiz;
LABEL_20:
    if ( !Buffera )
      return ElementCount;
    v6 = Buffera;
  }
  v10 = v6;
  if ( bufsiz )
    v10 = v6 - v6 % bufsiz;
  v11 = _read(Stream->_file, Buffer, v10);
  if ( !v11 )
  {
    Stream->_flag |= 0x10u;
    return (v5 - Buffera) / ElementSize;
  }
  if ( v11 != -1 )
  {
    Buffera -= v11;
    Buffer = (char *)Buffer + v11;
    goto LABEL_20;
  }
  Stream->_flag |= 0x20u;
  return (v5 - Buffera) / ElementSize;
}
