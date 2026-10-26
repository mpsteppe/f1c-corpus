int __thiscall sub_552BC0(int this, _DWORD *a2, float a3)
{
  int v3; // eax
  int v4; // ebp
  int result; // eax
  int v7; // ecx

  v3 = a2[4845];
  v4 = -1;
  if ( v3 == 3 || v3 == 2 )
    return -1;
  switch ( dword_B64134 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      result = -1;
      break;
    default:
      v7 = (unsigned __int64)((a3 - flt_FADE1C) / ((*(float *)(this + 224) - *(float *)(this + 220)) * 0.25));
      if ( a3 >= (double)*(float *)(this + 224) || dword_B64134 == 8 )
        v7 = 4;
      if ( a2[4831] == 1 )
        *(_DWORD *)(this + 212) = v7;
      if ( v7 < 5 && v7 > 0 && v7 <= *(_DWORD *)(this + 212) )
        v4 = sub_52D6D0(a2 + 4818, v7);
      result = v4;
      break;
  }
  return result;
}
