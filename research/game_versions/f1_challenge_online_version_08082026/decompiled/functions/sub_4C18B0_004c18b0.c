char __thiscall sub_4C18B0(float *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  LPVOID *v4; // ebp
  int v5; // eax
  LPVOID *v6; // edi
  int v7; // eax
  char *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // [esp+8h] [ebp-104h] BYREF
  CHAR v14[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( !*a2 )
    return 0;
  v3 = (_DWORD *)sub_587C03(24);
  if ( v3 )
    v4 = (LPVOID *)sub_4C03A0(v3);
  else
    v4 = 0;
  while ( sub_566CC0(&unk_8AC1E8, 256) )
  {
    v5 = sub_5651B0(&unk_8AC050);
    v6 = 0;
    if ( v5 )
    {
      v7 = v5 - 1;
      if ( !v7 || v7 == 3 )
        break;
    }
    else if ( sub_587C20(&unk_8AC1E8, aCareerseason) )
    {
      v10 = sub_587C03(45396);
      if ( v10 )
        v6 = (LPVOID *)sub_4C0AB0(v10);
      if ( sub_4C0B70((int)v6, a2) )
      {
        if ( v6 )
        {
          v11 = sub_587C03(12);
          if ( v11 )
          {
            *(_DWORD *)v11 = v6;
            *(_DWORD *)(v11 + 4) = 0;
            *(_BYTE *)(v11 + 8) = 1;
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
      else if ( v6 )
      {
        sub_4C0B10(v6);
        sub_587BCF(v6);
      }
    }
    else if ( sub_587C20(&unk_8AC1E8, aPlayertracksta) )
    {
      sub_4C18B0(a2);
    }
    else
    {
      sub_565760(aAbortedseasons, this + 8, 0, 0, 0);
      sub_565760(aTotallaps, this + 9, 0, 0, 0);
      sub_565760(aTotalraces, this + 10, 0, 0, 0);
      sub_565760(aTotalraceswith, this + 11, 0, 0, 0);
      sub_565760(aTotalpointssco, this + 12, 0, 0, 0);
      sub_565760(aTotalchampions, this + 13, 0, 0, 0);
      sub_565760(aTotalwins, this + 14, 0, 0, 0);
      sub_565760(aTotalpoles, this + 15, 0, 0, 0);
      sub_565760(aTotallaprecord, this + 16, 0, 0, 0);
      if ( sub_565520(aAvgstartpositi, v14, 0) )
        this[17] = sub_58850F(v14);
      if ( sub_565520(aAvgfinishposit, v14, 0) )
        this[18] = sub_58850F(v14);
      if ( sub_565520(aAvgracedistanc, v14, 0) )
        this[19] = sub_58850F(v14);
      if ( sub_565520(aAvgopponentstr, v14, 0) )
        this[20] = sub_58850F(v14);
      v13 = 0;
      if ( sub_565760(aMechfailRate, &v13, 0, 0, 0) )
        *((_DWORD *)this + 21) = v13;
      sub_565760(aRacecondReconn, this + 22, 0, 0, 0);
      sub_565760(aRacecondWalkth, this + 23, 0, 0, 0);
      sub_565760(aRacecondFormat, this + 24, 0, 0, 0);
      sub_565760(aRacecondFlagRu, this + 25, 0, 0, 0);
      if ( sub_565760(aRacecondWeathe, &v13, 0, 0, 0) )
        *((_DWORD *)this + 26) = v13;
      if ( sub_565760(aRacecondTimesc, &v13, 0, 0, 0) )
        *((_BYTE *)this + 108) = v13 != 0;
      sub_565760(aGameoptQualify, this + 28, 0, 0, 0);
      sub_565760(aGameoptRaceLap, this + 29, 0, 0, 0);
      sub_565760(aGameoptRaceTim, this + 30, 0, 0, 0);
      sub_565870(aGameoptRaceLen, this + 31, 0, 0, 0, 0, 0, 0, 0);
      sub_565760(aGameoptOpponen, this + 32, 0, 0, 0);
      sub_565760(aGameoptFuelMul, this + 33, 0, 0, 0);
      sub_565760(aGameoptTireMul, this + 34, 0, 0, 0);
      sub_565760(aGameoptSpeedCo, this + 35, 0, 0, 0);
      sub_565760(aTotalnumlaps, v4 + 4, 0, 0, 0);
      sub_565870(aBestlaptime, v4 + 5, 0, 0, 0, 0, 0, 0, 0);
      if ( sub_5654A0(aTrackname_0, v14) )
        sub_566650(v14);
      if ( sub_5654A0(aTrackfile, v14) )
        sub_566650(v14);
    }
  }
  v8 = (char *)v4[2];
  if ( !v8 )
    v8 = byte_5EA438;
  if ( sub_4C2860(v8) )
  {
    if ( v4 )
    {
      if ( v4[2] )
        sub_587BCF(v4[2]);
      if ( *v4 )
        sub_587BCF(*v4);
      sub_587BCF(v4);
    }
    return 0;
  }
  if ( !v4 )
    return 0;
  v9 = sub_587C03(12);
  if ( v9 )
  {
    *(_DWORD *)v9 = v4;
    *(_DWORD *)(v9 + 4) = 0;
    *(_BYTE *)(v9 + 8) = 1;
  }
  else
  {
    v9 = 0;
  }
  if ( *((_DWORD *)this + 4) )
  {
    *(_DWORD *)(*((_DWORD *)this + 5) + 4) = v9;
  }
  else
  {
    *((_DWORD *)this + 4) = v9;
    *((_DWORD *)this + 6) = v9;
  }
  *((_DWORD *)this + 5) = v9;
  ++*((_DWORD *)this + 7);
  return 0;
}
