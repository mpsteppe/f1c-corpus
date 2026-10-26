int __thiscall sub_677187(int this, size_t Size)
{
  void *v3; // edi

  if ( Size > *(_DWORD *)(this + 8) )
  {
    v3 = operator new(Size);
    if ( !v3 )
      return -2147024882;
    qmemcpy(v3, *(const void **)(this + 12), *(_DWORD *)(this + 8));
    j__free(*(void **)(this + 12));
    *(_DWORD *)(this + 12) = v3;
    *(_DWORD *)(this + 8) = Size;
  }
  return 0;
}
