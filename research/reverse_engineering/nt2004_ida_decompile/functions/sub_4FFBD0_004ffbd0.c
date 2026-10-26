__int64 __thiscall sub_4FFBD0(int this, int a2)
{
  int v3; // eax
  __int64 result; // rax
  int v5; // [esp+Ch] [ebp-5A0h] BYREF
  int v6; // [esp+10h] [ebp-59Ch] BYREF
  int v7[2]; // [esp+14h] [ebp-598h] BYREF
  int v8; // [esp+1Ch] [ebp-590h] BYREF
  int v9; // [esp+24h] [ebp-588h] BYREF
  int v10; // [esp+2Ch] [ebp-580h] BYREF
  int v11; // [esp+34h] [ebp-578h] BYREF
  int v12[2]; // [esp+3Ch] [ebp-570h] BYREF
  int v13; // [esp+44h] [ebp-568h] BYREF
  int v14; // [esp+4Ch] [ebp-560h] BYREF
  int v15; // [esp+54h] [ebp-558h] BYREF
  int v16; // [esp+5Ch] [ebp-550h] BYREF
  int v17; // [esp+64h] [ebp-548h] BYREF
  int v18; // [esp+6Ch] [ebp-540h] BYREF
  int v19[2]; // [esp+74h] [ebp-538h] BYREF
  int v20[2]; // [esp+7Ch] [ebp-530h] BYREF
  int v21; // [esp+84h] [ebp-528h] BYREF
  int v22; // [esp+8Ch] [ebp-520h] BYREF
  int v23; // [esp+94h] [ebp-518h] BYREF
  int v24; // [esp+9Ch] [ebp-510h] BYREF
  int v25; // [esp+A4h] [ebp-508h] BYREF
  int v26; // [esp+ACh] [ebp-500h] BYREF
  int v27; // [esp+B4h] [ebp-4F8h] BYREF
  int v28; // [esp+BCh] [ebp-4F0h] BYREF
  int v29; // [esp+C4h] [ebp-4E8h] BYREF
  int v30; // [esp+CCh] [ebp-4E0h] BYREF
  int v31; // [esp+D4h] [ebp-4D8h] BYREF
  int v32; // [esp+DCh] [ebp-4D0h] BYREF
  int v33[2]; // [esp+E4h] [ebp-4C8h] BYREF
  int v34; // [esp+ECh] [ebp-4C0h] BYREF
  int v35; // [esp+F4h] [ebp-4B8h] BYREF
  int v36; // [esp+FCh] [ebp-4B0h] BYREF
  int v37; // [esp+104h] [ebp-4A8h] BYREF
  int v38; // [esp+10Ch] [ebp-4A0h] BYREF
  int v39; // [esp+114h] [ebp-498h] BYREF
  int v40; // [esp+11Ch] [ebp-490h] BYREF
  int v41; // [esp+124h] [ebp-488h] BYREF
  int v42[2]; // [esp+12Ch] [ebp-480h] BYREF
  int v43; // [esp+134h] [ebp-478h] BYREF
  int v44; // [esp+13Ch] [ebp-470h] BYREF
  int v45; // [esp+144h] [ebp-468h] BYREF
  int v46; // [esp+14Ch] [ebp-460h] BYREF
  int v47; // [esp+154h] [ebp-458h] BYREF
  int v48; // [esp+15Ch] [ebp-450h] BYREF
  int v49; // [esp+164h] [ebp-448h] BYREF
  int v50; // [esp+16Ch] [ebp-440h] BYREF
  int v51; // [esp+174h] [ebp-438h] BYREF
  int v52[2]; // [esp+17Ch] [ebp-430h] BYREF
  int v53; // [esp+184h] [ebp-428h] BYREF
  int v54[2]; // [esp+18Ch] [ebp-420h] BYREF
  int v55[2]; // [esp+194h] [ebp-418h] BYREF
  int v56[2]; // [esp+19Ch] [ebp-410h] BYREF
  int v57[2]; // [esp+1A4h] [ebp-408h] BYREF
  int v58[2]; // [esp+1ACh] [ebp-400h] BYREF
  char Destination[32]; // [esp+1B4h] [ebp-3F8h] BYREF
  char v60[32]; // [esp+1D4h] [ebp-3D8h] BYREF
  char v61[32]; // [esp+1F4h] [ebp-3B8h] BYREF
  char String[384]; // [esp+214h] [ebp-398h] BYREF
  int v63; // [esp+394h] [ebp-218h]
  char v64; // [esp+398h] [ebp-214h]
  int v65; // [esp+3A0h] [ebp-20Ch]
  int v66; // [esp+3A4h] [ebp-208h]
  int v67; // [esp+3A8h] [ebp-204h]
  char Str[384]; // [esp+3ACh] [ebp-200h] BYREF
  char Source[128]; // [esp+52Ch] [ebp-80h] BYREF

  *(_DWORD *)(this + 8) = 1065353216;
  *(_DWORD *)(this + 12) = 1065353216;
  *(_DWORD *)(this + 16) = 10;
  *(_BYTE *)(this + 20) = 0;
  v5 = 0;
  sub_4FF780(v7);
  memset(Str, 0, sizeof(Str));
  v63 = 0;
  v67 = 0;
  v65 = 0;
  v66 = 0;
  v64 = 1;
  while ( sub_57A490(Str, 384) )
  {
    v3 = sub_577B60(String);
    if ( v3 == 1 || v3 == 4 )
      break;
    if ( !v3 )
    {
      if ( sub_577E50(String, aName_1, (int)Source) )
        sub_578600(Source);
      if ( sub_578110(aWetweather, (int)&v6, 0, 0, 0) )
        *(_BYTE *)(this + 20) = v6 != 0;
      if ( strstr(Str, aNone_2) )
      {
        sub_4FFAA0(this, &v5, v7, 0);
      }
      else if ( strstr(Str, aFrontleft_0) )
      {
        sub_4FFAA0(this, &v5, v7, 1);
      }
      else if ( strstr(Str, aFrontright_0) )
      {
        sub_4FFAA0(this, &v5, v7, 2);
      }
      else if ( strstr(Str, aRearleft_0) )
      {
        sub_4FFAA0(this, &v5, v7, 3);
      }
      else if ( strstr(Str, aRearright_0) )
      {
        sub_4FFAA0(this, &v5, v7, 4);
      }
      else if ( strstr(Str, aFront) )
      {
        sub_4FFAA0(this, &v5, v7, 5);
      }
      else if ( strstr(Str, aRear) )
      {
        sub_4FFAA0(this, &v5, v7, 6);
      }
      else if ( strstr(Str, aLeft) )
      {
        sub_4FFAA0(this, &v5, v7, 7);
      }
      else if ( strstr(Str, aRight) )
      {
        sub_4FFAA0(this, &v5, v7, 8);
      }
      else if ( strstr(Str, aAll) )
      {
        sub_4FFAA0(this, &v5, v7, 9);
      }
      sub_578450(aDrylatlong, (int)v7, (int)&v8, 0, 0);
      sub_578450(aWetlatlong, (int)&v9, (int)&v10, 0, 0);
      sub_578450(aRadius, (int)&v11, 0, 0, 0);
      if ( sub_578450(aRadiusrpm, (int)v12, 0, 0, 0) )
        *(double *)v12 = *(double *)v12 * 9.549296585513721;
      sub_578450(aWidth, (int)&v13, 0, 0, 0);
      sub_578450(aSpringbase, (int)&v14, 0, 0, 0);
      sub_578450(aSpringkpa, (int)&v15, 0, 0, 0);
      sub_578450(aDamper_0, (int)&v16, 0, 0, 0);
      sub_578450(aLobelift, (int)&v17, 0, 0, 0);
      sub_578450(aLobepeak, (int)&v18, 0, 0, 0);
      if ( sub_578450(aLobedwell, (int)v19, 0, 0, 0) )
        *(double *)v19 = *(double *)v19 * 0.0174532925199433;
      if ( sub_578450(aLobezeroliftrp, (int)v20, 0, 0, 0) )
        *(double *)v20 = *(double *)v20 * 0.1047197551196598;
      sub_578450(aLobesperrev, (int)&v21, 0, 0, 0);
      sub_578450(aSpeedeffects, (int)&v25, (int)&v26, 0, 0);
      sub_578450(aLoadsens, (int)&v22, (int)&v23, (int)&v24, 0);
      sub_578450(aLatpeak, (int)&v27, (int)&v28, (int)&v29, 0);
      sub_578450(aLongpeak, (int)&v30, (int)&v31, (int)&v32, 0);
      if ( sub_578450(aCamberlatlong, (int)v33, (int)&v34, (int)&v35, 0) )
        *(double *)v33 = *(double *)v33 * 0.0174532925199433;
      sub_578450(aRollingresista, (int)&v36, 0, 0, 0);
      sub_578450(aHeating, (int)&v37, (int)&v38, 0, 0);
      sub_578450(aTransfer, (int)&v39, (int)&v40, (int)&v41, 0);
      if ( sub_578450(aHeatdistrib, (int)v42, (int)&v43, 0, 0) )
        *(double *)v42 = *(double *)v42 * 0.0174532925199433;
      sub_578450(aAirtreadrate, (int)&v44, 0, 0, 0);
      sub_578450(aWearrate, (int)&v45, 0, 0, 0);
      sub_578450(aSoftness, (int)&v46, 0, 0, 0);
      sub_578450(aAisens, (int)&v47, (int)&v48, 0, 0);
      sub_578450(aAigripmult, (int)&v49, 0, 0, 0);
      sub_578450(aAipeakslip, (int)&v50, 0, 0, 0);
      sub_578450(aAiwear, (int)&v51, 0, 0, 0);
      sub_578450(aOptimumtemp, (int)v52, 0, 0, 0);
      sub_578450(aTemperatures, (int)v52, (int)&v53, 0, 0);
      sub_578450(aOptimumpressur, (int)v54, (int)v55, 0, 0);
      sub_578450(aOptimumpressur_0, (int)v54, 0, 0, 0);
      sub_578450(aOptimumpressur_1, (int)v55, 0, 0, 0);
      if ( sub_578450(aTempandpressgr, (int)v57, (int)v58, 0, 0) )
      {
        v56[0] = v57[0];
        v56[1] = v57[1];
      }
      sub_578450(aGriptemppress, (int)v56, (int)v57, (int)v58, 0);
      if ( sub_577E50(String, aLatcurve, (int)Source) )
      {
        strncpy(Destination, Source, 0x1Fu);
        Destination[31] = 0;
      }
      if ( sub_577E50(String, aBrakingcurve, (int)Source) )
      {
        strncpy(v60, Source, 0x1Fu);
        v60[31] = 0;
      }
      if ( sub_577E50(String, aTractivecurve, (int)Source) )
      {
        strncpy(v61, Source, 0x1Fu);
        v61[31] = 0;
      }
    }
  }
  sub_4FFAA0(this, &v5, v7, 0);
  *(float *)(this + 8) = (*(double *)(this + 1568)
                        + *(double *)(this + 1560)
                        + *(double *)(this + 1056)
                        + *(double *)(this + 1048)
                        + *(double *)(this + 544)
                        + *(double *)(this + 536)
                        + *(double *)(this + 32)
                        + *(double *)(this + 24))
                       * 0.125;
  *(float *)(this + 12) = (*(double *)(this + 1584)
                         + *(double *)(this + 1576)
                         + *(double *)(this + 1072)
                         + *(double *)(this + 1064)
                         + *(double *)(this + 560)
                         + *(double *)(this + 552)
                         + *(double *)(this + 48)
                         + *(double *)(this + 40))
                        * 0.125;
  result = (__int64)(22.5
                   - (*(double *)(this + 1872)
                    + *(double *)(this + 1360)
                    + *(double *)(this + 848)
                    + *(double *)(this + 336))
                   * 0.25
                   * 15.0);
  *(_DWORD *)(this + 16) = result;
  if ( (int)result <= 15 )
  {
    if ( (int)result < 7 )
      *(_DWORD *)(this + 16) = 7;
  }
  else
  {
    *(_DWORD *)(this + 16) = 15;
  }
  return result;
}
