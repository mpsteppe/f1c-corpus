int __fastcall sub_420820(char a1)
{
  int v1; // ebx
  int v2; // esi
  int v3; // ebp
  int i; // eax
  int v5; // edi
  int j; // eax
  int v7; // ecx
  int k; // eax
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int m; // eax
  int v13; // ecx
  char v14; // bl
  int n; // eax
  int v16; // eax
  int v17; // eax
  int v19; // [esp-14h] [ebp-ACh]
  char v20; // [esp+13h] [ebp-85h]
  int v22; // [esp+30h] [ebp-68h]
  float v23[8]; // [esp+40h] [ebp-58h] BYREF
  _DWORD v24[14]; // [esp+60h] [ebp-38h] BYREF

  v1 = -1;
  v2 = 0;
  v22 = -1;
  v3 = -1;
  memset(v24, 0, sizeof(v24));
  do
  {
    switch ( v2 )
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
    v24[v2++] = ChampionshipPointsAccumulator((int)&byte_5EA438, -1);
  }
  while ( v2 < 14 );
  for ( i = 0; i < 14; ++i )
  {
    if ( v24[i] > v1 )
    {
      v22 = i;
      v1 = v24[i];
    }
  }
  v5 = -1;
  for ( j = 0; j < 14; ++j )
  {
    if ( j != v22 )
    {
      v7 = v24[j];
      if ( v7 > v3 && v7 < v1 )
      {
        v5 = j;
        v3 = v24[j];
      }
    }
  }
  v20 = 0;
  for ( k = 0; k < 14; ++k )
  {
    if ( k != v5 && v24[v5] == v24[k] )
      v20 = 1;
  }
  if ( !v20 && v5 != -1 )
  {
    switch ( v5 )
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
    if ( a1 )
    {
      StructInitWithSentinelValues(v23);
      v9 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438);
      CommentaryEventQueue(v23, 423, v9, -1, -1, -1, -2.0, -2.0);
      InsertDriverTableEntry(flt_5EA618, v23);
    }
  }
  v10 = -1;
  v11 = -1;
  for ( m = 0; m < 14; ++m )
  {
    if ( m != v22 && m != v5 )
    {
      v13 = v24[m];
      if ( v13 > v11 && v13 < v3 )
      {
        v10 = m;
        v11 = v24[m];
      }
    }
  }
  v14 = 0;
  for ( n = 0; n < 14; ++n )
  {
    if ( n != v10 && v24[v10] == v24[n] )
      v14 = 1;
  }
  if ( v20 || v14 || v10 == -1 )
  {
LABEL_84:
    if ( a1 || v20 || v14 )
      return 0;
    goto LABEL_87;
  }
  switch ( v10 )
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
  if ( a1 )
  {
    StructInitWithSentinelValues(v23);
    v16 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438);
    CommentaryEventQueue(v23, 424, v16, -1, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v23);
    goto LABEL_84;
  }
LABEL_87:
  if ( v5 != -1 && v10 != -1 )
  {
    StructInitWithSentinelValues(v23);
    v19 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438);
    v17 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438);
    CommentaryEventQueue(v23, 488, v17, v19, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v23);
  }
  return 0;
}

