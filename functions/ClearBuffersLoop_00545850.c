int __thiscall sub_545850(_DWORD *this)
{
  int i; // edi
  int j; // esi
  int result; // eax
  int k; // esi

  for ( i = this[64]; i; i = *(_DWORD *)(i + 260) )
  {
    for ( j = *(_DWORD *)(i + 236); j; j = *(_DWORD *)(j + 76) )
    {
      BitmaskClear(0, 32, 0);
      result = SceneGraphFlagPropagation(0, 0x10000000, 0);
    }
  }
  for ( k = this[66]; k; k = *(_DWORD *)(k + 76) )
  {
    BitmaskClear(0, 32, 0);
    result = SceneGraphFlagPropagation(0, 0x10000000, 0);
  }
  return result;
}
