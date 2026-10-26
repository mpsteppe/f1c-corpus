int __thiscall sub_4DD140(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 48);
  *(float *)(this + 44) = *(float *)(this + 124);
  *(_DWORD *)(this + 40) = result;
  *(_DWORD *)(this + 52) = result;
  return result;
}
