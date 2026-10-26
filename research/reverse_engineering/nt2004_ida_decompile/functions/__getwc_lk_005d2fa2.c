__int16 __cdecl _getwc_lk(FILE *File)
{
  FILE *v1; // esi
  char *v2; // eax
  bool v3; // sf
  size_t v4; // edi
  int v5; // eax
  __int16 result; // ax
  int v7; // eax
  char SrcCh[4]; // [esp+8h] [ebp-4h] BYREF

  v1 = File;
  if ( (File->_flag & 0x40) != 0
    || (File->_file == -1
      ? (v2 = (char *)&unk_625A00)
      : (v2 = (char *)(dword_8003E0[File->_file >> 5] + 36 * (File->_file & 0x1F))),
        v2[4] >= 0) )
  {
    v3 = File->_cnt - 2 < 0;
    File->_cnt -= 2;
    if ( v3 )
    {
      return _filwbuf(v1);
    }
    else
    {
      result = *(_WORD *)v1->_ptr;
      v1->_ptr += 2;
    }
  }
  else
  {
    v3 = --File->_cnt < 0;
    v4 = 1;
    if ( v3 )
      v5 = _filbuf(v1);
    else
      v5 = *(unsigned __int8 *)v1->_ptr++;
    if ( v5 == -1 )
      return -1;
    SrcCh[0] = v5;
    if ( *((char *)off_625680 + 2 * (unsigned __int8)v5 + 1) < 0 )
    {
      v3 = --v1->_cnt < 0;
      if ( v3 )
        v7 = _filbuf(v1);
      else
        v7 = *(unsigned __int8 *)v1->_ptr++;
      if ( v7 == -1 )
      {
        ungetc(SrcCh[0], v1);
        return -1;
      }
      SrcCh[1] = v7;
      v4 = 2;
    }
    if ( mbtowc((wchar_t *)&File + 1, SrcCh, v4) == -1 )
    {
      *_errno() = 42;
      return -1;
    }
    return HIWORD(File);
  }
  return result;
}
