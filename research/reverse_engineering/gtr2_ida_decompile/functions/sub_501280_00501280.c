bool __thiscall sub_501280(_DWORD *this, char *Buffer)
{
  int v3; // eax
  int v4; // edx
  int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  v6 = 0;
  v7 = 0;
  v3 = sscanf(Buffer, "(%d, %d)", &v6, &v7);
  v4 = v7;
  this[5] = v6;
  this[6] = v4;
  return v3 == 2;
}
