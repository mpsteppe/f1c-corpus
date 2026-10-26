char __thiscall sub_5CCE20(int this, int a2, int a3, void *a4, int a5)
{
  int v6; // esi
  int v7; // edi
  char v8; // al
  void *v9; // eax
  int v10; // esi
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st6
  float v15; // edx
  float v16; // eax
  double v17; // st7
  int v18; // eax
  int v20; // [esp+1Ch] [ebp-ECh]
  int v21; // [esp+24h] [ebp-E4h]
  int v22; // [esp+24h] [ebp-E4h]
  void *Block; // [esp+34h] [ebp-D4h] BYREF
  float v24; // [esp+38h] [ebp-D0h] BYREF
  float v25; // [esp+3Ch] [ebp-CCh]
  float v26; // [esp+40h] [ebp-C8h]
  float v27; // [esp+44h] [ebp-C4h]
  float v28; // [esp+48h] [ebp-C0h]
  float v29; // [esp+4Ch] [ebp-BCh]
  float v30; // [esp+50h] [ebp-B8h]
  float v31; // [esp+54h] [ebp-B4h]
  float v32; // [esp+58h] [ebp-B0h]
  float v33; // [esp+5Ch] [ebp-ACh]
  float v34; // [esp+60h] [ebp-A8h]
  float v35; // [esp+64h] [ebp-A4h]
  float v36; // [esp+68h] [ebp-A0h]
  float v37; // [esp+6Ch] [ebp-9Ch]
  float v38; // [esp+70h] [ebp-98h]
  float v39; // [esp+74h] [ebp-94h]
  float v40; // [esp+78h] [ebp-90h]
  float v41; // [esp+7Ch] [ebp-8Ch]
  float v42; // [esp+80h] [ebp-88h]
  float v43; // [esp+84h] [ebp-84h]
  _BYTE v44[4]; // [esp+88h] [ebp-80h] BYREF
  const char *v45; // [esp+8Ch] [ebp-7Ch]
  float v46; // [esp+A4h] [ebp-64h]
  _BYTE v47[16]; // [esp+A8h] [ebp-60h] BYREF
  _BYTE v48[16]; // [esp+B8h] [ebp-50h] BYREF
  _BYTE v49[16]; // [esp+C8h] [ebp-40h] BYREF
  int v50; // [esp+104h] [ebp-4h]

  if ( a4 )
  {
    (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &v24, 80);
    sub_5BE610((int)v44, a2);
    v8 = *(_BYTE *)(this + 12);
    v50 = 6;
    if ( v8 )
    {
      sub_643E40("- Motion Part='%s'", v45);
      if ( *(_BYTE *)(this + 12) )
      {
        sub_643E40("    + Pose Position: x=%f, y=%f, z=%f", v24, v25, v26);
        if ( *(_BYTE *)(this + 12) )
        {
          sub_643E40("    + Pose Rotation: x=%f, y=%f, z=%f, w=%f", v27, v28, v29, v30);
          if ( *(_BYTE *)(this + 12) )
          {
            sub_643E40("    + Pose Scale:    x=%f, y=%f, z=%f", v31, v32, v33);
            if ( *(_BYTE *)(this + 12) )
            {
              sub_643E40("    + Bind Pose Position: x=%f, y=%f, z=%f", v34, v35, v36);
              if ( *(_BYTE *)(this + 12) )
              {
                sub_643E40("    + Bind Pose Rotation: x=%f, y=%f, z=%f, w=%f", v37, v38, v39, v40);
                if ( *(_BYTE *)(this + 12) )
                  sub_643E40("    + Bind Pose Scale:    x=%f, y=%f, z=%f", v41, v42, v43);
              }
            }
          }
        }
      }
    }
    v9 = operator new(0x98u);
    Block = v9;
    LOBYTE(v50) = 7;
    if ( v9 )
      v10 = sub_5D3270(v9, v44);
    else
      v10 = 0;
    v11 = v25;
    v12 = v26;
    *(float *)(v10 + 128) = v24;
    LOBYTE(v50) = 6;
    *(float *)(v10 + 132) = v11;
    *(float *)(v10 + 136) = v12;
    v13 = v32;
    v14 = v33;
    *(float *)(v10 + 140) = v31;
    *(float *)(v10 + 144) = v13;
    *(float *)(v10 + 148) = v14;
    v15 = v27;
    v16 = v30;
    v17 = v29;
    v46 = v30;
    *(float *)(v10 + 116) = v28;
    *(float *)(v10 + 112) = v15;
    *(float *)(v10 + 124) = v16;
    *(float *)(v10 + 120) = v17;
    if ( (*(int (__thiscall **)(void *))(*(_DWORD *)a4 + 4))(a4) == 1 )
      sub_5C7220(a4, v10);
    v18 = sub_5BE270(*(_DWORD **)(this + 16), 2);
    if ( v18 )
    {
      *(_DWORD *)(v18 + 4) = v10;
      v50 = -1;
      sub_5A8840();
      return 1;
    }
    if ( v10 )
    {
      sub_5D3300(v10);
      j__free((void *)v10);
    }
    if ( *(_BYTE *)(this + 12) )
      sub_643E40("Can't find shared data.");
    goto LABEL_23;
  }
  if ( *(_BYTE *)(this + 12) )
  {
    Block = (void *)2;
    sub_4050C0((int)"Passed motion seems to be not valid!");
    v21 = (int)*off_16C9B3C;
    v50 = 3;
    v6 = sub_4050C0(v21);
    v7 = sub_4050C0((int)"::");
    sub_4050C0((int)"MotionPartChunkProcessor3");
    sub_5BE180(v6, (int)v48, v7);
    LOBYTE(v50) = 4;
    v22 = sub_5BE180(v6, (int)v49, v6);
    LOBYTE(v50) = 5;
    sub_5C6150((__int32)&Block, (int)v47);
    sub_643D50(v20, &Block, v22);
    LOBYTE(v50) = 4;
    sub_5A8840();
    LOBYTE(v50) = 3;
    sub_5A8840();
    LOBYTE(v50) = 2;
    sub_5A8840();
    LOBYTE(v50) = 1;
    sub_5A8840();
    LOBYTE(v50) = 0;
    sub_5A8840();
LABEL_23:
    v50 = -1;
    sub_5A8840();
  }
  return 0;
}
