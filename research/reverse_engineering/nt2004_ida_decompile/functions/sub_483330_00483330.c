int __thiscall sub_483330(_DWORD *this)
{
  _DWORD *v1; // eax
  const char *v2; // eax
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  v1 = (_DWORD *)(36 * *(_DWORD *)dword_7689CC + 7762056);
  this[217] = v1;
  v2 = (const char *)sub_49D690(*v1);
  sprintf(Buffer, v2);
  sub_4A1AC0(Buffer);
  return 0;
}
