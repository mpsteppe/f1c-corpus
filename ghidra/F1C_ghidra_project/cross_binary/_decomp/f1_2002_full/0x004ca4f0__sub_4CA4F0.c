// f1_2002_full  0x004ca4f0  size=38
int sub_4CA4F0(int a1, char *Format, ...)
{
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, Format);
  vfprintf(*(FILE *const *)(a1 + 4), Format, va);
  return fflush(*(FILE **)(a1 + 4));
}
