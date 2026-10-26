int __thiscall sub_519CC0(char *this)
{
  void *v1; // edi
  void **v2; // esi
  int v3; // ebp
  int v4; // ebx
  int result; // eax

  v1 = this + 32;
  v2 = (void **)(this + 32);
  v3 = 32;
  do
  {
    v4 = 32;
    do
    {
      if ( *v2 )
        j__free(*v2);
      ++v2;
      --v4;
    }
    while ( v4 );
    --v3;
  }
  while ( v3 );
  result = 0;
  memset(v1, 0, 0x1000u);
  return result;
}
