int __thiscall sub_514EE0(_DWORD *this)
{
  int *v2; // esi
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  float *v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax

  v2 = this + 4380;
  if ( !(v4 | v5) || !this[4750] )
  {
    v6 = sub_403D10(&flt_628F60, (float *)this + 4380, this[4750]);
    v7 = *v2;
    v8 = v2[1];
    this[4750] = v6;
    v9 = v2[2];
    this[4751] = v7;
    this[4752] = v8;
    this[4753] = v9;
  }
  return this[4750];
}
