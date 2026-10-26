void __cdecl rewind(FILE *Stream)
{
  int file; // edi
  _BYTE *v2; // eax
  int flag; // eax

  file = Stream->_file;
  _lock_file(Stream);
  _flush(Stream);
  Stream->_flag &= 0xFFFFFFCF;
  if ( file == -1 )
    v2 = &unk_625A00;
  else
    v2 = (_BYTE *)(dword_8003E0[file >> 5] + 36 * (file & 0x1F));
  v2[4] &= ~2u;
  flag = Stream->_flag;
  if ( (flag & 0x80u) != 0 )
  {
    LOBYTE(flag) = flag & 0xFC;
    Stream->_flag = flag;
  }
  _lseek(file, 0, 0);
  _unlock_file(Stream);
}
