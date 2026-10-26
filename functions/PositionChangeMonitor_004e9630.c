int __thiscall sub_4E9630(_DWORD *this)
{
  int *v2; // esi
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  float *v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax

  v2 = this + 3381;
  if ( !(v4 | v5) || !this[3751] )
  {
    v6 = sub_403640(dword_5EA2C0, (float *)this + 3381, this[3751]);
    v7 = *v2;
    v8 = v2[1];
    this[3751] = v6;
    v9 = v2[2];
    this[3752] = v7;
    this[3753] = v8;
    this[3754] = v9;
  }
  return this[3751];
}
