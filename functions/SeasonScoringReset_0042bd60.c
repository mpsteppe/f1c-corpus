int sub_42BD60()
{
  int v0; // edi
  int *v1; // esi
  int result; // eax

  byte_7C5690 = 0;
  v0 = 0;
  v1 = (int *)&unk_5EC6E4;
  do
  {
    TeamIDSetter(v0);
    result = SessionStateTransition(-1, 0);
    v1 += 4656;
    ++v0;
  }
  while ( (int)v1 < (int)&dword_7C54E4 );
  return result;
}
