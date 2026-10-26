__int64 __thiscall sub_4C1710(int this, float a2)
{
  __int64 result; // rax
  int v4; // ecx

  result = (__int64)((a2 - *(double *)(this + 76)) / *(double *)(this + 84) + 0.5);
  if ( (int)result >= 0 )
  {
    v4 = *(_DWORD *)(this + 92);
    if ( (int)result < v4 )
      *(_DWORD *)(this + 96) = result;
    else
      *(_DWORD *)(this + 96) = v4 - 1;
  }
  else
  {
    *(_DWORD *)(this + 96) = 0;
  }
  return result;
}
