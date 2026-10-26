int __cdecl _filbuf(FILE *File)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  int v4; // edx
  _BYTE *v5; // edi
  int v6; // ecx
  char *ptr; // ecx
  int result; // eax

  flag = File->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    File->_flag = flag | 0x20;
    return -1;
  }
  v2 = flag | 1;
  File->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    File->_ptr = File->_base;
  else
    _getbuf(File);
  v3 = _read(File->_file, File->_base, File->_bufsiz);
  File->_cnt = v3;
  if ( !v3 || v3 == -1 )
  {
    File->_flag |= v3 != 0 ? 32 : 16;
    File->_cnt = 0;
    return -1;
  }
  v4 = File->_flag;
  if ( (v4 & 0x82) == 0 )
  {
    v5 = File->_file == -1 ? &unk_913430 : (_BYTE *)(dword_FBB4E0[File->_file >> 5] + 36 * (File->_file & 0x1F));
    if ( (v5[4] & 0x82) == 0x82 )
      File->_flag = v4 | 0x2000;
  }
  if ( File->_bufsiz == 512 )
  {
    v6 = File->_flag;
    if ( (v6 & 8) != 0 && (v6 & 0x400) == 0 )
      File->_bufsiz = 4096;
  }
  ptr = File->_ptr;
  File->_cnt = v3 - 1;
  result = (unsigned __int8)*ptr;
  File->_ptr = ptr + 1;
  return result;
}
