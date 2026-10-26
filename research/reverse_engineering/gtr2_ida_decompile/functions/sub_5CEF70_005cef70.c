char __thiscall sub_5CEF70(int this, int a2, int a3, int a4, int a5)
{
  int v6; // esi
  int v7; // edx
  double v8; // st7
  double v9; // st7
  double v10; // st6
  void *v11; // eax
  int v12; // ecx
  double v13; // st7
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  int v24; // esi
  void (__thiscall ***v26)(_DWORD, int, _DWORD, _DWORD); // [esp+8h] [ebp-98h]
  int v27; // [esp+Ch] [ebp-94h]
  void **v28; // [esp+14h] [ebp-8Ch]
  int v29; // [esp+18h] [ebp-88h]
  void (__thiscall ***v30)(_DWORD, int, _DWORD, int); // [esp+1Ch] [ebp-84h]
  void *v31; // [esp+34h] [ebp-6Ch] BYREF
  _DWORD v32[22]; // [esp+38h] [ebp-68h] BYREF
  char v33; // [esp+90h] [ebp-10h]
  int v34; // [esp+94h] [ebp-Ch]

  v32[0] = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)a2 + 4))(a2, this + 20);
    if ( *(_BYTE *)(this + 12) )
    {
      sub_643E40("- Node name = '%s'", (const char *)(this + 20));
      if ( *(_BYTE *)(this + 12) )
      {
        sub_643E40("    + Parent = '%s'", (const char *)(this + 60));
        if ( *(_BYTE *)(this + 12) )
        {
          sub_643E40(
            "    + Position:    x=%f, y=%f, z=%f",
            *(float *)(this + 100),
            *(float *)(this + 104),
            *(float *)(this + 108));
          if ( *(_BYTE *)(this + 12) )
          {
            sub_643E40(
              "    + Orientation: x=%f, y=%f, z=%f, w=%f",
              *(float *)(this + 112),
              *(float *)(this + 116),
              *(float *)(this + 120),
              *(float *)(this + 124));
            if ( *(_BYTE *)(this + 12) )
            {
              sub_643E40(
                "    + Scale:       x=%f, y=%f, z=%f",
                *(float *)(this + 128),
                *(float *)(this + 132),
                *(float *)(this + 136));
              if ( *(_BYTE *)(this + 12) )
                sub_643E40(
                  "    + Inverse Matrix: %f, \t%f, \t%f, \t%f",
                  *(float *)(this + 140),
                  *(float *)(this + 144),
                  *(float *)(this + 148),
                  *(float *)(this + 152));
            }
          }
        }
      }
    }
    if ( *(_BYTE *)(this + 12) )
      sub_643E40(
        "                      %f, \t%f, \t%f, \t%f",
        *(float *)(this + 156),
        *(float *)(this + 160),
        *(float *)(this + 164),
        *(float *)(this + 168));
    if ( *(_BYTE *)(this + 12) )
    {
      sub_643E40(
        "                      %f, \t%f, \t%f, \t%f",
        *(float *)(this + 172),
        *(float *)(this + 176),
        *(float *)(this + 180),
        *(float *)(this + 184));
      if ( *(_BYTE *)(this + 12) )
        sub_643E40(
          "                      %f, \t%f, \t%f, \t%f",
          *(float *)(this + 188),
          *(float *)(this + 192),
          *(float *)(this + 196),
          *(float *)(this + 200));
    }
    v31 = operator new(0x198u);
    v34 = 0;
    if ( v31 )
    {
      sub_4050C0(this + 20);
      v29 = a3;
      v28 = &v31;
      v33 = 1;
      v6 = sub_5C0780();
    }
    else
    {
      v6 = 0;
    }
    v32[20] = -1;
    sub_5C7280();
    v7 = *(_DWORD *)(this + 108);
    v8 = *(float *)(this + 104);
    *(float *)(v6 + 228) = *(float *)(this + 100);
    *(_DWORD *)(v6 + 236) = v7;
    *(float *)(v6 + 232) = v8;
    v9 = *(float *)(this + 128);
    v10 = *(float *)(this + 132);
    *(_DWORD *)(v6 + 248) = *(_DWORD *)(this + 136);
    *(float *)(v6 + 240) = v9;
    *(float *)(v6 + 244) = v10;
    v11 = *(void **)(this + 124);
    v13 = *(float *)(this + 116);
    v12 = *(_DWORD *)(this + 120);
    *(float *)(v6 + 212) = *(float *)(this + 112);
    *(_DWORD *)(v6 + 220) = v12;
    *(float *)(v6 + 216) = v13;
    v31 = v11;
    *(_DWORD *)(v6 + 224) = v11;
    sub_5C00F0(v6, v6, v28, v29);
    *(_DWORD *)(v6 + 264) = *(_DWORD *)(v6 + 228);
    *(_DWORD *)(v6 + 268) = *(_DWORD *)(v6 + 232);
    *(_DWORD *)(v6 + 272) = *(_DWORD *)(v6 + 236);
    *(_DWORD *)(v6 + 196) = *(_DWORD *)(v6 + 212);
    *(_DWORD *)(v6 + 200) = *(_DWORD *)(v6 + 216);
    *(_DWORD *)(v6 + 204) = *(_DWORD *)(v6 + 220);
    *(_DWORD *)(v6 + 208) = *(_DWORD *)(v6 + 224);
    *(_DWORD *)(v6 + 276) = *(_DWORD *)(v6 + 240);
    *(_DWORD *)(v6 + 280) = *(_DWORD *)(v6 + 244);
    *(_DWORD *)(v6 + 284) = *(_DWORD *)(v6 + 248);
    v14 = *(_DWORD *)(this + 144);
    v15 = *(_DWORD *)(this + 148);
    v32[0] = *(_DWORD *)(this + 140);
    v16 = *(_DWORD *)(this + 156);
    v32[1] = v14;
    v17 = *(_DWORD *)(this + 160);
    v32[2] = v15;
    v18 = *(_DWORD *)(this + 164);
    v32[4] = v16;
    v19 = *(_DWORD *)(this + 172);
    v32[5] = v17;
    v20 = *(_DWORD *)(this + 176);
    v32[6] = v18;
    v21 = *(_DWORD *)(this + 180);
    v32[8] = v19;
    v22 = *(_DWORD *)(this + 188);
    v32[9] = v20;
    v23 = *(_DWORD *)(this + 192);
    v32[3] = 0;
    v32[7] = 0;
    v32[11] = 0;
    v32[15] = 1065353216;
    v32[10] = v21;
    v32[12] = v22;
    v32[14] = *(_DWORD *)(this + 196);
    v32[13] = v23;
    qmemcpy((void *)(v6 + 132), v32, 0x40u);
    if ( *(_BYTE *)(this + 60) )
    {
      v27 = this + 60;
      v26 = v30;
      sub_5CC900();
    }
    v24 = sub_5BE270(*(_DWORD **)(this + 16), 1);
    if ( v24 )
    {
      sub_5BD430();
      *(_DWORD *)(v24 + 28) = v30;
      return 1;
    }
    (**v30)(v30, 1, v26, v27);
    if ( *(_BYTE *)(this + 12) )
      sub_643E40((const char *)0xB8);
  }
  else if ( *(_BYTE *)(this + 12) )
  {
    sub_643E40("Passed actor seems to be not valid!");
  }
  return 0;
}
