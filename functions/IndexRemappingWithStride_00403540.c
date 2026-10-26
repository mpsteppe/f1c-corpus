void __thiscall sub_403540(_DWORD *this)
{
  int v1; // edi
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // esi
  int v6; // edx
  int v7; // esi
  int v8; // edx
  int v9; // [esp+8h] [ebp-4h]

  v1 = this[76];
  v9 = 0;
  if ( v1 > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this[77];
      v4 = *(_DWORD *)(v2 + v3 + 292);
      if ( v4 == -1 || v4 >= v1 )
      {
        *(_DWORD *)(v2 + v3 + 272) = 0;
        *(_DWORD *)(v2 + this[77] + 292) = -1;
      }
      else
      {
        *(_DWORD *)(v2 + v3 + 272) = v3 + 316 * v4;
      }
      v5 = this[77];
      v6 = *(_DWORD *)(v2 + v5 + 288);
      if ( v6 == -1 || v6 >= this[76] )
      {
        *(_DWORD *)(v2 + v5 + 268) = 0;
        *(_DWORD *)(v2 + this[77] + 288) = -1;
      }
      else
      {
        *(_DWORD *)(v2 + v5 + 268) = v5 + 316 * v6;
      }
      v7 = this[77];
      v8 = *(_DWORD *)(v2 + v7 + 296);
      if ( v8 == -1 || v8 >= this[76] )
      {
        *(_DWORD *)(v2 + v7 + 276) = 0;
        *(_DWORD *)(v2 + this[77] + 296) = -1;
      }
      else
      {
        *(_DWORD *)(v2 + v7 + 276) = v7 + 316 * v8;
      }
      v1 = this[76];
      v2 += 316;
      ++v9;
    }
    while ( v9 < v1 );
  }
}
