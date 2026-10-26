void __thiscall sub_4F1BA0(int this, float a2, float a3, float a4, float a5)
{
  if ( *(_DWORD *)(this + 12988) )
  {
    *(float *)(this + 13924) = a2;
    *(float *)(this + 14172) = a3;
    *(float *)(this + 14420) = a4;
    *(float *)(this + 14668) = a5;
  }
  else
  {
    ForceTorqueApplicationToRigidBodyWithInertiaTens((int)&dbl_7C7428, a2, a3, a4, a5);
  }
}

