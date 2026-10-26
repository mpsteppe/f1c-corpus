int __thiscall sub_48D260(_DWORD *this, int a2)
{
  int *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int result; // eax

  v2 = (int *)this[217];
  v3 = *v2;
  if ( a2 == 1 )
    v4 = this[214] + v3;
  else
    v4 = v3 - this[215];
  v5 = this[213];
  if ( v4 < v5 || (v5 = this[212], v4 > v5) )
    v4 = v5;
  switch ( v4 )
  {
    case 0:
      *v2 = 0;
      result = (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
      break;
    case 1:
      *v2 = 1;
      result = (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
      break;
    case 2:
      *v2 = 2;
      result = (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
      break;
    case 3:
      *v2 = 3;
      goto LABEL_12;
    default:
LABEL_12:
      result = (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
      break;
  }
  return result;
}
