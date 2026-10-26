// f1c  0x0059abcd  size=114
_DWORD *__userpurge sub_59ABCD@<eax>(int a1@<ebp>, int a2)
{
  int v2; // ecx
  _DWORD *v3; // esi
  char *v4; // eax

  sub_58A5D8();
  v3 = (_DWORD *)v2;
  *(_DWORD *)(a1 - 16) = v2;
  *(_DWORD *)(v2 + 4) = 1;
  *(_DWORD *)v2 = &std::locale::facet::`vftable';
  *(_BYTE *)(v2 + 20) = *(_BYTE *)(a1 + 8);
  LOBYTE(v2) = *(_BYTE *)(a1 + 11);
  v3[2] = 0;
  v3[3] = 0;
  v3[4] = 0;
  *((_BYTE *)v3 + 24) = v2;
  *(_DWORD *)(a1 - 4) = 0;
  sub_5993AF(v3 + 6, 0);
  v4 = sub_58E1B0(&word_5C406C);
  sub_599615(v3 + 6, &word_5C406C, (unsigned int)v4);
  *v3 = &off_5B9D4C;
  return v3;
}
