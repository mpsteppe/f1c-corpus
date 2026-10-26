int __thiscall sub_520000(double *this, int a2, int a3, int a4, int a5)
{
  int result; // eax
  char *v7; // ebx

  for ( result = sub_5367E0(384); result; result = sub_5367E0(384) )
  {
    result = sub_577B60(a4);
    if ( result == 1 )
      break;
    if ( !result )
    {
      sub_578450(aBumptravel, (int)this, 0, 0, 0);
      sub_578450(aReboundtravel, (int)(this + 1), 0, 0, 0);
      sub_578450(aBumpstopspring, (int)(this + 2), 0, 0, 0);
      sub_578450(aBumpstoprising, (int)(this + 3), 0, 0, 0);
      sub_578450(aBumpstopdamper, (int)(this + 4), 0, 0, 0);
      sub_578450(aBumpstoprising_0, (int)(this + 5), 0, 0, 0);
      sub_578450(aBumpstage2, (int)(this + 6), 0, 0, 0);
      sub_578450(aReboundstage2, (int)(this + 7), 0, 0, 0);
      sub_578450(aFrictiontorque, (int)(this + 22), 0, 0, 0);
      sub_578450(aBraketorque, (int)(this + 23), 0, 0, 0);
      sub_578450(aBrakewearrate, (int)(this + 31), 0, 0, 0);
      sub_578450(aBrakefailure, (int)(this + 32), (int)(this + 33), 0, 0);
      if ( sub_578450(aBrakeoptimumte, (int)(this + 24), 0, 0, 0) )
        this[24] = this[24] + 273.16;
      sub_578450(aBrakefaderange, (int)(this + 25), 0, 0, 0);
      sub_578450(aBrakediscinert, (int)(this + 30), 0, 0, 0);
      sub_578450(aBrakeheating, (int)(this + 26), 0, 0, 0);
      sub_578450(aBrakecooling, (int)(this + 27), (int)(this + 28), 0, 0);
      sub_578450(aBrakeductcooli, (int)(this + 29), 0, 0, 0);
      sub_578450(aSpininertia, (int)(this + 19), 0, 0, 0);
      sub_578450(aCgoffsetx, (int)(this + 9), 0, 0, 0);
      sub_578450(aSpringmult, (int)(this + 8), 0, 0, 0);
      sub_578450(aPushrodspindle, (int)(this + 10), (int)(this + 11), (int)(this + 12), 0);
      sub_578450(aPushrodbody, (int)(this + 13), (int)(this + 14), (int)(this + 15), 0);
      v7 = (char *)(704 * a2 + a5);
      sub_430A90(v7 + 176, a4, aCamberrange, aCambersetting, 0.0174532925199433);
      sub_430A90(v7 + 240, a4, aPressurerange, aPressuresettin_0, 1.0);
      sub_430A90(v7 + 304, a4, aRideheightrang, aRideheightsett_0, 1.0);
      sub_430A90(v7 + 368, a4, aPackerrange, aPackersetting, 1.0);
      sub_430A90(v7 + 432, a4, aSpringrange, aSpringsetting, 1.0);
      sub_430A90(v7 + 496, a4, aSlowbumprange, aSlowbumpsettin_0, 1.0);
      sub_430A90(v7 + 560, a4, aFastbumprange, aFastbumpsettin_0, 1.0);
      sub_430A90(v7 + 624, a4, aSlowreboundran, aSlowreboundset_0, 1.0);
      sub_430A90(v7 + 688, a4, aFastreboundran, aFastreboundset_0, 1.0);
      sub_430A90(v7 + 752, a4, aBrakediscrange, aBrakediscsetti_0, 1.0);
      sub_430A90(v7 + 816, a4, aBrakepadrange, aBrakepadsettin_0, 1.0);
    }
  }
  return result;
}
