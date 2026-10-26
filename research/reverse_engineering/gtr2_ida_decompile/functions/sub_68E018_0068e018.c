int __thiscall sub_68E018(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int result; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a3) + 20);
  if ( v3 == -1 )
    return 0;
  result = sub_68DD50(this, a2, v3, 0, -1, -1);
  if ( result >= 0 )
    return 0;
  return result;
}
