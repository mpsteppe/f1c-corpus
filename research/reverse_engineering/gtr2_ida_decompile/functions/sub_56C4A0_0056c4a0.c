double __thiscall sub_56C4A0(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // ebp
  int v3; // ecx
  float **v4; // eax
  float *v5; // edi
  float v6; // eax
  int v7; // eax
  int v8; // ebx
  int i; // esi
  float *v10; // eax
  double v11; // st4
  int v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-Ch]
  double v16; // [esp+20h] [ebp-8h]

  v1 = this;
  v14 = sub_56C000();
  v16 = -1.797693134862316e308;
  v2 = 0;
  v15 = v1[136];
  if ( v15 > 0 )
  {
    do
    {
      v3 = v2;
      if ( v2 >= 0 && v2 < v1[136] )
      {
        v4 = (float **)v1[133];
        if ( v2 <= 0 )
        {
LABEL_7:
          if ( v4 )
          {
            v5 = *v4;
            goto LABEL_10;
          }
        }
        else
        {
          while ( v4 )
          {
            v4 = (float **)v4[1];
            if ( --v3 <= 0 )
              goto LABEL_7;
          }
        }
      }
      v5 = 0;
LABEL_10:
      if ( v5[60] == 0.0 )
      {
        v6 = *v5;
        if ( (*(_DWORD *)v5 & 0x200) != 0 )
          v7 = 2 - ((LODWORD(v6) & 0x100000) != 0);
        else
          v7 = 4 - ((LODWORD(v6) & 0x100000) != 0);
      }
      else
      {
        v7 = 0;
      }
      if ( v7 >= v14 )
      {
        v8 = sub_5EA5B0(v5);
        for ( i = 0; i < v8; ++i )
        {
          v10 = (float *)sub_5EB140(i, 1);
          v11 = *v10 * *v10 + v10[1] * v10[1] + v10[2] * v10[2];
          if ( v11 > v16 )
            v16 = v11;
        }
        v1 = this;
      }
      ++v2;
    }
    while ( v2 < v15 );
  }
  return v16;
}
