int __cdecl fgetc(FILE *Stream)
{
  int v2; // edi

  _lock_file(Stream);
  if ( --Stream->_cnt < 0 )
    v2 = _filbuf(Stream);
  else
    v2 = *(unsigned __int8 *)Stream->_ptr++;
  _unlock_file(Stream);
  return v2;
}
