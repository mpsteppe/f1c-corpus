int __thiscall sub_487940(_DWORD *this)
{
  const char *v1; // eax
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  this[217] = *(_DWORD *)dword_7689CC;
  this[218] = &dword_768204;
  v1 = (const char *)sub_49D690(dword_768204);
  sprintf(Buffer, v1);
  sub_4A1AC0(Buffer);
  return 0;
}
