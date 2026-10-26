int __thiscall sub_4BC320(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 44);
  *(float *)(this + 40) = *(float *)(this + 104);
  *(_DWORD *)(this + 36) = result;
  return result;
}
