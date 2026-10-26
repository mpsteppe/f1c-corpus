int __thiscall sub_4FC170(_DWORD *this, float a2)
{
  int result; // eax
  int v3; // ebp
  int v4; // eax
  int v5; // edx
  int i; // eax
  int v7; // edx
  int v8; // esi
  int v9; // edi
  int v10; // ebx
  int k; // esi
  int v12; // eax
  int v13; // [esp+0h] [ebp-44h]
  _DWORD v14[16]; // [esp+4h] [ebp-40h]
  float v15; // [esp+48h] [ebp+4h]
  int j; // [esp+48h] [ebp+4h]

  v15 = a2 * 255.0;
  result = 65793 * (int)v15;
  v13 = result;
  if ( this[16] != result )
  {
    this[16] = result;
    v3 = 0;
    if ( *this )
    {
      v14[0] = *this;
      v3 = 1;
    }
    v4 = this[4];
    if ( v4 )
      v14[v3++] = v4;
    v5 = this[18];
    for ( i = 0; i < v5; ++i )
    {
      if ( v3 < 16 )
        v14[v3++] = *(_DWORD *)(this[19] + 4 * i);
    }
    v7 = this[31];
    for ( result = 0; result < v7; ++result )
    {
      if ( v3 < 16 )
        v14[v3++] = *(_DWORD *)(this[32] + 4 * result);
    }
    v8 = 0;
    for ( j = 0; v8 < v3; j = v8 )
    {
      result = sub_54C230(0);
      v9 = result;
      if ( result )
      {
        v10 = sub_54E100(result);
        for ( k = 0; k < v10; *(_DWORD *)(v12 + 24) = v13 | *(_DWORD *)(v12 + 24) & 0xFF000000 )
          v12 = sub_54E120(k++);
        v8 = j;
        result = *(_DWORD *)(v9 + 20) & 0xEFFFFFFF;
        *(_DWORD *)(v9 + 20) = result;
      }
      ++v8;
    }
  }
  return result;
}
