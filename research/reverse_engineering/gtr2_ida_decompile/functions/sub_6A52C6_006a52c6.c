int __thiscall sub_6A52C6(_DWORD *this, int a2, unsigned int a3, int a4, int a5, unsigned int a6, int a7)
{
  int v7; // ebx
  int v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  unsigned int v18; // [esp+14h] [ebp-10h]
  BOOL v19; // [esp+18h] [ebp-Ch]
  int v21; // [esp+20h] [ebp-4h]

  v7 = 0;
  v8 = 0;
  v18 = 0;
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    v9 = *(_DWORD **)(a2 + 4 * v8);
    if ( v9 && *v9 )
    {
      v19 = sub_6A2293(*v9 & 0xFFF00000);
      if ( v11 == 285212672 )
        v19 = 1;
      v21 = 0;
      if ( v9[1] )
        break;
    }
LABEL_22:
    v8 = ++v18;
    if ( v18 >= a3 )
      return 0;
  }
  while ( 1 )
  {
    v12 = v10[5];
    v13 = *(_DWORD *)(v12 + 4 * *(_DWORD *)(v9[2] + 4 * v21));
    if ( *(_DWORD *)(v13 + 4) != v10[32]
      || (unsigned __int8)*(_DWORD *)(v13 + 108) != a4
      || a5 != *(unsigned __int8 *)(v13 + 109)
      || v19 && !*(_DWORD *)(v13 + 60) )
    {
      goto LABEL_21;
    }
    if ( a6 )
    {
      v14 = *(_DWORD *)(v13 + 16);
      while ( v14 != *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(a7 + 4 * v7)) + 16) )
      {
        if ( ++v7 >= a6 )
          goto LABEL_19;
      }
      v15 = sub_681AAA(this, this[34], 0, v14, 0.0);
      if ( v15 == -1 )
        return -2147024882;
      v16 = *(_DWORD *)(this[5] + 4 * v15);
      *(_DWORD *)(v16 + 60) = *(_DWORD *)(v13 + 60);
      *(_DWORD *)(v16 + 56) = *(_DWORD *)(a7 + 4 * v7);
      *(_DWORD *)(v9[2] + 4 * v21) = v15;
    }
LABEL_19:
    if ( v7 == a6 )
      break;
    v10 = this;
    v7 = 0;
LABEL_21:
    if ( (unsigned int)++v21 >= v9[1] )
      goto LABEL_22;
  }
  sub_686791((int)this, 0, 4801, "internal error: InputRemap component matchup failed");
  return -2147467259;
}
