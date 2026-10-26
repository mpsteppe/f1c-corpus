char __thiscall sub_4D2A70(char *this, char *Source)
{
  int v2; // eax
  int v3; // ebp
  char *v4; // eax
  BOOL v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // edx
  char *v9; // eax
  char *v10; // esi
  _DWORD *v11; // eax
  int v13; // [esp+8h] [ebp-380h] BYREF
  char *v14; // [esp+Ch] [ebp-37Ch]
  float v15; // [esp+10h] [ebp-378h]
  char v16[28]; // [esp+14h] [ebp-374h] BYREF
  char String1[64]; // [esp+30h] [ebp-358h] BYREF
  char String[384]; // [esp+70h] [ebp-318h] BYREF
  int v19; // [esp+1F0h] [ebp-198h]
  char v20; // [esp+1F4h] [ebp-194h]
  int v21; // [esp+1FCh] [ebp-18Ch]
  int v22; // [esp+200h] [ebp-188h]
  int v23; // [esp+204h] [ebp-184h]
  char Buffer[384]; // [esp+208h] [ebp-180h] BYREF

  v14 = this;
  sub_57A080(v16);
  memset(Buffer, 0, sizeof(Buffer));
  v19 = 0;
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 1;
  v15 = sub_4D9DF0(&unk_7D5DAC);
  *(float *)&v13 = 0.0;
  if ( (unsigned __int8)sub_57A2F0(Source, 1) )
  {
    while ( sub_57A490(Buffer, 256) )
    {
      v2 = sub_577B60(String);
      if ( v2 != 1 && (v2 <= 2 || v2 > 4) )
      {
        if ( sub_578220(aEt, (int)&v13, 0, 0, 0, 0, 0, 0, 0) )
        {
          *(float *)&v13 = *(float *)&v13 + v15;
        }
        else
        {
          v3 = 0;
          while ( 1 )
          {
            String1[0] = 0;
            v4 = sub_451960(v3);
            if ( sub_577ED0(String, v4, String1, 0) )
              break;
            if ( ++v3 >= 256 )
              goto LABEL_23;
          }
          v5 = _strcmpi(String1, aUp) != 0;
          if ( v3 != -1 )
          {
            v6 = operator new(8u);
            if ( v6 )
            {
              *(_DWORD *)v6 = -1082130432;
              v6[4] = 0;
              v7 = v6;
            }
            else
            {
              v7 = 0;
            }
            v8 = v13;
            v7[4] = v5;
            v9 = v14;
            *(_DWORD *)v7 = v8;
            v10 = &v9[16 * v3 + 2304];
            v11 = operator new(0xCu);
            if ( v11 )
            {
              *v11 = v7;
              v11[1] = 0;
              *((_BYTE *)v11 + 8) = 1;
            }
            else
            {
              v11 = 0;
            }
            if ( *(_DWORD *)v10 )
            {
              *(_DWORD *)(*((_DWORD *)v10 + 1) + 4) = v11;
            }
            else
            {
              *(_DWORD *)v10 = v11;
              *((_DWORD *)v10 + 2) = v11;
            }
            *((_DWORD *)v10 + 1) = v11;
            ++*((_DWORD *)v10 + 3);
          }
        }
      }
LABEL_23:
      ;
    }
    sub_57A360(v16);
    sub_57A0A0(v16);
    return 1;
  }
  else
  {
    sub_57A0A0(v16);
    return 0;
  }
}
