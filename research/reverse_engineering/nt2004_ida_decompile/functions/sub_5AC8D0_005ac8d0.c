double __thiscall sub_5AC8D0(unsigned int *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // edi
  unsigned __int64 v6; // kr00_8
  unsigned int v7; // eax
  unsigned __int64 v9; // [esp+8h] [ebp-1Ch] BYREF
  unsigned int v10; // [esp+10h] [ebp-14h]
  unsigned int v11; // [esp+14h] [ebp-10h]
  unsigned int v12; // [esp+18h] [ebp-Ch]
  __int64 v13; // [esp+1Ch] [ebp-8h]

  v2 = this[13];
  v3 = this[10];
  v4 = this[11];
  v5 = this[12];
  LODWORD(v13) = v5;
  v12 = v2;
  v11 = v3;
  v10 = v4;
  v6 = __PAIR64__(v4, v3);
  if ( v2 || v5 )
  {
    sub_5AC7D0(this, (LONG *)&v9 + 1, (DWORD *)&v9);
    v9 = __PAIR64__(v10, v11) + v9 - __PAIR64__(v12, v13);
    v6 = v9;
  }
  v7 = *this;
  v13 = HIDWORD(v6);
  return (double)(unsigned int)v6 / (double)v7 + (double)HIDWORD(v6) * *((double *)this + 1) + *((double *)this + 2);
}
