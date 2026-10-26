int __thiscall sub_4A5BD0(int this, float a2)
{
  int result; // eax
  int v4; // ecx

  result = CRTFtol((a2 - *(double *)(this + 88)) / *(double *)(this + 96) + 0.5);
  if ( result >= 0 )
  {
    v4 = *(_DWORD *)(this + 104);
    if ( result < v4 )
      *(_DWORD *)(this + 108) = result;
    else
      *(_DWORD *)(this + 108) = v4 - 1;
  }
  else
  {
    *(_DWORD *)(this + 108) = 0;
  }
  return result;
}
