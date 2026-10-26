unsigned __int64 __thiscall sub_4FB830(int this, float a2)
{
  unsigned __int64 result; // rax
  int v4; // ecx

  result = (unsigned __int64)((a2 - *(double *)(this + 152)) / *(double *)(this + 160) + 0.5);
  if ( (result & 0x80000000) == 0LL )
  {
    v4 = *(_DWORD *)(this + 168);
    if ( (int)result < v4 )
      *(_DWORD *)(this + 172) = result;
    else
      *(_DWORD *)(this + 172) = v4 - 1;
  }
  else
  {
    *(_DWORD *)(this + 172) = 0;
  }
  return result;
}
