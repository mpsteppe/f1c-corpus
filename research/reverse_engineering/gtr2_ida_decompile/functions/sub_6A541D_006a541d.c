int __thiscall sub_6A541D(_DWORD *this, int a2, unsigned int a3, int a4, int a5, unsigned int a6, int a7)
{
  unsigned int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  unsigned int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]

  v8 = 0;
  v16 = 0;
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    v9 = *(_DWORD *)(a2 + 4 * v8);
    if ( v9 )
    {
      v17 = 0;
      if ( *(_DWORD *)(v9 + 4) )
        break;
    }
LABEL_16:
    v8 = ++v16;
    if ( v16 >= a3 )
      return 0;
  }
  while ( 1 )
  {
    v10 = this[5];
    v11 = *(_DWORD *)(v10 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4 * v17));
    if ( *(_DWORD *)(v11 + 4) == this[32]
      && *(_DWORD *)(v11 + 60)
      && (unsigned __int8)*(_DWORD *)(v11 + 108) == a4
      && a5 == *(unsigned __int8 *)(v11 + 109) )
    {
      v18 = 0;
      if ( a6 )
      {
        while ( 1 )
        {
          v12 = *(_DWORD *)(v11 + 16);
          if ( v12 == *(_DWORD *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(a7 + 4 * v18)) + 16) )
            break;
          if ( ++v18 >= a6 )
            goto LABEL_14;
        }
        v13 = sub_681AAA(this, this[34], 0, v12, 0.0);
        if ( v13 == -1 )
          return -2147024882;
        v14 = *(_DWORD *)(this[5] + 4 * v13);
        *(_DWORD *)(v14 + 60) = *(_DWORD *)(v11 + 60);
        *(_DWORD *)(v14 + 56) = *(_DWORD *)(a7 + 4 * v18);
        *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4 * v17) = v13;
      }
LABEL_14:
      if ( v18 == a6 )
        break;
    }
    if ( (unsigned int)++v17 >= *(_DWORD *)(v9 + 4) )
      goto LABEL_16;
  }
  sub_686791((int)this, 0, 4802, "internal error: InputRemap component matchup failed");
  return -2147467259;
}
