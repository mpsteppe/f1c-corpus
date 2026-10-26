int __thiscall sub_463710(int *this, int a2)
{
  int result; // eax
  int v3; // esi

  if ( a2 )
  {
    v3 = *this + 432;
    result = sub_587DD0(v3, a2, 31);
    *(_BYTE *)(v3 + 31) = 0;
  }
  else
  {
    result = *this;
    *(_BYTE *)(*this + 432) = 0;
  }
  return result;
}

