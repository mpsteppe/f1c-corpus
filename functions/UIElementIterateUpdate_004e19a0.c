int __thiscall sub_4E19A0(char *this)
{
  int v2; // esi
  int *v3; // edi
  int result; // eax

  v2 = 0;
  v3 = (int *)(this + 2928);
  do
    result = SubsystemStateMachine(this, v2++, *v3++);
  while ( v2 < 14 );
  return result;
}
