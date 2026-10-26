char __thiscall sub_455BD0(float *this)
{
  float *v1; // esi
  int v2; // edi
  char result; // al

  v1 = this + 1736;
  v2 = 44;
  do
  {
    result = CollisionResultProcessing(v1);
    v1 += 11;
    --v2;
  }
  while ( v2 );
  return result;
}

