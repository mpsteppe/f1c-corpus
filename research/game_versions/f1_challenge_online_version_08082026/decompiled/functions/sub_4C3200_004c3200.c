int __thiscall sub_4C3200(char *this)
{
  char *v2; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // edi
  _DWORD *v7; // edi
  int v8; // edx
  double v9; // st7
  double v10; // st6
  _DWORD *v11; // ebp
  unsigned int v12; // edi
  _DWORD *v13; // eax
  _BYTE *v14; // ecx
  char v15; // al
  _BYTE *v16; // eax
  const char *v17; // edx
  char v18; // al
  const char *i; // ecx
  const char *v20; // ecx
  int v21; // ecx
  char *j; // eax
  char v23; // [esp+Eh] [ebp-61Eh]
  char v24; // [esp+Fh] [ebp-61Dh]
  int v25; // [esp+10h] [ebp-61Ch]
  _BYTE v26[64]; // [esp+14h] [ebp-618h] BYREF
  _BYTE v27[64]; // [esp+54h] [ebp-5D8h] BYREF
  _BYTE v28[64]; // [esp+94h] [ebp-598h] BYREF
  _BYTE v29[64]; // [esp+D4h] [ebp-558h] BYREF
  _BYTE v30[384]; // [esp+114h] [ebp-518h] BYREF
  int v31; // [esp+294h] [ebp-398h]
  char v32; // [esp+298h] [ebp-394h]
  int v33; // [esp+2A0h] [ebp-38Ch]
  int v34; // [esp+2A4h] [ebp-388h]
  int v35; // [esp+2A8h] [ebp-384h]
  _BYTE v36[384]; // [esp+2ACh] [ebp-380h] BYREF
  char v37[256]; // [esp+42Ch] [ebp-200h] BYREF
  _BYTE v38[256]; // [esp+52Ch] [ebp-100h] BYREF

  memset(v36, 0, sizeof(v36));
  v2 = *(char **)this;
  v3 = *(_DWORD *)this == 0;
  v31 = 0;
  v35 = 0;
  v33 = 0;
  v34 = 0;
  v32 = 1;
  v24 = 0;
  v23 = 0;
  v26[0] = 0;
  v28[0] = 0;
  v29[0] = 0;
  v27[0] = 0;
  if ( v3 )
    v2 = byte_5EA438;
  v4 = sub_587DB0(v2, aR);
  v5 = v4;
  v25 = v4;
  if ( v4 )
  {
    if ( sub_587CA0(v36, 384, v4) )
    {
      do
      {
        sub_5651B0(v30);
        sub_5654A0(aHdvehicle, v28);
        sub_5654A0(aHeadphysics, v26);
        sub_5654A0(aSounds, v27);
        sub_5654A0(aGraphics, v29);
        sub_5654A0(aGenstring, this + 40);
        v7 = this + 56;
        if ( sub_565870(aEyepoint, this + 56, this + 60, this + 64, 0, 0, 0, 0, 0) )
        {
          if ( !v24 )
          {
            *((_DWORD *)this + 17) = *v7;
            v8 = *((_DWORD *)this + 16);
            *((_DWORD *)this + 18) = *((_DWORD *)this + 15);
            *((_DWORD *)this + 19) = v8;
          }
          if ( !v23 )
          {
            v9 = *((float *)this + 16);
            v10 = *((float *)this + 15) - 0.079999998;
            *((float *)this + 20) = *(float *)v7;
            *((float *)this + 21) = v10;
            *((float *)this + 22) = v9;
          }
        }
        v11 = 0;
        if ( sub_565870(aCameratarget, this + 68, this + 72, this + 76, 0, 0, 0, 0, 0) )
          v24 = 1;
        if ( sub_565870(aMirrorpos, this + 80, this + 84, this + 88, 0, 0, 0, 0, 0) )
          v23 = 1;
        sub_565870(aMirrornorm, this + 92, this + 96, this + 100, 0, 0, 0, 0, 0);
        sub_565870(aSteeringwheela, this + 104, this + 108, this + 112, 0, 0, 0, 0, 0);
        sub_5654A0(aNumber, this + 116);
        sub_5654A0(aTeam_0, this + 124);
        sub_5654A0(aDriver_0, this + 188);
        sub_5654A0(aDescription, this + 252);
        sub_5654A0(aEngine, this + 316);
        sub_5654A0(aManufacturer, this + 380);
        sub_5654A0(aClasses, this + 444);
        sub_5654A0(aFullteamname, this + 700);
        sub_5654A0(aTeamfounded, this + 828);
        sub_5654A0(aTeamheadquarte, this + 844);
        sub_5654A0(aTeamstarts, this + 908);
        sub_5654A0(aTeampoles, this + 924);
        sub_5654A0(aTeamwins, this + 940);
        sub_5654A0(aTeamworldchamp, this + 956);
        if ( sub_5654A0(aDefaultlivery, v38) )
          sub_566650(v38);
        if ( sub_5654A0(aPitcrewlivery, v38) )
          sub_566650(v38);
        if ( sub_5654A0(aTracklivery, v38) )
        {
          v12 = sub_587C20(v38, asc_5D251C);
          if ( v12 )
          {
            v13 = (_DWORD *)sub_587C03(20);
            if ( v13 )
            {
              *v13 = 0;
              v13[1] = -1;
              v13[2] = 0;
              v13[3] = -1;
              v11 = v13;
            }
            v14 = v38;
            if ( v38[0] == 32 )
            {
              do
                v15 = *++v14;
              while ( v15 == 32 );
            }
            v16 = (_BYTE *)v12;
            if ( v12 > (unsigned int)v14 )
            {
              do
              {
                if ( *v16 != 32 && *v16 != 44 )
                  break;
                --v16;
              }
              while ( v16 > v14 );
            }
            v16[1] = 0;
            sub_566650(v14);
            v17 = (const char *)(v12 + 1);
            if ( *(_BYTE *)(v12 + 1) == 32 )
            {
              do
                v18 = *++v17;
              while ( v18 == 32 );
            }
            for ( i = &v17[strlen(v17)]; i > v17; --i )
            {
              if ( *i != 32 && *i )
                break;
            }
            *((_BYTE *)i + 1) = 0;
            sub_566650(v17);
            v11[4] = *((_DWORD *)this + 245);
            *((_DWORD *)this + 245) = v11;
          }
          else if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 173) )
          {
            sub_4D7AA0(&unk_8AD25C, aFormatIsTrackl);
          }
        }
      }
      while ( sub_587CA0(v36, 384, v25) );
      v5 = v25;
    }
    sub_587D02(v5);
    sub_4C38D0(this);
    if ( !this[252] )
      sub_58815F(this + 252, "#%.4s %.50s", this + 116, this + 124);
    v20 = *(const char **)this;
    if ( !*(_DWORD *)this )
      v20 = byte_5EA438;
    strcpy(v37, v20);
    v21 = strlen(v37);
    if ( v21 > 0 )
    {
      for ( j = &v36[v21 + 383]; j >= v37; *j-- = 0 )
      {
        if ( *j == 92 )
          break;
      }
    }
    sub_4C40D0(v28, aHdv, v37, this + 8);
    sub_4C40D0(v26, aIni, v37, this + 16);
    sub_4C40D0(v29, aGen, v37, this + 32);
    sub_4C40D0(v27, aSfx, v37, this + 24);
    return 0;
  }
  else
  {
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_8, 115) )
      sub_4D7AA0(&unk_8AD25C, aCouldNotOpenS);
    return -1;
  }
}
