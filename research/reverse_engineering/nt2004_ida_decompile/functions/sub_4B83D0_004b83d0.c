char __thiscall sub_4B83D0(_BYTE *this)
{
  float **v1; // eax
  double v3; // st7
  double v4; // st6
  double v5; // st6
  float v6; // esi
  void *v7; // eax
  CHAR *v8; // eax
  int *v9; // ebx
  int v10; // edx
  double v11; // st7
  int v12; // edi
  __int64 v13; // rax
  int v14; // ebp
  int v15; // esi
  int v16; // eax
  int *v17; // eax
  int v18; // eax
  int *v19; // edx
  int *i; // ecx
  int v21; // eax
  int v22; // esi
  int v23; // ecx
  int v24; // edx
  float **v25; // ecx
  float *v26; // ebp
  double v27; // st7
  double v28; // st7
  double v29; // st7
  bool v30; // bl
  int v31; // ecx
  const char *v32; // eax
  int v33; // eax
  long double v34; // st7
  long double v35; // st7
  int v36; // ecx
  float **v37; // esi
  float *v38; // edi
  float *v39; // esi
  float **v40; // eax
  LPVOID *v41; // edi
  char v42; // al
  const char *v44; // [esp+4h] [ebp-12Ch]
  char v45; // [esp+1Bh] [ebp-115h]
  int v46; // [esp+1Ch] [ebp-114h] BYREF
  int v47; // [esp+20h] [ebp-110h]
  float v48; // [esp+24h] [ebp-10Ch]
  float **v49; // [esp+28h] [ebp-108h] BYREF
  int *v50; // [esp+2Ch] [ebp-104h]
  float **v51; // [esp+30h] [ebp-100h]
  int v52; // [esp+34h] [ebp-FCh]
  int v53; // [esp+38h] [ebp-F8h]
  int v54; // [esp+3Ch] [ebp-F4h] BYREF
  float v55; // [esp+40h] [ebp-F0h]
  float v56; // [esp+44h] [ebp-ECh]
  _BYTE *v57; // [esp+48h] [ebp-E8h]
  int v58; // [esp+4Ch] [ebp-E4h]
  int v59; // [esp+50h] [ebp-E0h]
  char v60[4]; // [esp+54h] [ebp-DCh] BYREF
  float v61; // [esp+58h] [ebp-D8h]
  int v62; // [esp+64h] [ebp-CCh]
  float v63; // [esp+68h] [ebp-C8h]
  int v64; // [esp+6Ch] [ebp-C4h]
  char Destination[29]; // [esp+70h] [ebp-C0h] BYREF
  __int16 v66; // [esp+8Dh] [ebp-A3h]
  char v67; // [esp+8Fh] [ebp-A1h]
  char v68[32]; // [esp+90h] [ebp-A0h] BYREF
  char Buffer[128]; // [esp+B0h] [ebp-80h] BYREF

  LOBYTE(v1) = byte_76617C;
  v57 = this;
  if ( !byte_76617C && dword_7D7988 == -1 )
  {
    LOBYTE(v1) = sub_4FB240(&unk_7D7428);
    if ( !(_BYTE)v1 )
    {
      if ( dword_763BDC )
        this[28] = this[28] == 0;
      if ( this[28] || (v1 = (float **)sub_4633A0(dword_764D70)) != 0 )
      {
        v48 = 0.0;
        if ( flt_7D79F4 > 0.0 )
        {
          v47 = dword_6152EC;
          v48 = sub_507510(&flt_7D79F4) * (double)v47;
        }
        v47 = dword_6152EC;
        *(float *)&v46 = sub_45D2A0(&byte_764D68, 1) * (double)v47;
        v3 = (double)dword_6152EC;
        v4 = 0.0099999998 * v3;
        if ( v48 >= (double)*(float *)&v46 )
          v5 = v4 + v48;
        else
          v5 = v4 + *(float *)&v46;
        v53 = (__int64)v5;
        LODWORD(v56) = (__int64)(v3 - v5);
        LODWORD(v6) = dword_6152E8 - (__int64)(v3 * 0.050000001);
        v54 = (__int64)(v3 * 0.050000001);
        v55 = v6;
        v45 = 0;
        v48 = 175.0;
        v7 = (void *)sub_40C460(&dword_6291CC);
        if ( v7 )
        {
          v8 = sub_459BA0(v7);
          if ( !_strcmpi(v8, aTrackside) )
          {
            v48 = 350.0;
            v45 = 1;
          }
        }
        v47 = sub_40C4B0(&dword_6291CC);
        v49 = 0;
        v50 = 0;
        v51 = 0;
        v52 = 0;
        v9 = dword_632238;
        do
        {
          if ( *(v9 - 2178) != -1 && (!(unsigned __int8)sub_4EED40(v9 - 6324) || v45) && (*v9 & 2) != 0 )
          {
            v10 = *(v9 - 5828);
            v11 = *((float *)v9 - 5829) + 1.25;
            v62 = *(v9 - 5830);
            v63 = v11;
            v64 = v10;
            if ( (unsigned __int8)sub_5060A0((int)v60, (int)&v46, v48) )
            {
              v12 = (__int64)*(float *)v60;
              v13 = (__int64)v61;
              v14 = v13;
              if ( v12 > v54 && v12 < SLODWORD(v6) && (int)v13 > v53 && (int)v13 < SLODWORD(v56) && *(float *)&v46 > 3.0 )
              {
                v15 = sub_4DB530(&dword_765E60);
                if ( !v15 )
                {
                  if ( operator new(4u) )
                    v16 = sub_4B8CE0(0);
                  else
                    v16 = 0;
                  sub_4B8E10(v16, 0);
                  v15 = sub_4DB530(&dword_765E60);
                }
                *(_DWORD *)v15 = v9 - 6324;
                *(float *)(v15 + 4) = *(float *)&v46;
                *(_DWORD *)(v15 + 8) = v12;
                *(_DWORD *)(v15 + 12) = v14;
                v17 = (int *)operator new(0xCu);
                if ( v17 )
                {
                  *v17 = v15;
                  v17[1] = 0;
                  *((_BYTE *)v17 + 8) = 0;
                }
                else
                {
                  v17 = 0;
                }
                if ( v49 )
                {
                  v50[1] = (int)v17;
                }
                else
                {
                  v49 = (float **)v17;
                  v51 = (float **)v17;
                }
                v6 = v55;
                v50 = v17;
                ++v52;
              }
            }
          }
          v9 += 6326;
        }
        while ( (int)v9 < (int)dword_760D90 );
        if ( !v52 )
        {
          LOBYTE(v1) = sub_4DB110(&v49);
          return (char)v1;
        }
        v18 = sub_4B8D10(v49);
        v49 = (float **)v18;
        v19 = (int *)v18;
        if ( v18 )
        {
          for ( i = *(int **)(v18 + 4); i; i = (int *)i[1] )
            v19 = i;
        }
        v51 = (float **)v18;
        v50 = v19;
        v21 = sub_592CD0(off_609110);
        v22 = v21;
        v47 = v21;
        if ( v21 )
        {
          v23 = *(_DWORD *)(v21 + 172);
          v24 = *(_DWORD *)(v21 + 176);
          v54 = v53;
          v55 = (double)dword_6152E8 * 0.00125;
          v58 = v23;
          v25 = v49;
          v59 = v24;
          *(float *)&v46 = 0.0;
          v56 = (double)dword_6152EC * 0.0016666667;
          v51 = v49;
          if ( v49 )
          {
            v26 = *v49;
            if ( *v49 )
            {
              while ( 1 )
              {
                if ( v46 >= 3 || (double)dword_6152EC * 0.33399999 < (double)v54 )
                  goto LABEL_83;
                if ( v57[28] )
                  break;
LABEL_80:
                if ( v25 )
                {
                  v25 = (float **)v25[1];
                  v51 = v25;
                  if ( v25 )
                  {
                    v26 = *v25;
                    if ( *v25 )
                      continue;
                  }
                }
                goto LABEL_83;
              }
              if ( sub_463490(dword_764D70) )
                sub_463E00(dword_764D70, *(_DWORD *)(*(_DWORD *)v26 + 25248), -1.0);
              v27 = v26[1];
              Buffer[0] = 0;
              v28 = v27 / v48;
              *(float *)&v53 = v28;
              v29 = 0.55000001 - v28 * 0.33399999;
              *(float *)(v22 + 172) = v55 * v29;
              *(float *)(v22 + 176) = v29 * v56;
              v30 = dword_75CBB0 == 7 && *(int *)(*(_DWORD *)v26 + 20848) > 0;
              Destination[0] = byte_629120;
              memset(&Destination[1], 0, 0x1Cu);
              v66 = 0;
              v67 = 0;
              sub_4EDE00(Destination, 31);
              if ( !v30 )
              {
                v44 = (const char *)(*(_DWORD *)v26 + 24772);
                if ( *(_DWORD *)(*(_DWORD *)v26 + 25300) )
                  sprintf(Buffer, "%s", v44);
                else
                  sprintf(Buffer, "#%s %s", Destination, v44);
                goto LABEL_71;
              }
              v31 = *(_DWORD *)(*(_DWORD *)v26 + 20884);
              if ( v31 % 10 == 1 )
              {
                v32 = aSt;
                if ( v31 % 100 != 11 )
                  goto LABEL_67;
              }
              else if ( *(_DWORD *)(*(_DWORD *)v26 + 20884) % 10 == 2 )
              {
                if ( v31 % 100 != 12 )
                {
                  v32 = aNd;
                  goto LABEL_67;
                }
              }
              else if ( *(_DWORD *)(*(_DWORD *)v26 + 20884) % 10 == 3 && v31 % 100 != 13 )
              {
                v32 = aRd;
LABEL_67:
                sprintf(Buffer, "#%s %s (%d%s)", Destination, (const char *)(*(_DWORD *)v26 + 24772), v31, v32);
LABEL_71:
                if ( sub_4633A0(dword_764D70) )
                {
                  v33 = *(_DWORD *)v26;
                  if ( *(_DWORD *)(*(_DWORD *)v26 + 16584) == 2 && !*(_DWORD *)(v33 + 25300) )
                  {
                    v34 = fabs(sub_463E50(dword_764D70, *(float *)(v33 + 25248)) * 1000.0);
                    v60[0] = 0;
                    sprintf(v60, " [%d ms]", (unsigned int)(__int64)v34);
                    strcat(Buffer, v60);
                  }
                }
                if ( v45 )
                {
                  if ( !(unsigned __int8)sub_4D9AE0(&unk_7D5DAC) )
                  {
                    v35 = sqrt(
                            *(float *)(*(_DWORD *)v26 + 17628) * *(float *)(*(_DWORD *)v26 + 17628)
                          + *(float *)(*(_DWORD *)v26 + 17632) * *(float *)(*(_DWORD *)v26 + 17632)
                          + *(float *)(*(_DWORD *)v26 + 17636) * *(float *)(*(_DWORD *)v26 + 17636))
                        * 2.2369363;
                    if ( v35 > 1.0 )
                    {
                      v68[0] = 0;
                      sprintf(v68, " %.1f mph", (double)v35);
                      strcat(Buffer, v68);
                    }
                  }
                }
                sub_4B2890(v26, (int)Buffer, &v54, v47, v53, v57[28] == 0);
                v25 = v51;
                v22 = v47;
                ++v46;
                goto LABEL_80;
              }
              v32 = aTh;
              goto LABEL_67;
            }
          }
LABEL_83:
          v36 = v59;
          *(_DWORD *)(v22 + 172) = v58;
          *(_DWORD *)(v22 + 176) = v36;
        }
        v37 = v49;
        v1 = v49;
        v51 = v49;
        if ( v49 )
        {
          v38 = *v49;
          if ( *v49 )
          {
            while ( 1 )
            {
              v39 = v38;
              if ( v1 && (v40 = (float **)v1[1], (v51 = v40) != 0) )
                v38 = *v40;
              else
                v38 = 0;
              *v39 = 0.0;
              v39[1] = 3.4028235e38;
              v39[3] = 0.0;
              v39[2] = 0.0;
              v1 = (float **)operator new(0xCu);
              if ( v1 )
              {
                *v1 = v39;
                v1[1] = 0;
                *((_BYTE *)v1 + 8) = 0;
              }
              else
              {
                v1 = 0;
              }
              if ( dword_765E60 )
              {
                v1[1] = (float *)dword_765E60;
              }
              else
              {
                dword_765E64 = (int)v1;
                dword_765E68 = (int)v1;
              }
              dword_765E60 = (int)v1;
              ++dword_765E6C;
              if ( !v38 )
                break;
              v1 = v51;
            }
            v37 = v49;
          }
          for ( ; v37; LOBYTE(v1) = sub_5BE8AE(v41) )
          {
            v41 = (LPVOID *)v37;
            v42 = *((_BYTE *)v37 + 8);
            v37 = (float **)v37[1];
            if ( v42 )
              sub_5BE8AE(*v41);
          }
        }
      }
    }
  }
  return (char)v1;
}
