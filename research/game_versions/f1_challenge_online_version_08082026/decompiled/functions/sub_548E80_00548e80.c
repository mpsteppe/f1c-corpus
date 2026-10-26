int __thiscall sub_548E80(const CHAR *this, char *a2, int a3)
{
  char *v3; // eax
  const CHAR *v5; // edi
  int v6; // edx
  char v7; // cl
  int result; // eax

  v3 = a2;
  v5 = this + 8;
  v6 = this + 8 - a2;
  do
  {
    v7 = *v3;
    v3[v6] = *v3;
    ++v3;
  }
  while ( v7 );
  sub_589901(v5);
  result = a3;
  *((_DWORD *)this + 1) = a3;
  return result;
}
