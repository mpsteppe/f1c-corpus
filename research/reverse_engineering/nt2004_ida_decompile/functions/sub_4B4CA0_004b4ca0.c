int __thiscall sub_4B4CA0(_DWORD *this)
{
  int v2; // eax
  char Buffer[16]; // [esp+4h] [ebp-10h] BYREF

  if ( byte_768A14 )
    v2 = sub_4B2E60();
  else
    v2 = sub_4B2EB0();
  sprintf(Buffer, "%.3d", v2);
  return sub_5A3FF0(Buffer, 4, 43, *(_DWORD *)(this[4] + 16), 0);
}
