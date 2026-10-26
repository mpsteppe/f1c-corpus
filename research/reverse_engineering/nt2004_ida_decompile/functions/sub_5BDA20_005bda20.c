void __thiscall sub_5BDA20(_DWORD *this)
{
  _DWORD *v2; // ecx
  int v3; // esi
  _DWORD *v4; // [esp+4h] [ebp-4h] BYREF

  v2 = (_DWORD *)this[367];
  if ( v2 )
  {
    v4 = v2;
    do
    {
      v3 = sub_4AD870(v2);
      sub_5BA0C0(&v4);
      v2 = (_DWORD *)v3;
      v4 = (_DWORD *)v3;
    }
    while ( v3 );
    this[367] = 0;
  }
}
