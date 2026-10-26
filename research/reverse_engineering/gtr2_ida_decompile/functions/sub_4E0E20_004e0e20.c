void __thiscall sub_4E0E20(int *this)
{
  int v2; // esi
  void **v3; // edi
  char v4; // al

  v2 = *this;
  while ( v2 )
  {
    v3 = (void **)v2;
    v4 = *(_BYTE *)(v2 + 12);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
      j__free(*v3);
    j__free(v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
}
