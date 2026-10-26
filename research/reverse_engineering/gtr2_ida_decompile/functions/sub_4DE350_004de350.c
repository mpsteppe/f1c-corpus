void __thiscall sub_4DE350(_DWORD *this)
{
  int i; // esi
  int v2; // eax

  for ( i = this[85]; i; i = *(_DWORD *)(i + 84) )
  {
    v2 = *(_DWORD *)(i + 80);
    if ( v2 )
      (*(void (**)(void))(*(_DWORD *)v2 + 8))();
  }
}
