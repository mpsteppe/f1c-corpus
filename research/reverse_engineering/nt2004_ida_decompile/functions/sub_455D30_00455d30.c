char __thiscall sub_455D30(int this, float a2)
{
  int v3; // eax
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  double v35; // st7

  LOBYTE(v3) = sub_451680((_DWORD *)(this + 4), a2);
  if ( (*(_BYTE *)(this + 4488) & 1) != 0 )
  {
    sub_452270(this + 3472);
    v4 = *(float *)(this + 4424);
    if ( v4 <= flt_761C80 )
      v4 = 0.0;
    flt_761C7C = v4;
    v5 = *(float *)(this + 4424);
    if ( v5 >= flt_7645B4 )
      v5 = 0.0;
    flt_7645AC = v5;
    v6 = *(float *)(this + 4428);
    if ( v6 <= flt_761BD8 )
      v6 = 0.0;
    flt_761BD4 = v6;
    v7 = *(float *)(this + 4428);
    if ( v7 >= flt_761C64 )
      v7 = 0.0;
    flt_761C5C = v7;
    v8 = *(float *)(this + 4432);
    if ( v8 <= flt_764D00 )
      v8 = 0.0;
    flt_764CFC = v8;
    v9 = *(float *)(this + 4432);
    if ( v9 >= flt_761BBC )
      v9 = 0.0;
    flt_761BB4 = v9;
    v10 = *(float *)(this + 4436);
    if ( v10 <= flt_76471C )
      v10 = 0.0;
    flt_764718 = v10;
    v11 = *(float *)(this + 4436);
    if ( v11 >= flt_764B1C )
      v11 = 0.0;
    flt_764B14 = v11;
    v12 = *(float *)(this + 4440);
    if ( v12 <= flt_7645D8 )
      v12 = 0.0;
    flt_7645D4 = v12;
    v13 = *(float *)(this + 4440);
    if ( v13 >= flt_764AEC )
      v13 = 0.0;
    flt_764AE4 = v13;
    v14 = *(float *)(this + 4444);
    if ( v14 <= flt_764818 )
      v14 = 0.0;
    flt_764814 = v14;
    v15 = *(float *)(this + 4444);
    if ( v15 >= flt_7645EC )
      v15 = 0.0;
    flt_7645E4 = v15;
    v16 = *(float *)(this + 4448);
    if ( v16 <= flt_764CB0 )
      v16 = 0.0;
    flt_764CAC = v16;
    v17 = *(float *)(this + 4448);
    if ( v17 >= flt_764B48 )
      v17 = 0.0;
    flt_764B40 = v17;
    v18 = *(float *)(this + 4452);
    if ( v18 <= flt_764C70 )
      v18 = 0.0;
    flt_764C6C = v18;
    v19 = *(float *)(this + 4452);
    if ( v19 >= flt_764CF4 )
      v19 = 0.0;
    flt_764CEC = v19;
    sub_454CD0(&dword_7648B0, *(unsigned __int8 *)(this + 4456));
    sub_454CD0(&dword_764898, *(unsigned __int8 *)(this + 4457));
    sub_454CD0(&dword_764850, *(unsigned __int8 *)(this + 4458));
    sub_454CD0(dword_764838, *(unsigned __int8 *)(this + 4459));
    sub_454CD0(dword_764880, *(unsigned __int8 *)(this + 4460));
    sub_454CD0(&dword_764868, *(unsigned __int8 *)(this + 4461));
    sub_454CD0(dword_7647E0, *(unsigned __int8 *)(this + 4462));
    sub_454CD0(&dword_7647C8, *(unsigned __int8 *)(this + 4463));
    sub_454CD0(dword_764820, *(unsigned __int8 *)(this + 4464));
    sub_454CD0(dword_7647F8, *(unsigned __int8 *)(this + 4465));
    sub_454CD0(dword_764780, *(unsigned __int8 *)(this + 4466));
    sub_454CD0(&dword_764768, *(unsigned __int8 *)(this + 4467));
    sub_454CD0(dword_7647B0, *(unsigned __int8 *)(this + 4468));
    sub_454CD0(dword_764798, *(unsigned __int8 *)(this + 4469));
    sub_454CD0(dword_764940, *(unsigned __int8 *)(this + 4470));
    sub_454CD0(&dword_764928, *(unsigned __int8 *)(this + 4471));
    LOBYTE(v3) = *(_BYTE *)(this + 4488);
    if ( (v3 & 0x80u) != 0 )
    {
      dword_764D18 = *(_DWORD *)(this + 4472) == dword_764D1C;
      dword_764D30 = *(_DWORD *)(this + 4472) == dword_764D34;
      dword_764AB8 = *(_DWORD *)(this + 4472) == dword_764ABC;
      dword_764D48 = *(_DWORD *)(this + 4472) == dword_764D4C;
      v3 = *(_DWORD *)(this + 4488);
      if ( (v3 & 0x100) != 0 )
      {
        dword_764C08 = *(_DWORD *)(this + 4476) == dword_764C0C;
        dword_764C20 = *(_DWORD *)(this + 4476) == dword_764C24;
        dword_764C88 = *(_DWORD *)(this + 4476) == dword_764C8C;
        dword_764CA0 = *(_DWORD *)(this + 4476) == dword_764CA4;
        v3 = *(_DWORD *)(this + 4488);
        if ( (v3 & 0x200) != 0 )
        {
          dword_764B74 = *(_DWORD *)(this + 4480) == dword_764B78;
          dword_764BA4 = *(_DWORD *)(this + 4480) == dword_764BA8;
          dword_764C38 = *(_DWORD *)(this + 4480) == dword_764C3C;
          dword_764C50 = *(_DWORD *)(this + 4480) == dword_764C54;
          v3 = *(_DWORD *)(this + 4488);
          if ( (v3 & 0x400) != 0 )
          {
            dword_764570 = *(_DWORD *)(this + 4484) == dword_764574;
            dword_7645A0 = *(_DWORD *)(this + 4484) == dword_7645A4;
            dword_764BBC = *(_DWORD *)(this + 4484) == dword_764BC0;
            v3 = *(_DWORD *)(this + 4484);
            dword_764BD4 = v3 == dword_764BD8;
          }
        }
      }
    }
  }
  if ( (*(_BYTE *)(this + 5508) & 1) != 0 )
  {
    sub_452270(this + 4492);
    v20 = *(float *)(this + 5444);
    if ( v20 <= flt_761BA8[0] )
      v20 = 0.0;
    flt_761BA4 = v20;
    v21 = *(float *)(this + 5444);
    if ( v21 >= flt_76452C )
      v21 = 0.0;
    flt_764524 = v21;
    v22 = *(float *)(this + 5448);
    if ( v22 <= flt_764CC0 )
      v22 = 0.0;
    flt_764CBC = v22;
    v23 = *(float *)(this + 5448);
    if ( v23 >= flt_761D00 )
      v23 = 0.0;
    flt_761CF8 = v23;
    v24 = *(float *)(this + 5452);
    if ( v24 <= flt_764C60 )
      v24 = 0.0;
    flt_764C5C = v24;
    v25 = *(float *)(this + 5452);
    if ( v25 >= flt_761C2C )
      v25 = 0.0;
    flt_761C24 = v25;
    v26 = *(float *)(this + 5456);
    if ( v26 <= flt_761C38 )
      v26 = 0.0;
    flt_761C34 = v26;
    v27 = *(float *)(this + 5456);
    if ( v27 >= flt_764764 )
      v27 = 0.0;
    flt_76475C = v27;
    v28 = *(float *)(this + 5460);
    if ( v28 <= flt_761B98 )
      v28 = 0.0;
    flt_761B94 = v28;
    v29 = *(float *)(this + 5460);
    if ( v29 >= flt_761C74 )
      v29 = 0.0;
    flt_761C6C = v29;
    v30 = *(float *)(this + 5464);
    if ( v30 <= flt_764558 )
      v30 = 0.0;
    flt_764554 = v30;
    v31 = *(float *)(this + 5464);
    if ( v31 >= flt_761BCC )
      v31 = 0.0;
    flt_761BC4 = v31;
    v32 = *(float *)(this + 5468);
    if ( v32 <= flt_764AF8 )
      v32 = 0.0;
    flt_764AF4 = v32;
    v33 = *(float *)(this + 5468);
    if ( v33 >= flt_764ACC )
      v33 = 0.0;
    flt_764AC4 = v33;
    v34 = *(float *)(this + 5472);
    if ( v34 <= flt_764AD8 )
      v34 = 0.0;
    flt_764AD4 = v34;
    v35 = *(float *)(this + 5472);
    if ( v35 >= flt_764B0C )
      v35 = 0.0;
    flt_764B04 = v35;
    sub_454CD0(dword_764A90, *(unsigned __int8 *)(this + 5476));
    sub_454CD0(dword_764A78, *(unsigned __int8 *)(this + 5477));
    sub_454CD0(dword_764A30, *(unsigned __int8 *)(this + 5478));
    sub_454CD0(dword_764A18, *(unsigned __int8 *)(this + 5479));
    sub_454CD0(dword_764A60, *(unsigned __int8 *)(this + 5480));
    sub_454CD0(&dword_764A48, *(unsigned __int8 *)(this + 5481));
    sub_454CD0(dword_7649D0, *(unsigned __int8 *)(this + 5482));
    sub_454CD0(dword_7649B8, *(unsigned __int8 *)(this + 5483));
    sub_454CD0(dword_764A00, *(unsigned __int8 *)(this + 5484));
    sub_454CD0(&dword_7649E8, *(unsigned __int8 *)(this + 5485));
    sub_454CD0(dword_764970, *(unsigned __int8 *)(this + 5486));
    sub_454CD0(dword_764958, *(unsigned __int8 *)(this + 5487));
    sub_454CD0(dword_7649A0, *(unsigned __int8 *)(this + 5488));
    sub_454CD0(&dword_764988, *(unsigned __int8 *)(this + 5489));
    sub_454CD0(dword_764740, *(unsigned __int8 *)(this + 5490));
    sub_454CD0(&dword_764728, *(unsigned __int8 *)(this + 5491));
    LOBYTE(v3) = *(_BYTE *)(this + 5508);
    if ( (v3 & 0x80u) != 0 )
    {
      dword_764B34 = *(_DWORD *)(this + 4472) == dword_764B38;
      dword_764B5C = *(_DWORD *)(this + 4472) == dword_764B60;
      dword_764BF0 = *(_DWORD *)(this + 4472) == dword_764BF4;
      dword_764B8C = *(_DWORD *)(this + 4472) == dword_764B90;
      v3 = *(_DWORD *)(this + 5508);
      if ( (v3 & 0x100) != 0 )
      {
        dword_761D2C = *(_DWORD *)(this + 4476) == dword_761D30;
        dword_761D5C = *(_DWORD *)(this + 4476) == dword_761D60;
        dword_764588 = *(_DWORD *)(this + 4476) == dword_76458C;
        dword_7645C8 = *(_DWORD *)(this + 4476) == dword_7645CC;
        v3 = *(_DWORD *)(this + 5508);
        if ( (v3 & 0x200) != 0 )
        {
          dword_761CB0 = *(_DWORD *)(this + 4480) == dword_761CB4;
          dword_761CD8 = *(_DWORD *)(this + 4480) == dword_761CDC;
          dword_761D44 = *(_DWORD *)(this + 4480) == dword_761D48;
          dword_761D14 = *(_DWORD *)(this + 4480) == dword_761D18;
          v3 = *(_DWORD *)(this + 5508);
          if ( (v3 & 0x400) != 0 )
          {
            dword_761C18 = *(_DWORD *)(this + 4484) == dword_761C1C;
            dword_761BF0 = *(_DWORD *)(this + 4484) == dword_761BF4;
            dword_761C98 = *(_DWORD *)(this + 4484) == dword_761C9C;
            v3 = *(_DWORD *)(this + 4484);
            dword_761C50 = v3 == dword_761C54;
          }
        }
      }
    }
  }
  return v3;
}
