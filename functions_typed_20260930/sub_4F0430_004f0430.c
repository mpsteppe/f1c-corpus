void __thiscall sub_4F0430(char *this, float a2)
{
  double v2; // st7
  char v4; // al
  double v5; // st7
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st6
  double v10; // st6
  double v11; // st7
  float v12; // ecx
  double v13; // st7
  double v14; // st6
  float *v15; // esi
  double v16; // st7
  int v17; // edi
  double v18; // st7
  char *v19; // eax
  int v20; // edi
  float *v21; // esi
  float v22; // ecx
  double v23; // st7
  double v24; // st6
  double v25; // st5
  double v26; // st6
  double v27; // st7
  double v28; // st7
  double v29; // st6
  double v30; // st7
  bool v31; // zf
  double v32; // st7
  unsigned __int8 v34; // c0
  unsigned __int8 v35; // c3
  double v36; // st7
  double v37; // st7
  float v38; // ecx
  float v39; // eax
  float v40; // eax
  float v41; // edx
  char *v42; // edi
  int v43; // esi
  int v44; // eax
  double v45; // st7
  int i; // eax
  double v47; // st7
  float v48; // eax
  float v49; // edx
  float v50; // ecx
  int v51; // esi
  char v52; // al
  float v53; // [esp+0h] [ebp-330h]
  float v54; // [esp+4h] [ebp-32Ch]
  float v55; // [esp+14h] [ebp-31Ch]
  _DWORD *v56; // [esp+14h] [ebp-31Ch]
  float v57; // [esp+14h] [ebp-31Ch]
  float *v58; // [esp+14h] [ebp-31Ch]
  char v59; // [esp+1Bh] [ebp-315h]
  float v60; // [esp+1Ch] [ebp-314h]
  float v61; // [esp+1Ch] [ebp-314h]
  float v62; // [esp+1Ch] [ebp-314h]
  float v63; // [esp+1Ch] [ebp-314h]
  float v64; // [esp+20h] [ebp-310h]
  float v65; // [esp+20h] [ebp-310h]
  float v66; // [esp+20h] [ebp-310h]
  float v67; // [esp+20h] [ebp-310h]
  float v68; // [esp+24h] [ebp-30Ch]
  float v69; // [esp+24h] [ebp-30Ch]
  float v70; // [esp+24h] [ebp-30Ch]
  float v71; // [esp+24h] [ebp-30Ch]
  char *v72; // [esp+28h] [ebp-308h]
  float *v73; // [esp+28h] [ebp-308h]
  char *v74; // [esp+2Ch] [ebp-304h]
  float v75; // [esp+2Ch] [ebp-304h]
  float v76; // [esp+30h] [ebp-300h] BYREF
  float v77; // [esp+34h] [ebp-2FCh]
  float v78; // [esp+38h] [ebp-2F8h]
  float v79; // [esp+3Ch] [ebp-2F4h] BYREF
  float v80; // [esp+40h] [ebp-2F0h]
  float v81; // [esp+44h] [ebp-2ECh]
  float v82; // [esp+48h] [ebp-2E8h] BYREF
  float v83; // [esp+4Ch] [ebp-2E4h]
  float v84; // [esp+50h] [ebp-2E0h]
  _DWORD v85[3]; // [esp+54h] [ebp-2DCh] BYREF
  double v86; // [esp+60h] [ebp-2D0h] BYREF
  double v87; // [esp+68h] [ebp-2C8h]
  double v88; // [esp+70h] [ebp-2C0h]
  float v89[3]; // [esp+78h] [ebp-2B8h] BYREF
  float v90[9]; // [esp+84h] [ebp-2ACh] BYREF
  _BYTE v91[36]; // [esp+A8h] [ebp-288h] BYREF
  char v92[36]; // [esp+CCh] [ebp-264h] BYREF
  double v93[9]; // [esp+F0h] [ebp-240h] BYREF
  double v94[9]; // [esp+138h] [ebp-1F8h] BYREF
  int v95[108]; // [esp+180h] [ebp-1B0h] BYREF

  v2 = dbl_8AFE98;
  v53 = dbl_8AFE98;
  ConditionalDispatch_55a0((_DWORD *)this + 3248, v53, a2);
  v59 = 1;
  switch ( *((_DWORD *)this + 3247) )
  {
    case 0:
      v23 = a2 - *((float *)this + 3371);
      v24 = v23 * *((float *)this + 3387);
      v25 = v23 * *((float *)this + 3388);
      *(float *)&v87 = v23 * *((float *)this + 3389);
      v62 = v24 + *((float *)this + 3381);
      v76 = v62;
      v66 = v25 + *((float *)this + 3382);
      v77 = v66;
      v70 = *(float *)&v87 + *((float *)this + 3383);
      v78 = v70;
      v26 = v23 * *((float *)this + 3393);
      qmemcpy(v90, this + 13488, sizeof(v90));
      v63 = v26;
      v67 = v23 * *((float *)this + 3394);
      v27 = v23 * *((float *)this + 3395);
      v82 = v63;
      v71 = v27;
      v83 = v67;
      v84 = v71;
      sub_567120(&v82, v85);
      F_3x3MatrixTransform((_DWORD *)this + 441, &v76, v85, v90);
      if ( *((float *)this + 3678) <= 0.0 )
        v28 = 0.0;
      else
        v28 = *((float *)this + 3685);
      v29 = v28;
      v30 = *((float *)this + 3420);
      *((float *)this + 4) = v76;
      *((float *)this + 5) = v77;
      *((float *)this + 6) = v78;
      qmemcpy(this + 40, v90, 0x24u);
      *((_DWORD *)this + 19) = *((_DWORD *)this + 3387);
      *((_DWORD *)this + 20) = *((_DWORD *)this + 3388);
      *((_DWORD *)this + 21) = *((_DWORD *)this + 3389);
      *((float *)this + 37) = v29;
      *((float *)this + 38) = v30;
      v31 = dword_7CC730 == 0;
      this[16408] = dword_7CC730 != 0;
      if ( !v31 )
        HUDElementConfig(43, 1, 1.0, 1.0);
      v32 = dbl_7C7598 * 4.0;
      *((float *)this + 4103) = dbl_7C7598 * 4.0;
      if ( !(v34 | v35) )
      {
        if ( v32 > 1.0 )
          *((_DWORD *)this + 4103) = 1065353216;
        HUDElementConfig(44, 1, *((float *)this + 4103), 1.0);
      }
      v36 = *((float *)this + 3422);
      this[4189] = byte_7C9080;
      this[4185] = v36 > 0.0099999998;
      if ( dword_7CC75C )
        this[4187] = this[4187] == 0;
      v57 = dbl_7C7428;
      if ( v57 < -1.0 )
        goto LABEL_39;
      if ( v57 <= 1.0 )
      {
        if ( v57 >= -1.0 )
          v37 = v57;
        else
LABEL_39:
          v37 = -1.0;
      }
      else
      {
        v37 = 1.0;
      }
      *((float *)this + 1037) = v37;
      GetBodyMotionState((int)&dbl_7C7428, &v79, v89);
      v38 = v80;
      *((float *)this + 1017) = v79;
      v39 = v81;
      *((float *)this + 1018) = v38;
      *((float *)this + 1019) = v39;
      v40 = v89[1];
      *((float *)this + 1020) = v89[0];
      v41 = v89[2];
      *((float *)this + 1021) = v40;
      *((float *)this + 1022) = v41;
      v42 = this + 2088;
      v43 = 0;
      v73 = (float *)(this + 88);
      v58 = (float *)(this + 13744);
      v74 = this + 2088;
      do
      {
        CollisionPositionTransform((int)&dbl_7C7428, v43, &v86, (int)v93, (int)v94);
        v79 = v86;
        v44 = 0;
        v80 = v87;
        v81 = v88;
        do
        {
          v45 = v93[v44++];
          *(float *)&v91[4 * v44 + 32] = v45;
        }
        while ( v44 < 9 );
        for ( i = 0; i < 9; v90[i + 8] = v47 )
          v47 = v94[i++];
        if ( *(_DWORD *)v42 && v42[64] )
        {
          SuspensionGeometryInitializer((float *)this + 441, v43, &v79, v92, v91);
          VibrationStateMachine((_DWORD *)this + 441, v43, *v58);
          v48 = v80;
          v42 = v74;
          *v73 = v79;
          v49 = v81;
          v73[1] = v48;
          v73[2] = v49;
        }
        ++v43;
        v42 += 296;
        v74 = v42;
        v58 += 62;
        v73 += 3;
      }
      while ( v43 < 4 );
      v50 = dword_7C54F0[dword_7C54DC];
      dword_7C8B44 = 0;
      dword_7C8B48 = 0;
      LOBYTE(v50) = *(_DWORD *)(LODWORD(v50) + 18580) == *(_DWORD *)(*(_DWORD *)this + 18580);
      VehicleSoundTrigger(v50);
      break;
    case 1:
      v4 = VelocityThresholdCheck(this);
      v5 = *((float *)this + 3422);
      this[4189] = v4;
      this[4185] = v5 > 0.0099999998;
      goto LABEL_3;
    case 2:
LABEL_3:
      v6 = a2 - *((float *)this + 3371);
      v7 = v6 * *((float *)this + 3387);
      v8 = v6 * *((float *)this + 3388);
      *(float *)&v87 = v6 * *((float *)this + 3389);
      v60 = v7 + *((float *)this + 3381);
      v76 = v60;
      v9 = v8 + *((float *)this + 3382);
      qmemcpy(v90, this + 13488, sizeof(v90));
      v64 = v9;
      v68 = *(float *)&v87 + *((float *)this + 3383);
      v61 = v6 * *((float *)this + 3393);
      v77 = v64;
      v82 = v61;
      v10 = v6 * *((float *)this + 3394);
      v78 = v68;
      v65 = v10;
      v83 = v65;
      v69 = v6 * *((float *)this + 3395);
      v84 = v69;
      sub_567120(&v82, v85);
      F_3x3MatrixTransform((_DWORD *)this + 441, &v76, v85, v90);
      v55 = *((float *)this + 3421);
      if ( v55 < -1.0 )
        goto LABEL_7;
      if ( v55 <= 1.0 )
      {
        if ( v55 >= -1.0 )
          v11 = v55;
        else
LABEL_7:
          v11 = -1.0;
      }
      else
      {
        v11 = 1.0;
      }
      v12 = v76;
      *((float *)this + 1037) = v11;
      v13 = *((float *)this + 3420);
      v14 = *((float *)this + 3685);
      *((float *)this + 4) = v12;
      *((float *)this + 5) = v77;
      *((float *)this + 6) = v78;
      qmemcpy(this + 40, v90, 0x24u);
      *((_DWORD *)this + 19) = *((_DWORD *)this + 3387);
      *((_DWORD *)this + 20) = *((_DWORD *)this + 3388);
      *((_DWORD *)this + 21) = *((_DWORD *)this + 3389);
      *((float *)this + 37) = v14;
      *((float *)this + 38) = v13;
      if ( this[16408] )
        HUDElementConfig(43, 1, 1.0, 1.0);
      if ( *((float *)this + 4103) != 0.0 )
        HUDElementConfig(44, 1, *((float *)this + 4103), 1.0);
      if ( *((_DWORD *)this + 3247) == 2 )
      {
        v15 = (float *)(this + 13732);
        v16 = *((float *)this + 3672) * *((float *)this + 3421);
        v17 = 4;
        *((float *)this + 3434) = v16;
        *((float *)this + 3496) = v16;
        do
        {
          *v15 = dbl_8AFE98 * v15[3] + *v15;
          if ( fabs(*v15) > 50.265484 )
          {
            v18 = *v15;
            InterruptDispatch(v18);
            *v15 = v18;
          }
          v15 += 62;
          --v17;
        }
        while ( v17 );
      }
      v56 = this + 88;
      v19 = this + 2088;
      v20 = 0;
      v72 = this + 2088;
      v21 = (float *)(this + 13732);
      do
      {
        if ( *(_DWORD *)v19 && v19[64] )
        {
          SuspensionParamUpdate((float *)this + 441, v20, *(v21 - 5), *v21, v21[1]);
          VibrationStateMachine((_DWORD *)this + 441, v20, v21[3]);
          *v56 = *((_DWORD *)v21 - 6);
          v56[1] = *((_DWORD *)v21 - 5);
          v56[2] = *((_DWORD *)v21 - 4);
          v19 = v72;
        }
        ++v20;
        v19 += 296;
        v21 += 62;
        v72 = v19;
        v56 += 3;
      }
      while ( v20 < 4 );
      v22 = dword_7C54F0[dword_7C54DC];
      LOBYTE(v22) = *(_DWORD *)(LODWORD(v22) + 18580) == *(_DWORD *)(*(_DWORD *)this + 18580);
      VehicleSoundTrigger(v22);
      break;
    case 3:
      if ( (unsigned __int8)sub_4B9AC0(&dword_8AB6EC, *((_DWORD *)this + 1), (int)v95, -9.9999997e37) )
      {
        v51 = *((_DWORD *)this + 1);
        Delegation(&dword_8AB6EC);
        v54 = v2;
        VehiclePhysicsTimeStep((int)&stru_5EC6D8 + 18624 * v51, (int)v95, v54);
        if ( this[16408] )
          HUDElementConfig(43, 1, 1.0, 1.0);
        if ( *((float *)this + 4103) != 0.0 )
          HUDElementConfig(44, 1, *((float *)this + 4103), 1.0);
      }
      break;
    default:
      v59 = 0;
      break;
  }
  SteeringForceWithRandom(this);
  if ( v59 )
  {
    VehicleStateUpdate_19d0(this + 1764);
    v52 = this[16416] + 1;
    ++*((_DWORD *)this + 4104);
    if ( (v52 & 0xF) == 0 )
    {
      sub_4F0D20(this);
      v75 = 0.94 - *((float *)this + 1036) * 0.89999998;
      if ( flt_8AFECC < (double)v75 || *((float *)this + 1036) < (flt_8AFEE8 + flt_8AFEEC) * 0.5 )
      {
        this[4187] = 1;
      }
      else if ( v75 + 0.029999999 < flt_8AFECC && (flt_8AFEE8 + flt_8AFEEC) * 0.5 == 0.0 )
      {
        this[4187] = 0;
      }
    }
  }
}

