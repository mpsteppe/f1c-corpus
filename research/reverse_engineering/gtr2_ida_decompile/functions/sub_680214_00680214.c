void __thiscall sub_680214(_DWORD *this)
{
  int v2; // edi
  int v3; // eax

  while ( this[2] )
  {
    v2 = this[2];
    this[2] = *(_DWORD *)(v2 + 16);
    v3 = *(_DWORD *)(v2 + 8);
    if ( (v3 & 8) != 0 || (v3 & 1) == 0 )
      j__free(*(void **)v2);
    j__free((void *)v2);
  }
}
