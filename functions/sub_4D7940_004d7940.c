int sub_4D7940()
{
  int result; // eax

  result = dword_8AD25C[1];
  if ( result )
    return FileCloseWithLock(dword_8AD25C[1]);
  return result;
}
