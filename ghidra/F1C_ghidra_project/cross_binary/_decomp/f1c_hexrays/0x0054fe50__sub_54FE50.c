// f1c  0x0054fe50  size=109
int __thiscall sub_54FE50(const CHAR *this, const char *a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  unsigned int v5; // ecx
  char v6; // al
  int v7; // ecx
  const CHAR *v8; // esi
  const char *v9; // eax
  int v10; // edx
  char v11; // cl

  v3 = (_DWORD *)sub_587C03(60);
  if ( v3 )
    v4 = sub_5426A0(v3);
  else
    v4 = 0;
  *((_DWORD *)this + 21) = v4;
  v5 = strlen(a2) + 1;
  v6 = a2[v5 - 2];
  v7 = v5 - 2;
  if ( v6 != 92 )
  {
    do
      --v7;
    while ( v7 >= 0 && a2[v7] != 92 );
  }
  v8 = this + 4;
  v9 = &a2[v7 + 1];
  v10 = v8 - v9;
  do
  {
    v11 = *v9;
    v9[v10] = *v9;
    ++v9;
  }
  while ( v11 );
  sub_589901(v8);
  return 0;
}
