int __cdecl _fileno(FILE *Stream)
{
  return Stream->_file;
}
