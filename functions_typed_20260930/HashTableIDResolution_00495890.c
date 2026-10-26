const char *__stdcall sub_495890(const char *a1)
{
  int v1; // eax

  StringFormatWithBufferOverflowCheck(&unk_7CDE38, "%s", a1);
  v1 = ShortComputation_4fb0((int)&a1, (int)&unk_7CDE38, 1);
  return v1 == 0 ? a1 : 0;
}

