int __thiscall sub_416A70(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // esi

  result = this[8];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      result = sub_470140(a2, this + 4);
      if ( this[3] == 1 )
        this[3] = 0;
      break;
    case 7:
      sub_5768E0(a2);
      v4 = (_DWORD *)(this[9] + 15972);
      v5 = this + 4;
      *v5 = *v4;
      result = v4[1];
      v5[1] = result;
      v5[2] = v4[2];
      break;
    default:
      return result;
  }
  return result;
}
