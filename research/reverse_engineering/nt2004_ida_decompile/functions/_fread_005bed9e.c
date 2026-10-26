size_t __cdecl fread(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v4; // edi
  size_t v6; // ecx
  unsigned int cnt; // eax
  size_t v10; // edi
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  size_t Buffera; // [esp+18h] [ebp+8h]
  unsigned int Streama; // [esp+24h] [ebp+14h]

  v4 = ElementCount * ElementSize;
  v6 = ElementCount * ElementSize;
  Buffera = ElementCount * ElementSize;
  if ( !(ElementCount * ElementSize) )
    return 0;
  if ( (Stream->_flag & 0x10C) != 0 )
    Streama = Stream->_bufsiz;
  else
    Streama = 4096;
  while ( 1 )
  {
    if ( (Stream->_flag & 0x10C) != 0 )
    {
      cnt = Stream->_cnt;
      if ( cnt )
      {
        v10 = v6;
        if ( v6 >= cnt )
          v10 = Stream->_cnt;
        memcpy_0(Buffer, Stream->_ptr, v10);
        Buffera -= v10;
        Stream->_cnt -= v10;
        Stream->_ptr += v10;
        Buffer = (char *)Buffer + v10;
        v4 = ElementCount * ElementSize;
        goto LABEL_20;
      }
    }
    if ( v6 >= Streama )
      break;
    v13 = _filbuf(Stream);
    if ( v13 == -1 )
      return (v4 - Buffera) / ElementSize;
    *(_BYTE *)Buffer = v13;
    Buffer = (char *)Buffer + 1;
    --Buffera;
    Streama = Stream->_bufsiz;
LABEL_20:
    if ( !Buffera )
      return ElementCount;
    v6 = Buffera;
  }
  v11 = v6;
  if ( Streama )
    v11 = v6 - v6 % Streama;
  v12 = _read(Stream->_file, Buffer, v11);
  if ( !v12 )
  {
    Stream->_flag |= 0x10u;
    return (v4 - Buffera) / ElementSize;
  }
  if ( v12 != -1 )
  {
    Buffera -= v12;
    Buffer = (char *)Buffer + v12;
    goto LABEL_20;
  }
  Stream->_flag |= 0x20u;
  return (v4 - Buffera) / ElementSize;
}
