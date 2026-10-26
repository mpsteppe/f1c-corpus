int __thiscall sub_49EEF0(_DWORD *this)
{
  const char *v1; // eax
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  this[212] = *(_DWORD *)dword_B72314;
  this[211] = &dword_B74F70;
  v1 = (const char *)sub_4CFC00(dword_B74F70);
  sprintf(Buffer, v1);
  sub_4CE770(Buffer);
  return 0;
}
