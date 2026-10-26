int __thiscall sub_6A2CA6(_DWORD *this)
{
  int v1; // edx
  _DWORD *v2; // esi
  int v3; // eax
  unsigned int v4; // edi
  int v5; // esi
  unsigned int v6; // esi
  int v7; // ebx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  unsigned int v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // esi
  _DWORD *v14; // edx
  int v15; // edx
  _DWORD *v16; // eax
  _DWORD *v17; // edx
  unsigned int v18; // edi
  unsigned int v19; // esi
  _DWORD *v20; // eax
  int v21; // edx
  unsigned int v23; // [esp+10h] [ebp-20h]
  int v24; // [esp+14h] [ebp-1Ch]
  int v25; // [esp+14h] [ebp-1Ch]
  _DWORD *v26; // [esp+18h] [ebp-18h]
  _DWORD **v27; // [esp+1Ch] [ebp-14h]
  _DWORD **v28; // [esp+1Ch] [ebp-14h]
  _DWORD *v29; // [esp+20h] [ebp-10h]
  int v30; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+24h] [ebp-Ch]
  unsigned int v32; // [esp+28h] [ebp-8h]
  unsigned int v33; // [esp+2Ch] [ebp-4h]

  v1 = this[137];
  v2 = *(_DWORD **)(this[140] + 4 * v1 - 4);
  v29 = v2;
  if ( !v2 || *v2 != 268435460 )
    return 0;
  v3 = this[5];
  v4 = 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v3 + 4 * *(_DWORD *)(v4 + v2[4]));
    if ( *(_DWORD *)(v5 + 4) != this[33]
      || *(_DWORD *)(v5 + 60)
      || (*(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v4 + v29[2])) + 62) & 0x1F) != 0 )
    {
      return 0;
    }
    v4 += 4;
    if ( v4 >= 0x10 )
      break;
    v2 = *(_DWORD **)(this[140] + 4 * v1 - 4);
  }
  v32 = 0;
  v30 = 1;
  v33 = v1 - 1;
  v26 = (_DWORD *)v29[2];
  do
  {
    v6 = 0;
    v7 = 0;
    if ( v33 )
    {
      v27 = (_DWORD **)this[140];
      do
      {
        v8 = *v27;
        if ( *v27 && *v8 )
        {
          v9 = v8[3];
          if ( v9 )
          {
            v10 = (_DWORD *)v8[4];
            do
            {
              if ( *v10 == *v26 )
                v7 = 1;
              ++v10;
              --v9;
            }
            while ( v9 );
          }
          if ( v7 )
            break;
        }
        ++v27;
        ++v6;
      }
      while ( v6 < v33 );
    }
    if ( (unsigned __int16)this[50] != 260 )
    {
      if ( v6 >= this[19] )
        goto LABEL_27;
LABEL_26:
      v30 = 0;
      goto LABEL_27;
    }
    if ( v6 < this[19] && v6 )
      goto LABEL_26;
LABEL_27:
    if ( !v7 )
      return 0;
    v11 = v6 + 1;
    if ( v11 < v33 )
    {
      v28 = (_DWORD **)(this[140] + 4 * v11);
      v23 = v33 - v11;
      do
      {
        v12 = *v28;
        if ( *v28 && *v12 )
        {
          if ( v12[3] )
          {
            v13 = (_DWORD *)v12[4];
            v24 = v12[3];
            do
            {
              v14 = *(_DWORD **)(this[5] + 4 * *v13);
              if ( v14[1] == this[34] && v14[4] == v32 && !v14[3] )
                v30 = 0;
              ++v13;
              --v24;
            }
            while ( v24 );
          }
          v15 = v12[1];
          if ( v15 )
          {
            v16 = (_DWORD *)v12[2];
            v25 = v15;
            do
            {
              v17 = *(_DWORD **)(this[5] + 4 * *v16);
              if ( v17[1] == this[34] && v17[4] == v32 && !v17[3] )
                v30 = 0;
              ++v16;
              --v25;
            }
            while ( v25 );
          }
        }
        ++v28;
        --v23;
      }
      while ( v23 );
    }
    ++v32;
    ++v26;
  }
  while ( v32 < 4 );
  v18 = 0;
  if ( v30 )
  {
    do
    {
      v19 = 0;
      for ( i = 0; i < v33; v33 = this[137] - 1 )
      {
        v20 = *(_DWORD **)(this[140] + 4 * i);
        if ( v20 && *v20 && v20[3] )
        {
          do
          {
            v21 = *(_DWORD *)(v20[4] + 4 * v19);
            if ( v21 == *(_DWORD *)(v18 + v29[2]) )
              *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v21) + 12) = 0;
            ++v19;
          }
          while ( v19 < v20[3] );
          v19 = 0;
        }
        ++i;
      }
      v18 += 4;
    }
    while ( v18 < 0x10 );
    *v29 = 0;
  }
  return 0;
}
