void __thiscall sub_459CE0(int *this, int a2)
{
  int v2; // ecx

  v2 = *this;
  *(_DWORD *)(v2 + 136) = a2;
  if ( *(float *)(v2 + 136) >= 0.0 )
  {
    if ( *(float *)(v2 + 136) > 1.0 )
      *(_DWORD *)(v2 + 136) = 1065353216;
  }
  else
  {
    *(_DWORD *)(v2 + 136) = 0;
  }
}
