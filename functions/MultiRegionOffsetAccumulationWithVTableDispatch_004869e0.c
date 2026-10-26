int __thiscall sub_4869E0(_DWORD *this, int a2, int a3)
{
  int v5; // eax
  int v6; // ecx
  bool v7; // cc
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // edx
  int v16; // edx
  int i; // edi
  int v19; // [esp+18h] [ebp+8h]

  v5 = this[1];
  v6 = v5 + a3;
  v7 = v5 < v5 + a3;
  v19 = v5;
  if ( !v7 )
    v19 = v6;
  v8 = this[2];
  v9 = v8;
  if ( v8 <= v8 + a3 )
    v9 = v8 + a3;
  v10 = this[3];
  v11 = v10;
  if ( v10 >= v10 + a2 )
    v11 = v10 + a2;
  v12 = this[4];
  if ( v12 <= v12 + a2 )
    v12 += a2;
  GuardedSubRectangleRenderDispatch(v19, v9, v11, v12);
  v13 = this[2];
  v14 = this[3];
  v15 = a2 + this[4];
  this[1] += a3;
  this[4] = v15;
  v16 = *this;
  this[2] = a3 + v13;
  this[3] = a2 + v14;
  (*(void (__thiscall **)(_DWORD *, int))(v16 + 44))(this, 1);
  for ( i = this[36]; i; i = *(_DWORD *)(i + 140) )
    MultiRegionOffsetAccumulationWithVTableDispatch(a2, a3);
  return (*(int (__thiscall **)(_DWORD *))(*this + 160))(this);
}
