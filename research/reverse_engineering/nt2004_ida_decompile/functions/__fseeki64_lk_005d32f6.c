int __cdecl _fseeki64_lk(_DWORD *a1, __int64 Offset, unsigned int Origin)
{
  int v3; // eax
  int v4; // edi
  __int64 v5; // rax
  int v6; // eax
  __int64 v7; // rax

  v3 = a1[3];
  if ( (v3 & 0x83) != 0 && (v4 = Origin, Origin <= 2) )
  {
    LOBYTE(v3) = v3 & 0xEF;
    a1[3] = v3;
    if ( Origin == 1 )
    {
      LODWORD(v5) = _ftelli64_lk((int)a1);
      Offset += v5;
      v4 = 0;
    }
    _flush(a1);
    v6 = a1[3];
    if ( (v6 & 0x80u) == 0 )
    {
      if ( (v6 & 1) != 0 && (v6 & 8) != 0 && (v6 & 0x400) == 0 )
        a1[6] = 512;
    }
    else
    {
      LOBYTE(v6) = v6 & 0xFC;
      a1[3] = v6;
    }
    v7 = _lseeki64(a1[4], Offset, v4);
    if ( (HIDWORD(v7) & (unsigned int)v7) != 0xFFFFFFFF )
      return 0;
  }
  else
  {
    *_errno() = 22;
  }
  return -1;
}
