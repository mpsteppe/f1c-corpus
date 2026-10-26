int __thiscall sub_6C2BAB(int this)
{
  unsigned int v1; // eax
  int v2; // edi
  _DWORD *v3; // edx
  _DWORD *v4; // esi
  unsigned int v6; // [esp+Ch] [ebp-Ch]
  _DWORD *v7; // [esp+10h] [ebp-8h]
  _DWORD *v8; // [esp+14h] [ebp-4h]

  v1 = **(_DWORD **)(this + 256) & 0xFFFFF;
  v6 = 0;
  if ( v1 )
  {
    v2 = *(_DWORD *)(this + 20);
    v8 = *(_DWORD **)(*(_DWORD *)(this + 256) + 8);
    v7 = &v8[v1];
    while ( 1 )
    {
      v3 = *(_DWORD **)(v2 + 4 * *v8);
      v4 = *(_DWORD **)(v2 + 4 * *v7);
      if ( v3[1] != v4[1] || v3[2] != v4[2] || v3[3] != v4[3] || v3[4] != v4[4] || (v3[15] ^ v4[15]) != 0x80000 )
        return 1;
      ++v6;
      ++v8;
      ++v7;
      if ( v6 >= v1 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    **(_DWORD **)(this + 256) = **(_DWORD **)(this + 256) & 0xFFFFF | 0x70000000;
    *(_DWORD *)(*(_DWORD *)(this + 256) + 4) = v1;
    if ( v1 )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(*(_DWORD *)(this + 256) + 8)) + 62) & 8) != 0 )
        qmemcpy(
          *(void **)(*(_DWORD *)(this + 256) + 8),
          (const void *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + 4 * v1),
          4 * v1);
    }
    return 0;
  }
}
