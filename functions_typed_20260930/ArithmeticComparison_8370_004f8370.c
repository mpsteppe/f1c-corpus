int __thiscall sub_4F8370(int this)
{
  DoubleBufferFree(this);
  sub_4F70C0((_DWORD *)this);
  ArrayNonZeroCounter((_DWORD *)(this + 1620));
  ArrayNonZeroCounter((_DWORD *)(this + 1688));
  *(_DWORD *)(this + 148) = 0;
  *(_BYTE *)(this + 4) = 1;
  return 0;
}

