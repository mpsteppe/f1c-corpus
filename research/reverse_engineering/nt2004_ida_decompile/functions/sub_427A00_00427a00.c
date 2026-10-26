int __thiscall sub_427A00(int this)
{
  signed int v1; // edi
  int v3; // edi
  int v4; // ebp
  int result; // eax

  v1 = NumOfElements;
  v3 = rand() % v1;
  v4 = v3;
  sub_4DE920(this + 20836);
  *(_DWORD *)(this + 24604) = *(_DWORD *)(this + 20848);
  if ( !sub_4280C0(this) )
  {
LABEL_4:
    if ( !*(_BYTE *)(this + 24492) )
      ++*(_DWORD *)(this + 24584);
    goto LABEL_6;
  }
  if ( !*(_BYTE *)(this + 24492) )
  {
    *(_DWORD *)(this + 17416) = 0;
    goto LABEL_4;
  }
LABEL_6:
  if ( dword_75CBB0 == 7 )
    *(_DWORD *)(this + 24228) = 0;
  *(float *)(this + 23848) = *(float *)(this + 23852) + 4.0;
  result = dword_75CBB0;
  switch ( dword_75CBB0 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
      *(_DWORD *)(this + 24024) = 0;
      sub_4EEC20(0);
      sub_4EEC50(0);
      result = sub_4EECE0(0);
      break;
    case 5:
      *(_DWORD *)(this + 24024) = 3;
      sub_4EEC20(0);
      sub_4EEC50(0);
      sub_4EECE0(0);
      while ( 1 )
      {
        result = dword_75AAD0[v3];
        if ( !*(_DWORD *)(result + 24024) && *(_DWORD *)(result + 16584) == 1 )
          break;
        if ( ++v3 >= (int)NumOfElements )
          v3 = 0;
        if ( v3 == v4 )
          return result;
      }
      result = sub_42C000(dword_75AAD0[v3]);
      break;
    default:
      return result;
  }
  return result;
}
