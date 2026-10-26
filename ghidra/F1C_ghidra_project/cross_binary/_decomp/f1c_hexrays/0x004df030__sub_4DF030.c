// f1c  0x004df030  size=98
int __thiscall sub_4DF030(int this, float a2)
{
  int result; // eax
  float v3[9]; // [esp+0h] [ebp-24h] BYREF

  v3[1] = a2;
  result = *(_DWORD *)(this + 24);
  LODWORD(v3[0]) = 1;
  memset(&v3[2], 0, 28);
  if ( result )
    return sub_4DEDB0((float *)this, v3);
  return result;
}
