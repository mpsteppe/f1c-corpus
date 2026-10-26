_DWORD *__thiscall sub_5730B0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi

  v3 = operator new(0x9084u);
  if ( v3 )
  {
    v4 = v3 + 1;
    *v3 = 2;
    `eh vector constructor iterator'(
      v3 + 1,
      0x4840u,
      2,
      (void (__thiscall *)(void *))sub_572120,
      (void (__thiscall *)(void *))nullsub_5);
    *this = v4;
  }
  else
  {
    *this = 0;
  }
  return this;
}
