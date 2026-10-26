int __thiscall sub_4C9C00(_DWORD *this)
{
  int v1; // edi
  _DWORD *v3; // eax
  char *v4; // ecx
  int v5; // edx
  int result; // eax
  int v7; // ecx

  v1 = dword_5C329C;
  if ( dword_5C329C > 0 )
  {
    v3 = this;
    v4 = (char *)((char *)dword_7C54F0 - (char *)this);
    v5 = dword_5C329C;
    do
    {
      *v3 = *(_DWORD *)((char *)v3 + (_DWORD)v4) + 12;
      ++v3;
      --v5;
    }
    while ( v5 );
  }
  sub_5890AA(this, v1, 4, sub_4C9BA0);
  for ( result = 0; result < v1; *(float *)&this[result + 103] = *(float *)(v7 + 1856) + *(float *)(v7 + 1848) )
    v7 = this[result++];
  return result;
}
