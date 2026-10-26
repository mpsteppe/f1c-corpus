char __thiscall sub_40D150(_DWORD *this)
{
  const char *v2; // eax
  int v3; // eax
  _DWORD *v4; // eax
  void *v5; // esi
  _DWORD *v6; // eax
  LPVOID *v7; // eax
  LPVOID *v8; // esi
  LPVOID **v9; // eax
  const char *v10; // esi
  const char *v11; // eax
  int v12; // edx
  char v13; // bl
  int v14; // eax
  int v15; // eax
  int v17; // [esp+14h] [ebp-3B8h] BYREF
  _DWORD v18[7]; // [esp+18h] [ebp-3B4h] BYREF
  _BYTE Buffer[125]; // [esp+34h] [ebp-398h] BYREF
  __int16 v20; // [esp+B1h] [ebp-31Bh]
  char v21; // [esp+B3h] [ebp-319h]
  char v22[384]; // [esp+B4h] [ebp-318h] BYREF
  int v23; // [esp+234h] [ebp-198h]
  char v24; // [esp+238h] [ebp-194h]
  int v25; // [esp+240h] [ebp-18Ch]
  int v26; // [esp+244h] [ebp-188h]
  int v27; // [esp+248h] [ebp-184h]
  char String1[384]; // [esp+24Ch] [ebp-180h] BYREF

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v20 = 0;
  v21 = 0;
  sub_57A080(v18);
  (*(void (__thiscall **)(_DWORD *))(*this + 24))(this);
  v2 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v2 = &byte_629120;
  sub_405480(Buffer, 0x7Fu, "%s%s", v2, aCareerGdb);
  sub_57AC50(Buffer, 0);
  sub_4CD5B0(Buffer, 127);
  strcat(Buffer, aCareerIni);
  if ( (unsigned __int8)sub_57A2F0(Buffer, 0) )
  {
    memset(String1, 0, sizeof(String1));
    v23 = 0;
    v27 = 0;
    v25 = 0;
    v26 = 0;
    v24 = 1;
    while ( sub_57A490(String1, 383) )
    {
      v3 = sub_577B60(v22);
      if ( v3 )
      {
        if ( v3 == 2 || v3 == 4 )
          break;
      }
      else
      {
        if ( sub_578110(aSeasontype, (int)&v17, 0, 0, 0) )
        {
          this[9] = v17;
        }
        else if ( sub_578110(aRaceindex, (int)&v17, 0, 0, 0) )
        {
          *((_BYTE *)this + 40) = v17;
        }
        else if ( sub_578110(aSession, (int)&v17, 0, 0, 0) )
        {
          *((_BYTE *)this + 41) = v17;
        }
        if ( _strcmpi(String1, aParticipant) )
        {
          if ( !_strcmpi(String1, aAwards) )
          {
            v7 = (LPVOID *)operator new(0x50u);
            if ( v7 )
            {
              *v7 = 0;
              v7[1] = (LPVOID)-1;
              v7[2] = 0;
              v7[3] = (LPVOID)-1;
              v7[4] = 0;
              v7[5] = 0;
              v7[6] = (LPVOID)-1;
              v7[7] = 0;
              v7[8] = 0;
              v7[9] = (LPVOID)-1;
              v7[10] = 0;
              v7[11] = 0;
              v7[12] = (LPVOID)-1;
              v7[13] = 0;
              v7[14] = 0;
              v7[15] = (LPVOID)-1;
              v7[16] = 0;
              v7[17] = 0;
              v7[18] = (LPVOID)-1;
              v7[19] = 0;
              v8 = v7;
            }
            else
            {
              v8 = 0;
            }
            if ( sub_40C730(v8, v18) )
            {
              if ( v8 )
              {
                v9 = (LPVOID **)operator new(0xCu);
                if ( v9 )
                {
                  *v9 = v8;
                  v9[1] = 0;
                  *((_BYTE *)v9 + 8) = 1;
                }
                else
                {
                  v9 = 0;
                }
                if ( this[5] )
                {
                  *(_DWORD *)(this[6] + 4) = v9;
                }
                else
                {
                  this[5] = v9;
                  this[7] = v9;
                }
                this[6] = v9;
                ++this[8];
              }
            }
            else if ( v8 )
            {
              if ( v8[17] )
                sub_5BE8AE(v8[17]);
              if ( v8[14] )
                sub_5BE8AE(v8[14]);
              if ( v8[11] )
                sub_5BE8AE(v8[11]);
              sub_40D5B0(v8 + 8);
              sub_40D5B0(v8 + 5);
              sub_40D5B0(v8 + 2);
              sub_40D5B0(v8);
              sub_5BE8AE(v8);
            }
          }
        }
        else
        {
          v4 = operator new(0x24u);
          if ( v4 )
          {
            *v4 = 0;
            v4[1] = -1;
            *((_BYTE *)v4 + 8) = 1;
            v4[3] = 0;
            v4[4] = 0;
            v4[5] = 0;
            v4[6] = 0;
            v4[7] = 0;
            *((_BYTE *)v4 + 32) = 0;
            v5 = v4;
          }
          else
          {
            v5 = 0;
          }
          if ( (unsigned __int8)sub_40EC30(v18) )
          {
            if ( v5 )
            {
              v6 = operator new(0xCu);
              if ( v6 )
              {
                *v6 = v5;
                v6[1] = 0;
                *((_BYTE *)v6 + 8) = 1;
              }
              else
              {
                v6 = 0;
              }
              if ( this[1] )
              {
                *(_DWORD *)(this[2] + 4) = v6;
              }
              else
              {
                this[1] = v6;
                this[3] = v6;
              }
              this[2] = v6;
              ++this[4];
            }
          }
          else if ( v5 )
          {
            sub_40EB10(v5);
            sub_5BE8AE(v5);
          }
        }
      }
    }
    v10 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v10 = &byte_629120;
    v11 = (const char *)sub_40E4C0(this[9]);
    sub_405480(Buffer, 0x7Fu, "%s%s", v10, v11);
    sub_57AC50(Buffer, 0);
    sub_57A360(v18);
    v12 = *this;
    *((_BYTE *)this + 102) = 1;
    v13 = 1;
    if ( (*(int (__thiscall **)(_DWORD *))(v12 + 100))(this) )
    {
      v14 = (*(int (__thiscall **)(_DWORD *))(*this + 100))(this);
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v14 + 28) + 120))(*(_DWORD *)(v14 + 28));
      v15 = (*(int (__thiscall **)(_DWORD *))(*this + 100))(this);
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v15 + 28) + 208))(*(_DWORD *)(v15 + 28));
    }
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *))(*this + 24))(this);
    v13 = 0;
  }
  sub_57A0A0(v18);
  return v13;
}
