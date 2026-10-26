int __thiscall sub_448DA0(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int result; // eax

  while ( 1 )
  {
    ShadowVolumeExtrusion((int)this);
    v2 = this + 19;
    v3 = 4;
    do
    {
      if ( *v2 )
        CollisionTreeTraversal();
      ++v2;
      --v3;
    }
    while ( v3 );
    result = this[23];
    if ( !result )
      break;
    this = (_DWORD *)this[23];
  }
  return result;
}
