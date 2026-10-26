double __thiscall sub_57B7C0(double *this)
{
  unsigned int v2; // edx
  int v3; // eax
  int v4; // ecx
  double v5; // st6
  unsigned __int64 v7; // [esp+8h] [ebp-1Ch] BYREF
  unsigned int v8; // [esp+10h] [ebp-14h]
  unsigned int v9; // [esp+14h] [ebp-10h]
  unsigned int v10; // [esp+18h] [ebp-Ch]
  __int64 v11; // [esp+1Ch] [ebp-8h]

  v2 = *((_DWORD *)this + 10);
  v3 = *((_DWORD *)this + 6);
  v10 = *((_DWORD *)this + 7);
  v9 = v2;
  LODWORD(v11) = v3;
  v8 = *((_DWORD *)this + 11);
  sub_57B6E0(this, (LONG *)&v7 + 1, (DWORD *)&v7);
  v7 = v7 - __PAIR64__(v10, v11) - __PAIR64__(v8, v9);
  v4 = *(_DWORD *)this;
  v11 = (unsigned int)v7;
  LODWORD(v11) = v4;
  v5 = (double)v11;
  v11 = HIDWORD(v7);
  return (double)(unsigned int)v7 / v5 + (double)HIDWORD(v7) * this[1] + this[2];
}
