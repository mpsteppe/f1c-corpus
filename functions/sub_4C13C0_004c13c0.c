int __thiscall sub_4C13C0(char *this, int a2)
{
  int v3; // ebp
  int v4; // edi
  char *v5; // eax
  char *v6; // esi
  int v8; // [esp+10h] [ebp-24h]
  _BYTE v9[32]; // [esp+14h] [ebp-20h] BYREF

  v8 = 0;
  if ( !a2 )
    return 0;
  v3 = ActiveEntityCounter(this) + 1;
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  do
  {
    if ( v4 )
      v5 = ShortComputation_13a0(this, v4 - 1);
    else
      v5 = FixedOffsetReturn(this);
    v6 = v5;
    if ( v5 )
    {
      SceneNameLookupBySeason(v5, v9, 0x20u);
      if ( sub_566810(v9, a2) )
        v8 += *((_DWORD *)v6 + 102);
    }
    ++v4;
  }
  while ( v4 < v3 );
  return v8;
}
