unsigned int __thiscall sub_593460(int this, int a2)
{
  int v2; // eax
  double v3; // st7
  unsigned int result; // eax

  v2 = *(_DWORD *)(this + 128);
  v3 = (double)*(int *)(this + 84) * 0.5 / *(float *)(this + 28);
  if ( a2 )
  {
    result = v2 | 0x10;
    v3 = -v3;
  }
  else
  {
    result = v2 & 0xFFFFFFEF;
  }
  *(float *)(this + 12) = v3;
  *(_DWORD *)(this + 128) = result;
  return result;
}
