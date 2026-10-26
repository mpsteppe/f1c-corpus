int __thiscall sub_499DA0(_DWORD *this, _DWORD **a2)
{
  _DWORD **v2; // ebx
  _DWORD *v4; // esi
  int result; // eax

  v2 = a2;
  if ( !a2 )
    v2 = (_DWORD **)(this + 2);
  v4 = *v2;
  if ( *v2 )
  {
    TreeNodeRecursiveDestructor(v4 + 10);
    TreeNodeRecursiveDestructor(v4 + 9);
    ConditionalDualCleanup(v4);
    result = FreeWrapper_7bcf(v4);
  }
  *v2 = 0;
  this[3] = 0;
  return result;
}

