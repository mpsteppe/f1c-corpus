int __thiscall sub_514F70(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // edx

  v2 = this[4750];
  if ( !v2 || *(_DWORD *)(v2 + 328) != 1 )
  {
    v3 = this + 4380;
    v4 = sub_403FD0(&flt_628F60, (float *)this + 4380, *(_DWORD *)(*this + 23612));
    this[4751] = *v3;
    v5 = this[4382];
    this[4750] = v4;
    this[4752] = this[4381];
    this[4753] = v5;
  }
  return this[4750];
}
