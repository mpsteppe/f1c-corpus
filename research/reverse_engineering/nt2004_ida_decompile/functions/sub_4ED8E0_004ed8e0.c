_BYTE *__thiscall sub_4ED8E0(_BYTE *this, char a2)
{
  int v3; // esi

  if ( this[8] )
  {
    v3 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      if ( *(_DWORD *)(v3 + 40) )
      {
        sub_592310(*(_DWORD *)(v3 + 40));
        *(_DWORD *)(v3 + 40) = 0;
      }
      if ( *(_DWORD *)(v3 + 28) )
        sub_5BE8AE(*(LPVOID *)(v3 + 28));
      if ( *(_DWORD *)(v3 + 12) )
        sub_5BE8AE(*(LPVOID *)(v3 + 12));
      if ( *(_DWORD *)v3 )
        sub_5BE8AE(*(LPVOID *)v3);
      sub_5BE8AE((LPVOID)v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
