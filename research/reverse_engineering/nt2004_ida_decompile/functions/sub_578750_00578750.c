char __thiscall sub_578750(_DWORD *this, const void *a2, const char *a3)
{
  _DWORD *v3; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // eax

  v3 = 0;
  if ( a2 )
  {
    v5 = operator new(0x14Cu);
    if ( v5 )
    {
      v5[81] = 0;
      v5[82] = -1;
      *v5 = this;
      v3 = v5;
    }
    qmemcpy(v3 + 1, a2, 0x140u);
    if ( a3 )
      sub_578600((int)(v3 + 81), a3);
    v6 = operator new(0xCu);
    if ( v6 )
    {
      *v6 = v3;
      v6[1] = 0;
      *((_BYTE *)v6 + 8) = 1;
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
