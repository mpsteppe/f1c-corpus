void __thiscall sub_476770(int *this)
{
  int *v2; // edi
  int *v3; // ebp
  int v4; // ecx
  _DWORD *v5; // eax
  float v6; // [esp+0h] [ebp-20h]
  float v7; // [esp+4h] [ebp-1Ch]

  v2 = (int *)this[36];
  this[156] = 30;
  if ( v2 )
  {
    v3 = this + 108;
    do
    {
      v4 = *v3;
      if ( *v3 >= 0 && v4 < this[107] )
      {
        v5 = (_DWORD *)this[104];
        if ( v4 <= 0 )
        {
LABEL_8:
          if ( v5 )
          {
            if ( *v5 )
            {
              v7 = (double)v2[1] * 0.0016666667;
              v6 = ((double)v2[3] + (double)this[156]) * 0.00125;
              sub_506AE0(v6, v7, 1.0, 0);
              sub_5069A0(0.03125, 0.041666668);
            }
          }
        }
        else
        {
          while ( v5 )
          {
            v5 = (_DWORD *)v5[1];
            if ( --v4 <= 0 )
              goto LABEL_8;
          }
        }
      }
      v2 = (int *)v2[35];
      ++v3;
    }
    while ( v2 );
  }
}
