_DWORD *__userpurge sub_599CB7@<eax>(int a1@<ebp>, int a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // esi
  int v5; // [esp-10h] [ebp-10h]

  SEHHandlerInit();
  v3 = v2;
  *(_DWORD *)(a1 - 16) = v2;
  LocaleRefcountAcquireUnderLock(v2 + 13);
  *(_DWORD *)(a1 - 4) = 0;
  *v3 = &std::basic_streambuf<unsigned short>::`vftable';
  SelfReferentialPointerRingInit(v3);
  *(_DWORD *)(a1 - 4) = 1;
  LocaleRefcountAcquireUnderLock(v3 + 19);
  v5 = *(_DWORD *)(a1 + 8);
  *(_BYTE *)(a1 - 4) = 2;
  *v3 = &off_5B9C68;
  ObjectInitWithBufferDataPointerAssignment(v5, 0);
  return v3;
}
