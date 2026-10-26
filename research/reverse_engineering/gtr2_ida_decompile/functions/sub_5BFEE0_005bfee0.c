BOOL __thiscall sub_5BFEE0(_DWORD *this)
{
  int v2; // ecx
  int v3; // ecx
  BOOL result; // eax

  v2 = *(_DWORD *)(this[74] + 4);
  result = 1;
  if ( !v2 || !(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(v2) )
  {
    v3 = *(_DWORD *)(this[80] + 4);
    if ( !v3 || !(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3) )
      return 0;
  }
  return result;
}
