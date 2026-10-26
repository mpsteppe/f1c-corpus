void __thiscall sub_5511A0(_DWORD *this)
{
  void *v2; // esi
  int v3; // eax
  int v4; // ecx
  void *v5; // ebp
  int v6; // esi
  int v7; // ecx
  int v8; // edi

  v2 = (void *)*this;
  if ( *this )
  {
    EmptyStub_7470(*this);
    FreeWrapper_7bcf(v2);
  }
  v3 = this[6];
  *this = 0;
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 - 4);
    v5 = (void *)(v3 - 4);
    v6 = v3 + 136 * v4;
    v7 = v4 - 1;
    if ( v7 >= 0 )
    {
      v8 = v7 + 1;
      do
      {
        v6 -= 136;
        EmptyStub_7470(v6);
        --v8;
      }
      while ( v8 );
    }
    FreeWrapper_7bcf(v5);
  }
  this[6] = 0;
  EmptyStub_0170();
}

