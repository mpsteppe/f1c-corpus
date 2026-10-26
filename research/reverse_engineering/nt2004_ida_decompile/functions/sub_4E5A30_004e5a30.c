char __thiscall sub_4E5A30(int this, _DWORD *ArgList, char *Format)
{
  int **v4; // eax
  int *i; // eax
  int v6; // eax
  int **v7; // eax
  int v8; // edi
  int *v9; // eax
  int v10; // edi
  int v11; // eax
  int *v12; // eax
  char v14; // [esp+0h] [ebp-18h]
  double v15; // [esp+0h] [ebp-18h]
  double v16; // [esp+0h] [ebp-18h]
  double v17; // [esp+0h] [ebp-18h]
  double v18; // [esp+0h] [ebp-18h]
  double v19; // [esp+0h] [ebp-18h]
  char v20; // [esp+8h] [ebp-10h]
  int v21; // [esp+14h] [ebp-4h]

  if ( *ArgList )
  {
    if ( Format )
    {
      sub_57A400((int)ArgList, Format, v20);
      sub_57A400((int)ArgList, asc_5FB9D8, v14);
    }
    sub_57A400((int)ArgList, aAbortedseasons_0, *(_DWORD *)(this + 32));
    sub_57A400((int)ArgList, aTotallapsD, *(_DWORD *)(this + 36));
    sub_57A400((int)ArgList, aTotalracesD, *(_DWORD *)(this + 40));
    sub_57A400((int)ArgList, aTotalraceswith_0, *(_DWORD *)(this + 44));
    sub_57A400((int)ArgList, aTotalpointssco_0, *(_DWORD *)(this + 48));
    sub_57A400((int)ArgList, aTotalchampions_0, *(_DWORD *)(this + 52));
    sub_57A400((int)ArgList, aTotalwinsD, *(_DWORD *)(this + 56));
    sub_57A400((int)ArgList, aTotalpolesD, *(_DWORD *)(this + 60));
    sub_57A400((int)ArgList, aTotallaprecord_0, *(_DWORD *)(this + 64));
    v15 = *(float *)(this + 68);
    sub_57A400((int)ArgList, aAvgstartpositi_0, SLOBYTE(v15));
    v16 = *(float *)(this + 72);
    sub_57A400((int)ArgList, aAvgfinishposit_0, SLOBYTE(v16));
    v17 = *(float *)(this + 76);
    sub_57A400((int)ArgList, aAvgracedistanc_0, SLOBYTE(v17));
    v18 = *(float *)(this + 80);
    sub_57A400((int)ArgList, aAvgopponentstr_0, SLOBYTE(v18));
    v4 = *(int ***)(this + 4);
    *(_DWORD *)(this + 8) = v4;
    if ( v4 )
    {
      for ( i = *v4; i; i = *v7 )
      {
        sub_4E4100(i, (char)ArgList, ArgList, aCareerseason);
        v6 = *(_DWORD *)(this + 8);
        if ( !v6 )
          break;
        v7 = *(int ***)(v6 + 4);
        *(_DWORD *)(this + 8) = v7;
        if ( !v7 )
          break;
      }
    }
    if ( dword_7D6B50 > 0 )
    {
      v8 = 0;
      v21 = dword_7D6B50;
      do
      {
        sub_4E5E20((char *)(v8 + dword_7D6B58 + 4));
        v8 += 400;
        --v21;
      }
      while ( v21 );
    }
    v9 = *(int **)(this + 16);
    *(_DWORD *)(this + 24) = v9;
    if ( v9 )
    {
      v10 = *v9;
      if ( *v9 )
      {
        do
        {
          sub_57A400((int)ArgList, aS_5, (char)aPlayertracksta);
          sub_57A400((int)ArgList, aTracknameS, *(_DWORD *)v10);
          sub_57A400((int)ArgList, aTrackfileS, *(_DWORD *)(v10 + 8));
          sub_57A400((int)ArgList, aTotalnumlapsD, *(_DWORD *)(v10 + 16));
          v19 = *(float *)(v10 + 20);
          sub_57A400((int)ArgList, aBestlaptimeF, SLOBYTE(v19));
          v11 = *(_DWORD *)(this + 24);
          if ( !v11 )
            break;
          v12 = *(int **)(v11 + 4);
          *(_DWORD *)(this + 24) = v12;
          if ( !v12 )
            break;
          v10 = *v12;
        }
        while ( *v12 );
      }
    }
    sub_57A400((int)ArgList, asc_5FB9D8, v20);
  }
  return 0;
}
