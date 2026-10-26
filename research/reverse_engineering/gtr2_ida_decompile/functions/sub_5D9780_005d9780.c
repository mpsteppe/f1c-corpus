int __thiscall sub_5D9780(int *this)
{
  int v2; // esi
  void **v3; // edi
  char v4; // al
  void *v5; // ebp
  int result; // eax

  v2 = *this;
  while ( v2 )
  {
    v3 = (void **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        j_j_nullsub_7(*v3);
        j__free(v5);
      }
    }
    j__free(v3);
  }
  result = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
