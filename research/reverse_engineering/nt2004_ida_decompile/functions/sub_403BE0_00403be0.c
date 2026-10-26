void __thiscall sub_403BE0(_DWORD *this)
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

  v1 = this[89];
  v9 = 0;
  if ( v1 > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this[90];
      v4 = *(_DWORD *)(v2 + v3 + 320);
      if ( v4 == -1 || v4 >= v1 )
      {
        *(_DWORD *)(v2 + v3 + 296) = 0;
        *(_DWORD *)(v2 + this[90] + 320) = -1;
      }
      else
      {
        *(_DWORD *)(v2 + v3 + 296) = v3 + 348 * v4;
      }
      v5 = this[90];
      v6 = *(_DWORD *)(v2 + v5 + 316);
      if ( v6 == -1 || v6 >= this[89] )
      {
        *(_DWORD *)(v2 + v5 + 292) = 0;
        *(_DWORD *)(v2 + this[90] + 316) = -1;
      }
      else
      {
        *(_DWORD *)(v2 + v5 + 292) = v5 + 348 * v6;
      }
      v7 = this[90];
      v8 = *(_DWORD *)(v2 + v7 + 324);
      if ( v8 == -1 || v8 >= this[89] )
      {
        *(_DWORD *)(v2 + v7 + 300) = 0;
        *(_DWORD *)(v2 + this[90] + 324) = -1;
      }
      else
      {
        *(_DWORD *)(v2 + v7 + 300) = v7 + 348 * v8;
      }
      v1 = this[89];
      v2 += 348;
      ++v9;
    }
    while ( v9 < v1 );
  }
}
