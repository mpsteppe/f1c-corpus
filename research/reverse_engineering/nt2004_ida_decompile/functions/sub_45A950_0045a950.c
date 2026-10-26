int __thiscall sub_45A950(int this, _DWORD *a2)
{
  int v3; // eax
  int v4; // edx
  int result; // eax
  _DWORD v6[6]; // [esp+10h] [ebp-48h] BYREF
  double v7[3]; // [esp+28h] [ebp-30h] BYREF
  double v8[3]; // [esp+40h] [ebp-18h] BYREF

  if ( *(_DWORD *)(this + 212) )
  {
    sub_59E170(
      *(_DWORD *)(this + 4),
      *(_DWORD *)(this + 8),
      *(_DWORD *)(this + 12),
      *(float *)(this + 16),
      *(float *)(this + 20),
      *(float *)(this + 24));
    sub_5A1290(0x8000000);
  }
  v7[0] = *(float *)(this + 4);
  v7[1] = *(float *)(this + 8);
  v7[2] = *(float *)(this + 12);
  qmemcpy((void *)(this + 220), v7, 0x18u);
  v8[0] = *(float *)(this + 16);
  v8[1] = *(float *)(this + 20);
  v8[2] = *(float *)(this + 24);
  memset(v6, 0, sizeof(v6));
  sub_57BF60(v8);
  qmemcpy((void *)(this + 316), v6, 0x18u);
  sub_57C010(v6);
  *(_DWORD *)(this + 192) = *(_DWORD *)(this + 4);
  v3 = *(_DWORD *)(this + 12);
  *(_DWORD *)(this + 196) = *(_DWORD *)(this + 8);
  *(_DWORD *)(this + 200) = v3;
  v4 = *(_DWORD *)(this + 4);
  *(_DWORD *)(this + 208) = 0;
  *a2 = v4;
  result = *(_DWORD *)(this + 8);
  a2[1] = result;
  a2[2] = *(_DWORD *)(this + 12);
  return result;
}
