char __thiscall sub_57A610(_DWORD *this, float *a2, int a3, int a4)
{
  double v4; // st7
  int v6[2]; // [esp+Ch] [ebp-8h] BYREF

  v4 = MutexGuardedTimerRead(*this);
  if ( !(unsigned __int8)PhysicsQueryGetterWithReadyFlag((int)v6, a3, a4, v4) )
    return 0;
  *a2 = *(double *)v6;
  return 1;
}

