float *__thiscall sub_46CEE0(float **this)
{
  float **v1; // ebp
  double v2; // st7
  int v3; // esi
  _DWORD *v4; // edi
  LPVOID *v5; // ebp
  bool v6; // zf
  int v7; // esi
  _DWORD *v8; // edi
  LPVOID *v9; // ebp
  int i; // eax
  float *result; // eax
  float v12; // [esp+10h] [ebp-8h]

  v1 = this;
  v2 = sub_57B720(*this + 1);
  v12 = v2;
  if ( v2 >= 0.001 )
  {
    if ( v12 > 1.0 )
      v12 = 1.0;
    sub_46CC10(*v1, v12);
  }
  else
  {
    v12 = 0.001;
    sub_46CC10(*v1, 0.001);
  }
  (*v1)[24] = v12;
  v3 = *((_DWORD *)*v1 + 27);
  v4 = *v1 + 27;
  if ( v3 )
  {
    do
    {
      v5 = (LPVOID *)v3;
      v6 = *(_BYTE *)(v3 + 8) == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v6 )
        sub_5BE8AE(*v5);
      sub_5BE8AE(v5);
    }
    while ( v3 );
    v1 = this;
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v7 = *((_DWORD *)*v1 + 31);
  v8 = *v1 + 31;
  if ( v7 )
  {
    do
    {
      v9 = (LPVOID *)v7;
      v6 = *(_BYTE *)(v7 + 8) == 0;
      v7 = *(_DWORD *)(v7 + 4);
      if ( !v6 )
        sub_5BE8AE(*v9);
      sub_5BE8AE(v9);
    }
    while ( v7 );
    v1 = this;
  }
  *v8 = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  for ( i = 0; i < 3479; i += 71 )
    LOBYTE((*v1)[i + 49]) = 0;
  result = *v1;
  (*v1)[3514] = 0.0;
  return result;
}
