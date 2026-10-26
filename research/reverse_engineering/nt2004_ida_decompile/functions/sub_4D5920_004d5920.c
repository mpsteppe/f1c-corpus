int *__thiscall sub_4D5920(_DWORD *this)
{
  int v2; // esi
  int *result; // eax
  _DWORD *v4; // ebp
  _DWORD *v5; // ebx
  int v6; // esi
  int v7; // ebx

  switch ( this[327] )
  {
    case 1:
      v2 = 24;
      break;
    case 2:
      v2 = 32;
      break;
    case 3:
      v2 = 48;
      break;
    case 4:
      v2 = 96;
      break;
    default:
      v2 = 16;
      break;
  }
  result = (int *)this[331];
  if ( (int *)v2 != result )
  {
    sub_4D5A00(this);
    this[331] = v2;
    result = (int *)operator new((v2 << 7) + 4);
    if ( result )
    {
      v4 = result + 1;
      *result = v2;
      result = (int *)(v2 - 1);
      v5 = v4;
      if ( v2 - 1 >= 0 )
      {
        do
        {
          result = sub_4D3610(v5);
          v5 += 32;
          --v2;
        }
        while ( v2 );
        this[330] = v4;
        return result;
      }
    }
    else
    {
      v4 = 0;
    }
    this[330] = v4;
    return result;
  }
  v6 = 0;
  if ( (int)result > 0 )
  {
    v7 = 0;
    do
    {
      sub_4D3D70((float *)(v7 + this[330]));
      result = (int *)this[331];
      ++v6;
      v7 += 128;
    }
    while ( v6 < (int)result );
  }
  return result;
}
