int __cdecl _flswbuf(unsigned __int16 Buf, FILE *a2)
{
  FILE *v2; // esi
  int flag; // eax
  int file; // ecx
  int v5; // eax
  char *base; // eax
  signed int v7; // edi
  _BYTE *v8; // eax
  unsigned __int16 v9; // bx
  int v11; // [esp+8h] [ebp-4h]

  v2 = a2;
  flag = a2->_flag;
  file = a2->_file;
  v11 = file;
  if ( (flag & 0x82) == 0 || (flag & 0x40) != 0 )
    goto LABEL_25;
  if ( (flag & 1) != 0 )
  {
    a2->_cnt = 0;
    if ( (flag & 0x10) != 0 )
    {
      LOBYTE(flag) = flag & 0xFE;
      v2->_ptr = v2->_base;
      v2->_flag = flag;
      goto LABEL_6;
    }
LABEL_25:
    LOBYTE(flag) = flag | 0x20;
    v2->_flag = flag;
    return 0xFFFF;
  }
LABEL_6:
  v5 = v2->_flag;
  v2->_cnt = 0;
  a2 = 0;
  LOBYTE(v5) = v5 & 0xED | 2;
  v2->_flag = v5;
  if ( (v5 & 0x10C) == 0 )
  {
    if ( v2 != &File && v2 != (FILE *)&unk_625438 || !_isatty(file) )
      _getbuf(v2);
    file = v11;
  }
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    v7 = v2->_ptr - base;
    v2->_ptr = base + 2;
    v2->_cnt = v2->_bufsiz - 2;
    if ( v7 <= 0 )
    {
      if ( file == -1 )
        v8 = &unk_625A00;
      else
        v8 = (_BYTE *)(dword_8003E0[file >> 5] + 36 * (file & 0x1F));
      if ( (v8[4] & 0x20) != 0 )
        _lseek(file, 0, 2);
    }
    else
    {
      a2 = (FILE *)_write(file, base, v7);
    }
    v9 = Buf;
    *(_WORD *)v2->_base = Buf;
  }
  else
  {
    v9 = Buf;
    v7 = 2;
    a2 = (FILE *)_write(file, &Buf, 2u);
  }
  if ( a2 == (FILE *)v7 )
    return v9;
  v2->_flag |= 0x20u;
  return 0xFFFF;
}
