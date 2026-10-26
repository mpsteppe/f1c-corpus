int __thiscall sub_6A84FA(_DWORD *this, unsigned int a2, int a3, unsigned int a4, int a5, unsigned int a6)
{
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // edi
  int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // esi
  _DWORD *v14; // edx
  int *v15; // eax
  int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // edx
  unsigned int v19; // eax
  int v20; // edi
  _DWORD *v21; // edx
  _DWORD *v22; // eax
  int v23; // eax
  int v25; // [esp+Ch] [ebp-14h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  _DWORD *v28; // [esp+18h] [ebp-8h]
  unsigned int v29; // [esp+18h] [ebp-8h]
  unsigned int v30; // [esp+1Ch] [ebp-4h]

  v6 = 0;
  v30 = 0;
  if ( !a4 )
    return 0;
  while ( 1 )
  {
    v7 = *(_DWORD **)(a3 + 4 * v6);
    v8 = 0;
    v28 = v7;
    if ( !v7 )
      goto LABEL_39;
    v9 = *v7;
    if ( !*v7 )
      goto LABEL_39;
    v10 = v9 & 0xFFF00000;
    v11 = v9 & 0xFFFFF;
    if ( v10 == 1610612736 || v10 == 1615855616 || v10 == 1621098496 || v10 == 1626341376 )
      break;
    if ( v10 == 1913651200 )
    {
      v17 = 0;
      goto LABEL_25;
    }
    if ( a6 )
    {
      v12 = v7[1];
      while ( 1 )
      {
        v29 = 0;
        if ( v12 )
          break;
LABEL_20:
        if ( ++v8 >= a6 )
          goto LABEL_39;
      }
      v13 = *(_DWORD *)(a5 + 4 * v8);
      v14 = (_DWORD *)v7[2];
      while ( 1 )
      {
        if ( *v14 == v13 || *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v14) + 56) == v13 )
        {
          v15 = *(int **)(a3 + 4 * a2);
          if ( v15 )
          {
            if ( a2 < v30 )
            {
              v16 = *v15;
              if ( v16 )
              {
                if ( (v16 & 0xFFF00000) != 0x11000000 )
                  return 1;
              }
            }
          }
        }
        ++v29;
        v12 = v7[1];
        ++v14;
        if ( v29 >= v12 )
          goto LABEL_20;
      }
    }
LABEL_39:
    v6 = ++v30;
    if ( v30 >= a4 )
      return 0;
  }
  v17 = v11;
LABEL_25:
  v18 = 0;
  v25 = 0;
  if ( !a6 )
    goto LABEL_39;
  v19 = v7[1];
  while ( 1 )
  {
    v27 = v17;
    if ( v17 < v19 )
      break;
LABEL_38:
    v25 = ++v18;
    if ( v18 >= a6 )
      goto LABEL_39;
  }
  v20 = *(_DWORD *)(a5 + 4 * v18);
  v21 = (_DWORD *)(v7[2] + 4 * v17);
  while ( 1 )
  {
    if ( *v21 == v20 )
    {
      v22 = *(_DWORD **)(a3 + 4 * a2);
      if ( v22 && a2 < v30 && *v22 )
        return 1;
      v7 = v28;
    }
    v23 = *(_DWORD *)(this[5] + 4 * *v21);
    if ( (*(_BYTE *)(v23 + 62) & 0x1F) != 0 || *(_DWORD *)(v23 + 56) != -1 )
      break;
    ++v27;
    v19 = v7[1];
    ++v21;
    if ( v27 >= v19 )
    {
      v18 = v25;
      goto LABEL_38;
    }
  }
  sub_686791((int)this, 0, 4806, "internal error: texld alias found");
  return -2147467259;
}
