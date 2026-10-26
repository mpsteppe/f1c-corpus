void __thiscall sub_59E170(int this, int a2, int a3, int a4, float a5, float a6, float a7)
{
  *(_DWORD *)(this + 32) = a2;
  *(_DWORD *)(this + 36) = a3;
  *(_DWORD *)(this + 40) = a4;
  *(float *)(this + 44) = fmod(a5, 6.283185482025146);
  *(float *)(this + 48) = fmod(a6, 6.283185482025146);
  *(float *)(this + 52) = fmod(a7, 6.283185482025146);
  sub_59DFD0((_DWORD *)this, 64, 0, 0);
}
