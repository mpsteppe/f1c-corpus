char __thiscall sub_40EC30(int this, _DWORD *a2)
{
  char result; // al
  int v4; // eax
  void *v5; // eax
  void *v6; // esi
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // [esp+Ch] [ebp-39Ch] BYREF
  _BYTE v10[128]; // [esp+10h] [ebp-398h] BYREF
  char String[384]; // [esp+90h] [ebp-318h] BYREF
  int v12; // [esp+210h] [ebp-198h]
  char v13; // [esp+214h] [ebp-194h]
  int v14; // [esp+21Ch] [ebp-18Ch]
  int v15; // [esp+220h] [ebp-188h]
  int v16; // [esp+224h] [ebp-184h]
  char String1[384]; // [esp+228h] [ebp-180h] BYREF

  result = 0;
  if ( *a2 )
  {
    v10[0] = byte_629120;
    memset(&v10[1], 0, 127);
    memset(String1, 0, sizeof(String1));
    v12 = 0;
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v13 = 1;
    while ( sub_57A490(String1, 383) )
    {
      v4 = sub_577B60(String);
      if ( v4 )
      {
        if ( v4 == 2 || v4 == 4 )
          return 1;
      }
      else
      {
        if ( sub_578110(aIsplayer, (int)&v9, 0, 0, 0) )
        {
          *(_BYTE *)(this + 32) = v9 != 0;
        }
        else if ( sub_577E50(String, aVehiclefile, (int)v10) )
        {
          sub_578600(v10);
        }
        else if ( sub_578110(aPlace, (int)&v9, 0, 0, 0) )
        {
          *(_BYTE *)(this + 8) = v9;
        }
        if ( !_strcmpi(String1, aStats) )
        {
          v5 = operator new(0x1Cu);
          if ( v5 )
            v6 = (void *)sub_413DB0(v5);
          else
            v6 = 0;
          if ( (unsigned __int8)sub_413ED0(a2) )
          {
            if ( v6 )
            {
              v7 = operator new(0xCu);
              if ( v7 )
              {
                *v7 = v6;
                v7[1] = 0;
                *((_BYTE *)v7 + 8) = 1;
              }
              else
              {
                v7 = 0;
              }
              if ( *(_DWORD *)(this + 12) )
              {
                *(_DWORD *)(*(_DWORD *)(this + 16) + 4) = v7;
              }
              else
              {
                *(_DWORD *)(this + 12) = v7;
                *(_DWORD *)(this + 20) = v7;
              }
              *(_DWORD *)(this + 16) = v7;
              ++*(_DWORD *)(this + 24);
            }
          }
          else if ( v6 )
          {
            sub_413DD0(v6);
            sub_5BE8AE(v6);
          }
        }
        if ( !_strcmpi(String1, aCareerdata) )
        {
          v8 = sub_413700(0);
          *(_DWORD *)(this + 28) = v8;
          (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v8 + 56))(v8, a2);
        }
      }
    }
    return 1;
  }
  return result;
}
