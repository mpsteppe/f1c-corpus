char __thiscall sub_41F8A0(void *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // ebp
  int v5; // ebx
  int v6; // edi
  int v7; // ebp
  int i; // esi
  int j; // eax
  int v11; // [esp+10h] [ebp-44h]
  int v12; // [esp+10h] [ebp-44h]
  _DWORD v13[14]; // [esp+1Ch] [ebp-38h] BYREF

  v2 = 0;
  v11 = -1;
  v3 = LinkedListDereference(&dword_7D2DB0);
  v4 = FlagsGetter(v3);
  memset(v13, 0, sizeof(v13));
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
    if ( sub_566810(&byte_5EA438, this) )
      v11 = v2;
    ++v2;
  }
  while ( v2 < 14 );
  v5 = v11;
  if ( v11 == -1 )
    return 0;
  v6 = 0;
  v12 = v4 - 2;
  if ( v4 - 2 <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = 1;
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
      v13[i] = ChampionshipPointsAccumulator((int)&byte_5EA438, v6);
    }
    for ( j = 0; j < 14; ++j )
    {
      if ( j != v5 && v13[j] > v13[v5] )
        v7 = 0;
    }
    if ( v7 )
      return 1;
    if ( ++v6 >= v12 )
      return 0;
  }
}

