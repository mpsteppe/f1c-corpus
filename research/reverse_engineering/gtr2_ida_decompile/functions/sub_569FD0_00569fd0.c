void __thiscall sub_569FD0(_DWORD *this)
{
  char *v2; // eax
  char *v3; // edi
  char *v4; // eax
  char *v5; // edi

  v2 = (char *)this[3];
  this[1] = 0;
  this[2] = 0;
  if ( v2 )
  {
    v3 = v2 - 4;
    `eh vector destructor iterator'(
      v2,
      0xCu,
      *((_DWORD *)v2 - 1),
      (void (__thiscall *)(void *))Concurrency::details::TaskStack::~TaskStack);
    j_j__free(v3);
  }
  v4 = (char *)this[5];
  this[3] = 0;
  this[4] = 0;
  if ( v4 )
  {
    v5 = v4 - 4;
    `eh vector destructor iterator'(v4, 0x18u, *((_DWORD *)v4 - 1), (void (__thiscall *)(void *))sub_568D80);
    j_j__free(v5);
  }
  this[5] = 0;
  this[6] = 0;
}
