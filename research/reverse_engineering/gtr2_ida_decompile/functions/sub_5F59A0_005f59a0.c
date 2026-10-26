double __thiscall sub_5F59A0(int this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned __int64 v4; // kr00_8
  unsigned int v6; // [esp+8h] [ebp-10h] BYREF
  DWORD v7; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v8; // [esp+10h] [ebp-8h]
  unsigned int v9; // [esp+14h] [ebp-4h]

  v2 = *(_DWORD *)(this + 40);
  v3 = *(_DWORD *)(this + 44);
  v9 = v2;
  v8 = v3;
  sub_5F5760((double *)this, (LONG *)&v6, &v7, 0);
  v4 = __PAIR64__(v6, v7) - __PAIR64__(v8, v9);
  v7 -= v9;
  v6 = HIDWORD(v4);
  return (double)HIDWORD(v4) * *(double *)(this + 16) + (double)v7 * *(double *)(this + 8);
}
