_DWORD *__userpurge sub_59AE7D@<eax>(int a1@<ebp>, int a2)
{
  int v2; // ebx
  _DWORD *v3; // ecx
  _DWORD *v4; // esi
  char v5; // al

  SEHHandlerInit();
  v2 = *(_DWORD *)(a1 + 8);
  v4 = v3;
  *(_DWORD *)(a1 - 16) = v3;
  StrlenAllocCopyConstructorPattern(v2);
  v5 = *(_BYTE *)(v2 + 12);
  *(_DWORD *)(a1 - 4) = 0;
  *((_BYTE *)v4 + 12) = v5;
  ReferenceCountDecrementWithConditionalFree(v4 + 3, 0);
  sub_59A9CA(v4 + 3, (_DWORD *)(v2 + 12), 0, 0xFFFFFFFF);
  *v4 = &std::logic_error::`vftable';
  return v4;
}
