_DWORD *__thiscall sub_609190(_DWORD *this, int a2)
{
  int *v3; // eax
  int *v4; // eax

  sub_5D9010(this);
  *this = 0;
  sub_630A11(this + 13, 292, 16, sub_608B50, sub_608C00);
  this[2] = 2;
  v3 = (int *)operator new(0x124u);
  if ( v3 )
    v4 = sub_608B50(v3);
  else
    v4 = 0;
  this[12] = v4;
  this[1] = 4;
  this[1181] = 0;
  v4[6] = -1082130432;
  *(_DWORD *)(this[12] + 28) = -1082130432;
  *(_DWORD *)(this[12] + 32) = -1082130432;
  *(_DWORD *)(this[12] + 36) = 1065353216;
  *(_DWORD *)(this[12] + 40) = 1065353216;
  *(_DWORD *)(this[12] + 44) = 1065353216;
  *(float *)(this[12] + 48) = (*(float *)(this[12] + 36) + *(float *)(this[12] + 24)) * 0.5;
  *(float *)(this[12] + 52) = (*(float *)(this[12] + 40) + *(float *)(this[12] + 28)) * 0.5;
  *(float *)(this[12] + 56) = (*(float *)(this[12] + 44) + *(float *)(this[12] + 32)) * 0.5;
  return this;
}
