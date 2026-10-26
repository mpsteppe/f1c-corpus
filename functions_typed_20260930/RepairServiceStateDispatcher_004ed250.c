void __thiscall sub_4ED250(int *this, int a2)
{
  int v3; // eax
  int *v4; // edx

  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      if ( !*(_DWORD *)(*this + 16488) )
        *(_DWORD *)(*this + 16488) = 6;
      SubslotCleanup((char *)this + 1764, a2);
      v3 = this[3247];
      this[3928] = 2;
      if ( v3 )
        goto LABEL_12;
      WheelCollisionContactFlagSetter(&dbl_7C7428, a2);
      sub_41AFD0(*this, a2);
      return;
    case 4:
      v4 = this + 818;
      goto LABEL_8;
    case 5:
      v4 = this + 835;
LABEL_8:
      ConditionalResourceRelease(v4);
      StateTransition(this + 3248, 1);
      if ( !this[3928] )
        this[3928] = 1;
      this[3740] = this[3744];
      TireBrushModelForceSolver((int)this, 0);
      sub_41AFD0(*this, a2);
      return;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      ConditionalResourceRelease(&this[17 * a2 + 750]);
      goto LABEL_12;
    default:
LABEL_12:
      sub_41AFD0(*this, a2);
      return;
  }
}

