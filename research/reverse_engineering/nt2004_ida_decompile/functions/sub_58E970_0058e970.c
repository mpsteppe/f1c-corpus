int __cdecl sub_58E970(_BYTE *a1, int a2, int a3, char a4, char a5, int a6)
{
  int v7; // esi
  int result; // eax
  bool v9; // zf
  int v10; // edi
  _BYTE *v11; // esi
  int v12; // ebp
  int v13; // eax
  int v14; // [esp+18h] [ebp+8h]
  int v15; // [esp+20h] [ebp+10h]
  int v16; // [esp+24h] [ebp+14h]
  int v17; // [esp+28h] [ebp+18h]

  v7 = 200;
  v14 = *(unsigned __int8 *)(a2 + 4) >> 2;
  if ( v14 > 12 )
    return 0;
  result = sub_58F0C0(a2, a6);
  if ( result )
  {
    result = sub_58FEA0(a4, a5, a2);
    if ( result )
    {
      sub_58F100(a2);
      a1[96] = v14;
      while ( 1 )
      {
        v9 = v7 == 0;
        if ( v7 <= 0 )
          break;
        --v7;
        v10 = 0;
        v16 = 1;
        v15 = v7;
        v17 = 0;
        if ( v14 > 0 )
        {
          v11 = a1 + 7;
          do
          {
            v12 = a2 + 4 * *(unsigned __int8 *)(a2 + v10 + 8);
            if ( sub_58F150(a2, v12) )
            {
              if ( !*v11 )
              {
                *(v11 - 3) = a1[97];
                if ( !sub_58EAB0(v12, a3, v11 - 7) )
                  return 0;
                v13 = sub_58EB90(a1, a2, v11 - 7, v12, a3);
                if ( !v13 )
                  return 0;
                v10 = v17;
                *(v11 - 2) = v13;
                *v11 = 1;
              }
            }
            else
            {
              v16 = 0;
            }
            ++v10;
            v11 += 8;
            v17 = v10;
          }
          while ( v10 < v14 );
          v7 = v15;
          if ( !v16 )
            continue;
        }
        v9 = v7 == 0;
        return !v9;
      }
      return !v9;
    }
  }
  return result;
}
