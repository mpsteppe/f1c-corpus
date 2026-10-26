int __thiscall sub_6CBDBE(_DWORD *this)
{
  int v1; // eax
  int v2; // ebx
  int v3; // esi
  int v4; // edx
  int v5; // edx
  _DWORD v7[2]; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  v9 = 0;
  v1 = this[64];
  v8 = 0;
  v2 = this[4];
  do
  {
    v3 = *(_DWORD *)(v8 + *(_DWORD *)(v1 + 16));
    v4 = *(_DWORD *)(this[5] + 4 * v3);
    if ( (*(_BYTE *)(*(_DWORD *)(v2 + 4 * *(_DWORD *)(v4 + 4)) + 4) & 1) == 0 || *(_DWORD *)(v4 + 92) )
    {
      v5 = v9++;
      v7[v5] = v3;
    }
    v8 += 4;
  }
  while ( v8 < 8 );
  if ( v9 )
    return sub_6CB29C(
             this,
             37,
             v7,
             v9,
             *(_DWORD **)(v1 + 8),
             this[99] != 0 ? this + 100 : 0,
             this[99] != 0 ? this + 104 : 0,
             4,
             0,
             0,
             0,
             0);
  else
    return 0;
}
