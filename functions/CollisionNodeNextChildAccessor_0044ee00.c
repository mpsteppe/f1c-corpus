_DWORD *__thiscall CollisionNodeNextChildAccessor(_DWORD *this)
{
  if ( *this )
    return this + 76;
  else
    return 0;
}
