// f1c  0x00558dc0  size=72
void __thiscall sub_558DC0(int this, int a2, int a3, int a4)
{
  int v5; // eax

  if ( *(_DWORD *)(this + 76) == 1 && *(char *)(this + 32) < 0 )
  {
    sub_558D10((_DWORD *)this, 0);
    v5 = *(_DWORD *)(*(_DWORD *)(this + 80) + 32);
    if ( v5 )
      *(_DWORD *)(((a3 + *(_DWORD *)(this + 36) * *(_DWORD *)((a2 << 7) + *(_DWORD *)(this + 52) + 4)) << 6) + v5 + 24) = a4;
  }
}
