void __thiscall sub_426770(int this)
{
  int v2; // edx
  _BYTE *v3; // eax
  int v4; // ecx
  int v5; // ecx
  float *v6; // ecx
  double v7; // st7
  char v8; // al
  double v9; // st7
  float *v10; // ecx
  double v11; // st7
  double v12; // st7
  int v13; // eax
  int v14; // eax
  double v15; // st7
  int v16; // [esp+0h] [ebp-18h]
  int v17; // [esp+4h] [ebp-14h]
  float v18; // [esp+14h] [ebp-4h]

  v2 = 0;
  v3 = (_BYTE *)(this + 2296);
  v4 = 4;
  do
  {
    if ( *v3 )
      ++v2;
    v3 += 304;
    --v4;
  }
  while ( v4 );
  v5 = *(_DWORD *)(this + 19804);
  if ( (v5 == 2 || *(float *)(this + 18792) <= 0.001 || v2 < 4) && *(_DWORD *)(this + 24024) != 3 )
    *(_DWORD *)(this + 24024) = 4;
  if ( *(_DWORD *)(this + 24024) == 4 )
  {
    v6 = *(float **)(this + 23432);
    *(float *)(this + 24228) = *(float *)(this + 23852) + 120.0;
    if ( *(float *)(this + 23728) + v6[40] >= v6[19] - *(float *)(this + 23728) )
      v7 = v6[40];
    else
      v7 = -v6[19];
    v8 = *(_BYTE *)(this + 24208);
    *(float *)(this + 23716) = v7;
    if ( v8 )
    {
      v9 = *(float *)(this + 17636) * v6[55] + *(float *)(this + 17632) * v6[54] + *(float *)(this + 17628) * v6[53] >= flt_628F78
         ? *(float *)(this + 17636) * v6[55] + *(float *)(this + 17632) * v6[54] + *(float *)(this + 17628) * v6[53]
         : flt_628F78;
      *(float *)(this + 23760) = v9;
      if ( v9 < *(float *)(this + 24720) )
      {
        *(float *)&v17 = *(float *)(this + 23728) + 3.0;
        *(float *)&v16 = *(float *)(this + 23728) - 3.0;
        sub_529AC0(this + 23760, 0.25, v16, v17);
      }
    }
    if ( dword_75CBB0 == 7 )
      sub_51C180(this + 84);
    if ( *(float *)(this + 23764) < 1.0 && dword_75CBB0 != 7 )
    {
      sub_4276F0(this);
      v10 = (float *)(16 * *(_DWORD *)(this + 24584) + this + 24508);
      if ( *v10 >= 1.0 )
        v11 = *v10;
      else
        v11 = 1.0;
      if ( *(float *)(this + 18796) >= v11 )
      {
        if ( *v10 < 1.0 )
        {
          v18 = 1.0;
LABEL_33:
          sub_51E4A0(LODWORD(v18));
          sub_427A00(this);
          *(_DWORD *)(this + 24232) = 0;
          sub_427F60(18);
          v13 = *(_DWORD *)(this + 23612);
          *(_DWORD *)(this + 24248) = v13;
          *(_DWORD *)(this + 24244) = v13;
          *(_DWORD *)(this + 23752) = 0;
          sub_51F0F0(this + 84);
          *(_DWORD *)(this + 23596) = 0;
          *(_DWORD *)(this + 24024) = 3;
          sub_4EEC20(0);
          sub_4EEC50(0);
          sub_4EECE0(0);
          v14 = *(_DWORD *)(this + 23612);
          *(_DWORD *)(this + 24212) = 0;
          *(_DWORD *)(this + 23748) = 1065353216;
          *(_DWORD *)(this + 23740) = 0;
          *(_DWORD *)(this + 24240) = 0;
          *(_DWORD *)(this + 24248) = v14;
          *(_DWORD *)(this + 24244) = v14;
          *(_DWORD *)(this + 23724) = 0;
          sub_423870(this);
          v15 = *(float *)(this + 23852) + 180.0;
          *(_DWORD *)(this + 23920) = -1;
          *(float *)(this + 24228) = v15;
          return;
        }
        v12 = *v10;
      }
      else
      {
        v12 = *(float *)(this + 18796);
      }
      v18 = v12;
      goto LABEL_33;
    }
  }
  else if ( v5 == 1 && *(_BYTE *)(this + 18910) && *(_DWORD *)(this + 20848) + 2 < dword_7D74B8 )
  {
    sub_4271B0(0);
  }
  *(_DWORD *)(this + 23920) = -1;
}
