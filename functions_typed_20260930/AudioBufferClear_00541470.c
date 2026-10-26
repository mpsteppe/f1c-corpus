int __thiscall sub_541470(int *this)
{
  int v1; // edx
  int result; // eax

  v1 = this[1107];
  result = 0;
  if ( v1 )
    return BufferLockAllocate(this, (_DWORD *)(v1 + 36 * this[1106]), 96, 0, 0);
  return result;
}

