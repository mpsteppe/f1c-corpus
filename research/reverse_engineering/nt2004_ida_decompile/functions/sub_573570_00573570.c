int __thiscall sub_573570(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // edi
  int v3; // ebx
  void **v4; // ebp
  int result; // eax

  v1 = this;
  v2 = *this;
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) )
    {
      v4 = *(void ***)v3;
      if ( *(_DWORD *)v3 )
      {
        if ( *v4 )
        {
          `eh vector destructor iterator'(*v4, 0x4840u, *((_DWORD *)*v4 - 1), (void (__thiscall *)(void *))nullsub_5);
          sub_5BE8AE();
          v1 = this;
        }
        sub_5BE8AE();
      }
    }
    sub_5BE8AE();
  }
  result = 0;
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}
