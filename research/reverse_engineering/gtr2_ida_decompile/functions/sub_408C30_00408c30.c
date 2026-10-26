void (__thiscall ***__thiscall sub_408C30(_DWORD *this, int a2, int a3, int a4, int a5))(_DWORD, int)
{
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, int); // ebp
  int v9; // edi
  int v10; // ebx
  void *retaddr; // [esp+8h] [ebp+0h]

  v6 = sub_408350();
  v7 = (void (__thiscall ***)(_DWORD, int))v6;
  if ( !v6 )
    return 0;
  if ( !(*(unsigned __int8 (__thiscall **)(int, void *, int, int, int))(*(_DWORD *)v6 + 8))(v6, retaddr, a2, a4, a4) )
  {
    (**v7)(v7, 1);
    return 0;
  }
  v9 = this[2];
  v10 = sub_4055D0();
  sub_408B90();
  *(_DWORD *)(v9 + 4) = v10;
  **(_DWORD **)(v10 + 4) = v10;
  return v7;
}
