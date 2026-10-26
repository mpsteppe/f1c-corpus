// f1c  0x004651c0  size=268
float *__thiscall sub_4651C0(float **this)
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
  v2 = sub_568CF0(*this + 1);
  v12 = v2;
  if ( v2 >= 0.001 )
  {
    if ( v12 > 1.0 )
      v12 = 1.0;
    sub_464EF0(*v1, v12);
  }
  else
  {
    v12 = 0.001;
    sub_464EF0(*v1, 0.001);
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
        sub_587BCF(*v5);
      sub_587BCF(v5);
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
        sub_587BCF(*v9);
      sub_587BCF(v9);
    }
    while ( v7 );
    v1 = this;
  }
  *v8 = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  for ( i = 0; i < 14560; i += 140 )
    LOBYTE((*v1)[i + 62]) = 0;
  result = *v1;
  (*v1)[14595] = 0.0;
  return result;
}
