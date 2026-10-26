int __thiscall sub_47BE00(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ecx
  int result; // eax

  v2 = MenuCursorCount_bc90((_DWORD **)this);
  v3 = *(_DWORD *)(this + 276);
  v4 = v2 - 1;
  if ( v3 )
    *(_DWORD *)(this + 236) = (v4 * *(_DWORD *)(this + 272) + v3 / 2) / v3;
  else
    *(_DWORD *)(this + 236) = 0;
  result = *(_DWORD *)(this + 236);
  if ( result >= 0 )
  {
    if ( result > v4 )
      *(_DWORD *)(this + 236) = v4;
  }
  else
  {
    *(_DWORD *)(this + 236) = 0;
  }
  if ( v4 < *(_DWORD *)(this + 276) )
    return UtilityFunction_bd90(this);
  return result;
}

