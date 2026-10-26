_DWORD *__thiscall sub_459010(int this)
{
  _DWORD *result; // eax
  _DWORD v3[3]; // [esp+4h] [ebp-Ch] BYREF

  memset(v3, 0, sizeof(v3));
  StructFieldCopy((_DWORD *)this, v3);
  *(_DWORD *)(this + 188) = 0;
  *(_BYTE *)(this + 204) = 0;
  *(_DWORD *)(this + 172) = 1065353216;
  result = VectorCopy((_DWORD *)this, (_DWORD *)(this + 144));
  *(_BYTE *)(this + 160) = 1;
  return result;
}
