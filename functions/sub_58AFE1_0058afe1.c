int __cdecl sub_58AFE1(_DWORD *a1)
{
  int v1; // edi
  _BYTE *v2; // eax
  int v3; // eax

  v1 = a1[4];
  StreamBufferLockViaCriticalSection(a1);
  BufferFlushWrite(a1);
  a1[3] &= 0xFFFFFFCF;
  if ( v1 == -1 )
    v2 = &unk_5E7898;
  else
    v2 = (_BYTE *)(dword_8D4920[v1 >> 5] + 36 * (v1 & 0x1F));
  v2[4] &= ~2u;
  v3 = a1[3];
  if ( (v3 & 0x80u) != 0 )
  {
    LOBYTE(v3) = v3 & 0xFC;
    a1[3] = v3;
  }
  sub_58C724(v1, 0, 0);
  return AddressRangeCriticalSectionLeave(a1);
}
