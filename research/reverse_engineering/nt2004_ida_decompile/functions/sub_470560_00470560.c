int __thiscall sub_470560(_DWORD *this)
{
  int v2; // ecx
  double v3; // st7
  float v5; // [esp+8h] [ebp-4h]

  v2 = this[73];
  if ( v2 || this[72] != MEMORY[0x14] )
  {
    this[72] = *(_DWORD *)(v2 + 20);
    v3 = (double)*(int *)(v2 + 16);
    if ( v3 != 0.0 )
      v5 = (double)*(int *)(v2 + 20) / v3;
    if ( this[67] )
      this[69] = (__int64)((double)sub_5A8900() * v5);
  }
  if ( !this[69] )
    this[69] = 3;
  return 0;
}
