int __stdcall sub_6B9044(int a1, int a2)
{
  unsigned int v2; // edi
  unsigned int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  __int16 v7; // ax
  unsigned __int8 v8; // cl
  unsigned __int16 v9; // ax
  _WORD *v10; // ecx
  int v11; // eax
  unsigned int v12; // eax
  BOOL v13; // ebx
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  unsigned __int8 v25; // al
  int v26; // ecx
  int v27; // eax
  int v29; // ecx
  int v30; // eax

  v2 = 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 108);
    if ( v3 < 0x106 )
    {
      sub_6B8DC8(a1);
      v3 = *(_DWORD *)(a1 + 108);
      if ( v3 < 0x106 && !a2 )
        return 0;
      if ( !v3 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = *(_DWORD *)(a1 + 100);
      v5 = *(_DWORD *)(a1 + 76)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 48) + v4 + 2)
          ^ (*(_DWORD *)(a1 + 64) << *(_DWORD *)(a1 + 80)));
      v6 = *(_DWORD *)(a1 + 60);
      *(_DWORD *)(a1 + 64) = v5;
      v2 = *(unsigned __int16 *)(v6 + 2 * v5);
      *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (v4 & *(_DWORD *)(a1 + 44))) = v2;
      *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
    }
    if ( v2 && *(_DWORD *)(a1 + 100) - v2 <= *(_DWORD *)(a1 + 36) - 262 && *(_DWORD *)(a1 + 128) != 2 )
      *(_DWORD *)(a1 + 88) = sub_6B8C7E((_DWORD *)a1, v2);
    if ( *(_DWORD *)(a1 + 88) < 3u )
    {
      v25 = *(_BYTE *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v25;
      ++*(_WORD *)(a1 + 4 * v25 + 140);
      v13 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      --*(_DWORD *)(a1 + 108);
    }
    else
    {
      v7 = *(_WORD *)(a1 + 100) - *(_WORD *)(a1 + 104);
      v8 = *(_BYTE *)(a1 + 88) - 3;
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = v7;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v8;
      v9 = v7 - 1;
      v10 = (_WORD *)(a1 + 4 * (unsigned __int8)byte_748810[v8] + 1168);
      ++*v10;
      if ( v9 >= 0x100u )
        v11 = (unsigned __int8)byte_748710[v9 >> 7];
      else
        v11 = (unsigned __int8)byte_748610[v9];
      ++*(_WORD *)(a1 + 4 * v11 + 2432);
      v12 = *(_DWORD *)(a1 + 88);
      v13 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      *(_DWORD *)(a1 + 108) -= v12;
      if ( v12 > *(_DWORD *)(a1 + 120) || *(_DWORD *)(a1 + 108) < 3u )
      {
        *(_DWORD *)(a1 + 100) += v12;
        v20 = *(_DWORD *)(a1 + 100);
        v21 = *(_DWORD *)(a1 + 48);
        *(_DWORD *)(a1 + 88) = 0;
        v22 = v20 + v21;
        v23 = *(unsigned __int8 *)(v20 + v21);
        v24 = *(_DWORD *)(a1 + 80);
        *(_DWORD *)(a1 + 64) = v23;
        *(_DWORD *)(a1 + 64) = *(_DWORD *)(a1 + 76) & (*(unsigned __int8 *)(v22 + 1) ^ (v23 << v24));
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 88) = v12 - 1;
      do
      {
        v14 = ++*(_DWORD *)(a1 + 100);
        v15 = *(unsigned __int8 *)(v14 + *(_DWORD *)(a1 + 48) + 2);
        v16 = *(_DWORD *)(a1 + 44) & v14;
        v17 = *(_DWORD *)(a1 + 60);
        v18 = *(_DWORD *)(a1 + 76) & ((*(_DWORD *)(a1 + 64) << *(_DWORD *)(a1 + 80)) ^ v15);
        *(_DWORD *)(a1 + 64) = v18;
        v2 = *(unsigned __int16 *)(v17 + 2 * v18);
        *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * v16) = v2;
        *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
      }
      while ( (*(_DWORD *)(a1 + 88))-- != 1 );
    }
    ++*(_DWORD *)(a1 + 100);
LABEL_24:
    if ( v13 )
    {
      v26 = *(_DWORD *)(a1 + 84);
      v27 = v26 < 0 ? 0 : v26 + *(_DWORD *)(a1 + 48);
      sub_6DAAC0(a1, v27, *(_DWORD *)(a1 + 100) - v26, 0);
      *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
      sub_6B88EE(*(_DWORD *)a1);
      if ( !*(_DWORD *)(*(_DWORD *)a1 + 16) )
        return 0;
    }
  }
  v29 = *(_DWORD *)(a1 + 84);
  if ( v29 < 0 )
    v30 = 0;
  else
    v30 = v29 + *(_DWORD *)(a1 + 48);
  sub_6DAAC0(a1, v30, *(_DWORD *)(a1 + 100) - v29, a2 == 4);
  *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
  sub_6B88EE(*(_DWORD *)a1);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) )
    return 2 * (a2 == 4) + 1;
  if ( a2 != 4 )
    return 0;
  return 2;
}
