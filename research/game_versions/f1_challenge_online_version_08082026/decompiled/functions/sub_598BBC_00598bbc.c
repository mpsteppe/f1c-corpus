_DWORD *__userpurge sub_598BBC@<eax>(int a1@<ebp>, int a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // esi
  int v5; // [esp-10h] [ebp-10h]

  sub_58A5D8();
  v3 = v2;
  *(_DWORD *)(a1 - 16) = v2;
  sub_598C1C(v2 + 13);
  *(_DWORD *)(a1 - 4) = 0;
  *v3 = &std::streambuf::`vftable';
  sub_59A4C9(v3);
  *(_DWORD *)(a1 - 4) = 1;
  sub_598C1C(v3 + 19);
  v5 = *(_DWORD *)(a1 + 8);
  *(_BYTE *)(a1 - 4) = 2;
  *v3 = &off_5B9BCC;
  sub_5994BC(v5, 0);
  return v3;
}
