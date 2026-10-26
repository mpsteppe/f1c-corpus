int __thiscall sub_46E0E0(int this, int *a2, int a3)
{
  int *v4; // edi
  int v5; // eax
  int v6; // eax
  double v7; // st7
  double v9; // st7
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // edx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  char v35; // [esp+15h] [ebp-5FDh]
  int v36; // [esp+16h] [ebp-5FCh] BYREF
  int v37; // [esp+1Ah] [ebp-5F8h] BYREF
  int v38; // [esp+1Eh] [ebp-5F4h] BYREF
  int v39; // [esp+22h] [ebp-5F0h] BYREF
  int v40; // [esp+26h] [ebp-5ECh] BYREF
  int v41; // [esp+2Ah] [ebp-5E8h] BYREF
  int v42; // [esp+2Eh] [ebp-5E4h] BYREF
  int v43; // [esp+32h] [ebp-5E0h] BYREF
  int v44; // [esp+36h] [ebp-5DCh] BYREF
  int v45; // [esp+3Ah] [ebp-5D8h] BYREF
  int v46; // [esp+3Eh] [ebp-5D4h] BYREF
  int v47; // [esp+42h] [ebp-5D0h] BYREF
  int v48; // [esp+46h] [ebp-5CCh] BYREF
  int v49; // [esp+4Ah] [ebp-5C8h] BYREF
  int v50; // [esp+4Eh] [ebp-5C4h] BYREF
  int v51; // [esp+52h] [ebp-5C0h] BYREF
  int v52; // [esp+56h] [ebp-5BCh] BYREF
  int v53; // [esp+5Ah] [ebp-5B8h] BYREF
  int v54; // [esp+5Eh] [ebp-5B4h] BYREF
  int v55; // [esp+62h] [ebp-5B0h] BYREF
  int v56; // [esp+66h] [ebp-5ACh] BYREF
  int v57; // [esp+6Ah] [ebp-5A8h] BYREF
  int v58; // [esp+6Eh] [ebp-5A4h] BYREF
  int v59; // [esp+72h] [ebp-5A0h] BYREF
  int v60; // [esp+76h] [ebp-59Ch] BYREF
  _BYTE v61[512]; // [esp+7Ah] [ebp-598h] BYREF
  int v62; // [esp+27Ah] [ebp-398h]
  char v63; // [esp+27Eh] [ebp-394h]
  int v64; // [esp+286h] [ebp-38Ch]
  int v65; // [esp+28Ah] [ebp-388h]
  int v66; // [esp+28Eh] [ebp-384h]
  char String1[512]; // [esp+292h] [ebp-380h] BYREF
  char v68[384]; // [esp+492h] [ebp-180h] BYREF

  memset(String1, 0, sizeof(String1));
  v4 = a2;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v40 = 0;
  v45 = 0;
  v59 = 0;
  v43 = 0;
  *(float *)&v36 = 0.0;
  v55 = 0;
  v39 = 0;
  v38 = 0;
  v47 = 0;
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v5 = *a2;
  v62 = 0;
  v66 = 0;
  v64 = 0;
  v65 = 0;
  v63 = 1;
  v35 = 1;
  v46 = 0;
  v44 = 0;
  v42 = 0;
  v41 = 0;
  v60 = 0;
  v51 = 1065353216;
  *(float *)&v37 = 100.0;
  if ( (*(int (__thiscall **)(int *, char *, int))(v5 + 36))(a2, String1, 512) )
  {
    do
    {
      v6 = sub_612EB0(v61);
      if ( v6 )
      {
        if ( v6 == 2 )
          break;
        if ( v6 == 4 )
          return 1;
      }
      else
      {
        sub_6134B0("POSITION", (int)&v48, (int)&v49, (int)&v50, 0, 0, 0, 0, 0);
        sub_6134B0("ORIENTATION", (int)&v52, (int)&v53, (int)&v54, 0, 0, 0, 0, 0);
        sub_6134B0((char *)off_6F5D0C, (int)&v38, (int)&v39, 0, 0, 0, 0, 0, 0);
        sub_6133A0("COLOR", (int)&v60, (int)&v41, (int)&v42, 0);
        sub_6134B0("CLIPPLANES", (int)&v55, (int)&v36, 0, 0, 0, 0, 0, 0);
        sub_6134B0("LODMULTIPLIER", (int)&v51, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("SIZE", (int)&v43, (int)&v59, 0, 0, 0, 0, 0, 0);
        sub_6134B0("CENTER", (int)&v45, (int)&v40, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MIPMAPLODBIAS", (int)&v47, 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("FLAGS1", (int)&v44, 0, 0, 0);
        sub_6133A0("FLAGS2", (int)&v46, 0, 0, 0);
        if ( sub_6137E0(v61) )
        {
          v4 = a2;
          if ( !strcmp(v68, "FALSE") )
            v35 = 0;
        }
        sub_6134B0("ACTIVATIONLOCATION", (int)&v56, (int)&v57, (int)&v58, 0, 0, 0, 0, 0);
        sub_6134B0("ACTIVATIONRADIUS", (int)&v37, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("TRACKINGRATE", this + 168, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MOVEMENTRATE", this + 172, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("SHAKERATE", this + 264, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("SHAKEMAGNITUDE", this + 268, 0, 0, 0, 0, 0, 0, 0);
        if ( !_stricmp(String1, "MOVEMENTPATH") )
          sub_46DDE0((void *)(this + 180), v4);
      }
    }
    while ( (*(int (__thiscall **)(int *, char *, int))(*v4 + 36))(v4, String1, 512) );
  }
  switch ( dword_B71758 )
  {
    case 0:
      v7 = *(float *)&v36 - 250.0;
      goto LABEL_18;
    case 2:
      v7 = *(float *)&v36 + 250.0;
      goto LABEL_18;
    case 3:
      v7 = *(float *)&v36 + 500.0;
LABEL_18:
      *(float *)&v36 = v7;
      break;
  }
  sub_615860(a3);
  v9 = *(float *)&v37 * *(float *)&v37;
  v10 = v49;
  *(_DWORD *)(this + 12) = v48;
  *(float *)(this + 144) = v9;
  v11 = v50;
  *(_DWORD *)(this + 16) = v10;
  *(_DWORD *)(this + 20) = v11;
  v12 = v52;
  v13 = v54;
  v14 = v53;
  *(_DWORD *)(this + 24) = v52;
  *(_DWORD *)(this + 28) = v14;
  *(_DWORD *)(this + 32) = v13;
  *(_DWORD *)(this + 148) = v12;
  v15 = v39;
  *(_DWORD *)(this + 152) = v14;
  *(_DWORD *)(this + 156) = v13;
  v16 = v38;
  *(_DWORD *)(this + 48) = v38;
  v17 = v15;
  *(_DWORD *)(this + 52) = v15;
  v18 = v55;
  *(_DWORD *)(this + 56) = v16;
  v19 = v36;
  *(_DWORD *)(this + 60) = v17;
  v20 = v51;
  *(_DWORD *)(this + 64) = v18;
  v21 = v43;
  *(_DWORD *)(this + 68) = v19;
  v22 = v59;
  *(_DWORD *)(this + 72) = v20;
  v23 = v45;
  *(_DWORD *)(this + 76) = v21;
  v24 = v40;
  *(_DWORD *)(this + 80) = v22;
  v25 = v47;
  *(_DWORD *)(this + 84) = v23;
  *(_DWORD *)(this + 88) = v24;
  v26 = v60;
  *(_DWORD *)(this + 92) = v25;
  v27 = v41;
  *(_BYTE *)(this + 96) = v35;
  v28 = v42;
  *(_DWORD *)(this + 100) = v26;
  v29 = v44;
  *(_DWORD *)(this + 104) = v27;
  v30 = v46;
  *(_DWORD *)(this + 108) = v28;
  *(_DWORD *)(this + 116) = v29;
  v31 = v56;
  *(_DWORD *)(this + 120) = v30;
  v32 = v57;
  *(_DWORD *)(this + 128) = v31;
  v33 = v58;
  *(_DWORD *)(this + 132) = v32;
  v34 = v37;
  *(_DWORD *)(this + 112) = 2;
  *(_DWORD *)(this + 136) = v33;
  *(_DWORD *)(this + 140) = v34;
  return 0;
}
