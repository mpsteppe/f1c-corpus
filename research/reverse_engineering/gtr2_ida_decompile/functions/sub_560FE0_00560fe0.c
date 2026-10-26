void __thiscall sub_560FE0(int *this)
{
  int v2; // edi
  int v3; // ebx
  char *v4; // eax
  char *v5; // edi

  v2 = 0;
  if ( *this > 0 )
  {
    v3 = 0;
    do
    {
      sub_560A60();
      ++v2;
      v3 += 36;
    }
    while ( v2 < *this );
  }
  v4 = (char *)this[1];
  *this = 0;
  if ( v4 )
  {
    v5 = v4 - 4;
    `eh vector destructor iterator'(v4, 0x24u, *((_DWORD *)v4 - 1), (void (__thiscall *)(void *))sub_560F20);
    j_j__free(v5);
  }
  this[1] = 0;
}
