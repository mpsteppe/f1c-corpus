int __thiscall sub_4B6940(_DWORD *this, float a2)
{
  char *v3; // ecx
  int result; // eax

  sub_4B7860(0);
  if ( (unsigned __int8)CoordinateBoundCheck(this) )
  {
    v3 = (char *)this[620];
    this[623] = 0;
    this[622] = 0;
    PhysicsObjectListManager(v3);
  }
  else
  {
    CircularCounterIncrement(this);
  }
  result = 176 * this[622];
  *(float *)(result + this[620] + 108) = a2;
  return result;
}

