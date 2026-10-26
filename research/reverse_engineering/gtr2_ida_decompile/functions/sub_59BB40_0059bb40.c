char *__thiscall sub_59BB40(char *this, int a2)
{
  char *result; // eax
  _BYTE *v3; // edx
  int v4; // esi
  int v5; // edi
  _BYTE *v6; // edx
  int v7; // edi

  result = this;
  v3 = this;
  v4 = a2 - (_DWORD)this;
  v5 = 16;
  do
  {
    *v3 = v3[v4];
    ++v3;
    --v5;
  }
  while ( v5 );
  v6 = this + 16;
  v7 = 32;
  do
  {
    *v6 = v6[v4];
    ++v6;
    --v7;
  }
  while ( v7 );
  return result;
}
