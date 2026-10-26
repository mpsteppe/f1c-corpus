int __thiscall sub_6AB5E5(_DWORD *this, int a2, unsigned int a3)
{
  _DWORD *i; // edx
  int v5; // eax
  unsigned int v6; // eax
  int v8; // [esp+Ch] [ebp-4h]
  unsigned int v9; // [esp+18h] [ebp+8h]

  v8 = 0;
  v9 = *(_DWORD *)(a2 + 4);
  if ( !v9 )
    return 0;
  for ( i = *(_DWORD **)(a2 + 8); ; ++i )
  {
    v5 = *(_DWORD *)(this[5] + 4 * *i);
    if ( this[34] == *(_DWORD *)(v5 + 4) )
    {
      v6 = *(_DWORD *)(v5 + 80);
      if ( v6 < a3 && (*(_WORD *)(*(_DWORD *)(this[6] + 4 * v6) + 2) & 0xFFF0) != 0 )
        break;
    }
    if ( ++v8 >= v9 )
      return 0;
  }
  return 1;
}
