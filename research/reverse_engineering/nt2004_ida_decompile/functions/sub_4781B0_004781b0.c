char __thiscall sub_4781B0(void *this, int a2, int a3)
{
  int i; // esi
  int v4; // eax

  for ( i = 0; i < a3; ++i )
  {
    v4 = *(unsigned __int16 *)(a2 + 2 * i);
    if ( v4 == 21 )
    {
      sub_4BA060(&byte_766124);
      dword_608F60 = -1;
      sub_465910(dword_764D70, 0);
    }
    else if ( v4 == 49 )
    {
      sub_49D120(this);
    }
  }
  return 1;
}
