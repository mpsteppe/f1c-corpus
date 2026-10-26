char __thiscall sub_4E51B0(float *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  LPVOID *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  LPVOID **v8; // eax
  _DWORD *v9; // eax
  LPVOID *v10; // edi
  LPVOID **v11; // eax
  LPVOID *v13; // [esp+8h] [ebp-104h]
  char String[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( !*a2 )
    return 0;
  v3 = operator new(0x18u);
  if ( v3 )
  {
    v4 = (LPVOID *)sub_4E34D0(v3);
    v13 = v4;
  }
  else
  {
    v4 = 0;
    v13 = 0;
  }
  while ( sub_57A490(byte_7D68B0, 256) )
  {
    v5 = sub_577B60(byte_7D6718);
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( !v6 || v6 == 3 )
        break;
    }
    else if ( strstr(byte_7D68B0, aCareerseason) )
    {
      v9 = operator new(0x7904u);
      if ( v9 )
        v10 = (LPVOID *)sub_4E3DE0(v9);
      else
        v10 = 0;
      if ( sub_4E3F00(v10, a2) )
      {
        if ( v10 )
        {
          v11 = (LPVOID **)operator new(0xCu);
          if ( v11 )
          {
            *v11 = v10;
            v11[1] = 0;
            *((_BYTE *)v11 + 8) = 1;
          }
          else
          {
            v11 = 0;
          }
          if ( *(_DWORD *)this )
          {
            *(_DWORD *)(*((_DWORD *)this + 1) + 4) = v11;
          }
          else
          {
            *(_DWORD *)this = v11;
            *((_DWORD *)this + 2) = v11;
          }
          *((_DWORD *)this + 1) = v11;
          ++*((_DWORD *)this + 3);
        }
      }
      else if ( v10 )
      {
        sub_4E3E50(v10);
        sub_5BE8AE(v10);
      }
      v4 = v13;
    }
    else if ( strstr(byte_7D68B0, aPlayertracksta) )
    {
      sub_4E51B0(a2);
    }
    else
    {
      sub_578110(aAbortedseasons, (int)(this + 8), 0, 0, 0);
      sub_578110(aTotallaps, (int)(this + 9), 0, 0, 0);
      sub_578110(aTotalraces, (int)(this + 10), 0, 0, 0);
      sub_578110(aTotalraceswith, (int)(this + 11), 0, 0, 0);
      sub_578110(aTotalpointssco, (int)(this + 12), 0, 0, 0);
      sub_578110(aTotalchampions, (int)(this + 13), 0, 0, 0);
      sub_578110(aTotalwins, (int)(this + 14), 0, 0, 0);
      sub_578110(aTotalpoles, (int)(this + 15), 0, 0, 0);
      sub_578110(aTotallaprecord, (int)(this + 16), 0, 0, 0);
      if ( sub_577ED0(byte_7D6718, aAvgstartpositi, String, 0) )
        this[17] = atof(String);
      if ( sub_577ED0(byte_7D6718, aAvgfinishposit, String, 0) )
        this[18] = atof(String);
      if ( sub_577ED0(byte_7D6718, aAvgracedistanc, String, 0) )
        this[19] = atof(String);
      if ( sub_577ED0(byte_7D6718, aAvgopponentstr, String, 0) )
        this[20] = atof(String);
      sub_578110(aTotalnumlaps, (int)(v4 + 4), 0, 0, 0);
      sub_578220(aBestlaptime, (int)(v4 + 5), 0, 0, 0, 0, 0, 0, 0);
      if ( sub_577E50(byte_7D6718, aTrackname, (int)String) )
        sub_578600(String);
      if ( sub_577E50(byte_7D6718, aTrackfile, (int)String) )
        sub_578600(String);
    }
  }
  v7 = (char *)v4[2];
  if ( !v7 )
    v7 = &byte_629120;
  if ( sub_4E5DB0(v7) )
  {
    if ( v4 )
    {
      if ( v4[2] )
        sub_5BE8AE(v4[2]);
      if ( *v4 )
        sub_5BE8AE(*v4);
      sub_5BE8AE(v4);
    }
    return 0;
  }
  if ( !v4 )
    return 0;
  v8 = (LPVOID **)operator new(0xCu);
  if ( v8 )
  {
    *v8 = v4;
    v8[1] = 0;
    *((_BYTE *)v8 + 8) = 1;
  }
  else
  {
    v8 = 0;
  }
  if ( *((_DWORD *)this + 4) )
  {
    *(_DWORD *)(*((_DWORD *)this + 5) + 4) = v8;
  }
  else
  {
    *((_DWORD *)this + 4) = v8;
    *((_DWORD *)this + 6) = v8;
  }
  *((_DWORD *)this + 5) = v8;
  ++*((_DWORD *)this + 7);
  return 0;
}
