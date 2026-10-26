void __thiscall sub_54F7A0(_DWORD *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax

  if ( (_DWORD *)a2 != this && this[120] )
  {
    dword_8C5F44 = 0;
    sub_54B570((int)this, 0, this[129]);
    v4 = this[129];
    v5 = *(_DWORD *)(v4 + 20);
    if ( (v5 & 0x20000000) == 0 )
    {
      *(_DWORD *)(v4 + 20) = v5 | 0x20000000;
      (*(void (__cdecl **)(int, int, int, _DWORD *))(*(_DWORD *)dword_8B8F24 + 4))(
        dword_8B8F24,
        this[129] + 220,
        this[129] + 232,
        this + 69);
    }
    dword_8C5F40 = RenderListIteration(this, a3);
    SceneBatchRenderCheck((int)this, a2, a3);
  }
}

