int __thiscall sub_5D9840(int *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  char v4; // al
  void *v5; // ebp
  int result; // eax

  v2 = *this;
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = (void *)*v3;
      if ( *v3 )
      {
        sub_5DE8F0(*v3);
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
