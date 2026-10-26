void __thiscall sub_4DDB70(int this, float a2, char a3)
{
  int v4; // ebp
  long double v5; // st7
  long double v6; // st7
  char v7; // bl
  int v8; // eax
  char v9; // dl
  _DWORD *v10; // ecx
  char v11; // cl
  bool v12; // dl
  bool v13; // al
  bool v14; // cl
  int v15; // edi
  long double v16; // st7
  long double v17; // st7
  long double v18; // st7
  double v19; // st7
  double v20; // st6
  double v21; // st7
  double v22; // st7
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  double v26; // st7
  double v27; // st6
  double v28; // st7
  double v29; // st7
  long double v30; // st6
  long double v31; // st5
  long double v33; // st4
  unsigned __int8 v34; // c2
  unsigned __int8 v35; // c3
  long double v36; // st2
  int v37; // eax
  int v38; // edx
  float *v39; // eax
  double v40; // st7
  double v41; // st6
  double v42; // st5
  double v43; // st4
  long double v44; // st5
  double v45; // st7
  signed int i; // ebp
  float *v47; // edi
  unsigned __int8 v49; // c0
  unsigned __int8 v50; // c3
  double v51; // st7
  long double v52; // st7
  int v53; // ebx
  _DWORD *v54; // edx
  int v55; // edi
  _DWORD *v56; // edx
  double v57; // st7
  int v58; // [esp-4h] [ebp-C8h]
  float v59; // [esp+14h] [ebp-B0h]
  float v60; // [esp+14h] [ebp-B0h]
  float v61; // [esp+14h] [ebp-B0h]
  float v62; // [esp+14h] [ebp-B0h]
  float v63; // [esp+14h] [ebp-B0h]
  float v64; // [esp+18h] [ebp-ACh]
  float v65; // [esp+18h] [ebp-ACh]
  float v66; // [esp+18h] [ebp-ACh]
  float v67; // [esp+1Ch] [ebp-A8h]
  float v68; // [esp+1Ch] [ebp-A8h]
  float v69; // [esp+20h] [ebp-A4h]
  float *v70; // [esp+30h] [ebp-94h]
  float v71; // [esp+34h] [ebp-90h]
  float v72; // [esp+38h] [ebp-8Ch]
  int v73; // [esp+3Ch] [ebp-88h]
  int v74; // [esp+40h] [ebp-84h]
  char Destination; // [esp+44h] [ebp-80h] BYREF
  _BYTE v76[124]; // [esp+45h] [ebp-7Fh] BYREF
  __int16 v77; // [esp+C1h] [ebp-3h]
  char v78; // [esp+C3h] [ebp-1h]

  v4 = *(_DWORD *)this + 84;
  v70 = (float *)v4;
  if ( *(_BYTE *)(*(_DWORD *)this + 17412) && dword_75CBB4 >= 5 )
  {
    if ( !*(_BYTE *)(this + 188) )
    {
      *(_BYTE *)(this + 198) = 0;
      *(_BYTE *)(this + 196) = 0;
      *(_BYTE *)(this + 197) = 0;
      *(_DWORD *)(this + 192) = 0;
    }
    *(_BYTE *)(this + 188) = 1;
    if ( !a3 )
    {
      v5 = sqrt(
             *(float *)(v4 + 17544) * *(float *)(v4 + 17544)
           + *(float *)(v4 + 17548) * *(float *)(v4 + 17548)
           + *(float *)(v4 + 17552) * *(float *)(v4 + 17552))
         - flt_7D74DC;
      if ( v5 > 0.0 )
      {
        v6 = v5 * a2 + *(float *)(this + 192);
        *(float *)(this + 192) = v6;
        if ( v6 > 7.5 )
        {
          if ( *(_BYTE *)(this + 198) )
            *(_BYTE *)(this + 197) = 1;
          else
            *(_BYTE *)(this + 196) = 1;
        }
      }
      goto LABEL_56;
    }
  }
  else
  {
    if ( *(_BYTE *)(this + 188) )
    {
      *(_BYTE *)(this + 188) = 0;
      if ( dword_767310 >= 1 && dword_75CBB0 == 7 )
      {
        v7 = *(_BYTE *)(this + 196);
        if ( v7 || *(_BYTE *)(this + 197) )
        {
          v11 = *(_BYTE *)(this + 198);
          v12 = !v11 && *(float *)(this + 192) > 15.0;
          v13 = 0;
          if ( *(int *)(this + 64) > 0 )
            v13 = *(_DWORD *)(this + 68) == 2;
          v14 = !v11 && v13;
          if ( *(float *)(this + 192) <= 150.0 )
          {
            if ( (unsigned int)dword_7D7540 < 2 || dword_7D7540 == 6 || dword_7D7540 == 7 )
            {
              if ( v7 && *(_BYTE *)(this + 197) || v14 || v12 )
              {
                Destination = byte_629120;
                memset(v76, 0, sizeof(v76));
                v77 = 0;
                v78 = 0;
                if ( v7 && *(_BYTE *)(this + 197) || v12 )
                  strncpy(&Destination, aSpedIntoAndOut, 0x7Fu);
                else
                  strncpy(&Destination, aSpedIntoPitLan_0, 0x7Fu);
                v58 = 1;
              }
              else
              {
                Destination = byte_629120;
                memset(v76, 0, sizeof(v76));
                v77 = 0;
                v78 = 0;
                if ( v7 )
                  strncpy(&Destination, aSpedIntoPitLan, 0x7Fu);
                else
                  strncpy(&Destination, aSpedOutOfPitLa, 0x7Fu);
                v58 = 2;
              }
              v78 = 0;
              sub_4DC690((int *)this, &Destination, v58, 0);
            }
            else
            {
              sub_4DC690((int *)this, aSpeedingInPitl, 3, 0);
            }
          }
          else
          {
            sub_4DCCC0((int *)this, aExcessiveSpeed);
          }
        }
        else if ( !*(_BYTE *)(this + 198) )
        {
          v8 = *(_DWORD *)(this + 64);
          v9 = 0;
          if ( v8 > 0 )
          {
            v10 = (_DWORD *)(this + 68);
            do
            {
              if ( *v10 == 2 )
                v9 = 1;
              v10 += 3;
              --v8;
            }
            while ( v8 );
            if ( v9 )
              sub_4DC9C0((int *)this, 2);
          }
        }
      }
    }
    if ( !a3 )
    {
LABEL_56:
      v15 = sub_514EE0(v4);
      v74 = v15;
      if ( sub_4DD160((_DWORD *)this, 2) && dword_7D7540 )
        sub_4DE880(a2);
      if ( *(_BYTE *)(v4 + 19229) && *(float *)(v4 + 17564) < -15.0 && fabs(*(float *)(v15 + 164)) > 0.00019999999 )
      {
        if ( *(float *)(v4 + 17676) >= 0.0 )
          v16 = *(float *)(v4 + 17676);
        else
          v16 = 0.0;
        v17 = sqrt(v16) * a2;
        v59 = v17;
        v18 = v17 + *(float *)(this + 208);
        *(float *)(this + 208) = v18;
        v67 = v59 + *(float *)(this + 212);
        *(float *)(this + 212) = v67;
        if ( v18 <= 1.9 && v67 <= 2.9000001 )
          goto LABEL_78;
        if ( dword_75CBB0 == 7 )
        {
          if ( *(_BYTE *)(this + 204) )
          {
            sub_4DC690((int *)this, aRidingWall, 1, 0);
          }
          else
          {
            *(_BYTE *)(this + 204) = 1;
            sub_4DC580((void *)this, aRidingWall);
          }
        }
        else if ( dword_75CBB0 == 5 && *(_DWORD *)(this + 116) == 2 )
        {
          *(_DWORD *)(this + 116) = 1;
          if ( sub_41F230(dword_62A170, aLapTimeWillNot_0, ::Destination) )
          {
            strncpy(::Destination, aLapTimeWillNot_0, 0x1FFu);
            byte_62A37B = 0;
          }
          sub_45D100(&byte_764D68, (int)::Destination, 3, 16909060, 0);
        }
        *(_DWORD *)(this + 212) = 0;
      }
      *(_DWORD *)(this + 208) = 0;
LABEL_78:
      if ( sub_4DD160((_DWORD *)this, 1) && *(int *)(this + 228) >= 0 )
        sub_4DEBE0(*(float *)(*(_DWORD *)this + 17564));
      if ( !sub_4DD160((_DWORD *)this, 1) || (unsigned __int8)sub_4DEB10(*(_DWORD *)this + 20836) )
      {
        *(_BYTE *)(this + 248) = 0;
      }
      else
      {
        v19 = (*(float *)(v4 + 17528) - *(float *)(v15 + 8)) * *(float *)(v15 + 52)
            + (*(float *)(v4 + 17524) - *(float *)(v15 + 4)) * *(float *)(v15 + 48)
            + (*(float *)(v4 + 17520) - *(float *)v15) * *(float *)(v15 + 44);
        if ( v19 >= 0.0 )
          v20 = v19 - *(float *)(v15 + 152);
        else
          v20 = -(*(float *)(v15 + 148) + v19);
        v60 = v20;
        if ( *(_BYTE *)(this + 248) )
        {
          v21 = sub_51C630(v4);
          if ( v21 < *(float *)(this + 272) )
            *(float *)(this + 272) = v21;
          *(float *)(this + 268) = a2 + *(float *)(this + 268);
          if ( v60 < 1.0 )
          {
            v22 = 0.0;
            *(_BYTE *)(this + 248) = 0;
            v23 = dword_75CBB0;
            v64 = 0.0;
            if ( dword_75CBB0 == 7 )
            {
              v24 = *(_DWORD *)(this + 48);
              v25 = *(_DWORD *)(this + 256);
              if ( v24 < v25 )
              {
                v22 = (double)(v25 - v24) * 0.72500002;
                v64 = v22;
              }
            }
            if ( !*(_DWORD *)(this + 260) && !*(_DWORD *)(v15 + 328) )
            {
              v26 = sub_51CA30(v4)
                  - *(float *)(this + 264)
                  + (double)(*(_DWORD *)(this + 12) - *(_DWORD *)(this + 252)) * flt_6290DC;
              v61 = v26 / *(float *)(this + 268) - 0.875;
              v27 = 0.0;
              if ( v61 > 0.0 )
                v27 = v61 * 0.40000001;
              v23 = dword_75CBB0;
              v28 = v27 + (v26 - *(float *)(this + 268)) * 0.69999999;
              if ( dword_75CBB0 != 7 )
                v28 = v28 * 1.5;
              v22 = v28 + v64;
            }
            v29 = v22 + *(float *)(this + 272);
            v30 = *(float *)(v4 + 17544);
            v31 = *(float *)(v4 + 17548);
            v33 = *(float *)(v4 + 17552);
            if ( !(v35 | v34) || v31 != 0.0 || v33 != 0.0 )
            {
              v36 = 1.0 / sqrt(v33 * v33 + v31 * v31 + v30 * v30);
              v30 = v30 * v36;
              v31 = v31 * v36;
              v33 = v33 * v36;
            }
            v65 = v33 * *(float *)(v15 + 220) + v31 * *(float *)(v15 + 216) + v30 * *(float *)(v15 + 212) - 1.0 + v29;
            if ( v65 > 1.75 && dword_767310 >= 1 )
            {
              if ( (*(int *)(this + 276) > 1 || v65 > 2.75) && v23 == 7 )
                sub_4DC690((int *)this, aCutTrack, 1, 0);
              else
                sub_4DC580((void *)this, aCutTrack);
              v37 = *(_DWORD *)(this + 116);
              ++*(_DWORD *)(this + 276);
              if ( v37 )
              {
                *(_DWORD *)(this + 116) = 1;
                if ( dword_75CBB0 != 7 )
                {
                  if ( sub_41F230(dword_62A170, aLapWillNotCoun, ::Destination) )
                  {
                    strncpy(::Destination, aLapWillNotCoun, 0x1FFu);
                    byte_62A37B = 0;
                  }
                  sub_45D100(&byte_764D68, (int)::Destination, 3, 16909060, 0);
                }
              }
            }
          }
        }
        else if ( v60 > 2.5 )
        {
          v38 = *(_DWORD *)(this + 48);
          *(_DWORD *)(this + 252) = *(_DWORD *)(this + 12);
          *(_BYTE *)(this + 248) = 1;
          *(_DWORD *)(this + 256) = v38;
          *(_DWORD *)(this + 260) = *(_DWORD *)(v15 + 328);
          *(float *)(this + 264) = sub_51CA30(v4);
          *(_DWORD *)(this + 268) = 0;
          *(float *)(this + 272) = sub_51C630(v4);
        }
      }
      v39 = *(float **)(v15 + 296);
      v40 = *v39 - *(float *)v15;
      v41 = v39[1] - *(float *)(v15 + 4);
      v42 = v39[2] - *(float *)(v15 + 8);
      v43 = v42 * *(float *)(v4 + 17552) + v41 * *(float *)(v4 + 17548) + v40 * *(float *)(v4 + 17544);
      if ( v43 >= 0.0 )
      {
        *(_DWORD *)(this + 200) = 0;
      }
      else
      {
        v62 = *(float *)(this + 200);
        v44 = v62 - v43 * a2 / sqrt(v42 * v42 + v41 * v41 + v40 * v40);
        *(float *)(this + 200) = v44;
        if ( v62 <= 10.0 && v44 > 10.0 )
        {
          if ( sub_41F230(dword_62A170, aWrongWay, ::Destination) )
          {
            strncpy(::Destination, aWrongWay, 0x1FFu);
            byte_62A37B = 0;
          }
          sub_45D100(&byte_764D68, (int)::Destination, 3, 16909060, 0);
          if ( *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248)
            && sub_51C630(v4) > 0.0 )
          {
            sub_41B490();
          }
        }
        if ( dword_767310 >= 1 && v62 <= 125.0 && *(float *)(this + 200) > 125.0 )
          sub_4DCCC0((int *)this, aWrongWay);
      }
      sub_4DEB50(0);
      if ( *(_BYTE *)(*(_DWORD *)this + 17412) || dword_75CBB4 != 5 )
        goto LABEL_166;
      if ( dword_75CBB0 == 7 )
        v45 = 25.0;
      else
        v45 = 50.0;
      v69 = v45;
      v63 = v45;
      v73 = *(_DWORD *)(this + 320);
      v72 = sub_51C7A0(v4);
      for ( i = 0; i < (int)NumOfElements; ++i )
      {
        if ( i != *(_DWORD *)(this + 4) )
        {
          v47 = (float *)(dword_75AAD0[i] + 84);
          if ( !(v49 | v50) )
          {
            v51 = sub_51C7A0(v47);
            if ( v51 > v72 )
              v51 = v51 - flt_6290D0;
            v66 = v72 - v51;
            if ( v66 < (double)v69 )
            {
              v52 = sqrt(v47[4386] * v47[4386] + v47[4387] * v47[4387] + v47[4388] * v47[4388]);
              if ( v52 >= 5.0
                && v52 >= sqrt(v70[4387] * v70[4387] + v70[4388] * v70[4388] + v70[4386] * v70[4386]) - 5.0 )
              {
                v53 = *(_DWORD *)(this + 12);
                v71 = sub_4DD0C0((_DWORD *)this, v53 - 1);
                v55 = v54[3];
                v68 = sub_4DD0C0(v54, v55 - 1);
                if ( v71 <= 0.0 || v68 <= 0.0 || v71 + 0.75 >= v68 )
                {
                  if ( dword_75CBB0 == 7 )
                  {
                    if ( v56[12] < *(_DWORD *)(this + 48) && v55 >= 1 && (v55 > v53 || v56[4] != *(_DWORD *)(this + 16)) )
                    {
                      sub_4DEB50(1);
                      if ( v66 < (double)v63 )
                      {
                        *(_DWORD *)(this + 320) = i;
                        v63 = v66;
                      }
                    }
                  }
                  else if ( *(_DWORD *)(this + 116) != 2
                         && v56[29] == 2
                         && *(float *)(v74 + 188) * 0.5 * (*(float *)(v74 + 188) * 0.5) < sqrt(
                                                                                            v70[4386] * v70[4386]
                                                                                          + v70[4387] * v70[4387]
                                                                                          + v70[4388] * v70[4388]) )
                  {
                    sub_4DEB50(1);
                    if ( v66 < (double)v63 )
                    {
                      *(_DWORD *)(this + 320) = i;
                      v63 = v66;
                    }
                  }
                }
              }
            }
          }
        }
      }
      if ( *(_BYTE *)(this + 316) && *(_DWORD *)(this + 320) == v73 && dword_75CBB0 == 7 )
      {
        v57 = a2 + *(float *)(this + 324);
        *(float *)(this + 324) = v57;
        if ( v57 > 30.0 )
          sub_4DC690((int *)this, aIgnoredBlueFla, 1, 0);
      }
      else
      {
LABEL_166:
        *(_DWORD *)(this + 324) = 0;
      }
    }
  }
}
