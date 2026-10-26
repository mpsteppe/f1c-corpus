char *__cdecl fgets(char *Buffer, int MaxCount, FILE *Stream)
{
  char *v3; // ebx
  char *v4; // edi
  int v7; // eax

  v3 = Buffer;
  v4 = Buffer;
  if ( MaxCount <= 0 )
    return 0;
  _lock_file(Stream);
  do
  {
    if ( !--MaxCount )
      break;
    if ( --Stream->_cnt < 0 )
      v7 = _filbuf(Stream);
    else
      v7 = *(unsigned __int8 *)Stream->_ptr++;
    if ( v7 == -1 )
    {
      if ( v4 == Buffer )
      {
        v3 = 0;
        goto LABEL_14;
      }
      break;
    }
    *v4++ = v7;
  }
  while ( (_BYTE)v7 != 10 );
  *v4 = 0;
LABEL_14:
  _unlock_file(Stream);
  return v3;
}
