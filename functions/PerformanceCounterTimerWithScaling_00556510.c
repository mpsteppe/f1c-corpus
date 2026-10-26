double __thiscall sub_556510(double *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // ecx
  unsigned int v5; // edx
  double v6; // st6
  __int64 v8; // [esp+8h] [ebp-1Ch] BYREF
  __int64 v9; // [esp+10h] [ebp-14h]
  unsigned int v10; // [esp+18h] [ebp-Ch]
  __int64 v11; // [esp+1Ch] [ebp-8h]

  v2 = *((_DWORD *)this + 8);
  v3 = *((_DWORD *)this + 9);
  LODWORD(v11) = v2;
  v10 = v3;
  QueryPerformanceCounterWrapperWithModeDispatch(this, (LONG *)&v8 + 1, (DWORD *)&v8);
  v9 = v8 - __PAIR64__(v10, v11);
  v4 = HIDWORD(v8);
  v5 = v8 - v11;
  *((_DWORD *)this + 8) = v8;
  v11 = v5;
  *((_DWORD *)this + 9) = v4;
  v11 = *(unsigned int *)this;
  v6 = (double)v11;
  LODWORD(v11) = HIDWORD(v9);
  return (double)v5 / v6 + (double)v11 * this[1];
}
