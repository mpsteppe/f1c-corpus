void __thiscall sub_4537B0(int this, float a2)
{
  double v3; // st7
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

  sub_44F150((_DWORD *)(this + 4), a2);
  if ( (*(_BYTE *)(this + 4480) & 1) != 0 )
  {
    D3DShaderConstantSetup(this + 3464);
    v3 = *(float *)(this + 4416);
    if ( v3 <= flt_7CA498 )
      v3 = 0.0;
    flt_7CA494 = v3;
    v4 = *(float *)(this + 4416);
    if ( v4 >= flt_7CCA50 )
      v4 = 0.0;
    flt_7CCA48 = v4;
    v5 = *(float *)(this + 4420);
    if ( v5 <= flt_7CA3F0 )
      v5 = 0.0;
    flt_7CA3EC = v5;
    v6 = *(float *)(this + 4420);
    if ( v6 >= flt_7CA47C )
      v6 = 0.0;
    flt_7CA474 = v6;
    v7 = *(float *)(this + 4424);
    if ( v7 <= flt_7CD1A0 )
      v7 = 0.0;
    flt_7CD19C = v7;
    v8 = *(float *)(this + 4424);
    if ( v8 >= flt_7CA3D4 )
      v8 = 0.0;
    flt_7CA3CC = v8;
    v9 = *(float *)(this + 4428);
    if ( v9 <= flt_7CCBB8 )
      v9 = 0.0;
    flt_7CCBB4 = v9;
    v10 = *(float *)(this + 4428);
    if ( v10 >= flt_7CCFBC )
      v10 = 0.0;
    flt_7CCFB4 = v10;
    v11 = *(float *)(this + 4432);
    if ( v11 <= flt_7CCA74 )
      v11 = 0.0;
    flt_7CCA70 = v11;
    v12 = *(float *)(this + 4432);
    if ( v12 >= flt_7CCF8C )
      v12 = 0.0;
    flt_7CCF84 = v12;
    v13 = *(float *)(this + 4436);
    if ( v13 <= flt_7CCCB8 )
      v13 = 0.0;
    flt_7CCCB4 = v13;
    v14 = *(float *)(this + 4436);
    if ( v14 >= flt_7CCA88 )
      v14 = 0.0;
    flt_7CCA80 = v14;
    v15 = *(float *)(this + 4440);
    if ( v15 <= flt_7CD150 )
      v15 = 0.0;
    flt_7CD14C = v15;
    v16 = *(float *)(this + 4440);
    if ( v16 >= flt_7CCFE8 )
      v16 = 0.0;
    flt_7CCFE0 = v16;
    v17 = *(float *)(this + 4444);
    if ( v17 <= flt_7CD110 )
      v17 = 0.0;
    flt_7CD10C = v17;
    v18 = *(float *)(this + 4444);
    if ( v18 >= flt_7CD194 )
      v18 = 0.0;
    flt_7CD18C = v18;
    ConditionalFieldSetterWithState(&dword_7CCD50, *(unsigned __int8 *)(this + 4448));
    ConditionalFieldSetterWithState(&dword_7CCD38, *(unsigned __int8 *)(this + 4449));
    ConditionalFieldSetterWithState(&dword_7CCCF0, *(unsigned __int8 *)(this + 4450));
    ConditionalFieldSetterWithState(&dword_7CCCD8, *(unsigned __int8 *)(this + 4451));
    ConditionalFieldSetterWithState(&dword_7CCD20, *(unsigned __int8 *)(this + 4452));
    ConditionalFieldSetterWithState(&dword_7CCD08, *(unsigned __int8 *)(this + 4453));
    ConditionalFieldSetterWithState(dword_7CCC80, *(unsigned __int8 *)(this + 4454));
    ConditionalFieldSetterWithState(&dword_7CCC68, *(unsigned __int8 *)(this + 4455));
    ConditionalFieldSetterWithState(dword_7CCCC0, *(unsigned __int8 *)(this + 4456));
    ConditionalFieldSetterWithState(dword_7CCC98, *(unsigned __int8 *)(this + 4457));
    ConditionalFieldSetterWithState(dword_7CCC20, *(unsigned __int8 *)(this + 4458));
    ConditionalFieldSetterWithState(&dword_7CCC08, *(unsigned __int8 *)(this + 4459));
    ConditionalFieldSetterWithState(dword_7CCC50, *(unsigned __int8 *)(this + 4460));
    ConditionalFieldSetterWithState(dword_7CCC38, *(unsigned __int8 *)(this + 4461));
    ConditionalFieldSetterWithState(dword_7CCDE0, *(unsigned __int8 *)(this + 4462));
    ConditionalFieldSetterWithState(&dword_7CCDC8, *(unsigned __int8 *)(this + 4463));
    if ( *(char *)(this + 4480) < 0 )
    {
      dword_7CD1B8 = *(_DWORD *)(this + 4464) == dword_7CD1BC;
      dword_7CD1D0 = *(_DWORD *)(this + 4464) == dword_7CD1D4;
      dword_7CCF58 = *(_DWORD *)(this + 4464) == dword_7CCF5C;
      dword_7CD1E8 = *(_DWORD *)(this + 4464) == dword_7CD1EC;
      if ( (*(_DWORD *)(this + 4480) & 0x100) != 0 )
      {
        dword_7CD0A8 = *(_DWORD *)(this + 4468) == dword_7CD0AC;
        dword_7CD0C0 = *(_DWORD *)(this + 4468) == dword_7CD0C4;
        dword_7CD128 = *(_DWORD *)(this + 4468) == dword_7CD12C;
        dword_7CD140 = *(_DWORD *)(this + 4468) == dword_7CD144;
        if ( (*(_DWORD *)(this + 4480) & 0x200) != 0 )
        {
          dword_7CD014 = *(_DWORD *)(this + 4472) == dword_7CD018;
          dword_7CD044 = *(_DWORD *)(this + 4472) == dword_7CD048;
          dword_7CD0D8 = *(_DWORD *)(this + 4472) == dword_7CD0DC;
          dword_7CD0F0 = *(_DWORD *)(this + 4472) == dword_7CD0F4;
          if ( (*(_DWORD *)(this + 4480) & 0x400) != 0 )
          {
            dword_7CCA0C = *(_DWORD *)(this + 4476) == dword_7CCA10;
            dword_7CCA3C = *(_DWORD *)(this + 4476) == dword_7CCA40;
            dword_7CD05C = *(_DWORD *)(this + 4476) == dword_7CD060;
            dword_7CD074 = *(_DWORD *)(this + 4476) == dword_7CD078;
          }
        }
      }
    }
  }
  if ( (*(_BYTE *)(this + 5500) & 1) != 0 )
  {
    D3DShaderConstantSetup(this + 4484);
    v19 = *(float *)(this + 5436);
    if ( v19 <= flt_7CA3C0[0] )
      v19 = 0.0;
    flt_7CA3BC = v19;
    v20 = *(float *)(this + 5436);
    if ( v20 >= flt_7CC9C8 )
      v20 = 0.0;
    flt_7CC9C0 = v20;
    v21 = *(float *)(this + 5440);
    if ( v21 <= flt_7CD160 )
      v21 = 0.0;
    flt_7CD15C = v21;
    v22 = *(float *)(this + 5440);
    if ( v22 >= flt_7CA518 )
      v22 = 0.0;
    flt_7CA510 = v22;
    v23 = *(float *)(this + 5444);
    if ( v23 <= flt_7CD100 )
      v23 = 0.0;
    flt_7CD0FC = v23;
    v24 = *(float *)(this + 5444);
    if ( v24 >= flt_7CA444 )
      v24 = 0.0;
    flt_7CA43C = v24;
    v25 = *(float *)(this + 5448);
    if ( v25 <= flt_7CA450 )
      v25 = 0.0;
    flt_7CA44C = v25;
    v26 = *(float *)(this + 5448);
    if ( v26 >= flt_7CCC00 )
      v26 = 0.0;
    flt_7CCBF8 = v26;
    v27 = *(float *)(this + 5452);
    if ( v27 <= flt_7CA3B0 )
      v27 = 0.0;
    flt_7CA3AC = v27;
    v28 = *(float *)(this + 5452);
    if ( v28 >= flt_7CA48C )
      v28 = 0.0;
    flt_7CA484 = v28;
    v29 = *(float *)(this + 5456);
    if ( v29 <= flt_7CC9F4 )
      v29 = 0.0;
    flt_7CC9F0 = v29;
    v30 = *(float *)(this + 5456);
    if ( v30 >= flt_7CA3E4 )
      v30 = 0.0;
    flt_7CA3DC = v30;
    v31 = *(float *)(this + 5460);
    if ( v31 <= flt_7CCF98 )
      v31 = 0.0;
    flt_7CCF94 = v31;
    v32 = *(float *)(this + 5460);
    if ( v32 >= flt_7CCF6C )
      v32 = 0.0;
    flt_7CCF64 = v32;
    v33 = *(float *)(this + 5464);
    if ( v33 <= flt_7CCF78 )
      v33 = 0.0;
    flt_7CCF74 = v33;
    v34 = *(float *)(this + 5464);
    if ( v34 >= flt_7CCFAC )
      v34 = 0.0;
    flt_7CCFA4 = v34;
    ConditionalFieldSetterWithState(dword_7CCF30, *(unsigned __int8 *)(this + 5468));
    ConditionalFieldSetterWithState(dword_7CCF18, *(unsigned __int8 *)(this + 5469));
    ConditionalFieldSetterWithState(dword_7CCED0, *(unsigned __int8 *)(this + 5470));
    ConditionalFieldSetterWithState(dword_7CCEB8, *(unsigned __int8 *)(this + 5471));
    ConditionalFieldSetterWithState(dword_7CCF00, *(unsigned __int8 *)(this + 5472));
    ConditionalFieldSetterWithState(&dword_7CCEE8, *(unsigned __int8 *)(this + 5473));
    ConditionalFieldSetterWithState(dword_7CCE70, *(unsigned __int8 *)(this + 5474));
    ConditionalFieldSetterWithState(dword_7CCE58, *(unsigned __int8 *)(this + 5475));
    ConditionalFieldSetterWithState(dword_7CCEA0, *(unsigned __int8 *)(this + 5476));
    ConditionalFieldSetterWithState(&dword_7CCE88, *(unsigned __int8 *)(this + 5477));
    ConditionalFieldSetterWithState(dword_7CCE10, *(unsigned __int8 *)(this + 5478));
    ConditionalFieldSetterWithState(dword_7CCDF8, *(unsigned __int8 *)(this + 5479));
    ConditionalFieldSetterWithState(dword_7CCE40, *(unsigned __int8 *)(this + 5480));
    ConditionalFieldSetterWithState(&dword_7CCE28, *(unsigned __int8 *)(this + 5481));
    ConditionalFieldSetterWithState(dword_7CCBDC, *(unsigned __int8 *)(this + 5482));
    ConditionalFieldSetterWithState(dword_7CCBC4, *(unsigned __int8 *)(this + 5483));
    if ( *(char *)(this + 5500) < 0 )
    {
      dword_7CCFD4 = *(_DWORD *)(this + 4464) == dword_7CCFD8;
      dword_7CCFFC = *(_DWORD *)(this + 4464) == dword_7CD000;
      dword_7CD090 = *(_DWORD *)(this + 4464) == dword_7CD094;
      dword_7CD02C = *(_DWORD *)(this + 4464) == dword_7CD030;
      if ( (*(_DWORD *)(this + 5500) & 0x100) != 0 )
      {
        dword_7CA544 = *(_DWORD *)(this + 4468) == dword_7CA548;
        dword_7CA574 = *(_DWORD *)(this + 4468) == dword_7CA578;
        dword_7CCA24 = *(_DWORD *)(this + 4468) == dword_7CCA28;
        dword_7CCA64 = *(_DWORD *)(this + 4468) == dword_7CCA68;
        if ( (*(_DWORD *)(this + 5500) & 0x200) != 0 )
        {
          dword_7CA4C8 = *(_DWORD *)(this + 4472) == dword_7CA4CC;
          dword_7CA4F0 = *(_DWORD *)(this + 4472) == dword_7CA4F4;
          dword_7CA55C = *(_DWORD *)(this + 4472) == dword_7CA560;
          dword_7CA52C = *(_DWORD *)(this + 4472) == dword_7CA530;
          if ( (*(_DWORD *)(this + 5500) & 0x400) != 0 )
          {
            dword_7CA430 = *(_DWORD *)(this + 4476) == dword_7CA434;
            dword_7CA408 = *(_DWORD *)(this + 4476) == dword_7CA40C;
            dword_7CA4B0 = *(_DWORD *)(this + 4476) == dword_7CA4B4;
            dword_7CA468 = *(_DWORD *)(this + 4476) == dword_7CA46C;
          }
        }
      }
    }
  }
}
