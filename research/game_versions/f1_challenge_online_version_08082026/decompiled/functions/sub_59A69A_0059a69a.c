_DWORD *__userpurge sub_59A69A@<eax>(int a1@<ebp>, int a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // esi
  _BYTE *v4; // ebx

  sub_58A5D8();
  v3 = v2;
  *(_DWORD *)(a1 - 20) = v2;
  *(_DWORD *)(a1 - 16) = byte_5EA438;
  sub_59BF19(a1 - 16);
  v4 = *(_BYTE **)(a1 + 8);
  *(_DWORD *)(a1 - 4) = 0;
  *((_BYTE *)v3 + 12) = *v4;
  sub_5993AF(v3 + 3, 0);
  sub_59A9CA(v4, 0, -1);
  *v3 = &std::runtime_error::`vftable';
  return v3;
}
