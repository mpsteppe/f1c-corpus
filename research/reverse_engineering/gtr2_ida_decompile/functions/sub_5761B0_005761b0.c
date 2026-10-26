int __thiscall sub_5761B0(int this)
{
  float *v1; // edi
  float v3; // [esp+14h] [ebp-Ch]
  float v4; // [esp+18h] [ebp-8h]
  float v5; // [esp+1Ch] [ebp-4h]

  v1 = (float *)(this + 15972);
  v3 = *(float *)(this + 17480) - *(float *)(this + 15972);
  v4 = *(float *)(this + 17484) - *(float *)(this + 15976);
  v5 = *(float *)(this + 17488) - *(float *)(this + 15980);
  if ( v5 * v5 + v4 * v4 + v3 * v3 <= 0.0625 && *(_DWORD *)(this + 17476) )
    return *(_DWORD *)(this + 17476);
  sub_402D40(&flt_91BCA0, v1, *(_DWORD *)(this + 17476));
  return off_16C9724(*(_DWORD *)v1, *((_DWORD *)v1 + 1));
}
