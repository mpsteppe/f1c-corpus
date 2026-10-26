int __thiscall sub_5A07F0(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // edi
  void ***v3; // ebx
  char v4; // al
  void **v5; // ebp
  char *v6; // eax
  char *v7; // esi
  int result; // eax

  v1 = this;
  v2 = *this;
  while ( v2 )
  {
    v3 = (void ***)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        v6 = (char *)*v5;
        if ( *v5 )
        {
          v7 = v6 - 4;
          `eh vector destructor iterator'(v6, 0x54u, *((_DWORD *)v6 - 1), sub_5A6920);
          j_j__free(v7);
          v1 = this;
        }
        j__free(v5);
      }
    }
    j__free(v3);
  }
  result = 0;
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}
