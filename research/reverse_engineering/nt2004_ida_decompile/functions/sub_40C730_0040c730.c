char __thiscall sub_40C730(_DWORD *this, _DWORD *a2)
{
  char result; // al
  int v4; // eax
  int v5; // [esp+Ch] [ebp-39Ch] BYREF
  _BYTE v6[128]; // [esp+10h] [ebp-398h] BYREF
  char String[384]; // [esp+90h] [ebp-318h] BYREF
  int v8; // [esp+210h] [ebp-198h]
  char v9; // [esp+214h] [ebp-194h]
  int v10; // [esp+21Ch] [ebp-18Ch]
  int v11; // [esp+220h] [ebp-188h]
  int v12; // [esp+224h] [ebp-184h]
  char Buffer[384]; // [esp+228h] [ebp-180h] BYREF

  result = 0;
  if ( *a2 )
  {
    v6[0] = byte_629120;
    memset(&v6[1], 0, 127);
    memset(Buffer, 0, sizeof(Buffer));
    v8 = 0;
    v12 = 0;
    v10 = 0;
    v11 = 0;
    v9 = 1;
    while ( sub_57A490(Buffer, 383) )
    {
      v4 = sub_577B60(String);
      if ( v4 )
      {
        if ( v4 == 2 || v4 == 4 )
          return 1;
      }
      else if ( sub_577E50(String, aTrack, (int)v6)
             || sub_577E50(String, aPole, (int)v6)
             || sub_577E50(String, aRacewinner, (int)v6)
             || sub_577E50(String, aLedmostlaps, (int)v6)
             || sub_577E50(String, aBestlap, (int)v6)
             || sub_577E50(String, aBestrookie, (int)v6)
             || sub_577E50(String, aMostimprovemen, (int)v6) )
      {
        sub_578600(v6);
      }
      else if ( sub_578110(aPolebonus, (int)&v5, 0, 0, 0) )
      {
        this[4] = v5;
      }
      else if ( sub_578110(aRacewinnerbonu, (int)&v5, 0, 0, 0) )
      {
        this[7] = v5;
      }
      else if ( sub_578110(aLedmostlapsbon, (int)&v5, 0, 0, 0) )
      {
        this[10] = v5;
      }
      else if ( sub_578110(aBestlapbonus, (int)&v5, 0, 0, 0) )
      {
        this[13] = v5;
      }
      else if ( sub_578110(aBestrookiebonu, (int)&v5, 0, 0, 0) )
      {
        this[16] = v5;
      }
      else if ( sub_578110(aMostimprovemen_0, (int)&v5, 0, 0, 0) )
      {
        this[19] = v5;
      }
    }
    return 1;
  }
  return result;
}
