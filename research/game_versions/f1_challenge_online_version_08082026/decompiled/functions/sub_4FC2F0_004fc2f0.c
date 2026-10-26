int __thiscall sub_4FC2F0(_BYTE *this, int a2)
{
  int result; // eax
  int v3; // ebp
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // [esp+Ch] [ebp-80Ch]
  int v11; // [esp+14h] [ebp-804h]
  _DWORD v12[512]; // [esp+18h] [ebp-800h]

  result = *(_DWORD *)(a2 + 280);
  v3 = 0;
  v4 = 0;
  v9 = 0;
  if ( result > 0 )
  {
    v11 = *(_DWORD *)(a2 + 280);
    do
    {
      v5 = v3 + *(_DWORD *)(a2 + 296);
      if ( !sub_588640(v5 + 20, aClouds, 6) && v4 < 256 )
        v12[v4++] = v5;
      if ( !sub_588640(v5 + 20, aCloudr, 6) && v9 < 256 )
        v12[v9++ + 256] = v5;
      v3 += 256;
      result = --v11;
    }
    while ( v11 );
    if ( v4 > 0 )
    {
      v7 = sub_5884ED(v6);
      result = sub_587DD0(this + 80, v12[v7 % v4] + 20, 31);
      this[111] = 0;
    }
    if ( v9 > 0 )
    {
      v8 = sub_5884ED(v6) % v9;
      result = sub_587DD0(this + 132, v12[v8 + 256] + 20, 31);
      this[163] = 0;
    }
  }
  return result;
}
