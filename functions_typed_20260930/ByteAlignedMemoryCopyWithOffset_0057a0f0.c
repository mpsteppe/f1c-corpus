char *__thiscall sub_57A0F0(char *this, int a2)
{
  char *result; // eax
  _BYTE *v3; // edx
  int v4; // esi
  int v5; // edi
  _BYTE *v6; // edx

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
  do
  {
    *v6 = v6[v4];
    ++v6;
  }
  while ( (int)&v6[-16 - (_DWORD)this] < 32 );
  return result;
}

