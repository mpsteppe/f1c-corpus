bool __stdcall sub_45D000(const char *a1, char *Buffer, size_t BufferCount)
{
  const char *v3; // eax
  int v4; // eax

  v3 = a1;
  if ( !a1 )
    v3 = &byte_629120;
  v4 = _snprintf(Buffer, BufferCount, "%s: ", v3);
  Buffer[BufferCount - 1] = 0;
  return v4 >= 0;
}
