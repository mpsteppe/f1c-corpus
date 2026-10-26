char __thiscall sub_413AF0(int this, _DWORD *a2)
{
  int v2; // esi
  int v4; // eax
  _BYTE *v5; // edi
  int v6; // ebx
  int v8; // [esp+Ch] [ebp-39Ch] BYREF
  char Buffer[125]; // [esp+10h] [ebp-398h] BYREF
  __int16 v10; // [esp+8Dh] [ebp-31Bh]
  char v11; // [esp+8Fh] [ebp-319h]
  char String[384]; // [esp+90h] [ebp-318h] BYREF
  int v13; // [esp+210h] [ebp-198h]
  char v14; // [esp+214h] [ebp-194h]
  int v15; // [esp+21Ch] [ebp-18Ch]
  int v16; // [esp+220h] [ebp-188h]
  int v17; // [esp+224h] [ebp-184h]
  char v18[384]; // [esp+228h] [ebp-180h] BYREF

  v2 = 0;
  if ( !*a2 )
    return 0;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v10 = 0;
  v11 = 0;
  memset(v18, 0, sizeof(v18));
  v13 = 0;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 1;
  while ( sub_57A490(v18, 383) )
  {
    v4 = sub_577B60(String);
    if ( v4 )
    {
      if ( v4 == 2 || v4 == 4 )
        return 1;
    }
    else
    {
      if ( sub_577E50(String, aName_1, (int)Buffer) )
      {
        sub_578600(Buffer);
      }
      else if ( sub_578110(aIncome, (int)&v8, 0, 0, 0) )
      {
        *(_DWORD *)(this + 8) = v8;
      }
      else if ( sub_578110(aReputation, (int)&v8, 0, 0, 0) )
      {
        *(_BYTE *)(this + 12) = v8;
      }
      else if ( sub_578110(aContractlength, (int)&v8, 0, 0, 0) )
      {
        *(_BYTE *)(this + 13) = v8;
      }
      else if ( sub_578110(aTimeleftincont, (int)&v8, 0, 0, 0) )
      {
        *(_BYTE *)(this + 14) = v8;
      }
      v5 = (_BYTE *)(this + 15);
      v6 = 6;
      do
      {
        sub_405480(Buffer, 0x7Fu, "Level%d", v2);
        if ( sub_578110(Buffer, (int)&v8, 0, 0, 0) )
          *v5 = 1;
        ++v2;
        ++v5;
        --v6;
      }
      while ( v6 );
      v2 = 0;
    }
  }
  return 1;
}
