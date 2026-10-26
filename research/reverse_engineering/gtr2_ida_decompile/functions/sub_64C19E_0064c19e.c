int __thiscall sub_64C19E(_DWORD *this)
{
  int v3; // edi
  char *v4; // eax
  int v5; // edi
  _DWORD *v6; // eax
  int v7; // eax
  _DWORD *v8; // esi
  _DWORD *i; // eax
  unsigned int v10; // esi
  _DWORD *v11; // eax
  unsigned int v12; // esi
  char *v13; // esi
  int v14; // [esp+4h] [ebp-30h]
  int v15; // [esp+8h] [ebp-2Ch]
  int v16; // [esp+Ch] [ebp-28h]
  char *v17; // [esp+10h] [ebp-24h]
  _DWORD *v18; // [esp+10h] [ebp-24h]
  int v19; // [esp+10h] [ebp-24h]
  int v20; // [esp+14h] [ebp-20h]
  unsigned int v21; // [esp+18h] [ebp-1Ch]
  unsigned int v22; // [esp+1Ch] [ebp-18h]
  unsigned int v23; // [esp+20h] [ebp-14h]
  unsigned int v24; // [esp+24h] [ebp-10h]
  unsigned int v25; // [esp+28h] [ebp-Ch]
  _DWORD *v26; // [esp+2Ch] [ebp-8h]
  char *Block; // [esp+30h] [ebp-4h]

  if ( *((_BYTE *)this + 8) != 2 )
    return -2147467259;
  v3 = *(_DWORD *)(*this + 104);
  v4 = (char *)operator new(16 * v3);
  v17 = v4;
  if ( v4 )
  {
    sub_41D1B0((int)v4, 16, v3, (int)sub_681563);
    Block = v17;
  }
  else
  {
    Block = 0;
  }
  if ( !Block )
    return -2147024882;
  v5 = *(_DWORD *)(this[1] + 104);
  v6 = operator new(16 * v5);
  v18 = v6;
  if ( v6 )
  {
    sub_41D1B0((int)v6, 16, v5, (int)sub_681563);
    v26 = v18;
  }
  else
  {
    v26 = 0;
  }
  if ( v26 )
  {
    v7 = this[1];
    if ( *(_DWORD *)(v7 + 16) && *(_DWORD *)(*this + 16) )
    {
      *(_DWORD *)(v7 + 16) = 0;
      *(_DWORD *)(*this + 16) = 0;
    }
    v8 = (_DWORD *)this[1];
    v21 = 0;
    v24 = 0;
    v16 = (*(_DWORD *)(*this + 104) << 16) / v8[26];
    v15 = (*(_DWORD *)(*this + 108) << 16) / v8[27];
    v14 = (*(_DWORD *)(*this + 112) << 16) / v8[28];
    for ( i = v8; v24 < i[28]; i = (_DWORD *)this[1] )
    {
      v20 = -1;
      v10 = 0;
      v19 = 0;
      v25 = 0;
      if ( i[27] )
      {
        do
        {
          v23 = 0;
          v22 = 0;
          if ( ((v10 ^ v20) & 0xFFFF0000) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, char *))(*(_DWORD *)*this + 4))(
              *this,
              HIWORD(v10),
              HIWORD(v21),
              Block);
            v20 = v10;
          }
          if ( *(_DWORD *)(this[1] + 104) )
          {
            v11 = v26;
            do
            {
              v12 = v23;
              v23 += v16;
              v13 = &Block[16 * HIWORD(v12)];
              ++v22;
              *v11 = *(_DWORD *)v13;
              v13 += 4;
              v11[1] = *(_DWORD *)v13;
              v13 += 4;
              v11[2] = *(_DWORD *)v13;
              v11[3] = *((_DWORD *)v13 + 1);
              v11 += 4;
            }
            while ( v22 < *(_DWORD *)(this[1] + 104) );
          }
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, _DWORD *))(*(_DWORD *)this[1] + 8))(
            this[1],
            v25,
            v24,
            v26);
          v10 = v15 + v19;
          ++v25;
          v19 += v15;
        }
        while ( v25 < *(_DWORD *)(this[1] + 108) );
      }
      v21 += v14;
      ++v24;
    }
    j__free(Block);
    j__free(v26);
    return 0;
  }
  else
  {
    j__free(Block);
    return -2147024882;
  }
}
