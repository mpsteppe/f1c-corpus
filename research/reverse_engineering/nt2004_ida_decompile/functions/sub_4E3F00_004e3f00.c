char __thiscall sub_4E3F00(_BYTE *this, _DWORD *a2)
{
  _DWORD *v2; // esi
  char result; // al
  int v5; // eax
  int v6; // eax
  char *v7; // edx
  int v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  _DWORD *v11; // eax
  char v12; // [esp+Fh] [ebp-105h]
  int v13; // [esp+10h] [ebp-104h] BYREF
  int v14[64]; // [esp+14h] [ebp-100h] BYREF

  v2 = a2;
  result = 0;
  v12 = 0;
  if ( *a2 )
  {
    while ( sub_57A490(byte_7D68B0, 256) )
    {
      v12 = 1;
      v5 = sub_577B60(byte_7D6718);
      if ( v5 )
      {
        v6 = v5 - 1;
        if ( !v6 || v6 == 3 )
          return v12;
      }
      else
      {
        v7 = strstr(byte_7D68B0, aOpponent);
        if ( v7 )
        {
          v8 = atol(&v7[strlen(aOpponent)]);
          sub_4E3570(&this[644 * v8 + 16], v2);
        }
        else if ( strstr(byte_7D68B0, aPlayer_0) )
        {
          sub_4E3570(this + 30284, v2);
        }
        else if ( sub_578110(aSeasonstatus, (int)&v13, 0, 0, 0) )
        {
          *((_DWORD *)this + 7741) = v13;
        }
        else
        {
          sub_578110(aRacesession, (int)(this + 30972), 0, 0, 0);
          if ( sub_578110(aRaceover, (int)&v13, 0, 0, 0) )
            this[30976] = v13 != 0;
          sub_578110(aCurrentrace, (int)(this + 30968), 0, 0, 0);
          if ( sub_577E50(byte_7D6718, aEvent, (int)v14) )
          {
            v9 = operator new(8u);
            v10 = v9;
            if ( v9 )
            {
              *v9 = 0;
              v9[1] = -1;
              sub_578600(v14);
              v11 = operator new(0xCu);
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
            v2 = a2;
          }
        }
      }
    }
    return v12;
  }
  return result;
}
