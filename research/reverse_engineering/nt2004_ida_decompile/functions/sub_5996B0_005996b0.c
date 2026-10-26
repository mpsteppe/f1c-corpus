int __thiscall sub_5996B0(float *this, int a2, _DWORD *a3)
{
  __int64 v3; // rax

  LODWORD(v3) = a2 - 1;
  switch ( a2 )
  {
    case 1:
      if ( a3 )
      {
        v3 = (__int64)(this[24] * 255.0);
        *a3 = v3;
      }
      break;
    case 2:
      if ( a3 )
      {
        v3 = (__int64)(this[20] * 255.0);
        *a3 = v3;
      }
      break;
    case 3:
      if ( a3 )
      {
        v3 = (__int64)(this[28] * 255.0);
        *a3 = v3;
      }
      break;
    case 4:
      if ( a3 )
      {
        v3 = (__int64)(this[32] * 255.0);
        *a3 = v3;
      }
      break;
    default:
      return v3;
  }
  return v3;
}
