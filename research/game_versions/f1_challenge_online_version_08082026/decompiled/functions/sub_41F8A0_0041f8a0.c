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
  v3 = sub_4C2850(&unk_7D2DB0);
  v4 = sub_4C11D0(v3);
  memset(v13, 0, sizeof(v13));
  do
  {
    switch ( v2 )
    {
      case 0:
        sub_566650(aArrows);
        break;
      case 1:
        sub_566650(&off_5C25E0);
        break;
      case 2:
        sub_566650(aRenault);
        break;
      case 3:
        sub_566650(aFerrari);
        break;
      case 4:
        sub_566650(aJaguar);
        break;
      case 5:
        sub_566650(aJordan);
        break;
      case 6:
        sub_566650(aMclaren);
        break;
      case 7:
        sub_566650(aMinardi);
        break;
      case 8:
        sub_566650(aProst);
        break;
      case 9:
        sub_566650(aSauber);
        break;
      case 10:
        sub_566650(aWilliams);
        break;
      case 11:
        sub_566650(aToyota);
        break;
      case 12:
        sub_566650(aBenetton);
        break;
      case 13:
        sub_566650(aStewart);
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
          sub_566650(aArrows);
          break;
        case 1:
          sub_566650(&off_5C25E0);
          break;
        case 2:
          sub_566650(aRenault);
          break;
        case 3:
          sub_566650(aFerrari);
          break;
        case 4:
          sub_566650(aJaguar);
          break;
        case 5:
          sub_566650(aJordan);
          break;
        case 6:
          sub_566650(aMclaren);
          break;
        case 7:
          sub_566650(aMinardi);
          break;
        case 8:
          sub_566650(aProst);
          break;
        case 9:
          sub_566650(aSauber);
          break;
        case 10:
          sub_566650(aWilliams);
          break;
        case 11:
          sub_566650(aToyota);
          break;
        case 12:
          sub_566650(aBenetton);
          break;
        case 13:
          sub_566650(aStewart);
          break;
        default:
          break;
      }
      v13[i] = sub_41F220((int)&byte_5EA438, v6);
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
