int __thiscall sub_519D00(char *this)
{
  char *v1; // edi
  void **v2; // edi
  void **v3; // esi
  int v4; // ebp
  int v5; // ebx
  bool v6; // zf
  int result; // eax
  char *v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v1 = this;
  v8 = this;
  v9 = 105;
  do
  {
    v2 = (void **)(v1 + 32);
    v3 = v2;
    v4 = 32;
    do
    {
      v5 = 32;
      do
      {
        if ( *v3 )
          j__free(*v3);
        ++v3;
        --v5;
      }
      while ( v5 );
      --v4;
    }
    while ( v4 );
    memset(v2, 0, 0x1000u);
    v1 = v8 + 4128;
    result = v9 - 1;
    v6 = v9 == 1;
    v8 += 4128;
    --v9;
  }
  while ( !v6 );
  return result;
}
