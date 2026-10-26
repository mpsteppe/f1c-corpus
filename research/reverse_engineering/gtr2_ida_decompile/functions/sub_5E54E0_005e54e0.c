void __thiscall sub_5E54E0(int this, int a2, int a3)
{
  int v3; // eax
  int v4; // [esp-4h] [ebp-4h]

  *(_DWORD *)(this + 36) = a2;
  v4 = *(_DWORD *)this | 0x200;
  v3 = *(_DWORD *)(this + 124);
  *(_DWORD *)(this + 40) = a3;
  sub_5E5240(this, v3, *(float *)(this + 128), v4);
}
