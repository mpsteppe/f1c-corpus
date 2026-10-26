char __thiscall sub_4448C0(int *this, float a2)
{
  int v2; // edi
  char result; // al
  double i; // st7
  double v5; // st7
  long double *v6; // esi
  int v7; // ebx
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  double v12; // st7
  double v13; // st7
  double v14; // st6
  double v15; // st7
  int v16; // eax
  double v17; // [esp-Ch] [ebp-104h]
  double v18; // [esp+10h] [ebp-E8h]
  int v19; // [esp+10h] [ebp-E8h]
  double v20; // [esp+18h] [ebp-E0h]
  int v21; // [esp+18h] [ebp-E0h]
  int v23; // [esp+24h] [ebp-D4h]
  double v24; // [esp+28h] [ebp-D0h]
  double v25; // [esp+30h] [ebp-C8h]
  double v26; // [esp+38h] [ebp-C0h]
  double v27; // [esp+40h] [ebp-B8h]
  double v28; // [esp+48h] [ebp-B0h]
  double v29[3]; // [esp+50h] [ebp-A8h] BYREF
  double v30; // [esp+78h] [ebp-80h]
  _BYTE v31[24]; // [esp+80h] [ebp-78h] BYREF
  long double v32; // [esp+A0h] [ebp-58h]
  _BYTE v33[72]; // [esp+B0h] [ebp-48h] BYREF

  v2 = (int)this;
  if ( dbl_6152F8 == 1.0 || (result = byte_76617C) == 0 )
  {
    v23 = sub_579ED0(512);
    sub_447520(v2);
    for ( i = *(double *)(v2 + 136); ; i = v28 - v18 )
    {
      v18 = i;
      v28 = i;
      v24 = *(double *)(v2 + 128);
      sub_445010(v2);
      v20 = i * 0.5;
      sub_444740((int *)v2, v20);
      v5 = v20 + *(double *)(v2 + 128);
      *(double *)(v2 + 128) = v5;
      sub_445010(v2);
      sub_444870((int *)v2, v18);
      if ( v5 < 1.0 )
      {
        if ( *(_DWORD *)dword_766AA4 && v18 != *(double *)(v2 + 136) )
          v5 = v5 * (*(double *)(v2 + 136) / v18);
        if ( v5 < 1.0 )
        {
          if ( v5 <= 0.5 )
            v18 = v5 * 0.999 * v18;
          else
            v18 = v20;
          if ( v18 < 0.000003814697265625 )
            v18 = 0.000003814697265625;
          sub_4445D0((_DWORD *)v2);
          sub_444740((int *)v2, v18 * 0.5);
          *(double *)(v2 + 128) = v18 * 0.5 + v24;
          sub_445010(v2);
          sub_444870((int *)v2, v18);
        }
      }
      if ( v28 <= v18 )
        break;
      *(double *)(v2 + 128) = v24 + v18;
    }
    *(double *)(v2 + 6268) = *(double *)(v2 + 2264) + *(double *)(v2 + 1008);
    *(double *)(v2 + 128) = a2;
    sub_442160(v2);
    v6 = (long double *)(v2 + 840);
    v7 = 4;
    do
    {
      *v6 = fmod(*v6, 6.283185307179586);
      sub_43AB90((int)v6 - 172, *(double *)(v2 + 136));
      v6 += 157;
      --v7;
    }
    while ( v7 );
    sub_43AF90(v2 + 668, *(double *)(v2 + 136), *(_DWORD *)(v2 + 1020));
    sub_43AF90(v2 + 1924, *(double *)(v2 + 136), *(_DWORD *)(v2 + 2276));
    v17 = *(double *)(v2 + 136);
    if ( *(_DWORD *)(v2 + 5692) )
    {
      sub_43AF90(v2 + 3180, v17, *(_DWORD *)(v2 + 5692));
      v8 = *(_DWORD *)(v2 + 5692);
    }
    else
    {
      sub_43AF90(v2 + 3180, v17, *(_DWORD *)(v2 + 3532));
      v8 = *(_DWORD *)(v2 + 4788);
    }
    sub_43AF90(v2 + 4436, *(double *)(v2 + 136), v8);
    v9 = v2 + 800;
    v21 = 4;
    do
    {
      v10 = *(_DWORD *)(v9 + 220);
      if ( v10 )
      {
        if ( !*(_BYTE *)(v9 + 320) )
        {
          v25 = *(double *)(v10 + 28);
          v26 = *(double *)(v10 + 52);
          v27 = *(double *)(v10 + 76);
          v11 = *(_DWORD *)(v2 + 6164);
          v12 = v27 * *(double *)(v11 + 76) + v26 * *(double *)(v11 + 52) + v25 * *(double *)(v11 + 28);
          v32 = v27 * *(double *)(v11 + 84) + v26 * *(double *)(v11 + 60) + v25 * *(double *)(v11 + 36);
          if ( v12 < 0.5 || fabs(v32) > 0.7 )
          {
            v13 = *(double *)(v11 + 36) * *(double *)v9
                + *(double *)(v11 + 44) * *(double *)(v9 + 8)
                + *(double *)(v9 - 8) * *(double *)(v11 + 28);
            v14 = *(double *)(v11 + 60) * *(double *)v9
                + *(double *)(v11 + 68) * *(double *)(v9 + 8)
                + *(double *)(v11 + 52) * *(double *)(v9 - 8);
            v30 = *(double *)(v11 + 84) * *(double *)v9
                + *(double *)(v11 + 92) * *(double *)(v9 + 8)
                + *(double *)(v11 + 76) * *(double *)(v9 - 8);
            v29[0] = v13 + *(double *)(v11 + 4);
            v29[1] = v14 + *(double *)(v11 + 12);
            v15 = v30 + *(double *)(v11 + 20);
            qmemcpy(v33, (const void *)(v11 + 28), sizeof(v33));
            v29[2] = v15;
            sub_57EB70(v9 + 16, 0);
            qmemcpy(v31, (const void *)(this[1541] + 124), sizeof(v31));
            qmemcpy((void *)(*(_DWORD *)(v9 + 220) + 4), v29, 0x18u);
            v16 = *(_DWORD *)(v9 + 220);
            qmemcpy((void *)(v16 + 28), v33, 0x48u);
            v19 = v16;
            sub_57C030(v16);
            qmemcpy((void *)(v19 + 124), v31, 0x18u);
            sub_57C1A0(v19);
            sub_4446C0(this);
            v2 = (int)this;
          }
        }
      }
      v9 += 1256;
      result = --v21;
    }
    while ( v21 );
    if ( v23 != 512 )
      return sub_579F10(v23);
  }
  return result;
}
