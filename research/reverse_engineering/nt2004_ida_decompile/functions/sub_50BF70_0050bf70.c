BOOL __thiscall sub_50BF70(BOOL *this)
{
  int v2; // esi
  BOOL *v3; // edi
  BOOL result; // eax

  v2 = 0;
  v3 = this + 849;
  do
  {
    result = sub_50BEB0((int)this, v2);
    *v3 = result;
    ++v2;
    ++v3;
  }
  while ( v2 < 18 );
  return result;
}
