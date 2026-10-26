// f1c  0x005423c0  size=32
char __thiscall sub_5423C0(int this, int a2, int a3)
{
  float v3; // eax

  *(_DWORD *)(this + 4) = a2;
  v3 = *(float *)(this + 112);
  *(_DWORD *)(this + 8) = a3;
  return sub_542050(this, *(float *)(this + 108), v3, 1);
}
