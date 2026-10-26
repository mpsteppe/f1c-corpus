int __cdecl _filwbuf(unsigned __int16 **a1)
{
  unsigned __int16 *v1; // eax
  unsigned int v2; // eax
  unsigned __int16 *v3; // edx
  _BYTE *v4; // edi
  unsigned __int16 *v5; // ecx
  unsigned __int16 *v6; // ecx
  int result; // eax

  v1 = a1[3];
  if ( ((unsigned __int8)v1 & 0x83) == 0 || ((unsigned __int8)v1 & 0x40) != 0 )
    return 0xFFFF;
  if ( ((unsigned __int8)v1 & 2) != 0 )
  {
    LOBYTE(v1) = (unsigned __int8)v1 | 0x20;
    a1[3] = v1;
    return 0xFFFF;
  }
  LOBYTE(v1) = (unsigned __int8)v1 | 1;
  a1[3] = v1;
  if ( ((unsigned __int16)v1 & 0x10C) != 0 )
    *a1 = a1[2];
  else
    _getbuf(a1);
  v2 = _read((int)a1[4], a1[2], (unsigned int)a1[6]);
  a1[1] = (unsigned __int16 *)v2;
  if ( v2 < 2 || v2 == -1 )
  {
    a1[3] = (unsigned __int16 *)((v2 != 0 ? 32 : 16) | (unsigned int)a1[3]);
    a1[1] = 0;
    return 0xFFFF;
  }
  v3 = a1[3];
  if ( ((unsigned __int8)v3 & 0x82) == 0 )
  {
    v4 = a1[4] == (unsigned __int16 *)-1
       ? &unk_625A00
       : (_BYTE *)(dword_8003E0[(int)a1[4] >> 5] + 36 * ((unsigned int)a1[4] & 0x1F));
    if ( (v4[4] & 0x82) == 0x82 )
    {
      BYTE1(v3) |= 0x20u;
      a1[3] = v3;
    }
  }
  if ( a1[6] == (unsigned __int16 *)512 )
  {
    v5 = a1[3];
    if ( ((unsigned __int8)v5 & 8) != 0 && (BYTE1(v5) & 4) == 0 )
      a1[6] = (unsigned __int16 *)4096;
  }
  v6 = *a1;
  a1[1] = (unsigned __int16 *)(v2 - 2);
  result = *v6;
  *a1 = v6 + 1;
  return result;
}
