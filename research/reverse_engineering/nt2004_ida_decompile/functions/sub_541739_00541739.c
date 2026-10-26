int __thiscall sub_541739(_DWORD *this)
{
  int v3; // edi
  char *v4; // eax
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // esi
  _DWORD *v10; // eax
  unsigned int v11; // esi
  char *v12; // esi
  int v13; // [esp+4h] [ebp-3Ch]
  int v14; // [esp+8h] [ebp-38h]
  int v15; // [esp+Ch] [ebp-34h]
  char *v16; // [esp+10h] [ebp-30h]
  _DWORD *v17; // [esp+10h] [ebp-30h]
  int v18; // [esp+10h] [ebp-30h]
  int v19; // [esp+14h] [ebp-2Ch]
  unsigned int v20; // [esp+18h] [ebp-28h]
  unsigned int v21; // [esp+1Ch] [ebp-24h]
  unsigned int v22; // [esp+20h] [ebp-20h]
  unsigned int v23; // [esp+24h] [ebp-1Ch]
  unsigned int i; // [esp+28h] [ebp-18h]
  _DWORD *v25; // [esp+2Ch] [ebp-14h]
  char *v26; // [esp+30h] [ebp-10h]

  if ( *((_BYTE *)this + 8) != 2 )
    return -2147467259;
  v3 = *(_DWORD *)(*this + 4184);
  v4 = (char *)operator new(16 * v3);
  v16 = v4;
  if ( v4 )
  {
    sub_53D688((int)v4, 16, v3, (int (__thiscall *)(int))sub_53D5B2);
    v26 = v16;
  }
  else
  {
    v26 = 0;
  }
  if ( !v26 )
    return -2147024882;
  v5 = *(_DWORD *)(this[1] + 4184);
  v6 = operator new(16 * v5);
  v17 = v6;
  if ( v6 )
  {
    sub_53D688((int)v6, 16, v5, (int (__thiscall *)(int))sub_53D5B2);
    v25 = v17;
  }
  else
  {
    v25 = 0;
  }
  if ( v25 )
  {
    v7 = (_DWORD *)this[1];
    v8 = v7[1047];
    v20 = 0;
    v23 = 0;
    v15 = (*(_DWORD *)(*this + 4184) << 16) / v7[1046];
    v14 = (*(_DWORD *)(*this + 4188) << 16) / v8;
    v13 = (*(_DWORD *)(*this + 4192) << 16) / v7[1048];
    do
    {
      v19 = -1;
      v9 = 0;
      v18 = 0;
      for ( i = 0; i < v8; v18 += v14 )
      {
        v22 = 0;
        v21 = 0;
        if ( ((v9 ^ v19) & 0xFFFF0000) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, char *))(*(_DWORD *)*this + 4))(
            *this,
            HIWORD(v9),
            HIWORD(v20),
            v26);
          v19 = v9;
        }
        if ( *(_DWORD *)(this[1] + 4184) )
        {
          v10 = v25;
          do
          {
            v11 = v22;
            v22 += v15;
            v12 = &v26[16 * HIWORD(v11)];
            ++v21;
            *v10 = *(_DWORD *)v12;
            v12 += 4;
            v10[1] = *(_DWORD *)v12;
            v12 += 4;
            v10[2] = *(_DWORD *)v12;
            v10[3] = *((_DWORD *)v12 + 1);
            v10 += 4;
          }
          while ( v21 < *(_DWORD *)(this[1] + 4184) );
        }
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, _DWORD *))(*(_DWORD *)this[1] + 8))(
          this[1],
          i,
          v23,
          v25);
        v9 = v14 + v18;
        ++i;
        v8 = *(_DWORD *)(this[1] + 4188);
      }
      v20 += v13;
      ++v23;
    }
    while ( v23 < *(_DWORD *)(this[1] + 4192) );
    sub_5BE8AE();
    sub_5BE8AE();
    return 0;
  }
  else
  {
    sub_5BE8AE();
    return -2147024882;
  }
}
