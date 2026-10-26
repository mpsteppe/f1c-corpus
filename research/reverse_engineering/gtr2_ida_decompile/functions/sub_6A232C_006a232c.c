int __thiscall sub_6A232C(int this, int a2)
{
  _DWORD *v3; // edi

  memset((void *)(this + 504), 0, 0x20u);
  *(_DWORD *)(this + 536) = 0;
  *(_DWORD *)(this + 540) = 0;
  *(_DWORD *)(this + 544) = 0;
  *(_DWORD *)(this + 548) = 0;
  v3 = (_DWORD *)(this + 556);
  j__free(*(void **)(this + 556));
  j__free(*(void **)(this + 560));
  *v3 = 0;
  *(_DWORD *)(this + 560) = 0;
  return sub_6CA50D(this, a2);
}
