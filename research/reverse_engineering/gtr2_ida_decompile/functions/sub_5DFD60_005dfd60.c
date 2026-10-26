int __thiscall sub_5DFD60(void *this, int a2, int a3, int *a4)
{
  int v4; // ebx
  int v5; // esi
  float v7; // esi
  float v8; // [esp+8h] [ebp-144h]
  const char *v9; // [esp+1Ch] [ebp-130h] BYREF
  int (**v10)(); // [esp+20h] [ebp-12Ch]
  int v11; // [esp+30h] [ebp-11Ch]
  char *v12; // [esp+34h] [ebp-118h] BYREF
  char *EndPtr; // [esp+38h] [ebp-114h] BYREF
  char *v14; // [esp+3Ch] [ebp-110h] BYREF
  int v15; // [esp+40h] [ebp-10Ch]
  float v16; // [esp+44h] [ebp-108h]
  float v17; // [esp+48h] [ebp-104h]
  char *v18; // [esp+4Ch] [ebp-100h] BYREF
  float v19; // [esp+50h] [ebp-FCh]
  int v20; // [esp+54h] [ebp-F8h]
  float v21; // [esp+58h] [ebp-F4h]
  int v22; // [esp+5Ch] [ebp-F0h]
  float v23; // [esp+60h] [ebp-ECh]
  float v24; // [esp+64h] [ebp-E8h]
  int v25; // [esp+68h] [ebp-E4h]
  char *v26; // [esp+6Ch] [ebp-E0h] BYREF
  int v27; // [esp+70h] [ebp-DCh]
  char *v28; // [esp+74h] [ebp-D8h] BYREF
  _BYTE v29[4]; // [esp+78h] [ebp-D4h] BYREF
  int v30; // [esp+7Ch] [ebp-D0h] BYREF
  void *v31; // [esp+80h] [ebp-CCh] BYREF
  _BYTE v32[4]; // [esp+84h] [ebp-C8h] BYREF
  _BYTE v33[4]; // [esp+88h] [ebp-C4h] BYREF
  _BYTE v34[4]; // [esp+8Ch] [ebp-C0h] BYREF
  _BYTE v35[4]; // [esp+90h] [ebp-BCh] BYREF
  _BYTE v36[4]; // [esp+94h] [ebp-B8h] BYREF
  _BYTE v37[4]; // [esp+98h] [ebp-B4h] BYREF
  _BYTE v38[4]; // [esp+9Ch] [ebp-B0h] BYREF
  _BYTE v39[4]; // [esp+A0h] [ebp-ACh] BYREF
  _BYTE v40[4]; // [esp+A4h] [ebp-A8h] BYREF
  _BYTE v41[4]; // [esp+A8h] [ebp-A4h] BYREF
  _BYTE v42[4]; // [esp+ACh] [ebp-A0h] BYREF
  _BYTE v43[4]; // [esp+B0h] [ebp-9Ch] BYREF
  _BYTE v44[4]; // [esp+B4h] [ebp-98h] BYREF
  _BYTE v45[4]; // [esp+B8h] [ebp-94h] BYREF
  _BYTE v46[4]; // [esp+BCh] [ebp-90h] BYREF
  _BYTE v47[4]; // [esp+C0h] [ebp-8Ch] BYREF
  _BYTE v48[4]; // [esp+C4h] [ebp-88h] BYREF
  _BYTE v49[4]; // [esp+C8h] [ebp-84h] BYREF
  _BYTE v50[4]; // [esp+CCh] [ebp-80h] BYREF
  _BYTE v51[4]; // [esp+D0h] [ebp-7Ch] BYREF
  char v52[32]; // [esp+D4h] [ebp-78h] BYREF
  char v53[24]; // [esp+F4h] [ebp-58h] BYREF
  char String[16]; // [esp+10Ch] [ebp-40h] BYREF
  char v55[28]; // [esp+11Ch] [ebp-30h] BYREF
  int v56; // [esp+138h] [ebp-14h]
  int v57; // [esp+13Ch] [ebp-10h]

  v4 = 0;
  v31 = this;
  LOBYTE(v26) = 1;
  LOBYTE(v24) = 0;
  HIBYTE(EndPtr) = 0;
  v12 = 0;
  v25 = 0;
  v23 = 0.0;
  v21 = 0.0;
  v17 = 0.0;
  *(float *)&v18 = 0.0;
  v19 = 0.0;
  v30 = 0;
  v28 = 0;
  v20 = 1120403456;
  v27 = 1065353216;
  while ( sub_5DF750(a4) != 1 )
  {
    if ( *a4 == 3 )
      break;
    if ( *a4 != 2 )
    {
      sub_5DF240((int)a4, "TYPE", String, 0, 0, 0, 0, 0, 0, 0);
      v10 = &off_6F1B20;
      if ( sub_5DEF70() )
      {
        v14 = (char *)(a4[515] + 1);
        *(float *)&v18 = strtod(v14, &v14);
        v17 = strtod(v14 + 1, &v14);
        v16 = strtod(v14 + 1, &v14);
      }
      v9 = "DIR";
      if ( sub_5DEF70() )
      {
        v12 = (char *)(a4[515] + 1);
        v19 = strtod(v12, &v12);
        v21 = strtod(v12 + 1, &v12);
        v23 = strtod(v12 + 1, &v12);
      }
      if ( sub_5DEF70() )
      {
        EndPtr = (char *)(a4[515] + 1);
        v4 = strtol(EndPtr, &EndPtr, 10);
        v25 = strtol(EndPtr + 1, &EndPtr, 10);
        v27 = strtol(EndPtr + 1, &EndPtr, 10);
      }
      if ( sub_5DEF70() )
      {
        v18 = (char *)(a4[515] + 1);
        strtod(v18, &v18);
        v16 = strtod(v18 + 1, &v18);
      }
      sub_5DF240((int)a4, "ATTENUATE", v55, 0, 0, 0, 0, 0, 0, 0);
      if ( sub_5DEF70() )
      {
        v28 = (char *)(a4[515] + 1);
        v24 = strtod(v28, &v28);
      }
      if ( sub_5DEF70() )
      {
        v26 = (char *)(a4[515] + 1);
        v21 = strtod(v26, &v26);
      }
      if ( sub_5DF240((int)a4, "ACTIVE", v52, 0, 0, 0, 0, 0, 0, 0) )
      {
        if ( !strcmp(v52, "TRUE") )
        {
          LOBYTE(v20) = 1;
        }
        else if ( !strcmp(v52, "FALSE") )
        {
          LOBYTE(v20) = 0;
        }
      }
      if ( sub_5DF240((int)a4, "CASTSHADOW", v52, 0, 0, 0, 0, 0, 0, 0) )
      {
        if ( !strcmp(v52, "TRUE") )
        {
          LOBYTE(v18) = 1;
        }
        else if ( !strcmp(v52, "FALSE") )
        {
          LOBYTE(v18) = 0;
        }
      }
      if ( sub_5DF240((int)a4, "MOVEABLE", v52, 0, 0, 0, 0, 0, 0, 0) )
      {
        if ( !strcmp(v52, "TRUE") )
        {
          HIBYTE(v10) = 1;
        }
        else if ( !strcmp(v52, "FALSE") )
        {
          HIBYTE(v10) = 0;
        }
      }
      sub_5DF630((int)"PLANE0", (int)&v28, (int)v29, (int)&v30, (int)&v31);
      sub_5DF630((int)"PLANE1", (int)v32, (int)v33, (int)v34, (int)v35);
      sub_5DF630((int)"PLANE2", (int)v36, (int)v37, (int)v38, (int)v39);
      sub_5DF630((int)"PLANE3", (int)v40, (int)v41, (int)v42, (int)v43);
      sub_5DF630((int)"PLANE4", (int)v44, (int)v45, (int)v46, (int)v47);
      sub_5DF630((int)"PLANE5", (int)v48, (int)v49, (int)v50, (int)v51);
    }
  }
  if ( !strcmp(v53, "DIRECTIONAL") )
  {
    v5 = 2;
  }
  else if ( !strcmp(v53, "OMNI") )
  {
    v5 = 3;
  }
  else if ( !strcmp(v53, "VOLUME") )
  {
    v5 = 4;
  }
  else
  {
    v5 = 5;
    if ( strcmp(v53, "SPOT") )
      v5 = LODWORD(v23);
  }
  if ( sub_600E40(&v9, v56, v5, 0) )
    return -1;
  switch ( v5 )
  {
    case 2:
      sub_600C90(v15, LODWORD(v17), LODWORD(v19));
      sub_600E20(1);
      break;
    case 3:
      sub_600D60(EndPtr, v12, v11);
      sub_600660(v14);
      break;
    case 4:
      sub_600D60(EndPtr, v12, v11);
      sub_600E20((char)v18);
      sub_600680(0, &v28);
      sub_600680(1, v32);
      sub_600680(2, v36);
      sub_600680(3, v40);
      sub_600680(4, v44);
      sub_600680(5, v48);
      break;
    case 5:
      sub_600D60(EndPtr, v12, v11);
      sub_600C90(v15, LODWORD(v17), LODWORD(v19));
      sub_600660(v14);
      v8 = v23 * 0.01745433;
      sub_600670(LODWORD(v8));
      break;
    default:
      break;
  }
  sub_600C20(2, LODWORD(v24) | ((v22 | (v4 << 8)) << 8));
  v7 = v21;
  sub_600C50(1, LODWORD(v21));
  sub_600C50(2, LODWORD(v7));
  sub_600C50(3, LODWORD(v7));
  if ( HIBYTE(v10) )
    return off_16C9944(a2, a3, a4);
  sub_600A80(v20);
  if ( v57 )
    *((_DWORD *)v9 + 50) = v57;
  return 0;
}
