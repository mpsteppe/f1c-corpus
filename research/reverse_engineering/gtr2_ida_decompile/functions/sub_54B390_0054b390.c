int __thiscall sub_54B390(_DWORD *this)
{
  int v1; // esi
  int result; // eax
  int v3; // edx
  int v4; // ecx

  v1 = this[994654 * this[994657] + 878];
  result = 0;
  v3 = 0;
  if ( v1 > 0 )
  {
    v4 = (int)&this[994654 * this[994657] + 880] + 1;
    do
    {
      result = *(_DWORD *)(v4 + 2143);
      if ( !*(_BYTE *)v4 )
        break;
      ++v3;
      v4 += 37840;
    }
    while ( v3 < v1 );
  }
  return result;
}
