_DWORD *__thiscall sub_5978A0(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  int v4; // esi
  int v5; // esi

  switch ( *a2 & 0xF )
  {
    case 1:
      result = this + 72;
      v3 = this + 73;
      break;
    case 2:
      result = this + 76;
      v3 = this + 77;
      break;
    case 4:
      result = this + 74;
      v3 = this + 75;
      break;
    case 8:
      result = this + 78;
      v3 = this + 79;
      break;
    default:
      result = a2;
      v3 = a2;
      break;
  }
  v4 = a2[50];
  if ( v4 )
    *(_DWORD *)(v4 + 204) = a2[51];
  v5 = a2[51];
  if ( v5 )
    *(_DWORD *)(v5 + 200) = a2[50];
  if ( (_DWORD *)*v3 == a2 )
    *v3 = a2[51];
  --*result;
  return result;
}
