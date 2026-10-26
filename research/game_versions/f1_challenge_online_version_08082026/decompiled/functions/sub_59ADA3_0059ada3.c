_DWORD *__userpurge sub_59ADA3@<eax>(int a1@<ebp>, int a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // esi
  _DWORD *v4; // ebx

  sub_58A5D8();
  v3 = v2;
  *(_DWORD *)(a1 - 20) = v2;
  *(_DWORD *)(a1 - 16) = byte_5EA438;
  sub_59BF19(a1 - 16);
  v4 = *(_DWORD **)(a1 + 8);
  *(_DWORD *)(a1 - 4) = 0;
  *((_BYTE *)v3 + 12) = *(_BYTE *)v4;
  sub_5993AF(v3 + 3, 0);
  sub_59A9CA(v3 + 3, v4, 0, 0xFFFFFFFF);
  *v3 = &std::logic_error::`vftable';
  return v3;
}
