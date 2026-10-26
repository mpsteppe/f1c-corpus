int __thiscall sub_486770(_DWORD *this)
{
  const char *v1; // eax
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  this[218] = *(_DWORD *)dword_7689CC;
  this[217] = &dword_7689F0;
  v1 = (const char *)sub_49D690(dword_7689F0);
  sprintf(Buffer, v1);
  sub_4A1AC0(Buffer);
  return 0;
}
