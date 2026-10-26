int __thiscall sub_5420B0(int this)
{
  int v2; // ecx
  _DWORD v4[3]; // [esp+4h] [ebp-Ch] BYREF

  v2 = *(_DWORD *)(this + 4 * *(_DWORD *)(this + 28) + 32);
  if ( !v2 || (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 28))(v2) == 2 )
  {
    *(_DWORD *)(this + 28) = 0;
    if ( *(_DWORD *)(this + 32) && dword_B64134 != 2 )
    {
      memset(v4, 0, sizeof(v4));
      (*(void (__thiscall **)(_DWORD, _DWORD, int, _DWORD *, int, int, int))(**(_DWORD **)(this + 32) + 4))(
        *(_DWORD *)(this + 32),
        0,
        this + 8,
        v4,
        dword_B70948,
        1065353216,
        1);
    }
  }
  return 0;
}
