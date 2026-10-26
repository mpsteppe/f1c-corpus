void *__thiscall sub_4BDDE0(LPVOID *this)
{
  LPVOID *v2; // esi
  int v3; // ebx
  int v4; // edi

  v2 = this;
  v3 = 8;
  do
  {
    v4 = 8;
    do
    {
      StructCleanup(v2);
      v2 += 9;
      --v4;
    }
    while ( v4 );
    --v3;
  }
  while ( v3 );
  return StructCleanup(this + 576);
}

