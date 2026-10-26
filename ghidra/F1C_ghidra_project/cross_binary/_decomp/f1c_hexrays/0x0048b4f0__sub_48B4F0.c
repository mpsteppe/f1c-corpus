// f1c  0x0048b4f0  size=99
int __thiscall sub_48B4F0(int this)
{
  int result; // eax

  result = 0;
  **(_BYTE **)(this + 752) = 0;
  *(_DWORD *)(this + 756) = *(_DWORD *)(this + 752);
  *(_BYTE *)(this + 487) = 0;
  *(_DWORD *)(this + 760) = 256;
  *(_BYTE *)(this + 224) = 0;
  *(_BYTE *)(this + 226) = 0;
  *(_BYTE *)(this + 227) = 1;
  *(_BYTE *)(this + 228) = 1;
  *(_BYTE *)(this + 229) = 0;
  *(_BYTE *)(this + 748) = 1;
  *(_BYTE *)(this + 225) = 1;
  *(_DWORD *)(this + 768) = 16;
  *(_DWORD *)(this + 744) = 0;
  return result;
}
