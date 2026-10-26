int __thiscall sub_5E0AB0(void *this, char ArgList, int a3, int *a4)
{
  int v4; // ebx
  int v5; // eax
  double v7; // st7
  char v8; // [esp+1Ch] [ebp-1B6h]
  char v9; // [esp+1Dh] [ebp-1B5h]
  int v10; // [esp+1Eh] [ebp-1B4h]
  int v11; // [esp+22h] [ebp-1B0h] BYREF
  char *v12; // [esp+26h] [ebp-1ACh] BYREF
  char *v13; // [esp+2Ah] [ebp-1A8h] BYREF
  int v14; // [esp+2Eh] [ebp-1A4h]
  float v15; // [esp+32h] [ebp-1A0h]
  float v16; // [esp+36h] [ebp-19Ch]
  int v17; // [esp+3Ah] [ebp-198h]
  int v18; // [esp+3Eh] [ebp-194h]
  int v19; // [esp+42h] [ebp-190h] BYREF
  float v20; // [esp+46h] [ebp-18Ch]
  float v21; // [esp+4Ah] [ebp-188h]
  int v22; // [esp+4Eh] [ebp-184h] BYREF
  float v23; // [esp+52h] [ebp-180h]
  float v24; // [esp+56h] [ebp-17Ch]
  char *v25; // [esp+5Ah] [ebp-178h] BYREF
  int v26; // [esp+5Eh] [ebp-174h]
  char *EndPtr; // [esp+62h] [ebp-170h] BYREF
  char *v28; // [esp+66h] [ebp-16Ch] BYREF
  char *v29; // [esp+6Ah] [ebp-168h] BYREF
  char *v30; // [esp+6Eh] [ebp-164h] BYREF
  char v31[32]; // [esp+72h] [ebp-160h] BYREF
  char v32[64]; // [esp+92h] [ebp-140h] BYREF
  char v33[64]; // [esp+D2h] [ebp-100h] BYREF
  char v34[64]; // [esp+112h] [ebp-C0h] BYREF
  char String[64]; // [esp+152h] [ebp-80h] BYREF
  char v36[64]; // [esp+192h] [ebp-40h] BYREF

  v26 = (int)this;
  *(float *)&v22 = 0.0;
  v23 = 0.0;
  *(float *)&v19 = 0.0;
  v20 = 0.0;
  v24 = 0.0;
  v4 = 1;
  v8 = 1;
  v9 = 0;
  v10 = 2;
  v11 = 0;
  v21 = 0.0;
  v15 = 1.0;
  v16 = 10000.0;
  *(float *)&v17 = 100000.0;
  v18 = 1;
  v14 = 256;
  while ( sub_5DF750(a4) != 1 )
  {
    if ( *a4 == 3 )
      break;
    if ( *a4 != 2 )
    {
      if ( sub_5DEF70() )
      {
        v12 = (char *)(a4[515] + 1);
        *(float *)&v19 = strtod(v12, &v12);
        v20 = strtod(v12 + 1, &v12);
        v21 = strtod(v12 + 1, &v12);
      }
      if ( sub_5DEF70() )
      {
        v13 = (char *)(a4[515] + 1);
        *(float *)&v22 = strtod(v13, &v13);
        v23 = strtod(v13 + 1, &v13);
        v24 = strtod(v13 + 1, &v13);
      }
      if ( sub_5DEF70() )
      {
        v28 = (char *)(a4[515] + 1);
        v15 = strtod(v28, &v28);
      }
      if ( sub_5DEF70() )
      {
        v25 = (char *)(a4[515] + 1);
        *(float *)&v17 = strtod(v25, &v25);
      }
      if ( sub_5DEF70() )
      {
        v30 = (char *)(a4[515] + 1);
        v16 = strtod(v30, &v30);
      }
      sub_5DF240((int)a4, "FILTER", String, 0, 0, 0, 0, 0, 0, 0);
      sub_5DF240((int)a4, "BLEND", v32, v33, 0, 0, 0, 0, 0, 0);
      sub_5DF240((int)a4, "TEXMAP", v36, 0, 0, 0, 0, 0, 0, 0);
      if ( sub_5DEF70() )
      {
        EndPtr = (char *)(a4[515] + 1);
        v18 = strtol(EndPtr, &EndPtr, 10);
      }
      if ( sub_5DEF70() )
      {
        v29 = (char *)(a4[515] + 1);
        strtod(v29, &v29);
      }
      sub_5DF240((int)a4, "ANIMTYPE", v34, 0, 0, 0, 0, 0, 0, 0);
      if ( sub_5DF240((int)a4, (char *)off_72BA30, v31, 0, 0, 0, 0, 0, 0, 0) && !strcmp(v31, "TRUE") )
        v14 |= 0x80u;
      if ( sub_5DF240((int)a4, "ACTIVE", v31, 0, 0, 0, 0, 0, 0, 0) )
      {
        if ( !strcmp(v31, "TRUE") )
        {
          v8 = 1;
        }
        else if ( !strcmp(v31, "FALSE") )
        {
          v8 = 0;
        }
      }
      if ( sub_5DF240((int)a4, "MOVEABLE", v31, 0, 0, 0, 0, 0, 0, 0) )
      {
        if ( !strcmp(v31, "TRUE") )
        {
          v9 = 1;
        }
        else if ( !strcmp(v31, "FALSE") )
        {
          v9 = 0;
        }
      }
    }
  }
  if ( !strcmp(v32, "ZERO") )
  {
    v10 = 1;
  }
  else if ( !strcmp(v32, "ONE") )
  {
    v10 = 2;
  }
  else if ( !strcmp(v32, "SRCCOLOR") )
  {
    v10 = 3;
  }
  else if ( !strcmp(v32, "INVSRCCOLOR") )
  {
    v10 = 4;
  }
  else if ( !strcmp(v32, "SRCALPHA") )
  {
    v10 = 5;
  }
  else if ( !strcmp(v32, "INVSRCALPHA") )
  {
    v10 = 6;
  }
  else if ( !strcmp(v32, "DSTCOLOR") )
  {
    v10 = 9;
  }
  else if ( !strcmp(v32, "INVDSTCOLOR") )
  {
    v10 = 10;
  }
  else if ( !strcmp(v32, "DSTALPHA") )
  {
    v10 = 7;
  }
  else if ( !strcmp(v32, "INVDSTALPHA") )
  {
    v10 = 8;
  }
  if ( !memcmp(v33, off_16C9B24[0], 5u) )
  {
    v4 = 1;
  }
  else if ( !strcmp(v33, "ONE") )
  {
    v4 = 2;
  }
  else if ( !strcmp(v33, "SRCCOLOR") )
  {
    v4 = 3;
  }
  else if ( !strcmp(v33, "INVSRCCOLOR") )
  {
    v4 = 4;
  }
  else if ( !strcmp(v33, "SRCALPHA") )
  {
    v4 = 5;
  }
  else if ( !strcmp(v33, "INVSRCALPHA") )
  {
    v4 = 6;
  }
  else if ( !strcmp(v33, "DSTCOLOR") )
  {
    v4 = 9;
  }
  else if ( !strcmp(v33, "INVDSTCOLOR") )
  {
    v4 = 10;
  }
  else if ( !strcmp(v33, "DSTALPHA") )
  {
    v4 = 7;
  }
  else if ( !strcmp(v33, "INVDSTALPHA") )
  {
    v4 = 8;
  }
  if ( v10 == 2 && v4 == 1 )
    v5 = v14;
  else
    v5 = v14 | 0x200;
  if ( !strcmp(v34, "CYCLE")
    || !strcmp(v34, "ONESHOT")
    || !strcmp(v34, "PENDULUM")
    || !strcmp(v34, "TRANSIENT")
    || !strcmp(v34, "RANDOM")
    || !strcmp(v34, "MANUAL")
    || !strcmp(v34, "VIDEO") )
  {
    v5 |= 0x800u;
  }
  if ( sub_600510(v26, ArgList, (int)&v19, (int)&v22, v15, v17, (int)v36, v18, (int)&v11, v5) )
    return -1;
  v7 = v16;
  *(_DWORD *)(v11 + 252) = v10;
  *(_DWORD *)(v11 + 256) = v4;
  *(float *)(v11 + 236) = v7;
  if ( v8 )
    sub_5FF0C0(v11);
  else
    sub_5FF0D0(v11);
  if ( v9 )
    *(_DWORD *)v11 |= 0x400u;
  if ( !strcmp(String, "OMNILIGHT") )
    *(_DWORD *)(v11 + 264) = 0x4000000;
  else
    *(_DWORD *)(v11 + 264) = strcmp(String, "SHADOW") != 0 ? 0x4000000 : 1024;
  if ( a3 )
    *(_DWORD *)(v11 + 276) = a3;
  return 0;
}
