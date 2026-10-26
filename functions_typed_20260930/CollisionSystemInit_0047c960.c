void __stdcall CollisionSystemInit(float a1)
{
  float v1; // [esp+4h] [ebp+4h]
  float v2; // [esp+4h] [ebp+4h]

  if ( a1 >= 0.0 )
  {
    if ( a1 > 1.0 )
      a1 = 1.0;
  }
  else
  {
    a1 = 0.0;
  }
  v1 = ThunkToFUN004b9c80() * a1;
  v2 = VehicleLifetimeAverageAccessor(&dword_8AB6EC) + v1;
  SingleCallWrapper_9cd0((int *)&dword_8AB6EC, v2);
}

