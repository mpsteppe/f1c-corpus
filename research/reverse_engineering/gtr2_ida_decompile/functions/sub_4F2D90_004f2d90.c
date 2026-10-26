float *__thiscall sub_4F2D90(int this, int a2)
{
  _DWORD *v3; // eax
  float *v4; // esi

  v3 = operator new(0x1Cu);
  v4 = 0;
  if ( v3 )
    v4 = (float *)sub_4F16D0(v3, a2, *(_DWORD *)(this + 12));
  sub_4F26D0(v4, (float *)(this + 16));
  return v4;
}
