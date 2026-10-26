int __thiscall sub_67620F(int *this)
{
  int v2; // eax
  void *v3; // edi
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edi
  _DWORD *v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // esi
  unsigned __int16 v13; // cx
  unsigned __int16 v14; // dx
  unsigned __int16 v15; // ax
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // eax
  unsigned int v19; // eax
  _DWORD v21[5]; // [esp+Ch] [ebp-28h] BYREF
  int v22; // [esp+20h] [ebp-14h]
  int v23; // [esp+24h] [ebp-10h] BYREF
  int v24; // [esp+28h] [ebp-Ch] BYREF
  int v25; // [esp+2Ch] [ebp-8h]
  int v26; // [esp+30h] [ebp-4h]

  v2 = this[6];
  if ( !*(_WORD *)(v2 + 10) )
    return 0;
  v3 = operator new(4 * *(unsigned __int16 *)(v2 + 10));
  this[14] = (int)v3;
  if ( v3 )
  {
    memset(v3, 0, 4 * *(unsigned __int16 *)(this[6] + 10));
    v25 = this[8];
    v4 = this[6];
    qmemcpy(v21, this + 1, sizeof(v21));
    v5 = *(unsigned __int16 *)(v4 + 10);
    v6 = *(_DWORD *)(v4 + 12);
    if ( (unsigned int)(v6 + 8 * v5) > *(_DWORD *)(*this + 12) )
      return -2147467259;
    v7 = *(_DWORD *)(*this + 8);
    v26 = 0;
    v8 = (_DWORD *)(v6 + v7);
    if ( v5 )
    {
      while ( 1 )
      {
        v9 = v8[1];
        v10 = *this;
        if ( (unsigned int)(v9 + 16) > *(_DWORD *)(*this + 12) )
          break;
        v11 = *(_DWORD *)(v10 + 8);
        v24 = 0;
        v23 = 0;
        v12 = v9 + v11;
        sub_6733BF(v10, (int)v21, v12, 1, &v24, &v23);
        v13 = *((_WORD *)this + 6);
        v21[0] = *v8;
        v14 = *((_WORD *)this + 5);
        v21[3] = v8[1];
        v15 = v24 * *(_WORD *)(v12 + 8);
        v22 = v14;
        LOWORD(v21[2]) = v15;
        if ( v15 + HIWORD(v21[1]) > v13 + v14 )
          LOWORD(v21[2]) = *((_WORD *)this + 6) + v22 - HIWORD(v21[1]);
        v16 = sub_675F77(*this, (unsigned __int16 *)v21, v12, v25);
        v17 = v26;
        *(_DWORD *)(this[14] + 4 * v26) = v16;
        v18 = this[14] + 4 * v17;
        if ( !*(_DWORD *)v18 )
          return -2147024882;
        HIWORD(v21[1]) += LOWORD(v21[2]);
        v25 += 4 * *(unsigned __int16 *)(v12 + 8) * *(_DWORD *)(*(_DWORD *)v18 + 44) * (LOWORD(v21[1]) != 0 ? 4 : 1);
        v19 = *(unsigned __int16 *)(this[6] + 10);
        v8 += 2;
        if ( ++v26 >= v19 )
          return 0;
      }
      return -2147467259;
    }
    return 0;
  }
  return -2147024882;
}
