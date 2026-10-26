int __thiscall sub_681833(int this, long double *a2)
{
  int v3; // eax
  char *v4; // edx
  int result; // eax
  char *v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v3 = *(_DWORD *)(this + 32);
  if ( *(_DWORD *)(this + 8) == v3 )
  {
    if ( v3 )
      v7 = 2 * v3;
    else
      v7 = 1024;
    v4 = (char *)operator new(4 * v7);
    v6 = v4;
    if ( !v4 )
    {
      if ( a2 )
        sub_663A9B(a2, 1);
      return -1;
    }
    qmemcpy(v4, *(const void **)(this + 20), 4 * *(_DWORD *)(this + 8));
    memset(&v4[4 * *(_DWORD *)(this + 8)], 0, 4 * (v7 - *(_DWORD *)(this + 8)));
    j__free(*(void **)(this + 20));
    *(_DWORD *)(this + 20) = v6;
    *(_DWORD *)(this + 32) = v7;
  }
  if ( a2
    && (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *((_DWORD *)a2 + 1)) + 5) & 1) != 0
    && *((_DWORD *)a2 + 2) == -1 )
  {
    *(_BYTE *)a2 |= 0x80u;
    if ( 0.0 == a2[4] || 1.0 == a2[4] )
      *(_DWORD *)a2 |= 1u;
    if ( fabs(a2[4] - (double)(int)(__int64)a2[4]) < 0.000001 )
      *(_DWORD *)a2 |= 2u;
    if ( a2[4] >= 0.0 )
      *(_DWORD *)a2 |= 4u;
    if ( a2[4] <= 0.0 )
      *(_DWORD *)a2 |= 8u;
    if ( fabs(a2[4]) <= 1.0 )
      *(_DWORD *)a2 |= 0x10u;
  }
  *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(this + 8)) = a2;
  result = *(_DWORD *)(this + 8);
  *(_DWORD *)(this + 8) = result + 1;
  return result;
}
