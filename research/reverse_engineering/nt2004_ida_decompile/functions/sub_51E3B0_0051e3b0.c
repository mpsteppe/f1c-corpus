int __thiscall sub_51E3B0(int this, const void *a2, _DWORD *a3)
{
  int result; // eax

  result = this + 17484;
  qmemcpy((void *)(this + 17484), a2, 0x24u);
  *(_DWORD *)(this + 17616) = *a3;
  *(_DWORD *)(this + 17620) = a3[1];
  *(_DWORD *)(this + 17624) = a3[2];
  *(float *)(this + 17628) = *(float *)(this + 17508) * *(float *)(this + 17624)
                           + *(float *)(this + 17496) * *(float *)(this + 17620)
                           + *(float *)(this + 17616) * *(float *)(this + 17484);
  *(float *)(this + 17632) = *(float *)(this + 17512) * *(float *)(this + 17624)
                           + *(float *)(this + 17500) * *(float *)(this + 17620)
                           + *(float *)(this + 17488) * *(float *)(this + 17616);
  *(float *)(this + 17636) = *(float *)(this + 17516) * *(float *)(this + 17624)
                           + *(float *)(this + 17504) * *(float *)(this + 17620)
                           + *(float *)(this + 17492) * *(float *)(this + 17616);
  return result;
}
