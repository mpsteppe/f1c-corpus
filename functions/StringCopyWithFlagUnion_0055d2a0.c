int __thiscall sub_55D2A0(char *this, char *a2, int a3)
{
  char *v3; // eax
  int v5; // edx
  char v6; // cl

  v3 = a2;
  *(_DWORD *)this |= a3;
  v5 = this + 88 - a2;
  do
  {
    v6 = *v3;
    v3[v5] = *v3;
    ++v3;
  }
  while ( v6 );
  *((_DWORD *)this + 1) = SceneStateSetup(dword_8B78A0, a3);
  return 0;
}
