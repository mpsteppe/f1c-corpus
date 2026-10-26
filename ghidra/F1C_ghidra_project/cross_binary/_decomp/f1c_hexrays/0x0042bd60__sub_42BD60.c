// f1c  0x0042bd60  size=54
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
    sub_4C6960(v0);
    result = sub_4EF5A0(-1, 0);
    v1 += 4656;
    ++v0;
  }
  while ( (int)v1 < (int)&dword_7C54E4 );
  return result;
}
