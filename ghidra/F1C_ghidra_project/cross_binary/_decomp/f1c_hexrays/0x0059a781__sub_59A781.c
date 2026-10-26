// f1c  0x0059a781  size=93
_DWORD *__userpurge sub_59A781@<eax>(int a1@<ebp>, int a2)
{
  int v2; // ebx
  _DWORD *v3; // ecx
  _DWORD *v4; // esi
  char v5; // al

  sub_58A5D8();
  v2 = *(_DWORD *)(a1 + 8);
  v4 = v3;
  *(_DWORD *)(a1 - 16) = v3;
  sub_59BF56(v2);
  v5 = *(_BYTE *)(v2 + 12);
  *(_DWORD *)(a1 - 4) = 0;
  *((_BYTE *)v4 + 12) = v5;
  sub_5993AF(v4 + 3, 0);
  sub_59A9CA(v2 + 12, 0, -1);
  *v4 = &std::runtime_error::`vftable';
  return v4;
}
