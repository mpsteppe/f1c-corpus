int __thiscall sub_4D6B00(int this, int a2)
{
  int v3; // esi
  int v4; // eax
  int result; // eax
  int v6; // [esp+10h] [ebp-39Ch] BYREF
  _BYTE v7[128]; // [esp+14h] [ebp-398h] BYREF
  _BYTE v8[384]; // [esp+94h] [ebp-318h] BYREF
  int v9; // [esp+214h] [ebp-198h]
  char v10; // [esp+218h] [ebp-194h]
  int v11; // [esp+220h] [ebp-18Ch]
  int v12; // [esp+224h] [ebp-188h]
  int v13; // [esp+228h] [ebp-184h]
  _BYTE v14[384]; // [esp+22Ch] [ebp-180h] BYREF

  *(_DWORD *)(this + 8) = 1065353216;
  *(_DWORD *)(this + 12) = 1065353216;
  memset(v14, 0, sizeof(v14));
  *(_DWORD *)(this + 16) = 10;
  *(_BYTE *)(this + 20) = 0;
  v3 = this + 24;
  v9 = 0;
  v13 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 1;
  while ( sub_566CC0(v14, 384) )
  {
    v4 = sub_5651B0(v8);
    if ( v4 == 1 || v4 == 4 )
      break;
    if ( !v4 )
    {
      if ( sub_5654A0(aName, v7) )
        sub_566650(v7);
      if ( sub_565760(aWetweather, &v6, 0, 0, 0) )
        *(_BYTE *)(this + 20) = v6 != 0;
      if ( sub_587C20(v14, aFront_0) )
        v3 = this + 24;
      if ( sub_587C20(v14, aRear_0) )
        v3 = this + 352;
      sub_565AA0(aDrylatlong, v3, v3 + 8, 0, 0);
      sub_565AA0(aWetlatlong, v3 + 16, v3 + 24, 0, 0);
      sub_565AA0(aRadius, v3 + 32, 0, 0, 0);
      if ( sub_565AA0(aRadiusrpm, v3 + 40, 0, 0, 0) )
        *(double *)(v3 + 40) = *(double *)(v3 + 40) * 9.549296585513721;
      sub_565AA0(aWidth, v3 + 48, 0, 0, 0);
      sub_565AA0(aSpringbase, v3 + 56, 0, 0, 0);
      sub_565AA0(aSpringkpa, v3 + 64, 0, 0, 0);
      sub_565AA0(aDamper_0, v3 + 72, 0, 0, 0);
      sub_565AA0(aLoadsens, v3 + 80, v3 + 88, v3 + 96, 0);
      sub_565AA0(aLatpeak, v3 + 104, v3 + 112, v3 + 120, 0);
      sub_565AA0(aLongpeak, v3 + 128, v3 + 136, v3 + 144, 0);
      if ( sub_565AA0(aCamberlatlong, v3 + 152, v3 + 160, v3 + 168, 0) )
        *(double *)(v3 + 152) = *(double *)(v3 + 152) * 0.0174532925199433;
      sub_565AA0(aRollingresista, v3 + 176, 0, 0, 0);
      sub_565AA0(aHeating, v3 + 184, v3 + 192, 0, 0);
      sub_565AA0(aTransfer, v3 + 200, v3 + 208, v3 + 216, 0);
      sub_565AA0(aWearrate, v3 + 224, 0, 0, 0);
      sub_565AA0(aSoftness, v3 + 232, 0, 0, 0);
      sub_565AA0(aAisens, v3 + 240, v3 + 248, 0, 0);
      sub_565AA0(aAigripmult, v3 + 256, 0, 0, 0);
      sub_565AA0(aAipeakslip, v3 + 264, 0, 0, 0);
      sub_565AA0(aAiwear, v3 + 272, 0, 0, 0);
      sub_565AA0(aOptimumtemp, v3 + 280, 0, 0, 0);
      sub_565AA0(aOptimumpressur, v3 + 288, 0, 0, 0);
      sub_565AA0(aOptimumpressur_0, v3 + 296, 0, 0, 0);
      if ( sub_5654A0(aLatcurve, v7) )
        sub_566650(v7);
      if ( sub_5654A0(aBrakingcurve, v7) )
        sub_566650(v7);
      if ( sub_5654A0(aTractivecurve, v7) )
        sub_566650(v7);
    }
  }
  *(float *)(this + 8) = (*(double *)(this + 360)
                        + *(double *)(this + 352)
                        + *(double *)(this + 32)
                        + *(double *)(this + 24))
                       * 0.25;
  *(float *)(this + 12) = (*(double *)(this + 376)
                         + *(double *)(this + 368)
                         + *(double *)(this + 48)
                         + *(double *)(this + 40))
                        * 0.25;
  result = sub_587BDC(22.5 - (*(double *)(this + 584) + *(double *)(this + 256)) * 0.5 * 15.0);
  *(_DWORD *)(this + 16) = result;
  if ( result <= 15 )
  {
    if ( result < 7 )
      *(_DWORD *)(this + 16) = 7;
  }
  else
  {
    *(_DWORD *)(this + 16) = 15;
  }
  return result;
}
