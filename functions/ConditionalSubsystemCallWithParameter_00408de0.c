int __thiscall sub_408DE0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ecx

  if ( this[2] )
  {
    result = sub_541CA0(a2);
    if ( !a2 )
    {
      v4 = this[3];
      if ( v4 )
        return RenderDrawOperationWithClipping(0, 0, *(_DWORD *)(v4 + 28), *(_DWORD *)(v4 + 32), &unk_686B75);
    }
  }
  return result;
}
