void __thiscall sub_607620(_DWORD *this)
{
  void *v2; // ecx
  char *v3; // eax
  char *v4; // edi
  void *v5; // ecx
  int v6; // eax
  int i; // edi
  char *v8; // eax
  char *v9; // edi

  v2 = (void *)this[20];
  if ( v2 )
  {
    sub_5E2B10(v2);
    sub_5D9A40((int *)&dword_FB2D78, this[20], 1);
    v3 = (char *)this[20];
    if ( v3 )
    {
      v4 = v3 - 4;
      `eh vector destructor iterator'(v3, 0xD8u, *((_DWORD *)v3 - 1), j_j_nullsub_7);
      j__free(v4);
    }
    this[20] = 0;
  }
  v5 = (void *)this[19];
  if ( v5 )
  {
    v6 = *this & 0xC;
    if ( v6 == 4 )
    {
      nullsub_7(v5);
    }
    else if ( v6 == 8 )
    {
      for ( i = 0; i < 4896; i += 816 )
        nullsub_7((void *)(i + this[19]));
    }
    v8 = (char *)this[19];
    if ( v8 )
    {
      v9 = v8 - 4;
      `eh vector destructor iterator'(v8, 0x330u, *((_DWORD *)v8 - 1), (void (__thiscall *)(void *))sub_51D670);
      j__free(v9);
    }
    this[19] = 0;
  }
}
