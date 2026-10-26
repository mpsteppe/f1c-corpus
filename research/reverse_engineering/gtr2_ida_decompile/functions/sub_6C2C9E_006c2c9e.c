int __fastcall sub_6C2C9E(int a1)
{
  _DWORD *v1; // eax
  unsigned int v2; // edx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+14h] [ebp-14h]
  int v10; // [esp+18h] [ebp-10h]
  _DWORD *v11; // [esp+1Ch] [ebp-Ch]
  _DWORD *v12; // [esp+20h] [ebp-8h]
  unsigned int v13; // [esp+24h] [ebp-4h]

  v1 = *(_DWORD **)(a1 + 256);
  v2 = *v1 & 0xFFFFF;
  v8 = a1;
  v13 = 0;
  if ( v2 )
  {
    v3 = v1[2];
    v4 = *(_DWORD *)(a1 + 20);
    v11 = (_DWORD *)(v3 + 4 * v2);
    v12 = (_DWORD *)(v3 + 8 * v2);
    while ( 1 )
    {
      v5 = *(_DWORD *)(v3 + 4 * v13);
      v9 = *(_DWORD *)(v4 + 4 * v5);
      v10 = *(_DWORD *)(v4 + 4 * *v12);
      if ( v5 != *v11 )
        return 1;
      v6 = *(_DWORD *)(v10 + 56);
      if ( v6 != *(_DWORD *)(4 * v13 + *(_DWORD *)(*(_DWORD *)(a1 + 256) + 8))
        && (v6 == -1 || v6 != *(_DWORD *)(v9 + 56)) )
      {
        return 1;
      }
      if ( (*(_DWORD *)(v10 + 60) ^ 0x80000) != *(_DWORD *)(v9 + 60) )
        return 1;
      ++v13;
      ++v12;
      ++v11;
      a1 = v8;
      if ( v13 >= v2 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    **(_DWORD **)(a1 + 256) = v2 & 0xFFFFF | 0x70000000;
    *(_DWORD *)(*(_DWORD *)(a1 + 256) + 4) = v2;
    return 0;
  }
}
