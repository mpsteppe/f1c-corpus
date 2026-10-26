int __thiscall sub_5F3C20(int *this, const char *a2, int a3, int *a4)
{
  void *v5; // eax
  int v6; // esi

  v5 = operator new(0x4Cu);
  v6 = (int)v5;
  if ( v5 )
  {
    sub_5D9010(v5);
    memset((void *)v6, 0, 0x40u);
    *(_DWORD *)(v6 + 64) = 0;
    *(_BYTE *)(v6 + 72) = 0;
    *(_DWORD *)(v6 + 68) = 0;
  }
  else
  {
    v6 = 0;
  }
  if ( sub_5F3880(v6, a2, a3, this[2387]) )
  {
    if ( v6 )
    {
      nullsub_7((void *)v6);
      j__free((void *)v6);
    }
    return -1;
  }
  else
  {
    sub_5FDFB0(v6, 1);
    if ( a4 )
      *a4 = v6;
    return 0;
  }
}
