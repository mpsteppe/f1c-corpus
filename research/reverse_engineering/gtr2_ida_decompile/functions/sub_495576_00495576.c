int __thiscall sub_495576(void *this, _DWORD *a2, int a3, int a4, int a5)
{
  _DWORD *v5; // esi
  _DWORD *v6; // eax

  v5 = (_DWORD *)sub_5F4870((int)this, a3);
  if ( !v5 )
  {
    v6 = operator new(0x114u);
    v5 = v6;
    if ( v6 )
    {
      sub_5D9010(v6);
      *v5 = 0;
      v5[1] = 0;
      v5[2] = 0;
      v5[3] = 0;
      memset(v5 + 5, 0, 0x100u);
    }
    else
    {
      v5 = 0;
    }
    if ( sub_5F4640((int)v5, a3, a4, a5) )
    {
      if ( v5 )
      {
        nullsub_7(v5);
        j__free(v5);
      }
      return -1;
    }
    sub_5FDFB0(v5, 1);
  }
  ++v5[3];
  if ( a2 )
    *a2 = v5;
  return 0;
}
