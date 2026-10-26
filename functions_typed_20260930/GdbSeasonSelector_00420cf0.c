char __thiscall sub_420CF0(LPVOID *this)
{
  LPVOID *v1; // esi
  int v2; // ebp
  char v3; // bl
  LPVOID *v4; // eax
  int v5; // ebx
  char **v6; // eax
  char result; // al
  char *v8; // ecx
  int v9; // edi
  int i; // esi
  int v11; // eax
  int j; // eax
  char v13; // bl
  int v14; // edi
  int k; // esi
  int v16; // eax
  int m; // eax
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  char *v21; // eax
  char *v22; // eax
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // eax
  int v27; // [esp-18h] [ebp-D0h]
  int v28; // [esp-18h] [ebp-D0h]
  int v29; // [esp-18h] [ebp-D0h]
  int v30; // [esp-18h] [ebp-D0h]
  char v31; // [esp+1Ah] [ebp-9Eh]
  LPVOID *v32; // [esp+1Ch] [ebp-9Ch]
  int v33; // [esp+20h] [ebp-98h]
  LPVOID *v34; // [esp+24h] [ebp-94h]
  float v35[8]; // [esp+28h] [ebp-90h] BYREF
  _DWORD v36[14]; // [esp+48h] [ebp-70h] BYREF
  _DWORD v37[14]; // [esp+80h] [ebp-38h] BYREF

  v1 = this;
  v2 = 0;
  v3 = 0;
  if ( !this )
  {
    v4 = (LPVOID *)OperatorNewNhMallocWrapper(8);
    if ( v4 )
    {
      *v4 = 0;
      v4[1] = (LPVOID)-1;
      v32 = v4;
    }
    else
    {
      v32 = 0;
    }
    v5 = -1;
    memset(v37, 0, sizeof(v37));
    memset(v36, 0, sizeof(v36));
    v33 = 0;
    v31 = 0;
    v6 = sub_41F340(0, 1);
    v34 = (LPVOID *)v6;
    if ( !v6 )
      return 0;
    v8 = *v6;
    if ( !*v6 )
      v8 = &byte_5EA438;
    v9 = ChampionshipPointsAccumulator((int)v8, -1);
    for ( i = 0; i < 14; ++i )
    {
      switch ( i )
      {
        case 0:
          StringCopyWithBufferRealloc(aArrows);
          break;
        case 1:
          StringCopyWithBufferRealloc(&off_5C25E0);
          break;
        case 2:
          StringCopyWithBufferRealloc(aRenault);
          break;
        case 3:
          StringCopyWithBufferRealloc(aFerrari);
          break;
        case 4:
          StringCopyWithBufferRealloc(aJaguar);
          break;
        case 5:
          StringCopyWithBufferRealloc(aJordan);
          break;
        case 6:
          StringCopyWithBufferRealloc(aMclaren);
          break;
        case 7:
          StringCopyWithBufferRealloc(aMinardi);
          break;
        case 8:
          StringCopyWithBufferRealloc(aProst);
          break;
        case 9:
          StringCopyWithBufferRealloc(aSauber);
          break;
        case 10:
          StringCopyWithBufferRealloc(aWilliams);
          break;
        case 11:
          StringCopyWithBufferRealloc(aToyota);
          break;
        case 12:
          StringCopyWithBufferRealloc(aBenetton);
          break;
        case 13:
          StringCopyWithBufferRealloc(aStewart);
          break;
        default:
          break;
      }
      if ( ChampionshipPointsAccumulator((int)&byte_5EA438, -1) == v9 )
      {
        v11 = CountActiveEntitiesByState();
        v36[i] = v11;
        if ( v11 > v2 )
        {
          v2 = v11;
          v5 = i;
        }
      }
    }
    if ( v5 == -1 )
      return 0;
    for ( j = 0; j < 14; ++j )
    {
      if ( v5 != j && v36[j] == v2 )
        v31 = 1;
    }
    if ( v31 )
    {
      v13 = 0;
      v14 = -1;
      for ( k = 0; k < 14; ++k )
      {
        if ( v36[k] == v2 )
        {
          switch ( k )
          {
            case 0:
              StringCopyWithBufferRealloc(aArrows);
              break;
            case 1:
              StringCopyWithBufferRealloc(&off_5C25E0);
              break;
            case 2:
              StringCopyWithBufferRealloc(aRenault);
              break;
            case 3:
              StringCopyWithBufferRealloc(aFerrari);
              break;
            case 4:
              StringCopyWithBufferRealloc(aJaguar);
              break;
            case 5:
              StringCopyWithBufferRealloc(aJordan);
              break;
            case 6:
              StringCopyWithBufferRealloc(aMclaren);
              break;
            case 7:
              StringCopyWithBufferRealloc(aMinardi);
              break;
            case 8:
              StringCopyWithBufferRealloc(aProst);
              break;
            case 9:
              StringCopyWithBufferRealloc(aSauber);
              break;
            case 10:
              StringCopyWithBufferRealloc(aWilliams);
              break;
            case 11:
              StringCopyWithBufferRealloc(aToyota);
              break;
            case 12:
              StringCopyWithBufferRealloc(aBenetton);
              break;
            case 13:
              StringCopyWithBufferRealloc(aStewart);
              break;
            default:
              break;
          }
          v16 = ShortComputation_12e0();
          v37[k] = v16;
          if ( v16 > v33 )
          {
            v33 = v16;
            v14 = k;
          }
        }
      }
      if ( v14 == -1 )
        return 0;
      for ( m = 0; m < 14; ++m )
      {
        if ( v14 != m && v37[m] == v33 )
          v13 = 1;
      }
      if ( v13 )
      {
        v18 = (char *)*v34;
LABEL_83:
        if ( !v18 )
          v18 = &byte_5EA438;
        StringCopyWithBufferRealloc(v18);
        if ( *v34 )
          FreeWrapper_7bcf(*v34);
        FreeWrapper_7bcf(v34);
        v3 = 1;
        v1 = v32;
        goto LABEL_88;
      }
      switch ( v14 )
      {
        case 0:
          goto LABEL_67;
        case 1:
          goto LABEL_68;
        case 2:
          goto LABEL_69;
        case 3:
          goto LABEL_70;
        case 4:
          goto LABEL_71;
        case 5:
          goto LABEL_72;
        case 6:
          goto LABEL_73;
        case 7:
          goto LABEL_74;
        case 8:
          goto LABEL_75;
        case 9:
          goto LABEL_76;
        case 10:
          goto LABEL_77;
        case 11:
          goto LABEL_78;
        case 12:
          goto LABEL_79;
        case 13:
          goto LABEL_81;
        default:
          break;
      }
    }
    else
    {
      switch ( v5 )
      {
        case 0:
LABEL_67:
          StringCopyWithBufferRealloc(aArrows);
          break;
        case 1:
LABEL_68:
          StringCopyWithBufferRealloc(&off_5C25E0);
          break;
        case 2:
LABEL_69:
          StringCopyWithBufferRealloc(aRenault);
          break;
        case 3:
LABEL_70:
          StringCopyWithBufferRealloc(aFerrari);
          break;
        case 4:
LABEL_71:
          StringCopyWithBufferRealloc(aJaguar);
          break;
        case 5:
LABEL_72:
          StringCopyWithBufferRealloc(aJordan);
          break;
        case 6:
LABEL_73:
          StringCopyWithBufferRealloc(aMclaren);
          break;
        case 7:
LABEL_74:
          StringCopyWithBufferRealloc(aMinardi);
          break;
        case 8:
LABEL_75:
          StringCopyWithBufferRealloc(aProst);
          break;
        case 9:
LABEL_76:
          StringCopyWithBufferRealloc(aSauber);
          break;
        case 10:
LABEL_77:
          StringCopyWithBufferRealloc(aWilliams);
          break;
        case 11:
LABEL_78:
          StringCopyWithBufferRealloc(aToyota);
          break;
        case 12:
LABEL_79:
          StringCopyWithBufferRealloc(aBenetton);
          break;
        case 13:
LABEL_81:
          StringCopyWithBufferRealloc(aStewart);
          break;
        default:
          break;
      }
    }
    v18 = 0;
    goto LABEL_83;
  }
LABEL_88:
  StructInitWithSentinelValues(v35);
  v19 = (char *)dword_7D0434;
  if ( !dword_7D0434 )
    v19 = &byte_5EA438;
  if ( sub_588410(v19, aF11999Gdb) )
  {
    v21 = (char *)dword_7D0434;
    if ( !dword_7D0434 )
      v21 = &byte_5EA438;
    if ( sub_588410(v21, aF12000Gdb) )
    {
      v23 = (char *)dword_7D0434;
      if ( !dword_7D0434 )
        v23 = &byte_5EA438;
      if ( sub_588410(v23, aF12001Gdb) )
      {
        v25 = (char *)dword_7D0434;
        if ( !dword_7D0434 )
          v25 = &byte_5EA438;
        if ( !sub_588410(v25, aF12002Gdb) )
        {
          v26 = (char *)*v1;
          if ( !*v1 )
            v26 = &byte_5EA438;
          v30 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v26);
          CommentaryEventQueue(v35, 504, v30, -1, -1, -1, -2.0, -2.0);
        }
      }
      else
      {
        v24 = (char *)*v1;
        if ( !*v1 )
          v24 = &byte_5EA438;
        v29 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v24);
        CommentaryEventQueue(v35, 500, v29, -1, -1, -1, -2.0, -2.0);
      }
    }
    else
    {
      v22 = (char *)*v1;
      if ( !*v1 )
        v22 = &byte_5EA438;
      v28 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v22);
      CommentaryEventQueue(v35, 496, v28, -1, -1, -1, -2.0, -2.0);
    }
  }
  else
  {
    v20 = (char *)*v1;
    if ( !*v1 )
      v20 = &byte_5EA438;
    v27 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)v20);
    CommentaryEventQueue(v35, 492, v27, -1, -1, -1, -2.0, -2.0);
  }
  result = InsertDriverTableEntry(flt_5EA618, v35);
  if ( v3 && v1 )
  {
    if ( *v1 )
      FreeWrapper_7bcf(*v1);
    return FreeWrapper_7bcf(v1);
  }
  return result;
}

