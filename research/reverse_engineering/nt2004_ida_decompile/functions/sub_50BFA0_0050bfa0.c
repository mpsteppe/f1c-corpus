int __thiscall sub_50BFA0(int *this)
{
  int v2; // esi
  int *v3; // edi
  int result; // eax

  v2 = 0;
  v3 = this + 849;
  do
    result = sub_50BDD0(this, v2++, *v3++);
  while ( v2 < 18 );
  return result;
}
