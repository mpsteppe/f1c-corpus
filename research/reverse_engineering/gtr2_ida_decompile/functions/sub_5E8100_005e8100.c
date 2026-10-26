int __thiscall sub_5E8100(_DWORD *this, int a2)
{
  _DWORD *v2; // ebx
  _DWORD *v5; // eax
  char *v6; // eax
  char *v7; // esi

  v2 = 0;
  if ( a2 > 0 && this[65] )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Number of textures stages already set for material %s", (_BYTE)this + 4);
    return -1;
  }
  if ( a2 > 16 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Too many textures stages specified for material %s", (_BYTE)this + 4);
    return -1;
  }
  if ( a2 > 0 )
  {
    this[64] = a2;
    v5 = operator new(484 * a2 + 4);
    if ( v5 )
    {
      v2 = v5 + 1;
      *v5 = a2;
      sub_630A11(v5 + 1, 484, a2, sub_5E38B0, sub_5E39C0);
    }
LABEL_12:
    this[65] = v2;
    return 0;
  }
  if ( !a2 )
  {
    v6 = (char *)this[65];
    this[64] = 0;
    if ( v6 )
    {
      v7 = v6 - 4;
      `eh vector destructor iterator'(v6, 0x1E4u, *((_DWORD *)v6 - 1), (void (__thiscall *)(void *))sub_5E39C0);
      j__free(v7);
    }
    goto LABEL_12;
  }
  return 0;
}
