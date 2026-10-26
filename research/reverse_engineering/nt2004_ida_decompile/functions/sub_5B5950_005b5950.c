int __thiscall sub_5B5950(char *this, char *a2, int a3)
{
  char *v3; // eax
  int v4; // edx
  char v5; // cl

  v3 = a2;
  *(_DWORD *)this |= a3;
  v4 = this + 184 - a2;
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 );
  return 0;
}
