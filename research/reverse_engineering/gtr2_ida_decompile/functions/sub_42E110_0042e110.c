void __thiscall sub_42E110(float *this)
{
  char *v2; // eax
  int v3; // eax
  double v4; // st7
  int v5; // ecx
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  float v9; // eax
  float v10; // eax
  char *v11; // eax
  int v12; // eax
  double v13; // st7
  int v14; // ecx
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c2
  float v18; // eax
  float v19; // eax
  float v20; // [esp-8h] [ebp-10h]
  float v21; // [esp-8h] [ebp-10h]
  float v22; // [esp-8h] [ebp-10h]
  float v23; // [esp-8h] [ebp-10h]
  float v24; // [esp+4h] [ebp-4h] BYREF

  if ( ((dword_B698E8 & 1) == 0 || (byte_B69A09 & 2) == 0 && ((dword_B698E8 & 1) == 0 || (byte_B69A16 & 2) == 0))
    && !byte_B739A8
    && !byte_B739C0 )
  {
    if ( dword_B6A3D8 )
    {
      if ( byte_920484 )
      {
        v2 = dword_B6F708;
        if ( !dword_B6F708 )
          v2 = (char *)WindowName;
        v3 = sub_539670(v2);
        v4 = (double)dword_B6A33C;
        v5 = v3;
        this[4] = v4;
        if ( v7 | v8 )
        {
          v9 = *(float *)(v3 + 136);
          v20 = *(float *)(v5 + 132);
          v24 = flt_B70ED0 - 0.0024999999;
          sub_401760(&v24, v20, v9);
          sub_409B80((float *)off_16C9A14, &v24);
        }
        else if ( v4 > this[1] )
        {
          v10 = *(float *)(v3 + 136);
          v21 = *(float *)(v5 + 132);
          v24 = flt_B70ED0 + 0.0024999999;
          sub_401760(&v24, v21, v10);
          sub_409B80(flt_B70EBC, &v24);
        }
      }
      else
      {
        this[1] = (float)dword_B6A33C;
        byte_920484 = 1;
      }
    }
    else
    {
      byte_920484 = 0;
    }
    if ( dword_B6A3E0 )
    {
      if ( byte_920485 )
      {
        v11 = dword_B6F708;
        if ( !dword_B6F708 )
          v11 = (char *)WindowName;
        v12 = sub_539670(v11);
        v13 = (double)dword_B6A33C;
        v14 = v12;
        this[4] = v13;
        if ( v16 | v17 )
        {
          v18 = *(float *)(v12 + 140);
          v22 = *(float *)(v14 + 144);
          v24 = flt_B70EF4 + 0.001;
          sub_401760(&v24, v22, v18);
          sub_409B80(flt_B70EE0, &v24);
        }
        else if ( v13 > this[1] )
        {
          v19 = *(float *)(v12 + 140);
          v23 = *(float *)(v14 + 144);
          v24 = flt_B70EF4 - 0.001;
          sub_401760(&v24, v23, v19);
          sub_409B80(flt_B70EE0, &v24);
        }
      }
      else
      {
        this[1] = (float)dword_B6A33C;
        byte_920485 = 1;
      }
    }
    else
    {
      byte_920485 = 0;
    }
  }
}
