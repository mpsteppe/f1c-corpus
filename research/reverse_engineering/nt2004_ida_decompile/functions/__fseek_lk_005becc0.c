int __cdecl _fseek_lk(_DWORD *a1, int Offset, unsigned int Origin)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax

  v3 = a1[3];
  if ( (v3 & 0x83) != 0 && (v4 = Origin, Origin <= 2) )
  {
    LOBYTE(v3) = v3 & 0xEF;
    a1[3] = v3;
    if ( Origin == 1 )
    {
      Offset += _ftell_lk(a1);
      v4 = 0;
    }
    _flush(a1);
    v5 = a1[3];
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        a1[6] = 512;
    }
    else
    {
      LOBYTE(v5) = v5 & 0xFC;
      a1[3] = v5;
    }
    return (_lseek(a1[4], Offset, v4) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}
