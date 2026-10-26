int __cdecl sub_587AC0(int a1)
{
  unsigned int v1; // eax
  char *v2; // ecx
  int v3; // eax
  char *v4; // eax
  int v5; // esi
  int v6; // ecx

  sub_589D6B();
  v1 = sub_58BB68(dword_8D5A54);
  v2 = (char *)dword_8D5A50;
  if ( v1 >= dword_8D5A50 - (int)dword_8D5A54 + 4 )
    goto LABEL_5;
  v3 = sub_58BB68(dword_8D5A54);
  v4 = (char *)sub_58B5D4((LPVOID)dword_8D5A54, v3 + 16);
  if ( v4 )
  {
    v6 = dword_8D5A50 - (_DWORD)dword_8D5A54;
    dword_8D5A54 = v4;
    v2 = &v4[4 * (v6 >> 2)];
    dword_8D5A50 = (int)v2;
LABEL_5:
    *(_DWORD *)v2 = a1;
    dword_8D5A50 += 4;
    v5 = a1;
    goto LABEL_6;
  }
  v5 = 0;
LABEL_6:
  CriticalSectionLeave();
  return v5;
}
