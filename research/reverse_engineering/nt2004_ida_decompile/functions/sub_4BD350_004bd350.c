int __thiscall sub_4BD350(_DWORD *this, int a2, char *FileName)
{
  FILE *v4; // esi
  unsigned int v6; // ecx
  char v7; // dl
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  char v10; // dl
  unsigned int v11; // ecx
  char *v12; // eax
  int v13; // edx
  char v14; // cl
  int v15; // ebx
  CHAR *v16; // eax
  int *v17; // eax
  int v18; // esi
  int v19; // eax
  int *v20; // eax
  char *v21; // eax
  _DWORD *v22; // ecx
  int v23; // ecx
  int v24; // edx
  char *v25; // eax
  char v26; // cl
  int *v27; // eax
  int v28; // ebp
  const char *v29; // ecx
  const char *v30; // eax
  char *v31; // eax
  int v33; // [esp+14h] [ebp-7F0h]
  char Destination[8]; // [esp+18h] [ebp-7ECh] BYREF
  FILE *Stream; // [esp+20h] [ebp-7E4h]
  int v36; // [esp+24h] [ebp-7E0h] BYREF
  __int16 v37; // [esp+28h] [ebp-7DCh] BYREF
  char String[61]; // [esp+2Ch] [ebp-7D8h] BYREF
  __int16 v39; // [esp+69h] [ebp-79Bh]
  char v40; // [esp+6Bh] [ebp-799h]
  char ArgList[61]; // [esp+6Ch] [ebp-798h] BYREF
  __int16 v42; // [esp+A9h] [ebp-75Bh]
  char v43; // [esp+ABh] [ebp-759h]
  char String2[61]; // [esp+ACh] [ebp-758h] BYREF
  __int16 v45; // [esp+E9h] [ebp-71Bh]
  char v46; // [esp+EBh] [ebp-719h]
  char v47; // [esp+ECh] [ebp-718h] BYREF
  _BYTE v48[252]; // [esp+EDh] [ebp-717h] BYREF
  __int16 v49; // [esp+1E9h] [ebp-61Bh]
  char v50; // [esp+1EBh] [ebp-619h]
  char Buffer[253]; // [esp+1ECh] [ebp-618h] BYREF
  __int16 v52; // [esp+2E9h] [ebp-51Bh]
  char v53; // [esp+2EBh] [ebp-519h]
  char v54[384]; // [esp+2ECh] [ebp-518h] BYREF
  int v55; // [esp+46Ch] [ebp-398h]
  char v56; // [esp+470h] [ebp-394h]
  int v57; // [esp+478h] [ebp-38Ch]
  int v58; // [esp+47Ch] [ebp-388h]
  char *v59; // [esp+480h] [ebp-384h]
  char Str[384]; // [esp+484h] [ebp-380h] BYREF
  char v61[253]; // [esp+604h] [ebp-200h] BYREF
  __int16 v62; // [esp+701h] [ebp-103h]
  char v63; // [esp+703h] [ebp-101h]
  _BYTE v64[256]; // [esp+704h] [ebp-100h] BYREF

  String2[0] = byte_629120;
  memset(&String2[1], 0, 0x3Cu);
  v45 = 0;
  v46 = 0;
  String[0] = byte_629120;
  memset(&String[1], 0, 0x3Cu);
  v39 = 0;
  v40 = 0;
  ArgList[0] = byte_629120;
  memset(&ArgList[1], 0, 0x3Cu);
  v42 = 0;
  v43 = 0;
  v47 = byte_629120;
  memset(v48, 0, sizeof(v48));
  v49 = 0;
  v50 = 0;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v52 = 0;
  v53 = 0;
  v61[0] = byte_629120;
  memset(&v61[1], 0, 0xFCu);
  v62 = 0;
  v63 = 0;
  v64[0] = byte_629120;
  memset(&v64[1], 0, 255);
  memset(Str, 0, sizeof(Str));
  v55 = 0;
  v59 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 1;
  v4 = fopen(FileName, Mode);
  Stream = v4;
  if ( !v4 )
    return -1;
  strcpy(&v47, FileName);
  v6 = strlen(&v47) + 1;
  v7 = *((_BYTE *)&v45 + v6 + 1);
  v8 = v6 - 2;
  if ( v7 != 46 )
  {
    do
      --v8;
    while ( v8 && v48[v8 - 1] != 46 );
  }
  v48[v8 - 1] = 0;
  v9 = strlen(&v47) + 1;
  v10 = *((_BYTE *)&v45 + v9 + 1);
  v11 = v9 - 2;
  if ( v10 != 92 )
  {
    do
      --v11;
    while ( v11 && v48[v11 - 1] != 92 );
  }
  v12 = &v48[v11];
  v13 = Buffer - &v48[v11];
  do
  {
    v14 = *v12;
    v12[v13] = *v12;
    ++v12;
  }
  while ( v14 );
  if ( !this[51] )
  {
    if ( sub_597350(this + 51, Buffer, aPitlocMts, 20) )
      return -1;
    if ( sub_597350(this + 52, aPitlocator0, aPitlocMts, 20) )
      return -1;
    sub_59E050(0, 0, 1067517477);
    sub_59E690(this[52], 0);
    if ( sub_597350(this + 53, aPitlocator1, aPitlocMts, 20) )
      return -1;
    sub_59E050(0, 0, 1066292740);
    sub_59E690(this[53], 0);
    if ( sub_597350(this + 54, aPitlocator2, aPitlocMts, 20) )
      return -1;
    sub_59E050(0, 0, -1074152866);
    sub_59E690(this[54], 0);
    if ( sub_597350(this + 55, aPitlocator3, aPitlocMts, 20) )
      return -1;
    sub_59E050(0, 0, -1085099999);
    sub_59E690(this[55], 0);
    v4 = Stream;
  }
  fseek(v4, 0, 0);
  v15 = 0;
  if ( fgets(Str, 384, v4) )
  {
    do
    {
      if ( !sub_577B60(v54) )
      {
        if ( sub_577E50(v54, aSound_0, (int)v64) )
        {
          v16 = *(CHAR **)dword_62A070;
          if ( !*(_DWORD *)dword_62A070 )
            v16 = &byte_629120;
          sub_578600(v16);
          sub_578560(aPits_1);
          sub_578560(v64);
        }
        else if ( !sub_578220(aTime, (int)&this[a2 + 2], 0, 0, 0, 0, 0, 0, 0) )
        {
          if ( strstr(Str, aActor) )
          {
            sscanf(Str, "ACTOR %s", Buffer);
            sub_4BE060((int)Buffer, String2);
            v17 = (int *)this[46];
            this[48] = v17;
            if ( v17 && (v18 = *v17) != 0 )
            {
              while ( _strcmpi((const char *)(v18 + 4), String2) )
              {
                v19 = this[48];
                if ( v19 )
                  this[48] = *(_DWORD *)(v19 + 4);
                v20 = (int *)this[48];
                if ( v20 )
                {
                  v18 = *v20;
                  if ( *v20 )
                    continue;
                }
                goto LABEL_38;
              }
              v15 = v18;
            }
            else
            {
LABEL_38:
              v21 = (char *)operator new(0x22Cu);
              v15 = (int)v21;
              if ( v21 )
              {
                v22 = v21 + 108;
                do
                {
                  sub_4BC780(v22);
                  v22 = (_DWORD *)(v23 + 32);
                }
                while ( v24 != 1 );
                sub_4BC8D0((_BYTE *)v15);
              }
              else
              {
                v15 = 0;
              }
              v25 = String2;
              do
              {
                v26 = *v25;
                v25[v15 - (_DWORD)String2 + 4] = *v25;
                ++v25;
              }
              while ( v26 );
              if ( v15 )
              {
                v27 = (int *)operator new(0xCu);
                if ( v27 )
                {
                  *v27 = v15;
                  v27[1] = 0;
                  *((_BYTE *)v27 + 8) = 1;
                }
                else
                {
                  v27 = 0;
                }
                if ( this[46] )
                {
                  *(_DWORD *)(this[47] + 4) = v27;
                }
                else
                {
                  this[46] = v27;
                  this[48] = v27;
                }
                this[47] = v27;
                ++this[49];
              }
            }
            *(_DWORD *)(32 * a2 + v15 + 136) = a2;
            *(_BYTE *)(v15 + 3) = !strcmp(String2, aLman) || !strcmp(String2, aLollipop);
          }
          if ( strstr(Str, aDetail) )
          {
            sscanf(Str, "DETAIL %d", &v37);
            *(_WORD *)v15 = v37;
          }
          if ( strstr(Str, aMesh) )
          {
            v28 = 0;
            sscanf(Str, "MESH %s", Buffer);
            sub_4BE060((int)Buffer, String);
            sub_4BE060((int)Buffer, ArgList);
            sub_4CD7E0(Destination);
            if ( !strcmp(String, aLfwheeloffMts)
              || !strcmp(String, aLfwheelonMts)
              || !strcmp(String, aRfwheeloffMts)
              || !strcmp(String, aRfwheelonMts)
              || !strcmp(String, aLrwheeloffMts)
              || !strcmp(String, aLrwheelonMts)
              || !strcmp(String, aRrwheeloffMts)
              || !strcmp(String, aRrwheelonMts) )
            {
              sub_4BCED0(v15, String, ArgList, Destination);
              v28 = 1;
            }
            if ( sub_4BC7A0((__int16 *)v15, String2, (int)String, v33, 0, 0)
              && sub_4BC7A0((__int16 *)v15, String2, (int)ArgList, v33, 0, 1) )
            {
              return -1;
            }
            if ( v28 && *(_DWORD *)(v15 + 100) )
            {
              if ( *(_BYTE *)(v15 + 2) )
                sub_59ECC0(1, 1, 0, 0);
              else
                sub_59ECC0(0, 0, 0, 0);
            }
          }
          if ( strstr(Str, aParent) )
          {
            sscanf(Str, "PARENT %s", &v47);
            if ( !strcmp(&v47, aWorld) )
            {
              v33 = this[51];
            }
            else if ( !strcmp(&v47, aLocator1) )
            {
              v33 = this[52];
            }
            else if ( !strcmp(&v47, aLocator2) )
            {
              v33 = this[53];
            }
            else if ( !strcmp(&v47, aLocator3) )
            {
              v33 = this[54];
            }
            else if ( !strcmp(&v47, aLocator4) )
            {
              v33 = this[55];
            }
            else
            {
              v33 = 0;
            }
          }
          if ( strstr(Str, aPosition) )
            sscanf(Str, "POSITION %f %f %f", v15 + 76, v15 + 80, v15 + 84);
          if ( strstr(Str, aMove) )
          {
            v36 = 0;
            sscanf(Str, "MOVE %s %s %f", Buffer, v61, &v36);
            sub_4BE060((int)Buffer, &v47);
            v29 = (const char *)dword_62A0B0;
            if ( !dword_62A0B0 )
              v29 = &byte_629120;
            v30 = *(const char **)dword_62A068;
            if ( !*(_DWORD *)dword_62A068 )
              v30 = &byte_629120;
            sprintf(Buffer, "%s%s%s%s.ANM", v30, v29, aPits_0, &v47);
            if ( sub_4BC910((_DWORD *)v15, a2, (int)&v47, (int)Buffer, v61, v36) )
              return -1;
          }
          v31 = strstr(Str, aRotate);
          v59 = v31;
          if ( v31 )
          {
            sscanf(v31, "ROTATE %f", v15 + 92);
            *(float *)(v15 + 92) = *(float *)(v15 + 92) * 0.01745433;
          }
        }
      }
    }
    while ( fgets(Str, 384, Stream) );
    v4 = Stream;
  }
  fclose(v4);
  return 0;
}
