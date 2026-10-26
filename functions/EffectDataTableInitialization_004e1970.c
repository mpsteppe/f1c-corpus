int __thiscall sub_4E1970(int *this)
{
  int v2; // esi
  int *v3; // edi
  int result; // eax

  v2 = 0;
  v3 = this + 732;
  do
  {
    result = SubsystemReadyQuery((int)this, v2);
    *v3 = result;
    ++v2;
    ++v3;
  }
  while ( v2 < 14 );
  return result;
}
