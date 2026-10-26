int __thiscall sub_418900(_DWORD *this)
{
  int result; // eax
  int (__thiscall ***v3)(_DWORD, int); // ecx

  GlobalVTableDispatchWithQuery(0);
  GlobalVTableDispatchWithQuery(1);
  result = DrawableResourceCleanup(&dword_5EA5E8);
  v3 = (int (__thiscall ***)(_DWORD, int))this[701];
  if ( v3 )
  {
    result = (**v3)(v3, 1);
    this[701] = 0;
  }
  return result;
}

