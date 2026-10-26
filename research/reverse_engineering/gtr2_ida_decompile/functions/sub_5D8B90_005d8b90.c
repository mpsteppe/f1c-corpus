_DWORD *__thiscall sub_5D8B90(int this)
{
  int v2; // [esp+8h] [ebp-44h] BYREF
  _BYTE v3[64]; // [esp+Ch] [ebp-40h] BYREF

  v2 = 1;
  qmemcpy(v3, (const void *)(this + 4), sizeof(v3));
  return sub_5D7160(this, (float *)&v2);
}
