void __thiscall sub_550820(_DWORD *this)
{
  int v1; // ecx
  int v2; // eax
  void *v3; // ebx
  LPVOID *v4; // esi
  int v5; // eax
  int v6; // edi

  v1 = this[2];
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 - 4);
    v3 = (void *)(v1 - 4);
    v4 = (LPVOID *)(v1 + 8 * v2);
    v5 = v2 - 1;
    if ( v5 >= 0 )
    {
      v6 = v5 + 1;
      do
      {
        v4 -= 2;
        sub_550810(v4);
        --v6;
      }
      while ( v6 );
    }
    FreeWrapper_7bcf(v3);
  }
  EmptyStub_0170();
}

