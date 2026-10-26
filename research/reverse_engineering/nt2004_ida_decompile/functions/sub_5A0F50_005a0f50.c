void __thiscall sub_5A0F50(_DWORD *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax

  if ( (_DWORD *)a2 != this && this[120] )
  {
    dword_7F5E7C = 0;
    sub_59E210((int)this, 0, this[129]);
    v4 = this[129];
    v5 = *(_DWORD *)(v4 + 20);
    if ( (v5 & 0x20000000) == 0 )
    {
      *(_DWORD *)(v4 + 20) = v5 | 0x20000000;
      (*(void (__cdecl **)(int, int, int, _DWORD *))(*(_DWORD *)dword_7E8E58 + 4))(
        dword_7E8E58,
        this[129] + 220,
        this[129] + 232,
        this + 69);
    }
    dword_7F5E78 = sub_5A0EC0(this, a3);
    sub_5A0D70((int)this, a2, a3);
  }
}
