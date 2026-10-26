int __thiscall sub_54AA90(_DWORD *this)
{
  double v2; // st7
  int i; // edi
  int v4; // edx
  float *v5; // ecx
  int v6; // ebp
  float v7; // eax
  int result; // eax
  float v9; // [esp+0h] [ebp-4h]

  result = this[1];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = sub_548800((int)this);
      break;
    case 6:
    case 20:
      result = sub_54A630((int)this);
      break;
    case 7:
    case 8:
    case 16:
      if ( dword_BE1204 == 2 )
      {
        v2 = sub_5210A0(&dword_BE120C);
        result = this[27];
        for ( i = 0; i < result; ++i )
        {
          v4 = this[28];
          v5 = *(float **)(v4 + 4 * i);
          v9 = v2;
          if ( v9 < (double)v5[2] )
          {
            v6 = this[27] - 1;
            this[27] = v6;
            *(_DWORD *)(v4 + 4 * *((_DWORD *)v5 + 1)) = *(_DWORD *)(v4 + 4 * v6);
            *(float *)(*(_DWORD *)(this[28] + 4 * *((_DWORD *)v5 + 1)) + 4) = v5[1];
            v7 = *v5;
            v5[1] = NAN;
            sub_5FCB20(LODWORD(v7));
            --i;
          }
          result = this[27];
        }
      }
      break;
    case 9:
      result = sub_5452C0((int)this);
      break;
    case 14:
      result = sub_548F30((int)this);
      break;
    case 15:
      result = sub_548BA0((int)this);
      break;
    case 17:
      result = sub_544320((int)this);
      break;
    case 18:
    case 19:
      result = sub_548230(this);
      break;
    default:
      return result;
  }
  return result;
}
