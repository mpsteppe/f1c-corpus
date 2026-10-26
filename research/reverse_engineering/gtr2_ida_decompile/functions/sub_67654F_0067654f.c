int __thiscall sub_67654F(size_t *this, _DWORD *a2, int a3)
{
  int result; // eax
  size_t *v5; // esi
  void *v6; // eax
  _DWORD *v7; // eax
  void *v8; // edi
  size_t v9; // eax
  int v10; // ecx
  size_t v11; // esi
  int v12; // edi
  unsigned __int16 *v13; // ecx
  int *v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  void *v18; // eax
  size_t v19; // edi
  size_t v20; // ecx
  unsigned int v21; // ecx
  size_t v22; // ebx
  unsigned __int16 *v23; // eax
  int v24; // esi
  const void *v25; // [esp+8h] [ebp-8h] BYREF
  unsigned __int16 *v26; // [esp+Ch] [ebp-4h]
  int v27; // [esp+18h] [ebp+8h]
  int v28; // [esp+18h] [ebp+8h]

  if ( !a2 )
    return -2005530516;
  v5 = this + 3;
  result = sub_645FAC(a2, 1111577667, &v25, this + 3);
  if ( result >= 0 )
  {
    if ( result == 1 )
      return -2005529767;
    v6 = operator new(*v5);
    this[2] = (size_t)v6;
    if ( !v6 )
      return -2147024882;
    qmemcpy(v6, v25, *v5);
    v7 = (_DWORD *)this[2];
    this[4] = (size_t)v7;
    if ( *v7 < 0x1Cu )
      return -2005529767;
    v8 = operator new(4 * v7[3]);
    this[5] = (size_t)v8;
    if ( !v8 )
      return -2147024882;
    memset(v8, 0, 4 * *(_DWORD *)(this[4] + 12));
    v9 = this[4];
    this[6] = *(_DWORD *)(v9 + 12);
    v10 = *(_DWORD *)(v9 + 16);
    if ( v10 + 20 * *(_DWORD *)(v9 + 12) > this[3] )
      return -2005529767;
    v27 = 0;
    v11 = v10 + this[2];
    v12 = 0;
    if ( this[6] )
    {
      v13 = (unsigned __int16 *)(v11 + 12);
      v26 = (unsigned __int16 *)(v11 + 12);
      while ( *(_DWORD *)v13 + 16 <= this[3] )
      {
        *(_DWORD *)(this[5] + 4 * v12) = sub_675F77((int)this, v13 - 6, *(_DWORD *)v13 + this[2], 0);
        v14 = (int *)(this[5] + 4 * v12);
        if ( !*v14 )
          return -2147024882;
        v15 = *v14;
        v16 = *(unsigned __int16 *)(*(_DWORD *)(v15 + 24) + 8);
        v17 = *(_WORD *)(v15 + 8) != 0 ? 3 : 0;
        v26 += 10;
        v27 += *(_DWORD *)(v15 + 44) * v16 * (v17 + 1);
        if ( ++v12 >= this[6] )
          goto LABEL_19;
        v13 = v26;
      }
      return -2005529767;
    }
LABEL_19:
    v18 = operator new(4 * v27);
    v19 = 0;
    this[7] = (size_t)v18;
    if ( !v18 )
      return -2147024882;
    v28 = 0;
    if ( this[6] )
    {
      v20 = this[5];
      do
      {
        sub_6735BA(*(_DWORD **)(v20 + 4 * v19), this[7] + 4 * v28);
        v20 = this[5];
        v28 += *(_DWORD *)(*(_DWORD *)(v20 + 4 * v19) + 44)
             * *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v20 + 4 * v19) + 24) + 8)
             * (*(_WORD *)(*(_DWORD *)(v20 + 4 * v19) + 8) != 0 ? 4 : 1);
        ++v19;
      }
      while ( v19 < this[6] );
    }
    v21 = 0;
    if ( !a3 )
      return 0;
    if ( this[6] )
    {
      v22 = this[6];
      v23 = (unsigned __int16 *)(v11 + 8);
      do
      {
        if ( *(v23 - 2) == 2 )
        {
          v24 = *v23;
          if ( v21 < v24 + (unsigned int)*(v23 - 1) )
            v21 = v24 + *(v23 - 1);
        }
        v23 += 10;
        --v22;
      }
      while ( v22 );
    }
    result = sub_6772C7(16 * v21, a3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
