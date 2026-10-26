int __thiscall GuardedFunctionCall(int *this, int a2, int a3)
{
  int v3; // ecx

  v3 = *this;
  if ( v3 )
    return MPEGBuffer(v3, a2, a3);
  else
    return 0;
}
