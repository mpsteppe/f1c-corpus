int __thiscall sub_47BCF0(int this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // edi
  int v9; // ecx
  int v10; // eax

  v2 = MenuCursorCount(this);
  v3 = MenuCursorCount_bc90((_DWORD **)this);
  v4 = *(_DWORD *)(this + 236);
  if ( v2 >= v4 )
  {
    v7 = *(_DWORD *)(this + 240);
    if ( v2 < v7 + v4 )
      goto LABEL_14;
    if ( v2 <= v7 + v4 )
    {
      v6 = v4 + 1;
    }
    else
    {
      v8 = v2 - (v7 + v4 - 1);
      if ( v7 <= v8 )
        v7 = v8;
      v6 = v7 + v4;
    }
  }
  else
  {
    if ( v2 >= v4 - 1 )
    {
      *(_DWORD *)(this + 236) = v4 - 1;
      goto LABEL_14;
    }
    v5 = v4 - v2;
    if ( *(_DWORD *)(this + 240) > v4 - v2 )
      v5 = *(_DWORD *)(this + 240);
    v6 = v4 - v5;
  }
  *(_DWORD *)(this + 236) = v6;
LABEL_14:
  v9 = v3 - 1;
  v10 = *(_DWORD *)(this + 236);
  if ( v10 >= 0 )
  {
    if ( v10 > v9 )
      *(_DWORD *)(this + 236) = v9;
    return UtilityFunction_bd90(this);
  }
  else
  {
    *(_DWORD *)(this + 236) = 0;
    return UtilityFunction_bd90(this);
  }
}
