void __thiscall sub_4A2840(int this, float a2)
{
  int v3; // edx
  int v4; // ecx
  float *i; // esi
  int k; // ebx
  int v7; // eax
  int v8; // ebx
  int j; // ebx
  float v10; // [esp+10h] [ebp+4h]

  if ( *(_DWORD *)(this + 108) )
  {
    v3 = *(_DWORD *)(this + 112);
    v4 = 0;
    if ( v3 > 0 )
    {
      for ( i = *(float **)(this + 116); a2 > (double)*i; i += 7 )
      {
        if ( a2 <= (double)i[1] )
        {
          if ( *(float *)(this + 68) != a2 )
          {
            v7 = *(_DWORD *)(this + 104);
            *(float *)(this + 68) = a2;
            v8 = 0;
            v10 = (a2 - *i) * i[2] * (i[4] - i[3]) + i[3];
            if ( v7 > 0 )
            {
              do
                sub_551210(*(_DWORD *)(*(_DWORD *)(this + 108) + 4 * v8++), v10);
              while ( v8 < *(_DWORD *)(this + 104) );
            }
          }
          return;
        }
        if ( ++v4 == v3 )
        {
          if ( *(float *)(this + 68) != i[1] )
          {
            *(float *)(this + 68) = i[1];
            for ( j = 0; j < *(_DWORD *)(this + 104); ++j )
              sub_551210(*(_DWORD *)(*(_DWORD *)(this + 108) + 4 * j), i[4]);
          }
          return;
        }
        if ( v4 >= v3 )
          return;
      }
      if ( *(float *)(this + 68) != *i )
      {
        *(float *)(this + 68) = *i;
        for ( k = 0; k < *(_DWORD *)(this + 104); ++k )
          sub_551210(*(_DWORD *)(*(_DWORD *)(this + 108) + 4 * k), i[3]);
      }
    }
  }
}
