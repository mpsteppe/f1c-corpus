int __thiscall sub_525140(int *this)
{
  int v1; // esi
  void **v2; // edi
  char v3; // al

  v1 = *this;
  while ( v1 )
  {
    v2 = (void **)v1;
    v3 = *(_BYTE *)(v1 + 8);
    v1 = *(_DWORD *)(v1 + 4);
    if ( v3 )
      j__free(*v2);
    j__free(v2);
  }
  return off_16C9508();
}
