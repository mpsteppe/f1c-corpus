void __thiscall sub_53C6B0(_BYTE *this, _DWORD *a2)
{
  char *v2; // eax
  char v3; // dl

  if ( a2 )
  {
    v2 = (char *)(a2 + 1);
    do
    {
      v3 = *v2;
      v2[this - (_BYTE *)a2] = *v2;
      ++v2;
    }
    while ( v3 );
    *(_DWORD *)this = *a2;
  }
  else
  {
    this[4] = 0;
    *(_DWORD *)this = 0;
  }
}

