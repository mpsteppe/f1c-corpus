char __thiscall sub_410E10(_DWORD *this, _DWORD *a2)
{
  bool v2; // zf
  _DWORD *v3; // ebp
  int v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  void *v7; // eax
  LPVOID *v8; // esi
  LPVOID **v9; // eax
  _DWORD *v10; // esi
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // esi
  _BYTE *v14; // edi
  int v15; // ebp
  int v16; // eax
  _DWORD *v17; // eax
  _DWORD *v18; // esi
  _DWORD *v19; // ebp
  int v20; // eax
  int v21; // esi
  int v22; // edi
  _DWORD *v23; // eax
  _DWORD *v24; // ecx
  int *v25; // eax
  int v26; // esi
  const char *v27; // eax
  int v28; // eax
  int *v29; // eax
  int v31; // [esp+Ch] [ebp-420h] BYREF
  char *v32; // [esp+10h] [ebp-41Ch]
  char Buffer[125]; // [esp+14h] [ebp-418h] BYREF
  __int16 v34; // [esp+91h] [ebp-39Bh]
  char v35; // [esp+93h] [ebp-399h]
  char String[384]; // [esp+94h] [ebp-398h] BYREF
  int v37; // [esp+214h] [ebp-218h]
  char v38; // [esp+218h] [ebp-214h]
  int v39; // [esp+220h] [ebp-20Ch]
  int v40; // [esp+224h] [ebp-208h]
  int v41; // [esp+228h] [ebp-204h]
  char String1[384]; // [esp+22Ch] [ebp-200h] BYREF
  char String2[125]; // [esp+3ACh] [ebp-80h] BYREF
  __int16 v44; // [esp+429h] [ebp-3h]
  char v45; // [esp+42Bh] [ebp-1h]

  v2 = *a2 == 0;
  v3 = this;
  v32 = (char *)this;
  if ( v2 )
    return 0;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v34 = 0;
  v35 = 0;
  String2[0] = byte_629120;
  memset(&String2[1], 0, 0x7Cu);
  v44 = 0;
  v45 = 0;
  memset(String1, 0, sizeof(String1));
  v37 = 0;
  v41 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 1;
  if ( sub_57A490(String1, 383) )
  {
    while ( 1 )
    {
      v4 = sub_577B60(String);
      if ( v4 )
      {
        if ( v4 == 2 )
          break;
        if ( v4 == 4 )
        {
LABEL_109:
          v3 = v32;
          break;
        }
      }
      else
      {
        v31 = 0;
        if ( sub_578110(aBank, (int)&v31, 0, 0, 0) )
        {
          v3[1] = v31;
        }
        else if ( sub_578110(aReputation, (int)&v31, 0, 0, 0) )
        {
          *((_BYTE *)v3 + 8) = v31;
        }
        else if ( sub_577E50(String, aMessage, (int)Buffer) )
        {
          v5 = operator new(8u);
          if ( v5 )
          {
            *v5 = 0;
            v5[1] = -1;
            sub_578600(Buffer);
          }
          else
          {
            v5 = 0;
          }
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
            if ( v3[33] )
            {
              *(_DWORD *)(v3[34] + 4) = v6;
            }
            else
            {
              v3[33] = v6;
              v3[35] = v6;
            }
            v3[34] = v6;
            ++v3[36];
          }
        }
        else if ( sub_578110(aCarnumber, (int)&v31, 0, 0, 0) )
        {
          *((_BYTE *)v3 + 164) = v31;
        }
        if ( !_strcmpi(String1, aSponsor_0) )
        {
          v7 = operator new(0x18u);
          if ( v7 )
            v8 = (LPVOID *)sub_413AC0(v7);
          else
            v8 = 0;
          if ( (unsigned __int8)sub_413AF0(a2) )
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
              if ( v3[3] )
              {
                *(_DWORD *)(v3[4] + 4) = v9;
              }
              else
              {
                v3[3] = v9;
                v3[5] = v9;
              }
              v3[4] = v9;
              ++v3[6];
            }
          }
          else if ( v8 )
          {
            if ( *v8 )
              sub_5BE8AE(*v8);
            sub_5BE8AE(v8);
          }
        }
        if ( sub_577E50(String, aBootedsponsor, (int)Buffer) )
        {
          v10 = operator new(8u);
          if ( v10 )
          {
            *v10 = 0;
            v10[1] = -1;
            sub_578600(Buffer);
          }
          else
          {
            v10 = 0;
          }
          if ( v10 )
          {
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
            if ( v3[15] )
            {
              *(_DWORD *)(v3[16] + 4) = v11;
            }
            else
            {
              v3[15] = v11;
              v3[17] = v11;
            }
            v3[16] = v11;
            ++v3[18];
          }
        }
        if ( !_strcmpi(String1, aResearchdata) && sub_57A490(String1, 383) )
        {
          do
          {
            v12 = sub_577B60(String);
            if ( v12 )
            {
              if ( v12 == 2 || v12 == 4 )
                break;
            }
            else
            {
              v13 = 0;
              v14 = v32 + 76;
              v15 = 4;
              do
              {
                sub_405480(Buffer, 0x7Fu, "ResearchLevel%d", v13);
                if ( sub_578110(Buffer, (int)&v31, 0, 0, 0) )
                  *v14 = v31;
                ++v13;
                ++v14;
                --v15;
              }
              while ( v15 );
              if ( sub_578110(aCurrenttype, (int)&v31, 0, 0, 0) )
              {
                *((_DWORD *)v32 + 20) = v31;
              }
              else if ( sub_578110(aCurrentlevel, (int)&v31, 0, 0, 0) )
              {
                v32[84] = v31;
              }
              else if ( sub_578110(aCurrentnumrace, (int)&v31, 0, 0, 0) )
              {
                v32[85] = v31;
              }
              else if ( sub_578110(aCurrentnumrace_0, (int)&v31, 0, 0, 0) )
              {
                v32[86] = v31;
              }
              else if ( sub_578110(aCurrentcost, (int)&v31, 0, 0, 0) )
              {
                *((_DWORD *)v32 + 22) = v31;
              }
            }
          }
          while ( sub_57A490(String1, 383) );
        }
        if ( !_strcmpi(String1, aCardata) && sub_57A490(String1, 383) )
        {
          do
          {
            v16 = sub_577B60(String);
            if ( v16 )
            {
              if ( v16 == 2 || v16 == 4 )
                break;
            }
            else
            {
              sub_577E50(String, aCurrentcar, (int)String2);
              if ( !_strcmpi(String1, off_5FC21C) )
              {
                v17 = operator new(0x10u);
                v18 = v17;
                if ( v17 )
                {
                  v17[2] = 0;
                  v17[3] = -1;
                  *v17 = 0;
                  *((_BYTE *)v17 + 4) = 100;
                  sub_578600(aCar01);
                  v19 = v18;
                }
                else
                {
                  v19 = 0;
                }
                while ( sub_57A490(String1, 383) )
                {
                  v20 = sub_577B60(String);
                  if ( v20 )
                  {
                    if ( v20 == 2 || v20 == 4 )
                      break;
                  }
                  else
                  {
                    if ( sub_577E50(String, aName_1, (int)Buffer) )
                    {
                      sub_578600(Buffer);
                    }
                    else if ( sub_578110(aCondition, (int)&v31, 0, 0, 0) )
                    {
                      *((_BYTE *)v19 + 4) = v31;
                    }
                    v21 = 0;
                    v22 = 4;
                    do
                    {
                      sub_405480(Buffer, 0x7Fu, "Level%d", v21);
                      if ( sub_578110(Buffer, (int)&v31, 0, 0, 0) )
                        *((_BYTE *)v19 + v21) = v31;
                      ++v21;
                      --v22;
                    }
                    while ( v22 );
                  }
                }
                if ( v19 )
                {
                  v23 = operator new(0xCu);
                  if ( v23 )
                  {
                    *v23 = v19;
                    v23[1] = 0;
                    *((_BYTE *)v23 + 8) = 1;
                  }
                  else
                  {
                    v23 = 0;
                  }
                  v24 = v32;
                  if ( *((_DWORD *)v32 + 24) )
                  {
                    *(_DWORD *)(*((_DWORD *)v32 + 25) + 4) = v23;
                  }
                  else
                  {
                    *((_DWORD *)v32 + 24) = v23;
                    v24[26] = v23;
                  }
                  v24[25] = v23;
                  ++v24[27];
                }
              }
            }
          }
          while ( sub_57A490(String1, 383) );
        }
      }
      if ( !sub_57A490(String1, 383) )
        goto LABEL_109;
      v3 = v32;
    }
  }
  if ( strlen(String2) )
  {
    v25 = (int *)v3[24];
    v3[26] = v25;
    if ( v25 )
    {
      v26 = *v25;
      if ( *v25 )
      {
        while ( 1 )
        {
          v27 = *(const char **)(v26 + 8);
          if ( !v27 )
            v27 = &byte_629120;
          if ( !_strcmpi(v27, String2) )
            break;
          v28 = v3[26];
          if ( v28 )
            v3[26] = *(_DWORD *)(v28 + 4);
          v29 = (int *)v3[26];
          if ( v29 )
          {
            v26 = *v29;
            if ( *v29 )
              continue;
          }
          goto LABEL_120;
        }
        v3[23] = v26;
      }
    }
  }
LABEL_120:
  (*(void (__thiscall **)(_DWORD *))(*v3 + 192))(v3);
  return 1;
}
