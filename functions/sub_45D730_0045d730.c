int __thiscall sub_45D730(int this)
{
  int v2; // edi
  LPVOID **v3; // ecx
  int v4; // edi
  LPVOID **v5; // ecx
  int v6; // edi
  LPVOID **v7; // ecx
  int v8; // edi
  int v9; // ebp
  int v10; // edi
  int v11; // edi
  int v12; // ebp

  v2 = *(_DWORD *)(this + 112512);
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v2 = *(_DWORD *)(v2 + 4);
    DestructorWithDoubleFreePattern(v3, 1);
  }
  *(_DWORD *)(this + 112512) = 0;
  *(_DWORD *)(this + 112516) = 0;
  *(_DWORD *)(this + 112520) = 0;
  *(_DWORD *)(this + 112524) = 0;
  v4 = *(_DWORD *)(this + 112496);
  while ( v4 )
  {
    v5 = (LPVOID **)v4;
    v4 = *(_DWORD *)(v4 + 4);
    DestructorWithDoubleFreePattern(v5, 1);
  }
  *(_DWORD *)(this + 112496) = 0;
  *(_DWORD *)(this + 112500) = 0;
  *(_DWORD *)(this + 112504) = 0;
  *(_DWORD *)(this + 112508) = 0;
  v6 = *(_DWORD *)(this + 112472);
  while ( v6 )
  {
    v7 = (LPVOID **)v6;
    v6 = *(_DWORD *)(v6 + 4);
    DestructorWithDoubleFreePattern(v7, 1);
  }
  *(_DWORD *)(this + 112472) = 0;
  *(_DWORD *)(this + 112476) = 0;
  *(_DWORD *)(this + 112480) = 0;
  *(_DWORD *)(this + 112484) = 0;
  v8 = this + 107456;
  v9 = 104;
  do
  {
    v8 -= 872;
    EmptyStub_0170(v8);
    --v9;
  }
  while ( v9 );
  v10 = *(_DWORD *)(this + 16328);
  while ( v10 )
  {
    v10 = *(_DWORD *)(v10 + 4);
    ConditionalDestructor_46f0(1);
  }
  *(_DWORD *)(this + 16328) = 0;
  *(_DWORD *)(this + 16332) = 0;
  *(_DWORD *)(this + 16336) = 0;
  *(_DWORD *)(this + 16340) = 0;
  *(_DWORD *)(this + 16316) = off_59F0CC;
  v11 = this + 15476;
  v12 = 104;
  do
  {
    v11 -= 140;
    EmptyStub_0170(v11);
    --v12;
  }
  while ( v12 );
  if ( *(_DWORD *)(this + 188) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 188));
  if ( *(_DWORD *)(this + 180) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 180));
  return EmptyStub_0170(this + 52);
}
