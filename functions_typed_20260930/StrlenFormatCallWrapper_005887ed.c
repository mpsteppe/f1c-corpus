int sub_5887ED(int a1, const char *a2, ...)
{
  _DWORD v3[8]; // [esp+0h] [ebp-20h] BYREF
  va_list va; // [esp+30h] [ebp+10h] BYREF

  va_start(va, a2);
  v3[3] = 73;
  v3[2] = a1;
  v3[0] = a1;
  v3[1] = Strlen(a1);
  return sub_58E4D2(v3, a2, va);
}

