void __usercall sub_55DCF0(
        int a1@<esi>,
        int a2,
        int a3,
        int a4,
        void *Block,
        char *String1,
        unsigned int a7,
        int a8,
        int a9,
        int a10,
        __int128 a11)
{
  FILE **v11; // ecx
  FILE **v12; // esi
  int v13; // ebp
  char *v14; // edi
  const char *v15; // eax
  const char *v16; // eax
  FILE *v17; // eax
  int v18; // eax
  int i; // edi
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  const char *v23; // ecx
  int j; // ebx
  const char *v25; // edi
  int v26; // eax
  const char *v27; // ecx
  char *v28; // eax
  char v29; // cl
  const CHAR *v30; // eax
  __int128 *v31; // eax
  char *v32; // edi
  const CHAR *v34; // eax
  char *v35; // ebx
  char *v36; // ecx
  char *v37; // eax
  int v38; // ebp
  int v39; // edi
  const char *v40; // eax
  void *v41; // eax
  bool v42; // zf
  float v43; // [esp+3C74h] [ebp-14h]
  FILE *v44; // [esp+3C74h] [ebp-14h]
  int vars0; // [esp+3C88h] [ebp+0h] BYREF

  sub_631BD0();
  v12 = v11;
  if ( *v11 )
  {
    fseek(*v11, 0, 0);
    sub_631E50(v12 + 71, 4, 1, *v12);
    fclose(*v12);
    *v12 = 0;
  }
  if ( (_BYTE)dword_757C1C )
  {
    v13 = dword_91E084;
    if ( dword_91E084 )
    {
      v14 = dword_B6FCEC;
      v15 = dword_B6FCEC;
      if ( !dword_B6FCEC )
        v15 = WindowName;
      a7 = strlen(v15);
      if ( a7 && dword_B6FC88 > 0 )
      {
        switch ( dword_B6FC88 )
        {
          case 1:
          case 2:
          case 5:
          case 10:
          case 20:
          case 50:
          case 100:
            break;
          default:
            a3 = 10;
            sub_4762A0(dword_B6FC74, &a3);
            v14 = dword_B6FCEC;
            break;
        }
        if ( *(_DWORD *)dword_B640C8 != 6 || dword_B6FCAC )
        {
          v16 = v14;
          if ( !v14 )
            v16 = WindowName;
          v17 = fopen(v16, "wb");
          *v12 = v17;
          if ( v17 )
          {
            v43 = 40.0 / (double)dword_B6FC88;
            v18 = 10 * sub_4015C0(v43);
            v12[2] = (FILE *)v18;
            if ( v18 >= 10 )
            {
              if ( v18 > 400 )
                v12[2] = (FILE *)400;
            }
            else
            {
              v12[2] = (FILE *)10;
            }
            v44 = *v12;
            a9 = 0;
            sub_631E50(&a9, 4, 1, v44);
            for ( i = 0; i < 4; ++i )
              *((_BYTE *)&a2 + i) = rand();
            sub_631E50(&a2, 4, 1, *v12);
            v20 = BYTE2(a2);
            v21 = BYTE2(a2) + BYTE1(a2) + 77;
            v12[68] = (FILE *)((unsigned __int8)a2 + BYTE1(a2) + 18);
            v22 = HIBYTE(a2);
            v12[69] = (FILE *)v21;
            v12[70] = (FILE *)(v22 + v20 + 15);
            v12[71] = 0;
            a8 = 1028443341;
            sub_557190(v12, (int)&a8, 4);
            sub_557190(
              v12,
              v13 + 21568 + 108 * *(_DWORD *)(v13 + 21788),
              strlen((const char *)(v13 + 21568 + 108 * *(_DWORD *)(v13 + 21788))) + 1);
            sub_557190(v12, v13 + 21808, strlen((const char *)(v13 + 21808)) + 1);
            sub_557190(v12, v13 + 22084, strlen((const char *)(v13 + 22084)) + 1);
            v23 = dword_B6F6A8;
            if ( !dword_B6F6A8 )
              v23 = WindowName;
            sub_557190(v12, (int)v23, strlen(v23) + 1);
            a7 = 63;
            sub_557190(v12, (int)&a7, 4);
            HIBYTE(vars0) = 4;
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Elapsed Time (s)", strlen("Elapsed Time (s)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Pos X (m)", strlen("Pos X (m)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Pos Y (m)", strlen("Pos Y (m)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Pos Z (m)", strlen("Pos Z (m)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Yaw (rads)", strlen("Yaw (rads)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Lat Accel (m/s)", strlen("Lat Accel (m/s)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Vert Accel (m/s)", strlen("Vert Accel (m/s)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Long Accel (m/s)", strlen("Long Accel (m/s)") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Engine RPM", strlen("Engine RPM") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Clutch RPM", strlen("Clutch RPM") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Unfiltered Throttle", strlen("Unfiltered Throttle") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Throttle", strlen("Throttle") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Unfiltered Brake", strlen("Unfiltered Brake") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Brake", strlen("Brake") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Unfiltered Steering", strlen("Unfiltered Steering") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Steering", strlen("Steering") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Unfiltered Clutch", strlen("Unfiltered Clutch") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Clutch", strlen("Clutch") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Ground Speed", strlen("Ground Speed") + 1);
            for ( j = 0; j < 4; ++j )
            {
              if ( j )
              {
                if ( j == 1 )
                {
                  v25 = "FR ";
                }
                else
                {
                  v25 = "RL ";
                  if ( j != 2 )
                    v25 = "RR ";
                }
              }
              else
              {
                v25 = "FL ";
              }
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Wheelspeed (m/s)", strlen("Wheelspeed (m/s)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Suspension Deflection (m)", strlen("Suspension Deflection (m)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Suspension Speed (m/s)", strlen("Suspension Speed (m/s)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Undertray Ride Height (m)", strlen("Undertray Ride Height (m)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Tyre Left Temp (K)", strlen("Tyre Left Temp (K)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Tyre Center Temp (K)", strlen("Tyre Center Temp (K)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Tyre Right Temp (K)", strlen("Tyre Right Temp (K)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Tyre Pressure (kPa)", strlen("Tyre Pressure (kPa)") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Tyre Wear", strlen("Tyre Wear") + 1);
              sub_557190(v12, (int)&vars0 + 3, 1);
              sub_557190(v12, (int)v25, strlen(v25));
              sub_557190(v12, (int)"Corner Weight", strlen("Corner Weight") + 1);
            }
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Gear", strlen("Gear") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Water Temperature", strlen("Water Temperature") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Oil Temperature", strlen("Oil Temperature") + 1);
            sub_557190(v12, (int)&vars0 + 3, 1);
            sub_557190(v12, (int)"Fuel Remaining", strlen("Fuel Remaining") + 1);
            v26 = dword_BE1BD8 + 2824 * *(_DWORD *)(v13 + 22472);
            LOBYTE(STACK[0x3EB0]) = 0;
            LOBYTE(STACK[0x3FB0]) = 0;
            v27 = *(const char **)(v26 + 8);
            if ( !v27 )
              v27 = WindowName;
            strcpy((char *)&STACK[0x3EB0], v27);
            v28 = (char *)(v13 + 22212);
            do
            {
              v29 = *v28;
              v28[(_DWORD)((char *)&STACK[0x3FB0] - v13 - 22212)] = *v28;
              ++v28;
            }
            while ( v29 );
            sub_546B80();
            LOBYTE(a11) = 0;
            memset((char *)&a11 + 1, 0, 0x1FCu);
            LOWORD(STACK[0x3EB1]) = 0;
            LOBYTE(STACK[0x3EB3]) = 0;
            v30 = dword_B6F68C;
            if ( !dword_B6F68C )
              v30 = WindowName;
            sub_630FE0(&a11, v30, 511);
            LOBYTE(STACK[0x3EB3]) = 0;
            v31 = (__int128 *)((char *)&a11 + strlen((const char *)&a11));
            if ( v31 > &a11 )
            {
              while ( *(_BYTE *)v31 != 46 )
              {
                v31 = (__int128 *)((char *)v31 - 1);
                if ( v31 <= &a11 )
                  goto LABEL_43;
              }
              *(_BYTE *)v31 = 0;
            }
LABEL_43:
            v32 = (char *)&a10 + 3;
            while ( *++v32 )
              ;
            strcpy(v32, ".gdb");
            sub_5875F0(&STACK[0x41B4]);
            STACK[0x7E38] = 0;
            sub_435800(a1, (int)&vars0);
            LOBYTE(STACK[0x7E38]) = 1;
            sub_5886A0(&STACK[0x3EB4], &STACK[0x5F84], 2);
            a2 = sub_51C780();
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(40, &a2);
            a2 = (a2 ^ 0x12F3DCAA) + 1559;
            sub_557190(v12, (int)&a2, 4);
            a2 = 355 * (STACK[0x41BC] ^ 0xFFFAFE11);
            sub_557190(v12, (int)&a2, 4);
            Block = (void *)(dword_B68528 ^ 0x516141F2);
            sub_557190(v12, (int)&Block, 4);
            sub_617BD0(151, &a2);
            a2 = (a2 ^ 0x2033DAAA) - 1559;
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(4, &a2);
            a2 = 1559 * (a2 ^ 0x7711DAAB);
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(148, &a2);
            a2 = 69017 * (a2 ^ 0x7123456C);
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(153, &a2);
            a2 = 59015 * (a2 ^ 0x99009977);
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(26, &a2);
            a2 = 49414 * (a2 ^ 0xEEAC5370);
            sub_557190(v12, (int)&a2, 4);
            a2 = sub_51C780();
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(161, &a2);
            a2 = 330358 * (a2 ^ 0x4940AF7E);
            sub_557190(v12, (int)&a2, 4);
            a2 = (1121110 * (dword_BE27AC - 1413405834)) ^ 0x12131415;
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(82, &a2);
            a2 = (a2 ^ 0x3940AF73) + 330358;
            sub_557190(v12, (int)&a2, 4);
            a2 = 9 * ((dword_B64148 + 468717589) ^ 0xABBA717E);
            sub_557190(v12, (int)&a2, 4);
            a2 = sub_51C780();
            sub_557190(v12, (int)&a2, 4);
            sub_617BD0(242, &a2);
            a2 = 11600537 * ((unsigned int)&unk_B12003 ^ a2);
            sub_557190(v12, (int)&a2, 4);
            v34 = dword_B6F68C;
            if ( !dword_B6F68C )
              v34 = WindowName;
            String1 = 0;
            a7 = -1;
            sub_615860(v34);
            v35 = String1;
            v36 = String1;
            if ( !String1 )
              v36 = (char *)WindowName;
            v37 = &v36[strlen(v36)];
            if ( v37 > v36 )
            {
              while ( *v37 != 46 )
              {
                if ( --v37 <= v36 )
                  goto LABEL_54;
              }
              *v37 = 0;
              v35 = String1;
            }
LABEL_54:
            a2 = 0;
            if ( dword_BE1CD0 > 0 )
            {
              v38 = 0;
              a4 = dword_BE1CD0;
              while ( 1 )
              {
                v39 = dword_BE1CD8 + v38;
                v40 = v35;
                if ( !v35 )
                  v40 = WindowName;
                if ( !_stricmp(v40, (const char *)(v38 + 4 + dword_BE1CD8)) )
                  a2 = (445 * *(_DWORD *)(v39 + 392)) ^ 0xFEC950A4;
                v38 += 396;
                if ( !--a4 )
                  break;
                v35 = String1;
              }
            }
            sub_557190(v12, (int)&a2, 4);
            sub_5575E0();
            v41 = Block;
            v42 = Block == 0;
            v12[72] = 0;
            v12[73] = 0;
            if ( !v42 )
              j_j__free(v41);
            LOBYTE(STACK[0x7E34]) = 2;
            sub_431A70(&STACK[0x7A70]);
            if ( STACK[0x5FE8] )
              j_j__free((void *)STACK[0x5FE8]);
            if ( STACK[0x41DC] )
              j_j__free((void *)STACK[0x41DC]);
            if ( STACK[0x41D4] )
              j_j__free((void *)STACK[0x41D4]);
            if ( STACK[0x41CC] )
              j_j__free((void *)STACK[0x41CC]);
            if ( STACK[0x41C4] )
              j_j__free((void *)STACK[0x41C4]);
            if ( STACK[0x41BC] )
              j_j__free((void *)STACK[0x41BC]);
            if ( STACK[0x41B0] )
              j_j__free((void *)STACK[0x41B0]);
          }
        }
      }
    }
  }
}
