int __thiscall sub_4E6570(char *this)
{
  const char *v2; // eax
  FILE *v3; // eax
  FILE *v4; // edi
  CHAR *v5; // esi
  int v7; // ecx
  double v8; // st7
  double v9; // st6
  char *v10; // eax
  char v11; // cl
  int v12; // ebx
  signed int i; // edx
  char v14; // al
  char *v15; // eax
  int v16; // edx
  char v17; // cl
  char *v18; // eax
  int v19; // edx
  char v20; // cl
  CHAR *v21; // eax
  const char *v22; // ecx
  int v23; // ecx
  int *v24; // eax
  char v25; // [esp+Eh] [ebp-66Ah]
  char v26; // [esp+Fh] [ebp-669h]
  FILE *Stream; // [esp+10h] [ebp-668h]
  int v28; // [esp+14h] [ebp-664h] BYREF
  int v29; // [esp+18h] [ebp-660h] BYREF
  int v30; // [esp+1Ch] [ebp-65Ch] BYREF
  _BYTE v31[64]; // [esp+20h] [ebp-658h] BYREF
  char v32[64]; // [esp+60h] [ebp-618h] BYREF
  char Str[64]; // [esp+A0h] [ebp-5D8h] BYREF
  char v34[64]; // [esp+E0h] [ebp-598h] BYREF
  char v35[384]; // [esp+120h] [ebp-558h] BYREF
  int v36; // [esp+2A0h] [ebp-3D8h]
  char v37; // [esp+2A4h] [ebp-3D4h]
  int v38; // [esp+2ACh] [ebp-3CCh]
  int v39; // [esp+2B0h] [ebp-3C8h]
  int v40; // [esp+2B4h] [ebp-3C4h]
  char Buffer[384]; // [esp+2B8h] [ebp-3C0h] BYREF
  char v42[63]; // [esp+438h] [ebp-240h] BYREF
  char v44[256]; // [esp+478h] [ebp-200h] BYREF
  char String[256]; // [esp+578h] [ebp-100h] BYREF

  memset(Buffer, 0, sizeof(Buffer));
  v36 = 0;
  v40 = 0;
  v38 = 0;
  v39 = 0;
  v37 = 1;
  v25 = 0;
  v26 = 0;
  v34[0] = 0;
  Str[0] = 0;
  v42[0] = 0;
  v32[0] = 0;
  v31[0] = 0;
  this[175] = 0;
  sub_578600(&byte_629120);
  v2 = *(const char **)this;
  if ( !*(_DWORD *)this )
    v2 = &byte_629120;
  v3 = fopen(v2, aR);
  v4 = v3;
  Stream = v3;
  if ( v3 )
  {
    if ( fgets(Buffer, 384, v3) )
    {
      do
      {
        sub_577B60(v35);
        sub_577E50(v35, aHdvehicle, (int)Str);
        sub_577E50(v35, aHeadphysics, (int)v34);
        sub_577E50(v35, aSounds, (int)v32);
        sub_577E50(v35, aGraphics, (int)v42);
        if ( sub_577E50(v35, aAnimbasename, (int)v31) )
          sub_578600(v31);
        sub_577E50(v35, aGenstring, (int)(this + 40));
        if ( sub_578220(aEyepoint, (int)(this + 64), (int)(this + 68), (int)(this + 72), 0, 0, 0, 0, 0) )
        {
          if ( !v25 )
          {
            *((_DWORD *)this + 19) = *((_DWORD *)this + 16);
            v7 = *((_DWORD *)this + 18);
            *((_DWORD *)this + 20) = *((_DWORD *)this + 17);
            *((_DWORD *)this + 21) = v7;
          }
          if ( !v26 )
          {
            v8 = *((float *)this + 18);
            v9 = *((float *)this + 17) - 0.079999998;
            *((float *)this + 22) = *((float *)this + 16);
            *((float *)this + 23) = v9;
            *((float *)this + 24) = v8;
          }
        }
        if ( sub_578220(aCameratarget, (int)(this + 76), (int)(this + 80), (int)(this + 84), 0, 0, 0, 0, 0) )
          v25 = 1;
        if ( sub_578220(aMirrorpos, (int)(this + 88), (int)(this + 92), (int)(this + 96), 0, 0, 0, 0, 0) )
          v26 = 1;
        sub_578220(aMirrornorm, (int)(this + 100), (int)(this + 104), (int)(this + 108), 0, 0, 0, 0, 0);
        sub_578220(aSteeringwheela, (int)(this + 112), (int)(this + 116), (int)(this + 120), 0, 0, 0, 0, 0);
        sub_578220(aFlowcenter, (int)(this + 124), (int)(this + 128), (int)(this + 132), 0, 0, 0, 0, 0);
        sub_577E50(v35, aNumber, (int)(this + 168));
        sub_577E50(v35, aCommid, (int)(this + 175));
        sub_577E50(v35, aTeam, (int)(this + 182));
        sub_577E50(v35, aDriver, (int)String);
        sub_577E50(v35, aDescription, (int)(this + 438));
        sub_577E50(v35, aEngine_0, (int)(this + 502));
        sub_577E50(v35, aManufacturer, (int)(this + 566));
        sub_577E50(v35, aClasses, (int)(this + 630));
        sub_577E50(v35, aFullteamname, (int)(this + 886));
        sub_577E50(v35, aTeamfounded, (int)(this + 1014));
        sub_577E50(v35, aTeamheadquarte, (int)(this + 1030));
        sub_577E50(v35, aTeamstarts, (int)(this + 1094));
        sub_577E50(v35, aTeampoles, (int)(this + 1110));
        sub_577E50(v35, aTeamwins, (int)(this + 1126));
        sub_577E50(v35, aTeamworldchamp, (int)(this + 1142));
        if ( sub_578110(aColor, (int)&v29, (int)&v28, (int)&v30, 0) )
          *((_DWORD *)this + 290) = v30 | ((v28 | ((v29 | 0xFFFFFF00) << 8)) << 8);
      }
      while ( fgets(Buffer, 384, Stream) );
      v4 = Stream;
    }
    if ( !this[175] )
    {
      v10 = this + 168;
      do
      {
        v11 = *v10;
        v10[7] = *v10;
        ++v10;
      }
      while ( v11 );
    }
    fclose(v4);
    if ( strlen(String) )
    {
      v12 = 0;
      for ( i = 0; i < (int)strlen(String); ++i )
      {
        v14 = String[i];
        if ( v14 != 44 )
        {
          this[v12 + 246] = v14;
          ++v12;
        }
      }
      this[v12 + 246] = 0;
      v15 = strtok(String, asc_6100B8);
      if ( v15 )
      {
        v16 = this + 310 - v15;
        do
        {
          v17 = *v15;
          v15[v16] = *v15;
          ++v15;
        }
        while ( v17 );
      }
      v18 = strtok(0, &byte_629120);
      if ( v18 )
      {
        if ( *v18 == 32 )
          ++v18;
        if ( v18 )
        {
          v19 = this + 374 - v18;
          do
          {
            v20 = *v18;
            v18[v19] = *v18;
            ++v18;
          }
          while ( v20 );
        }
      }
    }
    if ( sub_4E6CD0(this) <= 0 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_18, 242) )
    {
      v21 = *(CHAR **)this;
      if ( !*(_DWORD *)this )
        v21 = &byte_629120;
      sub_500FE0((int)&unk_7D7920, aCouldNotFindAn, (char)v21);
    }
    if ( !this[438] )
      sprintf(this + 438, "#%.4s %.50s", this + 168, this + 182);
    v22 = *(const char **)this;
    if ( !*(_DWORD *)this )
      v22 = &byte_629120;
    strcpy(v44, v22);
    v23 = strlen(v44);
    if ( v23 > 0 )
    {
      v24 = (int *)&v44[v23 - 1];
      if ( &v44[v23 - 1] >= v44 )
      {
        do
        {
          if ( *(_BYTE *)v24 == 92 )
            break;
          *(_BYTE *)v24 = 0;
          v24 = (int *)((char *)v24 - 1);
        }
        while ( v24 >= (int *)v44 );
      }
    }
    sub_4E77B0(Str, (int)aHdv_0, (int)v44, (int)(this + 8));
    sub_4E77B0(v34, (int)aIni, (int)v44, (int)(this + 16));
    sub_4E77B0(v42, (int)aGen, (int)v44, (int)(this + 32));
    sub_4E77B0(v32, (int)aSfx, (int)v44, (int)(this + 24));
    return 0;
  }
  else
  {
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_18, 123) )
    {
      v5 = *(CHAR **)this;
      if ( !v5 )
        v5 = &byte_629120;
      sub_500FE0((int)&unk_7D7920, aCouldNotOpenS, (char)v5);
    }
    return -1;
  }
}
