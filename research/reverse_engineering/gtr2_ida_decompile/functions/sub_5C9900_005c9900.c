char __thiscall sub_5C9900(int this, int a2, int a3, void *a4, int a5)
{
  unsigned int v5; // kr00_4
  char v7; // al
  int v8; // esi
  int v9; // edi
  void *v10; // edi
  int v11; // edi
  int v12; // edx
  double v13; // st7
  double v14; // st7
  int v15; // ecx
  double v16; // st6
  int v17; // eax
  int v18; // ecx
  double v19; // st6
  double v20; // st7
  int v21; // eax
  int v23; // [esp+1Ch] [ebp-94h]
  int v24; // [esp+24h] [ebp-8Ch]
  int v25; // [esp+24h] [ebp-8Ch]
  _DWORD v26[2]; // [esp+38h] [ebp-78h] BYREF
  int v27; // [esp+40h] [ebp-70h] BYREF
  int v28; // [esp+48h] [ebp-68h]
  int v29; // [esp+4Ch] [ebp-64h]
  _BYTE v30[16]; // [esp+50h] [ebp-60h] BYREF
  _BYTE v31[16]; // [esp+60h] [ebp-50h] BYREF
  int v32; // [esp+ACh] [ebp-4h]

  v26[0] = 0;
  v7 = *(_BYTE *)(this + 12);
  if ( a4 )
  {
    if ( v7 )
      sub_643E40("- Motion Part:");
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 4))(a2, this + 20, 80);
    if ( *(_BYTE *)(this + 12) )
    {
      sub_643E40("    + Name = '%s'", (const char *)(this + 20));
      if ( *(_BYTE *)(this + 12) )
      {
        sub_643E40(
          "    + Pose Position: x=%f, y=%f, z=%f",
          *(float *)(this + 60),
          *(float *)(this + 64),
          *(float *)(this + 68));
        if ( *(_BYTE *)(this + 12) )
        {
          sub_643E40(
            "    + Pose Rotation: x=%f, y=%f, z=%f, w=%f",
            *(float *)(this + 72),
            *(float *)(this + 76),
            *(float *)(this + 80),
            *(float *)(this + 84));
          if ( *(_BYTE *)(this + 12) )
            sub_643E40(
              "    + Pose Scale:    x=%f, y=%f, z=%f",
              *(float *)(this + 88),
              *(float *)(this + 92),
              *(float *)(this + 96));
        }
      }
    }
    v10 = operator new(0x98u);
    v26[1] = v10;
    v32 = 6;
    if ( v10 )
    {
      sub_4050C0(this + 20);
      LOBYTE(v32) = 7;
      v26[0] = 1;
      v11 = sub_5D3270(v10, v30);
    }
    else
    {
      v11 = 0;
    }
    v32 = -1;
    if ( (v26[0] & 1) != 0 )
      sub_5A8840();
    v12 = *(_DWORD *)(this + 68);
    v13 = *(float *)(this + 64);
    *(float *)(v11 + 128) = *(float *)(this + 60);
    *(_DWORD *)(v11 + 136) = v12;
    v28 = v12;
    *(float *)(v11 + 132) = v13;
    v14 = *(float *)(this + 88);
    v15 = *(_DWORD *)(this + 96);
    v16 = *(float *)(this + 92);
    *(_DWORD *)(v11 + 148) = v15;
    v28 = v15;
    *(float *)(v11 + 140) = v14;
    *(float *)(v11 + 144) = v16;
    v17 = *(_DWORD *)(this + 84);
    v19 = *(float *)(this + 72);
    v20 = *(float *)(this + 76);
    v28 = *(_DWORD *)(this + 80);
    v18 = v28;
    *(float *)(v11 + 112) = v19;
    *(_DWORD *)(v11 + 120) = v18;
    *(float *)(v11 + 116) = v20;
    v29 = v17;
    *(_DWORD *)(v11 + 124) = v17;
    if ( (*(int (__thiscall **)(void *))(*(_DWORD *)a4 + 4))(a4) == 1 )
      sub_5C7220(a4, v11);
    v21 = sub_5BE270(*(_DWORD **)(this + 16), 2);
    if ( v21 )
    {
      *(_DWORD *)(v21 + 4) = v11;
      return 1;
    }
    if ( v11 )
    {
      sub_5D3300(v11);
      j__free((void *)v11);
    }
    if ( *(_BYTE *)(this + 12) )
      sub_643E40("Can't find shared data.");
  }
  else if ( v7 )
  {
    v26[0] = 2;
    sub_4050C0((int)"Passed motion seems to be not valid!");
    v5 = __readeflags();
    __writeeflags(v5);
    v24 = *((_DWORD *)off_16C6E20 - 500587);
    v32 = 3;
    v8 = sub_4050C0(v24);
    v9 = sub_4050C0((int)"::");
    sub_4050C0((int)"MotionPartChunkProcessor1");
    sub_5BE180(v8, (int)v31, v9);
    LOBYTE(v32) = 4;
    v25 = sub_5BE180(v8, (int)v30, v8);
    LOBYTE(v32) = 5;
    sub_5C6150((__int32)v26, (int)&v27);
    sub_643D50(v23, v26, v25);
    LOBYTE(v32) = 4;
    sub_5A8840();
    LOBYTE(v32) = 3;
    sub_5A8840();
    LOBYTE(v32) = 2;
    sub_5A8840();
    LOBYTE(v32) = 1;
    sub_5A8840();
    LOBYTE(v32) = 0;
    sub_5A8840();
    v32 = -1;
    sub_5A8840();
  }
  return 0;
}
