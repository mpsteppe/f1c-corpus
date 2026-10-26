unsigned int __thiscall sub_6B8C7E(_DWORD *this, unsigned int a2)
{
  unsigned int v2; // esi
  int v3; // eax
  _BYTE *v4; // edx
  unsigned int v5; // edi
  unsigned int v6; // eax
  _BYTE *v7; // esi
  _BYTE *v8; // esi
  _BYTE *v9; // edx
  _BYTE *v10; // esi
  _BYTE *v11; // esi
  _BYTE *v12; // esi
  _BYTE *v13; // esi
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  _BYTE *v16; // esi
  _BYTE *v17; // esi
  int v18; // eax
  unsigned int result; // eax
  unsigned int v20; // [esp+Ch] [ebp-18h]
  unsigned int v21; // [esp+10h] [ebp-14h]
  unsigned int v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+18h] [ebp-Ch]
  unsigned int v24; // [esp+1Ch] [ebp-8h]
  char v25; // [esp+22h] [ebp-2h]
  char v26; // [esp+23h] [ebp-1h]

  v24 = this[29];
  v2 = this[25];
  v23 = this[34];
  v3 = this[9];
  v4 = (_BYTE *)(v2 + this[12]);
  v5 = this[28];
  if ( v2 <= v3 - 262 )
    v22 = 0;
  else
    v22 = v2 - v3 + 262;
  v21 = (unsigned int)(v4 + 258);
  v26 = v4[v5 - 1];
  v25 = v4[v5];
  if ( v5 >= this[33] )
    v24 >>= 2;
  v20 = this[27];
  if ( v23 > v20 )
    v23 = this[27];
  v6 = a2;
  do
  {
    v7 = (_BYTE *)(v6 + this[12]);
    if ( v7[v5] == v25 && v7[v5 - 1] == v26 && *v7 == *v4 )
    {
      v8 = v7 + 1;
      if ( *v8 == v4[1] )
      {
        v9 = v4 + 2;
        v10 = v8 + 1;
        do
        {
          ++v9;
          v11 = v10 + 1;
          if ( *v9 != *v11 )
            break;
          ++v9;
          v12 = v11 + 1;
          if ( *v9 != *v12 )
            break;
          ++v9;
          v13 = v12 + 1;
          if ( *v9 != *v13 )
            break;
          ++v9;
          v14 = v13 + 1;
          if ( *v9 != *v14 )
            break;
          ++v9;
          v15 = v14 + 1;
          if ( *v9 != *v15 )
            break;
          ++v9;
          v16 = v15 + 1;
          if ( *v9 != *v16 )
            break;
          ++v9;
          v17 = v16 + 1;
          if ( *v9 != *v17 )
            break;
          ++v9;
          v10 = v17 + 1;
          if ( *v9 != *v10 )
            break;
        }
        while ( (unsigned int)v9 < v21 );
        v18 = (int)&v9[-v21 + 258];
        v4 = (_BYTE *)(v21 - 258);
        if ( v18 > (int)v5 )
        {
          this[26] = a2;
          v5 = v18;
          if ( v18 >= v23 )
            break;
          v26 = v4[v18 - 1];
          v25 = v4[v18];
        }
      }
    }
    v6 = *(unsigned __int16 *)(this[14] + 2 * (a2 & this[11]));
    a2 = v6;
    if ( v6 <= v22 )
      break;
    --v24;
  }
  while ( v24 );
  result = v20;
  if ( v5 <= v20 )
    return v5;
  return result;
}
