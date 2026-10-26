int __thiscall sub_6175E0(int this, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebp
  int v8; // edi
  bool v9; // al
  char v10; // bl

  v6 = a4;
  v8 = this + 96;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)(this + 96) + 4))(this + 96, a4);
  *(_BYTE *)(this + 132) = 0;
  v9 = sub_614460((_DWORD *)this, a2, 0);
  *(_BYTE *)(this + 92) = *(_BYTE *)(this + 88) && *(_DWORD *)(this + 68) == a4;
  if ( v9 )
  {
    v10 = *(_BYTE *)(this + 92);
    (**(void (__thiscall ***)(int))this)(this);
    *(_BYTE *)(this + 92) = v10;
    if ( !v10 )
      v6 = 0;
  }
  else
  {
    *(_BYTE *)(this + 92) = 1;
  }
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 4))(v8, v6);
  *(_DWORD *)(this + 68) = v6;
  *(_BYTE *)(this + 132) = 0;
  return sub_6146B0(a2, a3, 0, a5, a6);
}
