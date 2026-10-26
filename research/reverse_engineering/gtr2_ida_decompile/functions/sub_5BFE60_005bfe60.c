BOOL __thiscall sub_5BFE60(_DWORD *this, int a2)
{
  int v3; // edi
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  BOOL result; // eax

  v3 = 8 * a2;
  v4 = *(_DWORD *)(this[80] + 8 * a2 + 4);
  result = 0;
  if ( v4 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 12))(v4) )
    {
      v5 = *(_DWORD *)(this[83] + v3 + 4);
      if ( v5 )
      {
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(v5) )
        {
          v6 = this[83];
          v7 = *(_DWORD *)(v6 + v3 + 4);
          v8 = v3 + v6;
          v9 = v7 ? (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v8 + 4) + 12))(*(_DWORD *)(v8 + 4)) : 0;
          if ( sub_5C3D80(v9) > 0 )
            return 1;
        }
      }
    }
  }
  return result;
}
