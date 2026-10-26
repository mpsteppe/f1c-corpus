char **__fastcall sub_41F340(int a1, char a2)
{
  char **v4; // eax
  int v5; // edi
  int v6; // esi
  int v7; // esi
  char *v8; // eax
  char **v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+14h] [ebp-Ch]

  v4 = (char **)OperatorNewNhMallocWrapper(8);
  v5 = 0;
  if ( v4 )
  {
    *v4 = 0;
    v4[1] = (char *)-1;
    v10 = v4;
  }
  else
  {
    v10 = 0;
  }
  v11 = -1;
  do
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
    v6 = ChampionshipPointsAccumulator((int)&byte_5EA438, -1);
    if ( v11 < v6 && (!a1 || !sub_566810(&byte_5EA438, a1)) )
    {
      StringCopyWithBufferRealloc(&byte_5EA438);
      v11 = v6;
    }
    ++v5;
  }
  while ( v5 < 14 );
  if ( a2 )
    return v10;
  v7 = 0;
  while ( 1 )
  {
    switch ( v7 )
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
    v8 = *v10;
    if ( !*v10 )
      v8 = &byte_5EA438;
    if ( !sub_566810(v8, &byte_5EA438) && v11 == ChampionshipPointsAccumulator((int)&byte_5EA438, -1) )
      return 0;
    if ( ++v7 >= 14 )
      return v10;
  }
}

