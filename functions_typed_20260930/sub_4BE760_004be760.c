void __thiscall sub_4BE760(int this, int a2, int a3, float a4)
{
  double v4; // st7
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  double v10; // st7
  double v11; // st7
  int v12; // eax
  int v13; // eax
  double v14; // st7
  float v15; // [esp+10h] [ebp-Ch]
  float v16; // [esp+14h] [ebp-8h]
  float v17; // [esp+18h] [ebp-4h]
  float v18; // [esp+28h] [ebp+Ch]
  float v19; // [esp+28h] [ebp+Ch]

  v4 = 10.0;
  *(_DWORD *)(this + 844) = 1142292480;
  v6 = 0;
  v15 = 99999.898;
  v17 = 0.0;
  v16 = 0.0;
  if ( dword_5C329C <= 0 )
    goto LABEL_31;
  do
  {
    v7 = dword_7C54F0[v6];
    if ( *(float *)(v7 + 16540) > 1.0 && *(float *)(v7 + 16540) < (double)v15 && *(_DWORD *)(v7 + 13000) == 1 )
    {
      v15 = *(float *)(v7 + 16540);
      if ( *(_DWORD *)(this + 864) == 7 )
        v17 = *(float *)(v7 + 17604);
      else
        v17 = *(float *)(v7 + 17600);
    }
    ++v6;
  }
  while ( v6 < dword_5C329C );
  if ( v15 >= 9000.0 )
    goto LABEL_31;
  v8 = 0;
  do
  {
    v9 = dword_7C54F0[v8];
    if ( *(float *)(v9 + 16540) > 0.0
      && *(float *)(v9 + 16540) > (double)v16
      && v15 * 1.15 > *(float *)(v9 + 16540)
      && *(_DWORD *)(v9 + 13000) == 1 )
    {
      v16 = *(float *)(v9 + 16540);
      if ( *(_DWORD *)(this + 864) == 7 )
        v4 = *(float *)(v9 + 17604);
      else
        v4 = *(float *)(v9 + 17600);
    }
    ++v8;
  }
  while ( v8 < dword_5C329C );
  if ( v16 <= 1.0 || v15 == v16 )
  {
LABEL_31:
    if ( a3 && SeasonRacesSectionFinder(a3) )
    {
      v12 = a2 < 3 || a2 > 5 ? StringKeyedLinkedListSearch(off_5D2634[0]) : StringKeyedLinkedListSearch(off_5D2630[0]);
      if ( v12 )
      {
        v13 = DataEntryAccessor(v12);
        *(float *)(this + 844) = sub_58850F(v13);
      }
    }
    *(float *)(this + 840) = a4;
    v14 = 0.15000001 * *(float *)(this + 844);
    *(_BYTE *)(this + 834) = 1;
    *(float *)(this + 844) = v14 * (1.0 - a4) + *(float *)(this + 844);
  }
  else
  {
    v10 = v17 - v4;
    if ( v10 < 0.0099999998 )
      v10 = 0.0099999998;
    *(_BYTE *)(this + 834) = 1;
    v18 = v16 - v15;
    v11 = v15 - v18 / v10 * (1.0 - v17);
    *(float *)(this + 844) = v11;
    v19 = v15 * 0.97000003;
    if ( v11 < v19 )
      *(float *)(this + 844) = v19;
  }
}

