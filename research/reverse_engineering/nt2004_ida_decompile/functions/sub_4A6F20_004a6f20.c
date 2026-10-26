_DWORD *__stdcall sub_4A6F20(int a1, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  _DWORD *v7; // eax
  _BYTE v9[256]; // [esp+14h] [ebp-418h] BYREF
  char String[384]; // [esp+114h] [ebp-318h] BYREF
  int v11; // [esp+294h] [ebp-198h]
  char v12; // [esp+298h] [ebp-194h]
  int v13; // [esp+2A0h] [ebp-18Ch]
  int v14; // [esp+2A4h] [ebp-188h]
  int v15; // [esp+2A8h] [ebp-184h]
  char Buffer[384]; // [esp+2ACh] [ebp-180h] BYREF

  memset(Buffer, 0, sizeof(Buffer));
  v9[0] = byte_629120;
  memset(&v9[1], 0, 255);
  v11 = 0;
  v15 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 1;
  v2 = operator new(0x70u);
  v3 = v2;
  if ( v2 )
  {
    *v2 = 0;
    v2[1] = -1;
    v2[2] = 0;
    v2[3] = -1;
    v2[4] = 0;
    v2[5] = -1;
    v2[6] = 0;
    v2[7] = 0;
    v2[8] = 0;
    v2[9] = 0;
    v2[10] = 0;
    v2[11] = 1;
    sub_506720(v2 + 12);
    v3[22] = 0;
    v3[23] = -1;
    v3[24] = 0;
    v3[25] = -1;
    sub_506BA0(v3 + 12);
  }
  else
  {
    v3 = 0;
  }
  sub_578600(a2);
  while ( sub_57A490(Buffer, 383) )
  {
    v4 = sub_577B60(String);
    if ( v4 )
    {
      if ( v4 == 2 )
        return v3;
    }
    else if ( sub_577E50(String, aPage_0, (int)v9) || sub_577E50(String, aAutoselectchil, (int)v9) )
    {
      sub_578600(v9);
    }
    else if ( sub_577E50(String, (char *)&off_608754, (int)v9) )
    {
      v5 = sub_4A6F20(a1, v9);
      v6 = v5;
      if ( v5 )
      {
        *(_DWORD *)(v5 + 24) = v3;
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
        if ( v3[7] )
        {
          *(_DWORD *)(v3[8] + 4) = v7;
        }
        else
        {
          v3[7] = v7;
          v3[9] = v7;
        }
        v3[8] = v7;
        ++v3[10];
      }
    }
  }
  return v3;
}
