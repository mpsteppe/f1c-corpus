char __thiscall sub_432980(char **this, int a2)
{
  char *v3; // esi
  const char *v4; // edi
  unsigned int v5; // kr04_4
  _BYTE v7[256]; // [esp+Ch] [ebp-100h] BYREF

  sub_568620(256);
  sub_5665B0(v7);
  v3 = (char *)*((_DWORD *)*this + 2);
  v4 = v3;
  if ( !v3 )
    v4 = &byte_5EA438;
  v5 = strlen(v4) + 1;
  if ( (int)(v5 - 1) > 0 )
  {
    if ( !v3 )
      v3 = &byte_5EA438;
    if ( v3[v5 - 2] != 92 )
      sub_5665B0(&word_5C2AAC);
  }
  sub_431DB0(*this, 0);
  return 1;
}
