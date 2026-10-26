char __thiscall sub_615E60(_DWORD *this, const void *a2, const char *a3)
{
  int v3; // ebx
  _DWORD *v5; // eax

  v3 = 0;
  if ( a2 )
  {
    v5 = operator new(0x14Cu);
    if ( v5 )
    {
      v5[81] = 0;
      v5[82] = -1;
      *v5 = this;
      v3 = (int)v5;
    }
    qmemcpy((void *)(v3 + 4), a2, 0x140u);
    if ( a3 )
      sub_615860(v3 + 324, a3);
    sub_5FDFB0(this, v3, 1);
  }
  return 0;
}
