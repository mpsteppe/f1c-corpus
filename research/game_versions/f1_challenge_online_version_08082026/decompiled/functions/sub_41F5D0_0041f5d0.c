char **__fastcall sub_41F5D0(int a1, char a2)
{
  char **v3; // eax
  int v4; // edi
  int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // esi
  char *v10; // eax
  char *v11; // eax
  char **v13; // [esp+10h] [ebp-14h]
  int v15; // [esp+18h] [ebp-Ch]

  v3 = (char **)sub_587C03(8);
  v4 = 0;
  if ( v3 )
  {
    *v3 = 0;
    v3[1] = (char *)-1;
    v13 = v3;
  }
  else
  {
    v13 = 0;
  }
  v5 = -1;
  v6 = sub_4C2850(&unk_7D2DB0);
  v7 = sub_4C11D0(v6);
  if ( v7 >= 2 )
  {
    v15 = v7 - 1;
    do
    {
      switch ( v4 )
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
      v8 = sub_41F220((int)&byte_5EA438, v15);
      if ( v5 < v8 && (!a1 || !sub_566810(&byte_5EA438, a1)) )
      {
        sub_566650(&byte_5EA438);
        v5 = v8;
      }
      ++v4;
    }
    while ( v4 < 14 );
    if ( a2 )
      return v13;
    v9 = 0;
    while ( 1 )
    {
      switch ( v9 )
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
      v10 = *v13;
      if ( !*v13 )
        v10 = &byte_5EA438;
      if ( sub_588410(v10, &byte_5EA438) )
      {
        if ( !a1 )
          goto LABEL_50;
        v11 = *v13;
        if ( !*v13 )
          v11 = &byte_5EA438;
        if ( !sub_566810(v11, a1) )
        {
LABEL_50:
          if ( v5 == sub_41F220((int)&byte_5EA438, v15) )
            break;
        }
      }
      if ( ++v9 >= 14 )
        return v13;
    }
  }
  return 0;
}
