int __thiscall sub_48A7C0(int *this, int a2)
{
  double v3; // st7
  int *v4; // ecx
  int result; // eax
  float *v6; // ebp
  float *v7; // esi
  float **v8; // eax
  float *j; // eax
  int i; // eax
  float v11; // [esp+10h] [ebp-8h] BYREF
  int *v12; // [esp+14h] [ebp-4h] BYREF

  v3 = sub_617ED0(*this + 8);
  v11 = v3;
  if ( v3 >= 0.001 )
  {
    if ( v11 > 1.0 )
      v11 = 1.0;
  }
  else
  {
    v11 = 0.001;
  }
  sub_48A750(*this, SLODWORD(v11));
  *(float *)(*this + 104) = v11;
  sub_525140(*this + 116);
  sub_525140(*this + 132);
  v4 = *(int **)(*this + 152);
  result = *v4;
  v11 = *(float *)v4;
  if ( (int *)LODWORD(v11) != v4 )
  {
    do
    {
      *(_BYTE *)(*(_DWORD *)(result + 16) + 16) = 0;
      sub_476240((int *)&v11);
      result = LODWORD(v11);
    }
    while ( LODWORD(v11) != *(_DWORD *)(*this + 152) );
  }
  v6 = *(float **)(*this + 152);
  v7 = *(float **)v6;
  if ( *(float **)v6 == v6 )
  {
    *(_DWORD *)(*this + 160) = 0;
  }
  else
  {
    do
    {
      v11 = v7[3];
      if ( *sub_4796F0((_DWORD *)a2, &v12, &v11) == *(int **)(a2 + 4) )
      {
        sub_48A250();
        v6 = *(float **)(*this + 152);
        v7 = v6;
      }
      if ( !*((_BYTE *)v7 + 21) )
      {
        v8 = (float **)*((_DWORD *)v7 + 2);
        if ( *((_BYTE *)v8 + 21) )
        {
          for ( i = *((_DWORD *)v7 + 1); !*(_BYTE *)(i + 21); i = *(_DWORD *)(i + 4) )
          {
            if ( v7 != *(float **)(i + 8) )
              break;
            v7 = (float *)i;
          }
          v7 = (float *)i;
        }
        else
        {
          v7 = (float *)*((_DWORD *)v7 + 2);
          for ( j = *v8; !*((_BYTE *)j + 21); j = *(float **)j )
            v7 = j;
        }
      }
    }
    while ( v7 != v6 );
    result = *this;
    *(_DWORD *)(*this + 160) = 0;
  }
  return result;
}
