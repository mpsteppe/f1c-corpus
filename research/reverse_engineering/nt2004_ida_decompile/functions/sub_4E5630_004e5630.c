char __thiscall sub_4E5630(int this, _DWORD *a2)
{
  int v3; // eax
  int v4; // eax
  _DWORD *v6; // eax
  LPVOID *v7; // edi
  LPVOID **v8; // eax
  char String[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( *a2 )
  {
    while ( sub_57A490(byte_7D68B0, 256) )
    {
      v3 = sub_577B60(byte_7D6718);
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( !v4 || v4 == 3 )
          return 0;
      }
      else if ( strstr(byte_7D68B0, aCareerseason) )
      {
        v6 = operator new(0x7904u);
        if ( v6 )
          v7 = (LPVOID *)sub_4E3DE0(v6);
        else
          v7 = 0;
        if ( sub_4E3F00(v7, a2) )
        {
          if ( v7 )
          {
            v8 = (LPVOID **)operator new(0xCu);
            if ( v8 )
            {
              *v8 = v7;
              v8[1] = 0;
              *((_BYTE *)v8 + 8) = 1;
            }
            else
            {
              v8 = 0;
            }
            if ( *(_DWORD *)this )
            {
              *(_DWORD *)(*(_DWORD *)(this + 4) + 4) = v8;
            }
            else
            {
              *(_DWORD *)this = v8;
              *(_DWORD *)(this + 8) = v8;
            }
            *(_DWORD *)(this + 4) = v8;
            ++*(_DWORD *)(this + 12);
          }
        }
        else if ( v7 )
        {
          sub_4E3E50(v7);
          sub_5BE8AE(v7);
        }
      }
      else if ( strstr(byte_7D68B0, aPlayertracksta) )
      {
        sub_4E51B0((float *)this, a2);
      }
      else
      {
        sub_578110(aAbortedseasons, this + 32, 0, 0, 0);
        sub_578110(aTotallaps, this + 36, 0, 0, 0);
        sub_578110(aTotalraces, this + 40, 0, 0, 0);
        sub_578110(aTotalraceswith, this + 44, 0, 0, 0);
        sub_578110(aTotalpointssco, this + 48, 0, 0, 0);
        sub_578110(aTotalchampions, this + 52, 0, 0, 0);
        sub_578110(aTotalwins, this + 56, 0, 0, 0);
        sub_578110(aTotalpoles, this + 60, 0, 0, 0);
        sub_578110(aTotallaprecord, this + 64, 0, 0, 0);
        if ( sub_577ED0(byte_7D6718, aAvgstartpositi, String, 0) )
          *(float *)(this + 68) = atof(String);
        if ( sub_577ED0(byte_7D6718, aAvgfinishposit, String, 0) )
          *(float *)(this + 72) = atof(String);
        if ( sub_577ED0(byte_7D6718, aAvgracedistanc, String, 0) )
          *(float *)(this + 76) = atof(String);
        if ( sub_577ED0(byte_7D6718, aAvgopponentstr, String, 0) )
          *(float *)(this + 80) = atof(String);
      }
    }
  }
  return 0;
}
