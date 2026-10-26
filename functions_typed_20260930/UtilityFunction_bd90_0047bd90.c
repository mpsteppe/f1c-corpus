int __thiscall sub_47BD90(int this)
{
  int v2; // ecx
  int result; // eax
  int v4; // ecx

  v2 = MenuCursorCount_bc90((_DWORD **)this) - 1;
  if ( v2 > 0 )
    *(_DWORD *)(this + 272) = (*(_DWORD *)(this + 236) * *(_DWORD *)(this + 276) + v2 / 2) / v2;
  else
    *(_DWORD *)(this + 272) = 0;
  result = *(_DWORD *)(this + 272);
  v4 = *(_DWORD *)(this + 276);
  if ( result >= 0 )
  {
    if ( result > v4 )
      *(_DWORD *)(this + 272) = v4;
  }
  else
  {
    *(_DWORD *)(this + 272) = 0;
  }
  return result;
}

