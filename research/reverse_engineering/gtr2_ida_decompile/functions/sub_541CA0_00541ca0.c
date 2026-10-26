int __thiscall sub_541CA0(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-8h]

  if ( this[7] || (v2 = this[8]) == 0 || (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 28))(v2) == 2 )
  {
    v3 = this[8];
    if ( v3 )
      (*(void (**)(void))(*(_DWORD *)v3 + 8))();
    v4 = this[9];
    if ( v4 )
      (*(void (**)(void))(*(_DWORD *)v4 + 8))();
    v5 = this[10];
    if ( v5 )
      (*(void (**)(void))(*(_DWORD *)v5 + 8))();
  }
  if ( *(_DWORD *)dword_B640C8 && !byte_B6F118 )
  {
    *(float *)&v7 = flt_BE1D28 * *(float *)&dword_B70948;
    sub_541770(this, 0, v7);
  }
  return 0;
}
