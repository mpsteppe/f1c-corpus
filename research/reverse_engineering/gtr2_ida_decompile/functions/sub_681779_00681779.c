int __thiscall sub_681779(int this, void *Block)
{
  int v3; // eax
  char *v4; // edx
  int result; // eax
  char *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v3 = *(_DWORD *)(this + 28);
  if ( *(_DWORD *)(this + 4) != v3 )
    goto LABEL_10;
  if ( v3 )
    v7 = 2 * v3;
  else
    v7 = 16;
  v4 = (char *)operator new(4 * v7);
  v6 = v4;
  if ( v4 )
  {
    qmemcpy(v4, *(const void **)(this + 16), 4 * *(_DWORD *)(this + 4));
    memset(&v4[4 * *(_DWORD *)(this + 4)], 0, 4 * (v7 - *(_DWORD *)(this + 4)));
    j__free(*(void **)(this + 16));
    *(_DWORD *)(this + 28) = v7;
    *(_DWORD *)(this + 16) = v6;
LABEL_10:
    *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(this + 4)) = Block;
    result = *(_DWORD *)(this + 4);
    *(_DWORD *)(this + 4) = result + 1;
    return result;
  }
  if ( Block )
    sub_681758(Block, 1);
  return -1;
}
