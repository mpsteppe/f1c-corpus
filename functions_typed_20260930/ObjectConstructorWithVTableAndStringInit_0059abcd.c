_DWORD *__userpurge sub_59ABCD@<eax>(int a1@<ebp>, int a2)
{
  int v2; // ecx
  _DWORD *v3; // esi
  char *v4; // eax

  SEHHandlerInit();
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
  ReferenceCountDecrementWithConditionalFree(v3 + 6, 0);
  v4 = Strlen(&word_5C406C);
  BufferWriteWithNullTerminate(v3 + 6, &word_5C406C, (unsigned int)v4);
  *v3 = &off_5B9D4C;
  return v3;
}

