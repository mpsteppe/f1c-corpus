char *__thiscall sub_4E4C80(char *this)
{
  char *v2; // ecx
  char *v3; // ebx
  signed int v4; // edi
  int v5; // eax

  v3 = sub_4E4C50(this);
  if ( v3 )
  {
    v4 = 0;
    if ( sub_4E4C30(v2) > 0 )
    {
      do
      {
        v5 = sub_4E4C60(this, v4);
        if ( v5 && *((_DWORD *)v3 + 152) < *(_DWORD *)(v5 + 608) )
          v3 = (char *)v5;
        ++v4;
      }
      while ( v4 < sub_4E4C30(this) );
    }
  }
  return v3;
}
