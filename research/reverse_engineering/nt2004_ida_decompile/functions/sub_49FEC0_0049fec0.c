int __thiscall sub_49FEC0(_DWORD *this)
{
  int i; // esi
  int v3; // ecx
  int (__thiscall **v4)(int, int); // eax
  int result; // eax

  for ( i = this[36]; i; result = (*v4)(v3, 1) )
  {
    v3 = i;
    v4 = *(int (__thiscall ***)(int, int))i;
    i = *(_DWORD *)(i + 140);
  }
  this[36] = 0;
  this[101] = -1;
  this[37] = 0;
  return result;
}
