int __thiscall sub_4DB770(int *this)
{
  int v2; // esi
  int *v3; // edi
  char v4; // al
  int v5; // ebp
  int result; // eax

  v2 = *this;
  while ( v2 )
  {
    v3 = (int *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        nullsub_6((void *)(v5 + 148));
        sub_5BE8AE((LPVOID)v5);
      }
    }
    sub_5BE8AE(v3);
  }
  result = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
