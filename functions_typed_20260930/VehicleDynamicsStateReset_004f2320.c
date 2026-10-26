_DWORD *__thiscall sub_4F2320(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // esi

  this[3387] = 0;
  this[3388] = 0;
  this[3389] = 0;
  this[3390] = 0;
  this[3391] = 0;
  this[3392] = 0;
  this[3393] = 0;
  this[3394] = 0;
  this[3395] = 0;
  result = this + 3436;
  v2 = 4;
  do
  {
    *result = 0;
    result += 62;
    --v2;
  }
  while ( v2 );
  if ( !this[3247] )
    return PhysicsStateZeroingResetForSuspension(&dbl_7C7428);
  return result;
}

