char __thiscall sub_4582C0(float *this)
{
  float *v1; // esi
  int v2; // edi
  char result; // al

  v1 = this + 1738;
  v2 = 61;
  do
  {
    result = sub_4556B0(v1);
    v1 += 11;
    --v2;
  }
  while ( v2 );
  return result;
}
