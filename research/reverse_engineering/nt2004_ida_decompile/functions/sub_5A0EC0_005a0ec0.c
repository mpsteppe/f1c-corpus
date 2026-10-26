int __thiscall sub_5A0EC0(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // ebp
  _DWORD *v5; // esi
  int v7; // [esp+Ch] [ebp-4h]

  v3 = this[120];
  v4 = 0;
  v5 = *(_DWORD **)(v3 + 8);
  v7 = 0;
  if ( *(int *)(v3 + 4) <= 0 )
    return 0;
  do
  {
    if ( *v5 == 2 )
    {
      ++v7;
    }
    else
    {
      (*(void (__cdecl **)(int, _DWORD *, _DWORD *, _DWORD *))(*(_DWORD *)dword_7E8E58 + 4))(
        dword_7E8E58,
        v5 + 1,
        v5 + 4,
        this + 69);
      (*(void (__cdecl **)(int, _DWORD *, _DWORD *, _DWORD *))(*(_DWORD *)dword_7E8E58 + 4))(
        dword_7E8E58,
        v5 + 7,
        v5 + 10,
        this + 69);
    }
    v5 += 29;
    ++v4;
  }
  while ( v4 < *(_DWORD *)(this[120] + 4) );
  return v7;
}
