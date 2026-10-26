int __thiscall sub_4E6E80(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // edi
  int v8; // ebx
  int v10; // eax
  char *v11; // edi
  int v13; // eax
  char *v14; // edi
  double v16; // st7
  int v17; // eax
  char *v18; // edi
  double v20; // st7
  int v21; // eax
  char *v22; // edi
  double v24; // st7
  int v25; // eax
  char *v26; // edi
  double v28; // st7
  int v29; // eax
  char *v30; // edi
  double v32; // st7
  int v33; // eax
  char *v34; // edi
  double v36; // st7
  int v37; // eax
  char *v38; // edi
  double v40; // st7
  int v41; // eax
  char *v42; // edi
  double v44; // st7
  int v45; // eax
  char *v46; // edi
  double v48; // st7
  int i; // edi
  double v50; // st7
  int v51; // [esp+74h] [ebp-58h]
  int v53; // [esp+88h] [ebp-44h] BYREF
  char Buffer[4]; // [esp+8Ch] [ebp-40h] BYREF
  char v55[59]; // [esp+90h] [ebp-3Ch] BYREF
  char v56; // [esp+CBh] [ebp-1h]
  float v57; // [esp+DCh] [ebp+10h]

  v7 = this;
  v53 = 1;
  if ( a5 && a6 )
  {
    v8 = dword_91E084 + 14824;
    v53 = 0;
    if ( dword_91E084 == -14824 )
      return -1;
    sub_4FBF60(dword_91E084 + 14824);
    if ( *(_DWORD *)(v8 + 108) )
      v7[1] = 1;
    if ( *(int *)((v7[1] << 6) + v8 + 40) <= 1 )
      sub_4E6020(v7, 1);
    if ( v7[1] == 2 )
    {
      sub_4605B0(16);
      v51 = 1;
    }
    else
    {
      sub_4605B0(16);
      v51 = 0;
    }
    sub_4605B0(17);
    sub_630FE0(Buffer, v8 + 54, 63);
    v10 = v7[1];
    v56 = 0;
    if ( v10 )
    {
      ((void (__thiscall *)(int, char *, int))loc_5F0350)(a5, byte_FFFFFF, v51);
      sub_5F0DD0(Buffer, 470, 244, a6, 0);
    }
    else
    {
      v11 = (char *)&v53 + 3;
      while ( *++v11 )
        ;
      strcpy(v11, " *");
      ((void (__thiscall *)(int, char *, int))loc_5F0350)(a5, byte_FFFFFF, v51);
      sub_5F0DD0(Buffer, 470, 244, a6, 0);
      v7 = this;
    }
    sub_630FE0(Buffer, v8 + 118, 63);
    v13 = v7[1];
    v56 = 0;
    if ( v13 == 1 )
    {
      v14 = (char *)&v53 + 3;
      while ( *++v14 )
        ;
      strcpy(v14, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 341, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 341, a6, 0);
    }
    v16 = sub_4FC570(1);
    sprintf(Buffer, "%.1f", v16);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 341, a6, 0);
    sub_630FE0(Buffer, v8 + 182, 63);
    v17 = v7[1];
    v56 = 0;
    if ( v17 == 2 )
    {
      v18 = (char *)&v53 + 3;
      while ( *++v18 )
        ;
      strcpy(v18, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 369, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 369, a6, 0);
    }
    v20 = sub_4FC570(2);
    sprintf(Buffer, "%.1f", v20);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 369, a6, 0);
    sub_630FE0(Buffer, v8 + 246, 63);
    v21 = v7[1];
    v56 = 0;
    if ( v21 == 3 )
    {
      v22 = (char *)&v53 + 3;
      while ( *++v22 )
        ;
      strcpy(v22, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 397, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 397, a6, 0);
    }
    v24 = sub_4FC570(3);
    sprintf(Buffer, "%.1f", v24);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 397, a6, 0);
    sub_630FE0(Buffer, v8 + 310, 63);
    v25 = v7[1];
    v56 = 0;
    if ( v25 == 4 )
    {
      v26 = (char *)&v53 + 3;
      while ( *++v26 )
        ;
      strcpy(v26, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 425, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 425, a6, 0);
    }
    v28 = sub_4FC570(4);
    sprintf(Buffer, "%.1f", v28);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 425, a6, 0);
    sub_630FE0(Buffer, v8 + 374, 63);
    v29 = v7[1];
    v56 = 0;
    if ( v29 == 5 )
    {
      v30 = (char *)&v53 + 3;
      while ( *++v30 )
        ;
      strcpy(v30, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 591, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 591, a6, 0);
    }
    v32 = sub_4FC570(5);
    sprintf(Buffer, "%.1f", v32);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 591, a6, 0);
    sub_630FE0(Buffer, v8 + 438, 63);
    v33 = v7[1];
    v56 = 0;
    if ( v33 == 6 )
    {
      v34 = (char *)&v53 + 3;
      while ( *++v34 )
        ;
      strcpy(v34, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 619, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 619, a6, 0);
    }
    v36 = sub_4FC570(6);
    sprintf(Buffer, "%.1f", v36);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 619, a6, 0);
    sub_630FE0(Buffer, v8 + 502, 63);
    v37 = v7[1];
    v56 = 0;
    if ( v37 == 7 )
    {
      v38 = (char *)&v53 + 3;
      while ( *++v38 )
        ;
      strcpy(v38, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 647, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 647, a6, 0);
    }
    v40 = sub_4FC570(7);
    sprintf(Buffer, "%.1f", v40);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 647, a6, 0);
    sub_630FE0(Buffer, v8 + 566, 63);
    v41 = v7[1];
    v56 = 0;
    if ( v41 == 8 )
    {
      v42 = (char *)&v53 + 3;
      while ( *++v42 )
        ;
      strcpy(v42, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 675, a6, 0);
      v7 = this;
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 470, 675, a6, 0);
    }
    v44 = sub_4FC570(8);
    sprintf(Buffer, "%.1f", v44);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 675, a6, 0);
    sub_630FE0(Buffer, v8 + 630, 63);
    v45 = v7[1];
    v56 = 0;
    if ( v45 == 9 )
    {
      v46 = (char *)&v53 + 3;
      while ( *++v46 )
        ;
      strcpy(v46, " *");
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(v55, 470, 703, a6, 0);
    }
    else
    {
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(v55, 470, 703, a6, 0);
    }
    v48 = sub_4FC570(9);
    sprintf(v55, "%.1f", v48);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 703, a6, 0);
    v57 = 0.0;
    for ( i = 2; i <= 9; ++i )
    {
      v50 = sub_4FC570(i);
      v57 = v50 + v57;
    }
    sprintf(Buffer, "%.1f", v57);
    ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
    sub_5F0DD0(Buffer, 680, 783, a6, 0);
    if ( dword_91E07C[3232] != 1 || byte_B666C0 )
    {
      ((void (__thiscall *)(int, int *))loc_5F0350)(a5, dword_FF0000);
      sub_5F0DD0("X", 840, 550, a6, 0);
    }
    else
    {
      sprintf(Buffer, "%.0f", 100.0 - (dbl_B66710 - 0.6875) * 3.2 * 100.0);
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 840, 550, a6, 0);
    }
    if ( dword_91E07C[3528] != 1 || byte_B66BC0 )
    {
      ((void (__thiscall *)(int, int *))loc_5F0350)(a5, dword_FF0000);
      sub_5F0DD0("X", 1040, 550, a6, 0);
    }
    else
    {
      sprintf(Buffer, "%.0f", 100.0 - (dbl_B66C10 - 0.6875) * 3.2 * 100.0);
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 1040, 550, a6, 0);
    }
    if ( dword_91E07C[3824] != 1 || byte_B670C0 )
    {
      ((void (__thiscall *)(int, int *))loc_5F0350)(a5, dword_FF0000);
      sub_5F0DD0("X", 840, 720, a6, 0);
    }
    else
    {
      sprintf(Buffer, "%.0f", 100.0 - (dbl_B67110 - 0.6875) * 3.2 * 100.0);
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 840, 720, a6, 0);
    }
    if ( dword_91E07C[4120] == 1 && !byte_B675C0 )
    {
      sprintf(Buffer, "%.0f", 100.0 - (dbl_B67610 - 0.6875) * 3.2 * 100.0);
      ((void (__thiscall *)(int, char *))loc_5F0350)(a5, byte_FFFFFF);
      sub_5F0DD0(Buffer, 1040, 720, a6, 0);
      return v53;
    }
    ((void (__thiscall *)(int, int *))loc_5F0350)(a5, dword_FF0000);
    sub_5F0DD0("X", 1040, 720, a6, 0);
  }
  return v53;
}
