_DWORD *__thiscall sub_5455F0(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  int v4; // esi
  int v5; // esi

  switch ( *a2 & 7 )
  {
    case 1:
      result = this + 71;
      v3 = this + 72;
      break;
    case 2:
      result = this + 75;
      v3 = this + 76;
      break;
    case 4:
      result = this + 73;
      v3 = this + 74;
      break;
    default:
      result = a2;
      v3 = a2;
      break;
  }
  v4 = a2[26];
  if ( v4 )
    *(_DWORD *)(v4 + 108) = a2[27];
  v5 = a2[27];
  if ( v5 )
    *(_DWORD *)(v5 + 104) = a2[26];
  if ( (_DWORD *)*v3 == a2 )
    *v3 = a2[27];
  --*result;
  return result;
}
