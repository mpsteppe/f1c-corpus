int __thiscall sub_4F2C60(double *this, int a2, int a3, int a4, int a5)
{
  int result; // eax
  char *v7; // ebx

  for ( result = LineInputReader(384); result; result = LineInputReader(384) )
  {
    result = sub_5651B0(a4);
    if ( result == 1 )
      break;
    if ( !result )
    {
      sub_565AA0(aBumptravel, this, 0, 0, 0);
      sub_565AA0(aReboundtravel, this + 1, 0, 0, 0);
      sub_565AA0(aBumpstopspring, this + 2, 0, 0, 0);
      sub_565AA0(aBumpstoprising, this + 3, 0, 0, 0);
      sub_565AA0(aBumpstopdamper, this + 4, 0, 0, 0);
      sub_565AA0(aBumpstoprising_0, this + 5, 0, 0, 0);
      sub_565AA0(aBumpstage2, this + 6, 0, 0, 0);
      sub_565AA0(aReboundstage2, this + 7, 0, 0, 0);
      sub_565AA0(aFrictiontorque, this + 21, 0, 0, 0);
      sub_565AA0(aBraketorque, this + 22, 0, 0, 0);
      sub_565AA0(aBrakewearrate, this + 30, 0, 0, 0);
      sub_565AA0(aBrakefailure, this + 31, this + 32, 0, 0);
      if ( sub_565AA0(aBrakeoptimumte, this + 23, 0, 0, 0) )
        this[23] = this[23] + 273.16;
      sub_565AA0(aBrakefaderange, this + 24, 0, 0, 0);
      sub_565AA0(aBrakediscinert, this + 29, 0, 0, 0);
      sub_565AA0(aBrakeheating, this + 25, 0, 0, 0);
      sub_565AA0(aBrakecooling, this + 26, this + 27, 0, 0);
      sub_565AA0(aBrakeductcooli, this + 28, 0, 0, 0);
      sub_565AA0(aSpininertia, this + 18, 0, 0, 0);
      sub_565AA0(aCgoffsetx, this + 8, 0, 0, 0);
      sub_565AA0(aPushrodspindle, this + 9, this + 10, this + 11, 0);
      sub_565AA0(aPushrodbody, this + 12, this + 13, this + 14, 0);
      v7 = (char *)(704 * a2 + a5);
      CRTMathHelper_e1f0(v7 + 176, a4, (int)aCamberrange, (int)aCambersetting, 0.0174532925199433);
      CRTMathHelper_e1f0(v7 + 240, a4, (int)aPressurerange, (int)aPressuresettin, 1.0);
      CRTMathHelper_e1f0(v7 + 304, a4, (int)aRideheightrang, (int)aRideheightsett, 1.0);
      CRTMathHelper_e1f0(v7 + 368, a4, (int)aPackerrange, (int)aPackersetting, 1.0);
      CRTMathHelper_e1f0(v7 + 432, a4, (int)aSpringrange, (int)aSpringsetting, 1.0);
      CRTMathHelper_e1f0(v7 + 496, a4, (int)aSlowbumprange, (int)aSlowbumpsettin, 1.0);
      CRTMathHelper_e1f0(v7 + 560, a4, (int)aFastbumprange, (int)aFastbumpsettin, 1.0);
      CRTMathHelper_e1f0(v7 + 624, a4, (int)aSlowreboundran, (int)aSlowreboundset, 1.0);
      CRTMathHelper_e1f0(v7 + 688, a4, (int)aFastreboundran, (int)aFastreboundset, 1.0);
      CRTMathHelper_e1f0(v7 + 752, a4, (int)aBrakediscrange, (int)aBrakediscsetti, 1.0);
      CRTMathHelper_e1f0(v7 + 816, a4, (int)aBrakepadrange, (int)aBrakepadsettin, 1.0);
    }
  }
  return result;
}
