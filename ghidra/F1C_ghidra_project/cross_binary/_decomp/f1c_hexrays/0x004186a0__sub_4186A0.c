// f1c  0x004186a0  size=78
int __thiscall sub_4186A0(_DWORD *this)
{
  _DWORD *v1; // ecx
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  int result; // eax

  v1 = this + 537;
  v2 = 20;
  do
  {
    sub_4144D0(v1);
    v1 = (_DWORD *)(v4 + 32);
    --v2;
  }
  while ( v2 );
  memset32((void *)(v3 + 2808), -1082130432, 0x219u);
  result = 0;
  *(_DWORD *)(v3 + 2792) = 0;
  *(_BYTE *)(v3 + 2788) = 0;
  *(_DWORD *)(v3 + 2796) = -1;
  *(_DWORD *)(v3 + 4956) = 0;
  return result;
}
