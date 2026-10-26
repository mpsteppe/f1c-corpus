int __thiscall MultiStageVTableDispatch(int this)
{
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  DualFieldRead(*(_DWORD **)(this + 64), &v4, &v3);
  if ( !UIValueValidator((_BYTE *)this)
    || !(*(int (__thiscall **)(int, int, int))(*(_DWORD *)this + 48))(this, v4, v3)
    || (*(int (__thiscall **)(int))(*(_DWORD *)this + 156))(this) )
  {
    return -1;
  }
  LinkedListTraversalWithCallback((_DWORD *)this);
  return 0;
}

