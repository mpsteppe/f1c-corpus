// f1c  0x00565ca0  size=169
char __thiscall sub_565CA0(_DWORD *this, const void *a2, int a3)
{
  _DWORD *v3; // ebx
  _DWORD *v5; // eax
  int v6; // eax

  v3 = 0;
  if ( a2 )
  {
    v5 = (_DWORD *)sub_587C03(332);
    if ( v5 )
    {
      v5[81] = 0;
      v5[82] = -1;
      *v5 = this;
      v3 = v5;
    }
    qmemcpy(v3 + 1, a2, 0x140u);
    if ( a3 )
      sub_566650(a3);
    v6 = sub_587C03(12);
    if ( v6 )
    {
      *(_DWORD *)v6 = v3;
      *(_DWORD *)(v6 + 4) = 0;
      *(_BYTE *)(v6 + 8) = 1;
    }
    else
    {
      v6 = 0;
    }
    if ( !*this )
    {
      *this = v6;
      this[2] = v6;
      this[1] = v6;
      ++this[3];
      return 0;
    }
    *(_DWORD *)(this[1] + 4) = v6;
    this[1] = v6;
    ++this[3];
  }
  return 0;
}
