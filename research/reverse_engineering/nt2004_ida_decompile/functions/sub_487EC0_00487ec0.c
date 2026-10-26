int __thiscall sub_487EC0(_DWORD *this)
{
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  this[218] = *(_DWORD *)dword_7689CC;
  this[217] = &dword_7680C0;
  sprintf(Buffer, "%d", dword_7680C0);
  sub_4A1AC0(Buffer);
  return 0;
}
