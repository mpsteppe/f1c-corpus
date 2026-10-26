int __fastcall sub_6C2D70(int a1)
{
  unsigned int v1; // eax
  int v2; // edx
  int v3; // ebx
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  _DWORD *v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  unsigned int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v1 = **(_DWORD **)(a1 + 256) & 0xFFFFF;
  v8 = a1;
  v13 = 0;
  if ( v1 )
  {
    v2 = *(_DWORD *)(a1 + 20);
    v3 = *(_DWORD *)(*(_DWORD *)(a1 + 256) + 8);
    v14 = 8 * v1;
    v11 = (_DWORD *)(v3 + 4 * v1);
    while ( 1 )
    {
      v4 = *(_DWORD *)(v3 + 4 * v13);
      v9 = *(_DWORD *)(v2 + 4 * v4);
      v10 = *(_DWORD *)(v2 + 4 * *v11);
      v12 = *(_DWORD *)(v2 + 4 * *(_DWORD *)(v14 + v3));
      if ( v4 != *v11 )
        return 1;
      a1 = v8;
      v5 = *(_DWORD *)(v10 + 56);
      if ( v5 != *(_DWORD *)(v14 + *(_DWORD *)(*(_DWORD *)(v8 + 256) + 8)) && (v5 == -1 || v5 != *(_DWORD *)(v12 + 56)) )
        return 1;
      if ( (*(_DWORD *)(v10 + 60) ^ 0x80000) != *(_DWORD *)(v12 + 60) )
        return 1;
      v6 = *(_DWORD *)(v9 + 56);
      if ( v6 != *(_DWORD *)(v14 + *(_DWORD *)(*(_DWORD *)(v8 + 256) + 8)) && (v6 == -1 || v6 != *(_DWORD *)(v12 + 56)) )
        return 1;
      if ( (*(_DWORD *)(v9 + 60) ^ 0x80000) != *(_DWORD *)(v12 + 60) )
        return 1;
      ++v13;
      ++v11;
      v14 += 4;
      if ( v13 >= v1 )
        goto LABEL_13;
    }
  }
  else
  {
LABEL_13:
    **(_DWORD **)(a1 + 256) = v1 & 0xFFFFF | 0x70000000;
    *(_DWORD *)(*(_DWORD *)(a1 + 256) + 4) = v1;
    qmemcpy(
      *(void **)(*(_DWORD *)(a1 + 256) + 8),
      (const void *)(*(_DWORD *)(*(_DWORD *)(a1 + 256) + 8) + 8 * v1),
      4 * v1);
    return 0;
  }
}
