_DWORD *__userpurge sub_599BF0@<eax>(_DWORD *a1@<ebp>, int a2, int a3, int a4)
{
  _DWORD *v4; // ecx
  bool v5; // zf
  _DWORD *v6; // esi
  int v8; // [esp-14h] [ebp-14h]
  int v9; // [esp-10h] [ebp-10h]

  sub_58A5D8();
  v5 = a1[4] == 0;
  v6 = v4;
  *(a1 - 5) = v4;
  *(a1 - 4) = 0;
  if ( !v5 )
  {
    *v4 = &unk_5B9C5C;
    v4[11] = 0;
    v4[2] = &std::basic_ios<unsigned short>::`vftable';
    *(a1 - 4) = 1;
    *(a1 - 1) = 0;
  }
  v4[1] = 0;
  v9 = a1[3];
  v8 = a1[2];
  *(_DWORD *)((char *)v4 + *(_DWORD *)(*v4 + 4)) = &std::basic_istream<unsigned short>::`vftable';
  sub_59A3A9(v8, v9);
  return v6;
}
