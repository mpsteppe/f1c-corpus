// f1c  0x004ba980  size=105
_DWORD *__thiscall sub_4BA980(_DWORD *this, char a2)
{
  int v3; // esi
  int *v4; // eax
  _DWORD *v5; // ebx
  _DWORD *v6; // edi

  v3 = a2 != 0 ? 0 : 2;
  v4 = (int *)sub_587C03(884 * v3 + 4);
  if ( v4 )
  {
    v5 = v4 + 1;
    *v4 = v3;
    v6 = v4 + 1;
    if ( v3 - 1 >= 0 )
    {
      do
      {
        sub_4FF670(v6);
        v6 += 221;
        --v3;
      }
      while ( v3 );
    }
    *this = v5;
    return this;
  }
  else
  {
    *this = 0;
    return this;
  }
}
