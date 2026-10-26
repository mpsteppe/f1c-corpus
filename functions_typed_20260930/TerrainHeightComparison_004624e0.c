bool __thiscall sub_4624E0(void *this, int a2, float a3)
{
  if ( a3 < 0.0 )
    a3 = flt_7D108C;
  TerrainSurfaceRoughnessHeightSampling((unsigned __int8 *)(*(_DWORD *)this + 107456), a2, (float *)&a2, 0.0);
  return a3 < fabs(*(float *)&a2);
}

