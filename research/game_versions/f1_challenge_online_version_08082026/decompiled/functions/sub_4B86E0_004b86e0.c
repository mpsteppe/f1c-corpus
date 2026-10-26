void __thiscall sub_4B86E0(int this, float a2)
{
  double v2; // st7
  int v3; // edx

  v2 = a2;
  *(_DWORD *)(this + 3900) = *(_DWORD *)(this + 3896);
  *(float *)(this + 3896) = a2;
  if ( !*(_BYTE *)(this + 3969) )
  {
    while ( 1 )
    {
      if ( v2 <= *(float *)(this + 3892) )
      {
        if ( v2 >= *(float *)(this + 3888) )
          return;
        v2 = v2 + *(float *)(this + 3892) - *(float *)(this + 3888);
      }
      else
      {
        v2 = v2 - (*(float *)(this + 3892) - *(float *)(this + 3888));
      }
      v3 = *(_DWORD *)(this + 3896);
      *(float *)(this + 3896) = v2;
      *(_DWORD *)(this + 3900) = v3;
    }
  }
  if ( v2 <= *(float *)(this + 3892) )
  {
    if ( v2 < *(float *)(this + 3888) )
      *(_DWORD *)(this + 3896) = *(_DWORD *)(this + 3888);
  }
  else
  {
    *(_DWORD *)(this + 3896) = *(_DWORD *)(this + 3892);
  }
}
