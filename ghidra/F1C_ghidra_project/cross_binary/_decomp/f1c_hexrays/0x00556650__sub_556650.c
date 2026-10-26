// f1c  0x00556650  size=123
double __thiscall sub_556650(double *this)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // edx
  double v5; // st6
  __int64 v7; // [esp+8h] [ebp-14h] BYREF
  unsigned int v8; // [esp+10h] [ebp-Ch]
  __int64 v9; // [esp+14h] [ebp-8h]

  v2 = *((_DWORD *)this + 6);
  v3 = *((_DWORD *)this + 7);
  LODWORD(v9) = v2;
  v8 = v3;
  sub_5564B0(this, (LONG *)&v7 + 1, (DWORD *)&v7);
  v7 -= __PAIR64__(v8, v9);
  v4 = *(_DWORD *)this;
  v9 = (unsigned int)v7;
  LODWORD(v9) = v4;
  v5 = (double)v9;
  v9 = HIDWORD(v7);
  return (double)(unsigned int)v7 / v5 + (double)HIDWORD(v7) * this[1];
}
