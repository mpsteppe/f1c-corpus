int __thiscall sub_4A2A90(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  int v5; // esi
  int v7; // eax
  int v8; // edi
  _DWORD *v9; // eax
  _DWORD *v10; // ebp
  int v11; // edi
  _DWORD *v12; // esi
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // esi
  int v16; // ebp
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // edx
  double v21; // st7
  int v22; // ecx
  int v23; // eax
  int v24; // esi
  int v25; // edi
  double v26; // [esp-Ch] [ebp-6F8h]
  double v27; // [esp-4h] [ebp-6F0h]
  double v28; // [esp+4h] [ebp-6E8h]
  int v30; // [esp+14h] [ebp-6D8h]
  int v31; // [esp+18h] [ebp-6D4h] BYREF
  int v32; // [esp+1Ch] [ebp-6D0h] BYREF
  int v33; // [esp+20h] [ebp-6CCh] BYREF
  int v34; // [esp+24h] [ebp-6C8h] BYREF
  int v35; // [esp+28h] [ebp-6C4h]
  float v36; // [esp+2Ch] [ebp-6C0h] BYREF
  int v37; // [esp+30h] [ebp-6BCh]
  __int16 v38; // [esp+34h] [ebp-6B8h] BYREF
  int v39; // [esp+38h] [ebp-6B4h]
  char v40[64]; // [esp+3Ch] [ebp-6B0h] BYREF
  _BYTE v41[12]; // [esp+7Ch] [ebp-670h] BYREF
  _BYTE v42[12]; // [esp+88h] [ebp-664h] BYREF
  char v43[64]; // [esp+94h] [ebp-658h] BYREF
  char v44[256]; // [esp+D4h] [ebp-618h] BYREF
  _BYTE v45[384]; // [esp+1D4h] [ebp-518h] BYREF
  int v46; // [esp+354h] [ebp-398h]
  char v47; // [esp+358h] [ebp-394h]
  int v48; // [esp+360h] [ebp-38Ch]
  int v49; // [esp+364h] [ebp-388h]
  int v50; // [esp+368h] [ebp-384h]
  _BYTE v51[384]; // [esp+36Ch] [ebp-380h] BYREF
  char v52[256]; // [esp+4ECh] [ebp-200h] BYREF
  char v53[256]; // [esp+5ECh] [ebp-100h] BYREF

  v4 = this;
  memset(v51, 0, sizeof(v51));
  v46 = 0;
  v50 = 0;
  v48 = 0;
  v49 = 0;
  v47 = 1;
  v5 = sub_587DB0(a2, aRt);
  v30 = v5;
  if ( !v5 )
    return -1;
  v39 = dword_8AFE88;
  if ( sub_5450E0(v4 + 5, a4, aFuelrigMts, 20) )
    return -1;
  if ( dword_7CF884 >= 2 )
  {
    v7 = sub_54C230(0);
    if ( v7 )
      sub_545930(v7, 0);
  }
  v8 = 0;
  while ( sub_587CA0(v51, 384, v5) )
  {
    if ( !sub_5651B0(v45) && sub_587C20(v51, aActor) )
      ++v8;
  }
  sub_587F64(v5, 0, 0);
  v9 = (_DWORD *)sub_587C03(120 * v8 + 4);
  if ( v9 )
  {
    *v9 = v8;
    v10 = v9 + 1;
    v11 = v8 - 1;
    v12 = v9 + 1;
    if ( v11 >= 0 )
    {
      v13 = v11 + 1;
      do
      {
        v12[25] = 0;
        v12[27] = 0;
        v12[29] = 0;
        sub_4A2220(v12);
        v12 += 30;
        --v13;
      }
      while ( v13 );
    }
    v14 = v10;
  }
  else
  {
    v14 = 0;
  }
  v15 = v30;
  v4[4] = v14;
  v16 = 0;
  v4[3] = 0;
  if ( sub_587CA0(v51, 384, v30) )
  {
    do
    {
      if ( !sub_5651B0(v45) )
      {
        if ( sub_587C20(v51, aActor) )
        {
          v16 = this[4] + 120 * this[3]++;
          sub_5887ED(v51, "ACTOR %s", v44);
          sub_4A2A40(v44, v40);
          *(_BYTE *)(v16 + 3) = !strcmp(v40, aLman) || !strcmp(v40, aLollipop);
        }
        if ( sub_587C20(v51, aDetail) )
        {
          sub_5887ED(v51, "DETAIL %d", &v38);
          *(_WORD *)v16 = v38;
        }
        if ( sub_587C20(v51, aMesh) )
        {
          sub_5887ED(v51, "MESH %s", v44);
          sub_4A2A40(v44, v43);
          if ( !strcmp(v43, aLfwheeloffMts) )
          {
            sub_4A2770(v16, 0, 0, v40, *(_DWORD *)(a3 + 4), this[5]);
          }
          else if ( !strcmp(v43, aLfwheelonMts) )
          {
            sub_4A2770(v16, 1, 0, v40, *(_DWORD *)(a3 + 4), this[5]);
          }
          else if ( !strcmp(v43, aRfwheeloffMts) )
          {
            sub_4A2770(v16, 0, 1, v40, *(_DWORD *)(a3 + 4), this[5]);
          }
          else if ( !strcmp(v43, aRfwheelonMts) )
          {
            sub_4A2770(v16, 1, 1, v40, *(_DWORD *)(a3 + 4), this[5]);
          }
          else if ( !strcmp(v43, aLrwheeloffMts) )
          {
            sub_4A2770(v16, 0, 2, v40, *(_DWORD *)(a3 + 8), this[5]);
          }
          else if ( !strcmp(v43, aLrwheelonMts) )
          {
            sub_4A2770(v16, 1, 2, v40, *(_DWORD *)(a3 + 8), this[5]);
          }
          else if ( !strcmp(v43, aRrwheeloffMts) )
          {
            sub_4A2770(v16, 0, 3, v40, *(_DWORD *)(a3 + 8), this[5]);
          }
          else if ( !strcmp(v43, aRrwheelonMts) )
          {
            sub_4A2770(v16, 1, 3, v40, *(_DWORD *)(a3 + 8), this[5]);
          }
          else
          {
            sub_4A21D0((__int16 *)v16, v40, v43, this[5], 0);
          }
        }
        if ( sub_587C20(v51, aPosition) )
        {
          LODWORD(v27) = &v33;
          HIDWORD(v26) = &v32;
          LODWORD(v26) = &v31;
          v31 = 0;
          v32 = 0;
          v33 = 0;
          sub_5887ED(v51, "POSITION %f %f %f", v26, v27, v28);
          v17 = v32;
          *(_DWORD *)(v16 + 76) = v31;
          v18 = v33;
          *(_DWORD *)(v16 + 80) = v17;
          *(_DWORD *)(v16 + 84) = v18;
        }
        if ( sub_587C20(v51, aMove) )
        {
          LODWORD(v27) = &v34;
          v34 = 0;
          sub_5887ED(v51, "MOVE %s %s %f", v44, v53, v27);
          sub_4A2A40(v44, v52);
          sub_58815F(v44, "%s.ANM", v52);
          sub_4A22D0((_DWORD *)v16, (int)v52, (int)v44, v53, v34);
        }
        v19 = sub_587C20(v51, aRotate);
        v50 = v19;
        if ( v19 )
        {
          v35 = *(_DWORD *)(v16 + 88);
          v20 = *(_DWORD *)(v16 + 96);
          v36 = *(float *)(v16 + 92);
          LODWORD(v27) = &v36;
          v37 = v20;
          sub_5887ED(v19, "ROTATE %f", v27);
          v21 = v36 * 0.01745433;
          v22 = v37;
          *(_DWORD *)(v16 + 88) = v35;
          v36 = v21;
          *(float *)(v16 + 92) = v36;
          *(_DWORD *)(v16 + 96) = v22;
        }
      }
      v15 = v30;
    }
    while ( sub_587CA0(v51, 384, v30) );
    v4 = this;
  }
  sub_587D02(v15);
  sub_545250(v4[5]);
  if ( sub_543FA0(dword_8AFE88) )
  {
    sub_53C5B0(0, v52);
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_2, 708) )
      sub_4D7AA0(&unk_8AD25C, aUnableToSetupA);
  }
  v23 = sub_54C230(0);
  if ( v23 )
    *(float *)(v23 + 24) = *(float *)(v23 + 24) * 4.0;
  sub_4D1100(dword_7C54E8, v42, v41);
  sub_4A3320(v42, v41);
  sub_54C030(1, 0, 0, 0);
  *v4 = 1;
  sub_4A3440(v4);
  v24 = 0;
  if ( (int)v4[3] > 0 )
  {
    v25 = 0;
    do
    {
      sub_4A27D0(v25 + v4[4]);
      ++v24;
      v25 += 120;
    }
    while ( v24 < v4[3] );
  }
  return 0;
}
