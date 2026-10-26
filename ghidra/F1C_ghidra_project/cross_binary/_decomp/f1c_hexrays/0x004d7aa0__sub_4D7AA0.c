// f1c  0x004d7aa0  size=38
int sub_4D7AA0(int a1, int a2, ...)
{
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, a2);
  sub_58A163(*(_DWORD *)(a1 + 4), a2, va);
  return sub_589FFD(*(_DWORD *)(a1 + 4));
}
