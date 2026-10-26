int __cdecl sub_587F90(_DWORD *a1, LONG a2, unsigned int a3)
{
  int v3; // eax
  DWORD v4; // edi
  int v5; // eax

  v3 = a1[3];
  if ( (v3 & 0x83) != 0 && (v4 = a3, a3 <= 2) )
  {
    LOBYTE(v3) = v3 & 0xEF;
    a1[3] = v3;
    if ( a3 == 1 )
    {
      a2 += sub_58AD08(a1);
      v4 = 0;
    }
    BufferFlushWrite(a1);
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
    return (sub_58C724(a1[4], a2, v4) != -1) - 1;
  }
  else
  {
    *(_DWORD *)TLSOffsetGetter() = 22;
    return -1;
  }
}
