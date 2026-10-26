int __thiscall sub_683C12(_DWORD *this, _DWORD *a2)
{
  unsigned int v3; // edi
  int v4; // eax
  int v7; // eax
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v11; // edx
  int v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  _DWORD *v16; // edi
  unsigned int v17; // ebx
  bool j; // cf
  int v19; // edx
  unsigned int v20; // eax
  _DWORD *v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // edi
  int v24; // eax
  int v25; // eax
  _DWORD *v26; // edi
  unsigned int v27; // ebx
  unsigned int v28; // edx
  unsigned int v29; // eax
  int v30; // [esp+Ch] [ebp-2Ch]
  int v31; // [esp+10h] [ebp-28h]
  unsigned int v32; // [esp+14h] [ebp-24h]
  int v33; // [esp+14h] [ebp-24h]
  int v34; // [esp+18h] [ebp-20h]
  unsigned int v35; // [esp+1Ch] [ebp-1Ch]
  unsigned int v36; // [esp+1Ch] [ebp-1Ch]
  unsigned int v37; // [esp+1Ch] [ebp-1Ch]
  int v38; // [esp+20h] [ebp-18h]
  unsigned int i; // [esp+20h] [ebp-18h]
  unsigned int v40; // [esp+20h] [ebp-18h]
  unsigned int m; // [esp+20h] [ebp-18h]
  unsigned int k; // [esp+24h] [ebp-14h]
  int v43; // [esp+24h] [ebp-14h]
  unsigned int v44; // [esp+24h] [ebp-14h]
  unsigned int v45; // [esp+28h] [ebp-10h]
  unsigned int v46; // [esp+2Ch] [ebp-Ch]
  _DWORD *v47; // [esp+30h] [ebp-8h]
  int v48; // [esp+34h] [ebp-4h]
  int v49; // [esp+34h] [ebp-4h]
  unsigned int v50; // [esp+34h] [ebp-4h]
  int v51; // [esp+34h] [ebp-4h]
  unsigned int v52; // [esp+40h] [ebp+8h]

  v3 = a2[3];
  v4 = a2[1] / v3;
  v47 = this;
  v52 = v3;
  v45 = v4;
  if ( sub_680DB1(a2) )
  {
    v38 = 0;
    while ( 1 )
    {
      v7 = sub_681B0A(this, *a2 & 0xFFF00000 | 1, -1, -1);
      if ( v7 == -1 )
        break;
      v8 = *(_DWORD *)(this[6] + 4 * v7);
      sub_680D22((_DWORD *)v8, (int)a2);
      v9 = 0;
      if ( v45 )
      {
        do
        {
          *(_DWORD *)(*(_DWORD *)(v8 + 8) + 4 * v9) = *(_DWORD *)(a2[2] + 4 * (v38 + v9 * a2[3]));
          ++v9;
        }
        while ( v9 < v45 );
        this = v47;
      }
      j = v38 + 1 < v52;
      **(_DWORD **)(v8 + 16) = *(_DWORD *)(a2[4] + 4 * v38++);
      if ( !j )
        return 0;
    }
    return -2147024882;
  }
  else
  {
    v11 = 0;
    v46 = v3;
    for ( i = 0; i < v52; ++i )
    {
      v12 = a2[4];
      v13 = *(_DWORD *)(v12 + 4 * v11);
      if ( v13 != -1
        && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v13) + 4)) + 4) & 0x40) != 0 )
      {
        v48 = 0;
        v14 = v11;
        v32 = v11;
        if ( v11 < v52 )
        {
          while ( 1 )
          {
            if ( *(_DWORD *)(4 * v14 + v12) != -1
              && sub_683ACB(this, *(_DWORD *)(a2[4] + 4 * v11), *(_DWORD *)(a2[4] + 4 * v14)) )
            {
              ++v48;
            }
            v14 = ++v32;
            if ( v32 >= v52 )
              break;
            v11 = i;
          }
        }
        v15 = sub_681B0A(this, *a2 ^ (v48 ^ *a2) & 0xFFFFF, -1, -1);
        if ( v15 == -1 )
          return -2147024882;
        v16 = *(_DWORD **)(this[6] + 4 * v15);
        sub_680D22(v16, (int)a2);
        v17 = i;
        v49 = 0;
        v30 = *(_DWORD *)(a2[4] + 4 * i);
        for ( j = i < v52; ; j = v17 < v52 )
        {
          v35 = v17;
          if ( !j )
            break;
          if ( *(_DWORD *)(a2[4] + 4 * v17) != -1 && sub_683ACB(v47, v30, *(_DWORD *)(a2[4] + 4 * v17)) )
          {
            for ( k = 0; k < v45; v17 = v35 )
            {
              v19 = v49 + k * v16[3];
              v20 = v17 + k * a2[3];
              ++k;
              *(_DWORD *)(v16[2] + 4 * v19) = *(_DWORD *)(a2[2] + 4 * v20);
            }
            *(_DWORD *)(v16[4] + 4 * v49) = *(_DWORD *)(a2[4] + 4 * v17);
            *(_DWORD *)(a2[4] + 4 * v17) = -1;
            --v46;
            ++v49;
          }
          ++v17;
        }
        this = v47;
      }
      v11 = i + 1;
    }
    v31 = sub_680F76(a2);
    v34 = 1;
    v33 = 1;
    if ( !v31 )
    {
      v36 = 0;
      v21 = (_DWORD *)a2[4];
      while ( *v21 == -1
           || (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v21) + 4)) + 5) & 0x10) == 0 )
      {
        ++v36;
        ++v21;
        if ( v36 >= v52 )
          goto LABEL_38;
      }
      v31 = 1;
    }
LABEL_38:
    if ( v46 )
    {
      while ( 1 )
      {
        if ( v46 <= 4 && !v31 )
        {
          v34 = 0;
          v33 = 0;
        }
        v22 = 0;
        v50 = 0;
        v43 = 0;
        do
        {
          if ( *(_DWORD *)(a2[4] + 4 * v22) != -1 )
          {
            v23 = 0;
            v40 = 0;
            do
            {
              if ( v40 >= 4 )
                break;
              v24 = a2[4];
              if ( *(_DWORD *)(v24 + 4 * v23) != -1
                && (!v34 || sub_683B40(this, *(_DWORD *)(v24 + 4 * v22), *(_DWORD *)(v24 + 4 * v23)))
                && (!v33 || !sub_683B6D(this, a2, v43, v23)) )
              {
                ++v40;
              }
              v22 = v43;
              ++v23;
            }
            while ( v23 < v52 );
            if ( v50 < v40 )
            {
              v50 = v40;
              v30 = v22;
            }
          }
          v43 = ++v22;
        }
        while ( v22 < v52 );
        if ( !v50 )
          break;
        v25 = sub_681B0A(this, *a2 ^ (v50 ^ *a2) & 0xFFFFF, -1, -1);
        if ( v25 == -1 )
          return -2147024882;
        v26 = *(_DWORD **)(this[6] + 4 * v25);
        sub_680D22(v26, (int)a2);
        v27 = 0;
        v51 = *(_DWORD *)(a2[4] + 4 * v30);
        v44 = 0;
        v37 = 0;
        do
        {
          if ( v44 >= 4 )
            break;
          if ( *(_DWORD *)(a2[4] + 4 * v27) != -1
            && (!v34 || sub_683B40(v47, v51, *(_DWORD *)(a2[4] + 4 * v27)))
            && (!v33 || !sub_683B6D(v47, a2, v30, v27)) )
          {
            for ( m = 0; m < v45; v27 = v37 )
            {
              v28 = v44 + m * v26[3];
              v29 = v27 + m * a2[3];
              ++m;
              *(_DWORD *)(v26[2] + 4 * v28) = *(_DWORD *)(a2[2] + 4 * v29);
            }
            *(_DWORD *)(v26[4] + 4 * v44) = *(_DWORD *)(a2[4] + 4 * v27);
            *(_DWORD *)(a2[4] + 4 * v27) = -1;
            --v46;
            ++v44;
          }
          v37 = ++v27;
        }
        while ( v27 < v52 );
        if ( !v46 )
          break;
        this = v47;
      }
    }
    return 0;
  }
}
