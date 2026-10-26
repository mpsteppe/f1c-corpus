char __thiscall sub_41BF30(_DWORD *this, int a2, int a3)
{
  int v4; // edi
  int v5; // ecx
  int v6; // esi
  int v7; // ecx
  _DWORD *v8; // ebx
  int v10; // [esp-14h] [ebp-1Ch]

  ((void (*)(void))sub_41C050)();
  if ( a2 <= 0 || a3 <= 0 )
    return 0;
  v4 = 1;
  v5 = 0;
  if ( a2 > 1 )
  {
    do
      v4 = 1 << ++v5;
    while ( a2 > 1 << v5 );
  }
  v6 = 1;
  v7 = 0;
  if ( a3 > 1 )
  {
    do
      v6 = 1 << ++v7;
    while ( a3 > 1 << v7 );
  }
  sub_5A29F0((int)this, aCompositetex, v4, v6, 8, 0, 262152, 1);
  v8 = this + 2;
  if ( !sub_5A29F0((int)(this + 2), aWordtex, v4, v6, 8, 0, 262152, 1) )
  {
    v10 = *v8;
    this[3] = *(_DWORD *)(*v8 + 16);
    sub_5A1A60(this + 4, 2, v10, 48, 3136);
  }
  sub_592250(this + 1, v4, v6, 8, 1);
  if ( *this && *(_DWORD *)(*this + 16) && *v8 && this[3] && this[4] && this[1] )
    return 1;
  sub_41C050(this);
  return 0;
}
