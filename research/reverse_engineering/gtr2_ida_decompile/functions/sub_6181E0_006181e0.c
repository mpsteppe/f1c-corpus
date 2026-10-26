int __thiscall sub_6181E0(int this, int a2)
{
  int v3; // edi
  void *v4; // eax
  void *v5; // esi

  if ( *(_DWORD *)(this + 4) < *(_DWORD *)(a2 + 4) )
  {
    j__free(*(void **)this);
    *(_DWORD *)this = operator new(*(_DWORD *)(a2 + 4));
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  }
  if ( *(_DWORD *)(this + 12) < *(_DWORD *)(a2 + 12) )
  {
    j__free(*(void **)(this + 8));
    v3 = *(_DWORD *)(a2 + 12);
    v4 = operator new(4 * v3);
    v5 = v4;
    if ( v4 )
      sub_41D1B0((int)v4, 4, v3, (int)sub_618030);
    else
      v5 = 0;
    *(_DWORD *)(this + 8) = v5;
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  }
  qmemcpy(*(void **)this, *(const void **)a2, *(_DWORD *)(a2 + 4));
  qmemcpy(*(void **)(this + 8), *(const void **)(a2 + 8), 4 * *(_DWORD *)(a2 + 20));
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  return this;
}
