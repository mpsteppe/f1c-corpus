char *__thiscall sub_4D6360(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx

  v2 = this[330];
  v3 = (this[332] + 1) % this[331];
  this[332] = v3;
  return sub_4D3D70((float *)(v2 + (v3 << 7)));
}
