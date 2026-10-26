bool __thiscall sub_4AFB30(_DWORD *this)
{
  int v1; // eax

  v1 = this[5];
  if ( v1 )
    this[5] = *(_DWORD *)(v1 + 56);
  return this[5] != 0;
}
