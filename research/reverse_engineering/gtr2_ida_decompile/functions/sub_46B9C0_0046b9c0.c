int __thiscall sub_46B9C0(int this, _DWORD *a2, int a3)
{
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // eax
  double v7; // st7
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // ecx
  char v30; // [esp+15h] [ebp-5EDh]
  int v31; // [esp+16h] [ebp-5ECh] BYREF
  int v32; // [esp+1Ah] [ebp-5E8h] BYREF
  int v33; // [esp+1Eh] [ebp-5E4h] BYREF
  int v34; // [esp+22h] [ebp-5E0h] BYREF
  int v35; // [esp+26h] [ebp-5DCh] BYREF
  int v36; // [esp+2Ah] [ebp-5D8h] BYREF
  int v37; // [esp+2Eh] [ebp-5D4h] BYREF
  int v38; // [esp+32h] [ebp-5D0h] BYREF
  int v39; // [esp+36h] [ebp-5CCh] BYREF
  int v40; // [esp+3Ah] [ebp-5C8h] BYREF
  int v41; // [esp+3Eh] [ebp-5C4h] BYREF
  int v42; // [esp+42h] [ebp-5C0h] BYREF
  int v43; // [esp+46h] [ebp-5BCh] BYREF
  int v44; // [esp+4Ah] [ebp-5B8h] BYREF
  int v45; // [esp+4Eh] [ebp-5B4h] BYREF
  int v46; // [esp+52h] [ebp-5B0h] BYREF
  int v47; // [esp+56h] [ebp-5ACh] BYREF
  int v48; // [esp+5Ah] [ebp-5A8h] BYREF
  int v49; // [esp+5Eh] [ebp-5A4h] BYREF
  int v50; // [esp+62h] [ebp-5A0h] BYREF
  int v51; // [esp+66h] [ebp-59Ch] BYREF
  _BYTE v52[512]; // [esp+6Ah] [ebp-598h] BYREF
  int v53; // [esp+26Ah] [ebp-398h]
  char v54; // [esp+26Eh] [ebp-394h]
  int v55; // [esp+276h] [ebp-38Ch]
  int v56; // [esp+27Ah] [ebp-388h]
  int v57; // [esp+27Eh] [ebp-384h]
  _BYTE v58[512]; // [esp+282h] [ebp-380h] BYREF
  char v59[384]; // [esp+482h] [ebp-180h] BYREF

  memset(v58, 0, sizeof(v58));
  v4 = a2;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v34 = 0;
  v46 = 0;
  v38 = 0;
  v50 = 0;
  *(float *)&v31 = 0.0;
  v40 = 0;
  v33 = 0;
  v32 = 0;
  v51 = 0;
  v5 = *a2;
  v53 = 0;
  v57 = 0;
  v55 = 0;
  v56 = 0;
  v54 = 1;
  v30 = 1;
  v41 = 0;
  v39 = 0;
  v37 = 0;
  v35 = 0;
  v42 = 0;
  v36 = 1065353216;
  if ( (*(int (__thiscall **)(_DWORD *, _BYTE *, int))(v5 + 36))(a2, v58, 512) )
  {
    do
    {
      v6 = sub_612EB0(v52);
      if ( v6 )
      {
        if ( v6 == 2 )
          break;
        if ( v6 == 4 )
          return 1;
      }
      else
      {
        sub_6134B0("POSITION", (int)&v43, (int)&v44, (int)&v45, 0, 0, 0, 0, 0);
        sub_6134B0("ORIENTATION", (int)&v47, (int)&v48, (int)&v49, 0, 0, 0, 0, 0);
        sub_6134B0((char *)off_6F5D0C, (int)&v32, (int)&v33, 0, 0, 0, 0, 0, 0);
        sub_6133A0("COLOR", (int)&v42, (int)&v35, (int)&v37, 0);
        sub_6134B0("CLIPPLANES", (int)&v40, (int)&v31, 0, 0, 0, 0, 0, 0);
        sub_6134B0("LODMULTIPLIER", (int)&v36, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("SIZE", (int)&v50, (int)&v38, 0, 0, 0, 0, 0, 0);
        sub_6134B0("CENTER", (int)&v46, (int)&v34, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MIPMAPLODBIAS", (int)&v51, 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("FLAGS1", (int)&v39, 0, 0, 0);
        sub_6133A0("FLAGS2", (int)&v41, 0, 0, 0);
        if ( sub_6137E0(v52) )
        {
          v4 = a2;
          if ( !strcmp(v59, "FALSE") )
            v30 = 0;
        }
        sub_6134B0("ACTIVATIONLOCATION", this + 128, this + 132, this + 136, 0, 0, 0, 0, 0);
        sub_6134B0("ACTIVATIONRADIUS", this + 140, 0, 0, 0, 0, 0, 0, 0);
      }
    }
    while ( (*(int (__thiscall **)(_DWORD *, _BYTE *, int))(*v4 + 36))(v4, v58, 512) );
  }
  switch ( dword_B71758 )
  {
    case 0:
      v7 = *(float *)&v31 - 250.0;
      goto LABEL_17;
    case 2:
      v7 = *(float *)&v31 + 250.0;
      goto LABEL_17;
    case 3:
      v7 = *(float *)&v31 + 500.0;
LABEL_17:
      *(float *)&v31 = v7;
      break;
  }
  sub_615860(a3);
  v9 = v44;
  *(_DWORD *)(this + 12) = v43;
  v10 = v45;
  *(_DWORD *)(this + 16) = v9;
  *(_DWORD *)(this + 20) = v10;
  v11 = v47;
  v12 = v49;
  v13 = v48;
  *(_DWORD *)(this + 24) = v47;
  *(_DWORD *)(this + 28) = v13;
  *(_DWORD *)(this + 32) = v12;
  *(_DWORD *)(this + 148) = v11;
  v14 = v33;
  *(_DWORD *)(this + 152) = v13;
  *(_DWORD *)(this + 156) = v12;
  v15 = v32;
  *(_DWORD *)(this + 48) = v32;
  v16 = v14;
  *(_DWORD *)(this + 52) = v14;
  v17 = v40;
  *(_DWORD *)(this + 56) = v15;
  v18 = v31;
  *(_DWORD *)(this + 64) = v17;
  v19 = v50;
  *(_DWORD *)(this + 60) = v16;
  v20 = v36;
  *(_DWORD *)(this + 68) = v18;
  v21 = v38;
  *(_DWORD *)(this + 76) = v19;
  v22 = v34;
  *(_DWORD *)(this + 72) = v20;
  v23 = v46;
  *(_DWORD *)(this + 80) = v21;
  v24 = v51;
  *(_DWORD *)(this + 88) = v22;
  v25 = v42;
  *(_DWORD *)(this + 84) = v23;
  *(_DWORD *)(this + 92) = v24;
  v26 = v35;
  *(_DWORD *)(this + 100) = v25;
  v27 = v39;
  *(_BYTE *)(this + 96) = v30;
  v28 = v37;
  *(_DWORD *)(this + 104) = v26;
  v29 = v41;
  *(_DWORD *)(this + 116) = v27;
  *(_DWORD *)(this + 108) = v28;
  *(_DWORD *)(this + 112) = 1;
  *(_DWORD *)(this + 120) = v29;
  return 0;
}
