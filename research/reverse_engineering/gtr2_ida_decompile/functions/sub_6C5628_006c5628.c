int __stdcall sub_6C5628(_DWORD *a1, int a2, void *Block, unsigned int a4, _DWORD *a5)
{
  __int16 v5; // cx
  int v7; // eax
  int result; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  bool v12; // sf
  unsigned __int16 v13; // cx
  int v14; // eax
  _DWORD *v15; // ebx
  int v16; // eax
  int v17; // edi
  int v18; // edi
  int v19; // esi
  int v20; // [esp+4h] [ebp-10h] BYREF
  int v21; // [esp+8h] [ebp-Ch]
  int v22; // [esp+Ch] [ebp-8h]
  int v23; // [esp+10h] [ebp-4h] BYREF
  int v24; // [esp+20h] [ebp+Ch]
  void *Blocka; // [esp+24h] [ebp+10h]

  if ( !a5 )
    return 0;
  v5 = (__int16)Block;
  while ( *(_DWORD *)(a2 + 4) != 1 )
  {
    if ( *(_DWORD *)(a2 + 4) != 8 )
    {
      if ( *(_DWORD *)(a2 + 4) != 9 )
        return -2147467259;
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v23 = 0;
      v9 = *(_DWORD *)(a2 + 16);
      if ( v9 )
      {
        v10 = v9 - 1;
        if ( v10 )
        {
          v11 = v10 - 1;
          if ( v11 )
          {
            if ( v11 == 1 )
              LOWORD(v20) = 4;
          }
          else
          {
            LOWORD(v20) = ((*(_DWORD *)(a2 + 32) & 0x400) == 0) | 2;
          }
        }
        else
        {
          LOWORD(v20) = 1;
        }
      }
      else
      {
        LOWORD(v20) = 0;
      }
      switch ( *(_DWORD *)(a2 + 20) )
      {
        case 0:
          HIWORD(v20) = 1;
          break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 0xD:
          HIWORD(v20) = 2;
          break;
        case 9:
        case 0xA:
        case 0xB:
        case 0xC:
          HIWORD(v20) = 3;
          break;
        case 0xE:
          HIWORD(v20) = 4;
          break;
        case 0xF:
          HIWORD(v20) = 5;
          break;
        case 0x10:
          HIWORD(v20) = 6;
          break;
        case 0x11:
          HIWORD(v20) = 7;
          break;
        case 0x12:
          HIWORD(v20) = 8;
          break;
        case 0x13:
          HIWORD(v20) = 9;
          break;
        case 0x14:
          if ( (a4 & 0x200000) != 0 )
            goto LABEL_28;
          if ( (a4 & 0x400000) != 0 )
            goto LABEL_30;
          HIWORD(v20) = (a4 >> 22) & 2 | 0xC;
          break;
        case 0x15:
          HIWORD(v20) = 11;
          break;
        case 0x16:
LABEL_28:
          HIWORD(v20) = 12;
          break;
        case 0x17:
LABEL_30:
          HIWORD(v20) = 13;
          break;
        case 0x18:
          HIWORD(v20) = 14;
          break;
        case 0x19:
          HIWORD(v20) = 15;
          break;
        case 0x1A:
          HIWORD(v20) = 16;
          break;
        case 0x1B:
          HIWORD(v20) = 17;
          break;
        case 0x1C:
          HIWORD(v20) = 18;
          break;
        default:
          HIWORD(v20) = 0;
          break;
      }
      LOWORD(v21) = *(_WORD *)(a2 + 24);
      HIWORD(v21) = *(_WORD *)(a2 + 28);
      LOWORD(v22) = v5;
      result = sub_68024C(a1, (char *)&v20, 0x10u, 2, a5);
      v12 = result < 0;
      goto LABEL_52;
    }
    v7 = *(_DWORD *)(a2 + 20);
    a2 = *(_DWORD *)(a2 + 16);
    v5 *= (_WORD)v7;
  }
  v20 = 5;
  LOWORD(v21) = 1;
  v23 = 0;
  HIWORD(v21) = sub_6C55C5((_DWORD *)a2);
  v22 = v13;
  v14 = a2;
  do
  {
    ++HIWORD(v22);
    v14 = *(_DWORD *)(v14 + 12);
  }
  while ( v14 );
  v15 = operator new(8 * HIWORD(v22));
  Blocka = v15;
  if ( !v15 )
    return -2147024882;
  do
  {
    v16 = *(_DWORD *)(a2 + 8);
    v17 = *(_DWORD *)(v16 + 24);
    v24 = sub_68024C(a1, *(char **)(*(_DWORD *)(v16 + 20) + 24), 0xFFFFFFFF, 7, v15);
    if ( v24 < 0 )
    {
      j__free(Blocka);
      return v24;
    }
    v18 = sub_6C5628((int)a1, *(_DWORD *)(v17 + 32), (void *)1, a4, (int)(v15 + 1));
    if ( v18 < 0 )
    {
      j__free(Blocka);
      return v18;
    }
    a2 = *(_DWORD *)(a2 + 12);
    v15 += 2;
  }
  while ( a2 );
  v19 = sub_68024C(a1, (char *)Blocka, 8 * HIWORD(v22), 2, &v23);
  j__free(Blocka);
  if ( v19 < 0 )
    return v19;
  result = sub_68024C(a1, (char *)&v20, 0x10u, 2, a5);
  v12 = result < 0;
LABEL_52:
  if ( !v12 )
    return 0;
  return result;
}
