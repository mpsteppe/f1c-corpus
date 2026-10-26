int __cdecl _setmode_lk(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax

  v2 = 36 * (a1 & 0x1F);
  v3 = *(_BYTE *)(dword_FBB4E0[a1 >> 5] + v2 + 4) & 0x80;
  if ( a2 == 0x8000 )
  {
    *(_BYTE *)(dword_FBB4E0[a1 >> 5] + v2 + 4) &= ~0x80u;
    return v3 != 0 ? 0x4000 : 0x8000;
  }
  if ( a2 == 0x4000 )
  {
    *(_BYTE *)(dword_FBB4E0[a1 >> 5] + v2 + 4) |= 0x80u;
    return v3 != 0 ? 0x4000 : 0x8000;
  }
  *_errno() = 22;
  return -1;
}
