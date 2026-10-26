int __thiscall sub_5E6040(_DWORD *this, const char *a2)
{
  int *v3; // eax
  int *v4; // eax
  char *v5; // esi

  v3 = (int *)operator new(0x1E4u);
  if ( v3 )
    v4 = sub_5E38B0(v3);
  else
    v4 = 0;
  this[10] = v4;
  sub_5E3A10(v4, a2, 128);
  *(_DWORD *)(this[10] + 4) = 1;
  if ( sub_5E3AA0((char *)this[10], 0.0, 0, 1.0, 1) )
  {
    sub_5E4AA0(this[10], 0);
    v5 = (char *)this[10];
    if ( v5 )
    {
      sub_5E39C0(v5);
      j__free(v5);
    }
    return -1;
  }
  else
  {
    *this |= 0x20000u;
    return 0;
  }
}
