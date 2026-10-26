int __thiscall sub_6844C5(_DWORD *this, int a2)
{
  int v3; // eax
  int result; // eax
  _DWORD *v5; // edi
  unsigned int v6; // esi
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // esi
  int v10; // [esp+14h] [ebp-Ch]
  int *v11; // [esp+18h] [ebp-8h]
  _DWORD *v12; // [esp+18h] [ebp-8h]
  unsigned int v13; // [esp+1Ch] [ebp-4h]
  unsigned int v14; // [esp+1Ch] [ebp-4h]

  v3 = sub_681C03(this, (_DWORD *)a2);
  if ( v3 == -1 )
    return -2147024882;
  v5 = *(_DWORD **)(this[6] + 4 * v3);
  sub_680D22(v5, a2);
  v6 = *(_DWORD *)(a2 + 12);
  v13 = 0;
  if ( v6 )
  {
    v10 = **(_DWORD **)(a2 + 16);
    v11 = *(int **)(a2 + 16);
    do
    {
      if ( !sub_683ACB(this, v10, *v11) )
        break;
      ++v13;
      ++v11;
    }
    while ( v13 < v6 );
  }
  if ( v13 == v6 )
    return 0;
  v7 = sub_681B0A(this, v6 & 0xFFFFF | 0x10000000, -1, -1);
  if ( v7 == -1 )
    return -2147024882;
  v8 = *(_DWORD **)(this[6] + 4 * v7);
  v12 = v8;
  sub_680D22(v8, a2);
  v14 = 0;
  if ( v5[3] )
  {
    while ( 1 )
    {
      v9 = 4 * v14;
      *(_DWORD *)(4 * v14 + v12[4]) = *(_DWORD *)(4 * v14 + v5[4]);
      *(_DWORD *)(v9 + v12[2]) = sub_681AAA(this, this[34], -1, -1, 0.0);
      *(_DWORD *)(v9 + v5[4]) = *(_DWORD *)(v9 + v12[2]);
      if ( *(_DWORD *)(4 * v14 + v5[4]) == -1 )
        return -2147024882;
      sub_681692(
        *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v9 + v5[4])),
        *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v9 + *(_DWORD *)(a2 + 16))));
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v9 + v5[4])) + 20) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v9 + *(_DWORD *)(a2 + 16)))
                                                                                       + 20);
      ++v14;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v9 + v5[4])) + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v9 + *(_DWORD *)(a2 + 16)))
                                                                                       + 24);
      **(_DWORD **)(this[5] + 4 * *(_DWORD *)(v9 + v5[4])) = **(_DWORD **)(this[5]
                                                                         + 4 * *(_DWORD *)(v9 + *(_DWORD *)(a2 + 16)));
      if ( v14 >= v5[3] )
      {
        v8 = v12;
        break;
      }
    }
  }
  result = sub_683C12(this, v8);
  if ( result >= 0 )
  {
    *v8 = 0;
    return 0;
  }
  return result;
}
