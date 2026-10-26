// Address: 0x00564000
// Size: 129 bytes
// Name: sub_564000
// Type: int()
// Source: IDA Hex-Rays decompilation

int sub_564000()
{
  const char *v0; // esi
  int result; // eax

  v0 = (const char *)sub_5644B0(byte_5EA438);
  result = strcmp((const char *)sub_5644B0(byte_5EA438), v0);
  if ( !*(_DWORD *)(dword_8D46B4 + 132) )
    return -result;
  return result;
}
