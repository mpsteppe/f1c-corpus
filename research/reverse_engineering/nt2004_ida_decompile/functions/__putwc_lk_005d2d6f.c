wchar_t __cdecl _putwc_lk(wchar_t WCh, FILE *File)
{
  FILE *v2; // esi
  char *v3; // eax
  int v4; // eax
  wchar_t result; // ax
  bool v6; // sf
  int v7; // eax
  int v8; // eax

  v2 = File;
  if ( (File->_flag & 0x40) != 0
    || (File->_file == -1
      ? (v3 = (char *)&unk_625A00)
      : (v3 = (char *)(dword_8003E0[File->_file >> 5] + 36 * (File->_file & 0x1F))),
        v3[4] >= 0) )
  {
    v6 = File->_cnt - 2 < 0;
    File->_cnt -= 2;
    if ( v6 )
      return _flswbuf(WCh, (int)v2);
    result = WCh;
    *(_WORD *)v2->_ptr = WCh;
    v2->_ptr += 2;
    return result;
  }
  v4 = wctomb((char *)&File, WCh);
  if ( v4 == -1 )
  {
    *_errno() = 42;
    return -1;
  }
  if ( v4 == 1 )
  {
    v6 = --v2->_cnt < 0;
    if ( v6 )
    {
      v7 = _flsbuf((char)File, v2);
      goto LABEL_14;
    }
    *v2->_ptr = (char)File;
    v7 = (unsigned __int8)File;
  }
  else
  {
    v6 = --v2->_cnt < 0;
    if ( v6 )
    {
      v8 = _flsbuf((char)File, v2);
    }
    else
    {
      *v2->_ptr++ = (char)File;
      v8 = (unsigned __int8)File;
    }
    if ( v8 == -1 )
      return -1;
    v6 = --v2->_cnt < 0;
    if ( v6 )
    {
      v7 = _flsbuf(SBYTE1(File), v2);
      goto LABEL_14;
    }
    *v2->_ptr = BYTE1(File);
    v7 = BYTE1(File);
  }
  ++v2->_ptr;
LABEL_14:
  if ( v7 == -1 )
    return -1;
  return WCh;
}
