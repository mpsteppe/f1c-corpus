int __thiscall sub_489CB0(int *this)
{
  int v2; // esi
  int v3; // ecx
  void (__thiscall **v4)(int, int); // eax
  int v5; // edx

  v2 = this[36];
  while ( v2 )
  {
    v3 = v2;
    v4 = *(void (__thiscall ***)(int, int))v2;
    v2 = *(_DWORD *)(v2 + 140);
    (*v4)(v3, 1);
  }
  v5 = *this;
  this[36] = 0;
  this[90] = -1;
  this[37] = 0;
  return (*(int (__thiscall **)(int *, int))(v5 + 44))(this, 1);
}
