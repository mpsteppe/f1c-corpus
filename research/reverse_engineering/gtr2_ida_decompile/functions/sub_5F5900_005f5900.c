double __thiscall sub_5F5900(int this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // edi
  unsigned __int64 v6; // kr00_8
  double v7; // st7
  unsigned __int64 v9; // [esp+8h] [ebp-18h] BYREF
  unsigned int v10; // [esp+10h] [ebp-10h]
  unsigned int v11; // [esp+14h] [ebp-Ch]
  unsigned int v12; // [esp+18h] [ebp-8h]
  unsigned int v13; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD *)(this + 68);
  v3 = *(_DWORD *)(this + 56);
  v4 = *(_DWORD *)(this + 60);
  v5 = *(_DWORD *)(this + 64);
  v13 = v5;
  v12 = v2;
  v11 = v3;
  v10 = v4;
  v6 = __PAIR64__(v4, v3);
  if ( v2 || v5 )
  {
    sub_5F5760((double *)this, (LONG *)&v9 + 1, (DWORD *)&v9, 0);
    v9 = __PAIR64__(v10, v11) + v9 - __PAIR64__(v12, v13);
    v6 = v9;
  }
  v13 = HIDWORD(v6);
  v7 = (double)HIDWORD(v6) * *(double *)(this + 16);
  v13 = v6;
  return v7 + (double)(unsigned int)v6 * *(double *)(this + 8) + *(double *)(this + 24);
}
