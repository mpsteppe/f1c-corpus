int __thiscall sub_6CB0CE(int this, int a2)
{
  unsigned int v3; // eax
  void *v4; // edi
  unsigned int i; // ecx

  if ( (*(_BYTE *)(this + 204) & 1) != 0 && *(_DWORD *)(this + 292) )
  {
    v3 = *(_DWORD *)(this + 300);
    if ( *(_DWORD *)(this + 296) >= v3 )
    {
      v4 = operator new(48 * v3);
      if ( !v4 )
        return -2147024882;
      qmemcpy(v4, *(const void **)(this + 292), 24 * *(_DWORD *)(this + 296));
      j__free(*(void **)(this + 292));
      *(_DWORD *)(this + 300) *= 2;
      *(_DWORD *)(this + 292) = v4;
    }
    *(_DWORD *)(*(_DWORD *)(this + 292) + 24 * *(_DWORD *)(this + 296)) = *(_DWORD *)(this + 260);
    *(_DWORD *)(*(_DWORD *)(this + 292) + 24 * *(_DWORD *)(this + 296) + 4) = 4 * *(_DWORD *)(this + 272);
    for ( i = 0; i < 4; ++i )
      *(_DWORD *)(*(_DWORD *)(this + 292) + 4 * (i + 6 * *(_DWORD *)(this + 296)) + 8) = -1;
    ++*(_DWORD *)(this + 296);
  }
  *(_DWORD *)(this + 280) = *(_DWORD *)(this + 272);
  sub_6C9357((_DWORD *)this, a2);
  return 0;
}
