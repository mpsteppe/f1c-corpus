void __thiscall sub_59E0F0(int this, float a2, float a3, float a4)
{
  *(float *)(this + 44) = fmod(a2, 6.283185482025146);
  *(float *)(this + 48) = fmod(a3, 6.283185482025146);
  *(float *)(this + 52) = fmod(a4, 6.283185482025146);
  sub_59DFD0((_DWORD *)this, 64, 0, 0);
}
