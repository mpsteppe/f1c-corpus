char __thiscall sub_593D20(int this, int a2, int a3)
{
  float v3; // eax
  int v5; // [esp-4h] [ebp-4h]

  *(_DWORD *)(this + 4) = a2;
  v5 = *(_DWORD *)(this + 128);
  v3 = *(float *)(this + 108);
  *(_DWORD *)(this + 8) = a3;
  return sub_593820(this, v3, *(float *)(this + 112), v5);
}
