int __thiscall sub_541420(_DWORD *this)
{
  int result; // eax

  result = this[1107];
  if ( result )
  {
    ObjectResetWithVirtualRelease(this, this[1107]);
    ObjectResetWithVirtualRelease(this, this[1107] + 36);
    result = this[1107];
    if ( result )
      result = FreeWrapper_7bcf((LPVOID)(result - 4));
    this[1107] = 0;
  }
  return result;
}

