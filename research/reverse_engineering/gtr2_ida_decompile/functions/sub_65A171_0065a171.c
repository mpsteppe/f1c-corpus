int __thiscall sub_65A171(_DWORD *this, int a2, int a3)
{
  *(_DWORD *)(this[155] + 28) = a2;
  if ( this[158] != 12 )
    --*(_DWORD *)(this[155] + 28);
  if ( a3 )
    *(_DWORD *)(this[155] + 24) = a3;
  return 0;
}
