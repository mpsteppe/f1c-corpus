double __thiscall sub_568CF0(double *this)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // ecx
  int v5; // edx
  int v6; // edx
  double v7; // st6
  _BYTE v9[12]; // [esp+8h] [ebp-18h] BYREF
  unsigned int v10; // [esp+14h] [ebp-Ch]
  __int64 v11; // [esp+18h] [ebp-8h]

  v2 = *((_DWORD *)this + 8);
  v3 = *((_DWORD *)this + 9);
  LODWORD(v11) = v2;
  v10 = v3;
  sub_568CB0(this, (LONG *)&v9[8], (DWORD *)&v9[4]);
  v4 = *(_DWORD *)&v9[4];
  v5 = *(_DWORD *)&v9[8];
  *(_QWORD *)v9 = *(_QWORD *)&v9[4] - __PAIR64__(v10, v11);
  *((_DWORD *)this + 8) = v4;
  *((_DWORD *)this + 9) = v5;
  v6 = *(_DWORD *)this;
  v11 = *(unsigned int *)v9;
  LODWORD(v11) = v6;
  v7 = (double)v11;
  v11 = *(unsigned int *)&v9[4];
  return (double)*(unsigned int *)v9 / v7 + (double)*(unsigned int *)&v9[4] * this[1];
}
