char __thiscall GuardedConditionalRenderCall(int *this, char a2)
{
  int *v2; // eax
  _DWORD *v3; // ecx

  v2 = this;
  if ( a2 )
  {
    v3 = (_DWORD *)this[38];
    if ( v3 )
      LOBYTE(v2) = GuardedSubRectangleRenderDispatch(v3, v2[1], v2[2], v2[3], v2[4]);
  }
  return (char)v2;
}

