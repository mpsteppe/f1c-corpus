int __cdecl fputs(const char *Buffer, FILE *Stream)
{
  size_t v2; // edi
  int v3; // ebx
  const char *Buffera; // [esp+14h] [ebp+8h]

  v2 = strlen(Buffer);
  _lock_file(Stream);
  v3 = _stbuf(Stream);
  Buffera = (const char *)fwrite(Buffer, 1u, v2, Stream);
  _ftbuf(v3, Stream);
  _unlock_file(Stream);
  return (Buffera == (const char *)v2) - 1;
}
