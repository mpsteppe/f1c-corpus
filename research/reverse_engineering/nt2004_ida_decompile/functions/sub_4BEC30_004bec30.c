void __thiscall sub_4BEC30(_DWORD *this)
{
  int *v2; // eax
  int i; // eax
  int v4; // eax
  int v5; // eax
  int *v6; // eax

  if ( (*(_BYTE *)this & 1) != 0 )
  {
    v2 = (int *)this[46];
    this[48] = v2;
    if ( v2 )
    {
      for ( i = *v2; i; i = *v6 )
      {
        v4 = *(_DWORD *)(i + 100);
        if ( v4 )
          sub_59EF60(v4);
        v5 = this[48];
        if ( !v5 )
          break;
        v6 = *(int **)(v5 + 4);
        this[48] = v6;
        if ( !v6 )
          break;
      }
    }
  }
  *this &= 0xFFFFFFFC;
  this[50] = -1;
  this[16] = 0;
}
