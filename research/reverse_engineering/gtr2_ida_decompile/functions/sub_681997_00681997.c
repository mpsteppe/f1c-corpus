int __thiscall sub_681997(int this, void *a2)
{
  int v3; // eax
  char *v4; // edx
  int result; // eax
  char *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v3 = *(_DWORD *)(this + 36);
  if ( *(_DWORD *)(this + 12) != v3 )
    goto LABEL_10;
  if ( v3 )
    v7 = 2 * v3;
  else
    v7 = 256;
  v4 = (char *)operator new(4 * v7);
  v6 = v4;
  if ( v4 )
  {
    qmemcpy(v4, *(const void **)(this + 24), 4 * *(_DWORD *)(this + 12));
    memset(&v4[4 * *(_DWORD *)(this + 12)], 0, 4 * (v7 - *(_DWORD *)(this + 12)));
    j__free(*(void **)(this + 24));
    *(_DWORD *)(this + 36) = v7;
    *(_DWORD *)(this + 24) = v6;
LABEL_10:
    *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(this + 12)) = a2;
    result = *(_DWORD *)(this + 12);
    *(_DWORD *)(this + 12) = result + 1;
    return result;
  }
  if ( a2 )
    sub_66238F(a2, 1);
  return -1;
}
