BOOL __thiscall sub_688927(int this)
{
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // esi
  unsigned int v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  _DWORD *v10; // ebx
  unsigned int v11; // eax
  _DWORD *v12; // ebx
  int v13; // edx
  int v14; // ecx
  _DWORD *v15; // ecx
  unsigned int *v16; // eax
  unsigned int v17; // edx
  bool v18; // zf
  int v20; // [esp+4h] [ebp-2Ch]
  unsigned int v21; // [esp+4h] [ebp-2Ch]
  int v22; // [esp+8h] [ebp-28h]
  int v23; // [esp+Ch] [ebp-24h]
  _DWORD *v24; // [esp+10h] [ebp-20h]
  unsigned int v25; // [esp+10h] [ebp-20h]
  unsigned int v26; // [esp+14h] [ebp-1Ch]
  int v27; // [esp+18h] [ebp-18h]
  int v28; // [esp+18h] [ebp-18h]
  int v29; // [esp+1Ch] [ebp-14h]
  unsigned int v30; // [esp+1Ch] [ebp-14h]
  unsigned int v31; // [esp+20h] [ebp-10h]
  unsigned int v32; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+24h] [ebp-Ch]
  unsigned int v34; // [esp+28h] [ebp-8h]
  unsigned int v35; // [esp+28h] [ebp-8h]
  unsigned int v36; // [esp+28h] [ebp-8h]
  unsigned int v37; // [esp+2Ch] [ebp-4h]

  if ( (*(_BYTE *)(this + 108) & 1) != 0 )
    return 1;
  v22 = 0;
  sub_686074(this);
  v2 = *(_DWORD *)(this + 12);
  if ( !v2 )
    return 1;
  do
  {
    v3 = v2 - 1;
    v4 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v3);
    v23 = v3;
    v5 = *v4 & 0xFFF00000;
    if ( v5 != 0x10000000 && v5 != 544210944 )
      goto LABEL_42;
    v34 = 0;
    if ( v4[3] )
    {
      v6 = (_DWORD *)v4[4];
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16)
                                   + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v6) + 4))
                       + 4)
            & 0x20) == 0 )
          break;
        ++v34;
        ++v6;
      }
      while ( v34 < v4[3] );
    }
    if ( v34 < v4[3] )
      goto LABEL_42;
    v35 = 0;
    if ( v4[1] )
    {
      v7 = (_DWORD *)v4[2];
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16)
                                   + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v7) + 4))
                       + 4)
            & 2) == 0 )
          break;
        ++v35;
        ++v7;
      }
      while ( v35 < v4[1] );
    }
    v8 = v4[1];
    if ( v35 < v8 )
      goto LABEL_42;
    v9 = *v4 & 0xFFFFF;
    v32 = 0;
    v31 = v9;
    v26 = v8 / v9;
    if ( !(v8 / v9) )
      goto LABEL_32;
    v27 = 0;
    while ( 1 )
    {
      v36 = 0;
      if ( v9 )
        break;
LABEL_30:
      ++v32;
      v27 += 4 * v9;
      if ( v32 >= v26 )
        goto LABEL_31;
    }
    v29 = v27;
    do
    {
      v10 = *(_DWORD **)(*(_DWORD *)(this + 24)
                       + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v29 + v4[2])) + 72));
      v37 = 0;
      v20 = sub_680D7E(v10);
      v11 = v10[3];
      if ( v11 )
      {
        v12 = (_DWORD *)v10[4];
        v13 = *(_DWORD *)(this + 20);
        v24 = v12;
        do
        {
          v14 = *(_DWORD *)(v13 + 4 * *v12);
          if ( *(_DWORD *)(v14 + 92) > 1u
            || *(_DWORD *)(v14 + 84) != v23
            || v20 && v37 != *(_DWORD *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v4[4] + 4 * v36)) + 16) )
          {
            break;
          }
          ++v37;
          v12 = ++v24;
        }
        while ( v37 < v11 );
      }
      if ( v37 < v11 )
        break;
      ++v36;
      v29 += 4;
    }
    while ( v36 < v31 );
    if ( v36 >= v31 )
    {
      v9 = v31;
      goto LABEL_30;
    }
LABEL_31:
    if ( v32 >= v26 )
    {
LABEL_32:
      for ( i = 0; i < v4[3]; v15[1] = *(_DWORD *)(this + 116) )
      {
        v15 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(4 * i + v4[4]));
        if ( v26 )
        {
          v28 = 4 * i;
          v30 = v26;
          do
          {
            v16 = *(unsigned int **)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v28 + v4[2]));
            v25 = *v16 & 0xE000000;
            v17 = *v15 & 0xE000000;
            v21 = *v16 & 0xF1FFFFFF;
            *v16 = v21;
            if ( v17 <= v25 )
              v17 = v25;
            v18 = v16[24] == 0;
            *v16 = v17 | v21;
            v16[1] = v15[1];
            v16[2] = v15[2];
            v16[3] = v15[3];
            v16[4] = v15[4];
            if ( v18 )
            {
              v16[24] = v15[24];
              v16[25] = v15[25];
            }
            v16[26] = v15[26];
            v16[27] = v15[27];
            v16[28] = v15[28];
            v28 += 4 * v31;
            --v30;
          }
          while ( v30 );
        }
        ++i;
      }
      v22 = 1;
      *v4 = 0;
      v4[1] = 0;
      v4[3] = 0;
    }
LABEL_42:
    v2 = v23;
  }
  while ( v23 );
  return !v22;
}
