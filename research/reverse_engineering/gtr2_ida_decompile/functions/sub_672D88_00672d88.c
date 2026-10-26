int __thiscall sub_672D88(_DWORD *this, unsigned int a2)
{
  unsigned int v4; // edi
  unsigned int *v5; // eax
  unsigned int *v6; // ebx
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // [esp+4h] [ebp-4h]
  unsigned int i; // [esp+4h] [ebp-4h]

  if ( *(_DWORD *)(a2 + 4) != 13 )
    return 0;
  v4 = *(_DWORD *)(a2 + 20) * *(_DWORD *)(a2 + 24);
  v5 = (unsigned int *)operator new(4 * v4);
  v6 = v5;
  if ( v5 )
  {
    v10 = sub_6624CC(v5, v4);
    if ( v10 >= 0 )
    {
      v10 = sub_6714D6((int)this, __SPAIR64__((unsigned int)v6, a2), 0);
      if ( v10 >= 0 )
      {
        v10 = sub_6641F3(this, a2, v4 & 0xFFFFF | 0x10000000, (int)v6, v6, 0);
        if ( v10 >= 0 )
        {
          for ( i = 0; i < v4; ++i )
          {
            v7 = v6[i];
            v8 = (_DWORD *)this[2];
            if ( v7 >= v8[2] )
              v9 = 0;
            else
              v9 = *(_DWORD *)(v8[5] + 4 * v7);
            if ( v9 )
              *(_DWORD *)(v9 + 4) = v8[33];
          }
          v10 = sub_666E91(this, *(_DWORD **)(a2 + 16), v6, *(_DWORD *)(this[2] + 132), 1, 1, 0, 0);
        }
      }
    }
  }
  else
  {
    v10 = -2147024882;
  }
  j__free(v6);
  if ( this[19] )
    return -2147467259;
  return v10;
}
