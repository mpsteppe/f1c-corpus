char *__thiscall sub_4764C0(char *this, _DWORD *a2)
{
  CHAR *v2; // eax
  int v3; // esi
  CHAR v4; // dl
  int v5; // edx
  double v6; // st7

  v2 = (CHAR *)a2[1];
  if ( !v2 )
    v2 = &byte_629120;
  v3 = this - v2;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 );
  v5 = *a2;
  v6 = *(float *)(*a2 + 20);
  if ( *((float *)this + 32) <= 0.0 )
  {
    *((_DWORD *)this + 32) = *(_DWORD *)(v5 + 20);
    return this;
  }
  else if ( v6 <= 0.0 || v6 >= *((float *)this + 32) )
  {
    return this;
  }
  else
  {
    *((_DWORD *)this + 32) = *(_DWORD *)(v5 + 20);
    return this;
  }
}
