void __thiscall sub_41F410(_DWORD *this)
{
  float *v1; // esi
  int v2; // edi
  int v3; // ebx
  int *v4; // ebp
  size_t v5; // eax
  float *v6; // edx
  bool v7; // zf

  v1 = (float *)this[192];
  v2 = 0;
  if ( !v1 )
  {
    if ( (int)NumOfElements > 0 )
    {
      v3 = -1;
      v4 = dword_75AAD0;
      do
      {
        this[4 * *(_DWORD *)(*v4 + 25248) + 2] = *(_DWORD *)(*v4 + 25248);
        this[4 * *(_DWORD *)(*v4 + 25248)] = &this[4 * *(_DWORD *)(dword_75AAD0[(v3 + 2) % (int)NumOfElements] + 25248)];
        if ( v3 >= 0 )
          v5 = v3;
        else
          v5 = NumOfElements - 1;
        ++v3;
        this[4 * *(_DWORD *)(*v4++ + 25248) + 1] = &this[4 * *(_DWORD *)(dword_75AAD0[v5] + 25248)];
      }
      while ( v3 + 1 < (int)NumOfElements );
    }
    this[192] = &this[4 * *(_DWORD *)(dword_75AAD0[0] + 25248)];
  }
  if ( (int)NumOfElements >= 6 )
  {
    v6 = *(float **)this[192];
    do
    {
      if ( v2 )
      {
        while ( v1[3] > (double)*(float *)(*((_DWORD *)v1 + 1) + 12) )
        {
          **(_DWORD **)(v2 + 4) = v1;
          *(_DWORD *)(*(_DWORD *)v1 + 4) = v2;
          *(float *)v2 = *v1;
          v1[1] = *(float *)(v2 + 4);
          *(_DWORD *)v1 = v2;
          *(_DWORD *)(v2 + 4) = v1;
          if ( v2 == this[192] )
          {
            this[192] = v1;
            break;
          }
          v2 = *((_DWORD *)v1 + 1);
          if ( !v2 )
            break;
        }
      }
      v1 = v6;
      v7 = this[192] == (_DWORD)v6;
      v6 = *(float **)v6;
      v2 = *((_DWORD *)v1 + 1);
    }
    while ( !v7 );
  }
}
