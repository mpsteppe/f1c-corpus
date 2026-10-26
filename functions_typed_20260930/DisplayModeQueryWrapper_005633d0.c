int __thiscall sub_5633D0(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // [esp+10h] [ebp+Ch]

  v5 = StructAllocInitWithSwitchBasedType(a4, this[37]);
  AudioStackPushWithOverflowRealloc(a3);
  return v5;
}

