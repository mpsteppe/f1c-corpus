__time32_t __cdecl time(__time32_t *const Time)
{
  unsigned __int64 v1; // rax
  struct _FILETIME SystemTimeAsFileTime; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  v1 = (*(_QWORD *)&SystemTimeAsFileTime - 116444736000000000LL) / (unsigned __int64)(unsigned int)&unk_989680;
  if ( Time )
    *Time = v1;
  return v1;
}
