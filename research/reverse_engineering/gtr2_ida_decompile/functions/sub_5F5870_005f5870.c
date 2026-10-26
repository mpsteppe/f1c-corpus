double __thiscall sub_5F5870(int this)
{
  unsigned int v2; // eax
  __int64 v3; // kr00_8
  unsigned __int64 v4; // kr08_8
  int v5; // ecx
  __int64 v7; // [esp+8h] [ebp-18h] BYREF
  int v8; // [esp+10h] [ebp-10h]
  unsigned int v9; // [esp+14h] [ebp-Ch]
  unsigned int v10; // [esp+18h] [ebp-8h]
  unsigned int v11; // [esp+1Ch] [ebp-4h]

  sub_5F5760((double *)this, (LONG *)&v7 + 1, (DWORD *)&v7, 0);
  v2 = *(_DWORD *)(this + 52);
  v11 = *(_DWORD *)(this + 48);
  v10 = v2;
  v3 = v7 - __PAIR64__(v2, v11);
  v4 = v7 - __PAIR64__(v2, v11);
  v8 = HIDWORD(v4);
  v9 = v4;
  v5 = HIDWORD(v7);
  *(_DWORD *)(this + 48) = v7;
  *(_DWORD *)(this + 52) = v5;
  return (double)HIDWORD(v3) * *(double *)(this + 16) + (double)v9 * *(double *)(this + 8);
}
