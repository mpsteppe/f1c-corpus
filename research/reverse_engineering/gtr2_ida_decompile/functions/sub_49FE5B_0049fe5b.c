int __userpurge sub_49FE5B@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>, int a6, int a7)
{
  int *v8; // edi
  int v9; // eax
  int v10; // eax
  double v11; // st7
  int v13; // eax
  int v14; // eax
  int v15; // edx
  double v16; // st7
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  char v23; // [esp+1h] [ebp-5F1h]
  float v24; // [esp+2h] [ebp-5F0h]
  int v25; // [esp+6h] [ebp-5ECh]
  int v28; // [esp+16h] [ebp-5DCh] BYREF
  int v29; // [esp+1Ah] [ebp-5D8h] BYREF
  int v30; // [esp+1Eh] [ebp-5D4h] BYREF
  int v31; // [esp+22h] [ebp-5D0h] BYREF
  int v32; // [esp+26h] [ebp-5CCh] BYREF
  int v33; // [esp+2Ah] [ebp-5C8h] BYREF
  int v34; // [esp+2Eh] [ebp-5C4h] BYREF
  int v35; // [esp+32h] [ebp-5C0h] BYREF
  int v36; // [esp+36h] [ebp-5BCh] BYREF
  int v37; // [esp+3Ah] [ebp-5B8h] BYREF
  int v38; // [esp+3Eh] [ebp-5B4h] BYREF
  int v39; // [esp+42h] [ebp-5B0h] BYREF
  int v40; // [esp+46h] [ebp-5ACh] BYREF
  int v41; // [esp+4Ah] [ebp-5A8h] BYREF
  int v42; // [esp+4Eh] [ebp-5A4h] BYREF
  _DWORD v43[131]; // [esp+52h] [ebp-5A0h] BYREF
  char v44[8]; // [esp+25Eh] [ebp-394h] BYREF
  int v45; // [esp+266h] [ebp-38Ch]
  int v46; // [esp+26Ah] [ebp-388h]
  int v47; // [esp+26Eh] [ebp-384h]
  char v48[896]; // [esp+272h] [ebp-380h] BYREF

  memset(v48, 0, 0x200u);
  v8 = *(int **)(a3 + 8);
  v25 = 512;
  v39 = 0;
  v33 = 0;
  v37 = 0;
  v41 = 0;
  v30 = 0;
  v43[1] = 0;
  v32 = 0;
  v31 = 0;
  v43[0] = 0;
  v9 = *v8;
  v24 = COERCE_FLOAT(v48);
  v43[130] = 0;
  v47 = 0;
  v45 = 0;
  v46 = 0;
  v44[0] = 1;
  HIBYTE(v29) = 1;
  v42 = 0;
  v40 = 0;
  v38 = 0;
  v36 = 0;
  v34 = 0;
  v35 = 1065353216;
  if ( (*(int (__thiscall **)(int *))(v9 + 36))(v8) )
  {
    do
    {
      v10 = sub_612EB0(v43);
      if ( v10 )
      {
        if ( v10 == 2 )
          break;
        if ( v10 == 4 )
          return 1;
      }
      else
      {
        sub_6134B0((char *)off_6F5D0C, (int)&v29, (int)&v30, 0, 0, 0, 0, 0, 0);
        sub_6133A0("COLOR", (int)&v32, (int)&v34, (int)&v36, 0);
        sub_6134B0("CLIPPLANES", (int)&v42, (int)&v28, 0, 0, 0, 0, 0, 0);
        sub_6134B0("LODMULTIPLIER", (int)&v33, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("SIZE", (int)&v39, (int)&v35, 0, 0, 0, 0, 0, 0);
        sub_6134B0("CENTER", (int)&v31, (int)&v37, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MIPMAPLODBIAS", (int)&v41, 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("FLAGS1", (int)&v38, 0, 0, 0);
        sub_6133A0("FLAGS2", (int)&v40, 0, 0, 0);
        v23 = 0;
        if ( sub_6137E0(v43) )
        {
          v8 = *(int **)(a3 + 8);
          if ( !strcmp(&v48[492], "FALSE") )
            HIBYTE(v25) = 0;
        }
        sub_6134B0("RADIUSLIMITS", a1 + 132, a1 + 136, 0, 0, 0, 0, 0, 0);
        sub_6134B0("ORIENTATIONRATE", a1 + 140, a1 + 144, a1 + 148, 0, 0, 0, 0, 0);
        if ( !_stricmp("COCKPIT", *(const char **)(a3 + 12)) )
        {
          *(_DWORD *)(a1 + 152) = 0;
          *(_DWORD *)(a1 + 156) = 0;
          *(_DWORD *)(a1 + 160) = 0;
        }
        else
        {
          sub_6134B0("POSITIONOFFSET", a1 + 152, a1 + 156, a1 + 160, 0, 0, 0, 0, 0);
        }
        sub_6134B0("ORIENTATIONOFFSET", a1 + 164, a1 + 168, a1 + 172, 0, 0, 0, 0, 0);
        sub_6134B0("RADIUS", a1 + 176, 0, 0, 0, 0, 0, 0, 0);
      }
    }
    while ( (*(int (__thiscall **)(int *, char *, int))(*v8 + 36))(v8, v44, 512) );
  }
  switch ( dword_B71758 )
  {
    case 0:
      v11 = COERCE_FLOAT(v48) - 250.0;
      goto LABEL_20;
    case 2:
      v11 = COERCE_FLOAT(v48) + 250.0;
      goto LABEL_20;
    case 3:
      v11 = COERCE_FLOAT(v48) + 500.0;
LABEL_20:
      v24 = v11;
      break;
  }
  sub_615860(*(_DWORD *)(a3 + 12));
  *(_DWORD *)(a1 + 48) = v25;
  *(_DWORD *)(a1 + 52) = a4;
  v13 = v37;
  *(_DWORD *)(a1 + 56) = v25;
  *(_DWORD *)(a1 + 64) = v13;
  v14 = v30;
  *(_DWORD *)(a1 + 60) = a4;
  v15 = v34;
  *(float *)(a1 + 68) = v24;
  v16 = flt_B71AF8 * *(float *)&v28;
  *(_DWORD *)(a1 + 80) = v14;
  v17 = v36;
  *(_DWORD *)(a1 + 76) = v15;
  *(float *)(a1 + 72) = v16;
  v18 = v32;
  *(_DWORD *)(a1 + 92) = v17;
  v19 = v29;
  *(_DWORD *)(a1 + 84) = a5;
  *(_DWORD *)(a1 + 88) = v18;
  *(_DWORD *)(a1 + 104) = v19;
  v20 = v35;
  *(_BYTE *)(a1 + 96) = v23;
  v21 = v31;
  *(_DWORD *)(a1 + 100) = a2;
  v22 = v33;
  *(_DWORD *)(a1 + 112) = 0;
  *(_DWORD *)(a1 + 120) = v20;
  *(_DWORD *)(a1 + 108) = v21;
  *(_DWORD *)(a1 + 116) = v22;
  return 0;
}
